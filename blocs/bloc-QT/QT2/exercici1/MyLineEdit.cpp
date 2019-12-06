#include "MyLabel.h"

MyLabel::MyLabel(QWidget *parent=0): 
    QLabel(parent){
        recaptacio = 0;
        coches = 0;
        camiones = 0;
        motos = 0;
}

//slots


void MyLabel::clickClose(){
    setStyleSheet("background:red");
}

void MyLabel::clickOpen(){
    setStyleSheet("background:green");
}

void MyLabel::aumentaMoto(){
    recaptacio++;
    motos++;
    emit addMoto(motos);
    emit recaudacion(recaptacio);
}

void MyLabel::aumentaCoche(){
    recaptacio++;
    coches++;
    emit addCoche(coches);
    emit recaudacion(recaptacio);
}

void MyLabel::aumentaCamion(){
    recaptacio += 4;
    camiones++;
    emit addCamion(camiones);
    emit recaudacion(recaptacio);
}
