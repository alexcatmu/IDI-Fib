#include <QLabel>

class MyLabel: public QLabel{
    Q_OBJECT
    public:
        MyLabel(QWidget *parent);
        QString repe, intro;
        
    public slots:
        void passwordIntrodueix(QString);
        void passwordRepeteix(QString);
        void activaTexto();

    signals:
        void setEstado(const QString &);
};
