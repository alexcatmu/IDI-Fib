#include <QLabel>

class MyLabel: public QLabel{
    Q_OBJECT
    public:
        MyLabel(QWidget *parent);
        QString repe, intro;
        
    public slots:
        void passwordIntrodueix(QString);
        void passwordRepeteix(QString);
};
