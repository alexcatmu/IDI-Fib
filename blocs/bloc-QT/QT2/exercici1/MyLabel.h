#include <QLabel>

class MyLabel: public QLabel{
    Q_OBJECT
    public:
        MyLabel(QWidget *parent);
        int recaptacio, camiones, coches, motos;
        
    public slots:
        void clickOpen();
        void clickClose();
        void aumentaMoto();
        void aumentaCoche();
        void aumentaCamion();
    signals:
        void addMoto(int);
        void addCoche(int);
        void addCamion(int);
        void recaudacion(int);
};
