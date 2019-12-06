#include <QLineEdit>

class MyLineEdit: public QLineEdit{
    Q_OBJECT
    public:
        MyLineEdit(QWidget *parent);
        QString letraIntroducida, password, asteriscos;
        int erroresPermitidos;
        
    public slots:
        void nuevaLetra(QString);

    signals:
        void enviarError(int);
        void enviarPalabra(QString);
};
