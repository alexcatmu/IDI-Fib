#include "MyLabel.h"

MyLabel::MyLabel(QWidget *parent=0): 
    QLabel(parent){
}

//slots


void MyLabel::passwordIntrodueix(QString s){
    setStyleSheet("background:blue");
}

void MyLabel::passwordRepeteix(QString s){
    setStyleSheet("background:red");
}
