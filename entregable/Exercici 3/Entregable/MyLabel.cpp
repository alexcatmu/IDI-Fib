#include "MyLabel.h"

MyLabel::MyLabel(QWidget *parent=0): 
    QLabel(parent){
        QString intro = "";
        QString repe = "";
}

//slots


void MyLabel::passwordIntrodueix(QString s){
    intro = s;
    if(intro == repe && s.length() >= 6) setStyleSheet("background:lightgreen");
    else if(intro == repe) setStyleSheet("background:yellow");
    else setStyleSheet("background:red");
}

void MyLabel::passwordRepeteix(QString s){
    repe = s;
    if(intro == repe && s.length() >= 6) setStyleSheet("background:lightgreen");
    else if(intro == repe) setStyleSheet("background:yellow");
    else setStyleSheet("background:red");
}
