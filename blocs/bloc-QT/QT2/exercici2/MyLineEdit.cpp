#include "MyLineEdit.h"

MyLineEdit::MyLineEdit(QWidget *parent=0): 
    QLineEdit(parent){
        letraIntroducida = "";
        erroresPermitidos = 5;
        password = "DICCIONARI";
        asteriscos = "**********";
}

//slots


void MyLineEdit::nuevaLetra(QString s){
    if(s == ""){
        //restart todo
        erroresPermitidos = 5;
        asteriscos = "**********";
        setEnabled(true);
        setStyleSheet("background:white");
    } else {
        bool acierto = false;
        for(int j = 0; j < password.length(); j++){
            if(password[j] == s[s.length()-1]) {
                acierto = true;
                asteriscos[j] = password[j];
            }
        }
        if(!acierto) erroresPermitidos--;
        if(password == asteriscos){
            //pasan cosas de ganador
            setStyleSheet("background:green");
            setDisabled(true);
        } else if(erroresPermitidos == 0){
            //pasan cosas de perdedor
            setDisabled(true);
            setStyleSheet("background:red");
            
        }
    }
                emit enviarError(erroresPermitidos);
            emit enviarPalabra(asteriscos);   

}
