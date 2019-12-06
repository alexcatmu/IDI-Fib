/********************************************************************************
** Form generated from reading UI file 'MyForm.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYFORM_H
#define UI_MYFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "MyLabel.h"

QT_BEGIN_NAMESPACE

class Ui_MyForm
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLCDNumber *lcdNumber;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QLCDNumber *lcdNumber_2;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QLCDNumber *lcdNumber_3;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout;
    MyLabel *label;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLCDNumber *lcdNumber_4;

    void setupUi(QWidget *MyForm)
    {
        if (MyForm->objectName().isEmpty())
            MyForm->setObjectName(QStringLiteral("MyForm"));
        MyForm->resize(400, 309);
        gridLayout = new QGridLayout(MyForm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(MyForm);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        lcdNumber = new QLCDNumber(MyForm);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        verticalLayout_2->addWidget(lcdNumber);

        pushButton = new QPushButton(MyForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(false);

        verticalLayout_2->addWidget(pushButton);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_4 = new QLabel(MyForm);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);

        lcdNumber_2 = new QLCDNumber(MyForm);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));

        verticalLayout_3->addWidget(lcdNumber_2);

        pushButton_2 = new QPushButton(MyForm);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(false);

        verticalLayout_3->addWidget(pushButton_2);


        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_3 = new QLabel(MyForm);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_4->addWidget(label_3);

        lcdNumber_3 = new QLCDNumber(MyForm);
        lcdNumber_3->setObjectName(QStringLiteral("lcdNumber_3"));

        verticalLayout_4->addWidget(lcdNumber_3);

        pushButton_3 = new QPushButton(MyForm);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setEnabled(false);

        verticalLayout_4->addWidget(pushButton_3);


        horizontalLayout_2->addLayout(verticalLayout_4);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new MyLabel(MyForm);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(100, 100));
        label->setMaximumSize(QSize(100, 100));
        label->setStyleSheet(QStringLiteral("background:red"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        radioButton_2 = new QRadioButton(MyForm);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout->addWidget(radioButton_2);

        radioButton = new QRadioButton(MyForm);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout->addWidget(radioButton);


        horizontalLayout->addLayout(verticalLayout);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(MyForm);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_3->addWidget(label_5);

        lcdNumber_4 = new QLCDNumber(MyForm);
        lcdNumber_4->setObjectName(QStringLiteral("lcdNumber_4"));

        horizontalLayout_3->addWidget(lcdNumber_4);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);


        retranslateUi(MyForm);
        QObject::connect(radioButton_2, SIGNAL(clicked()), label, SLOT(clickOpen()));
        QObject::connect(radioButton, SIGNAL(clicked()), label, SLOT(clickClose()));
        QObject::connect(radioButton_2, SIGNAL(clicked(bool)), pushButton, SLOT(setEnabled(bool)));
        QObject::connect(radioButton_2, SIGNAL(clicked(bool)), pushButton_2, SLOT(setEnabled(bool)));
        QObject::connect(radioButton_2, SIGNAL(clicked(bool)), pushButton_3, SLOT(setEnabled(bool)));
        QObject::connect(radioButton, SIGNAL(clicked(bool)), pushButton_3, SLOT(setDisabled(bool)));
        QObject::connect(radioButton, SIGNAL(clicked(bool)), pushButton_2, SLOT(setDisabled(bool)));
        QObject::connect(radioButton, SIGNAL(clicked(bool)), pushButton, SLOT(setDisabled(bool)));
        QObject::connect(pushButton, SIGNAL(clicked()), label, SLOT(aumentaCoche()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), label, SLOT(aumentaMoto()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), label, SLOT(aumentaCamion()));
        QObject::connect(label, SIGNAL(addCoche(int)), lcdNumber, SLOT(display(int)));
        QObject::connect(label, SIGNAL(addMoto(int)), lcdNumber_2, SLOT(display(int)));
        QObject::connect(label, SIGNAL(addCamion(int)), lcdNumber_3, SLOT(display(int)));
        QObject::connect(label, SIGNAL(recaudacion(int)), lcdNumber_4, SLOT(display(int)));

        QMetaObject::connectSlotsByName(MyForm);
    } // setupUi

    void retranslateUi(QWidget *MyForm)
    {
        MyForm->setWindowTitle(QApplication::translate("MyForm", "Form", 0));
        label_2->setText(QApplication::translate("MyForm", "coches", 0));
        pushButton->setText(QApplication::translate("MyForm", "afegir", 0));
        label_4->setText(QApplication::translate("MyForm", "motos", 0));
        pushButton_2->setText(QApplication::translate("MyForm", "afegir", 0));
        label_3->setText(QApplication::translate("MyForm", "camions", 0));
        pushButton_3->setText(QApplication::translate("MyForm", "afegir", 0));
        label->setText(QString());
        radioButton_2->setText(QApplication::translate("MyForm", "Obrir", 0));
        radioButton->setText(QApplication::translate("MyForm", "&Tancar", 0));
        label_5->setText(QApplication::translate("MyForm", "Recaptaci\303\263", 0));
    } // retranslateUi

};

namespace Ui {
    class MyForm: public Ui_MyForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYFORM_H
