#define GLM_FORCE_RADIANS
#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <QKeyEvent>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "./Model/model.h"

class MyGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core 
{
  Q_OBJECT

  public:
    MyGLWidget (QWidget *parent=0);
    ~MyGLWidget ();

  protected:
    // initializeGL - Aqui incluim les inicialitzacions del contexte grafic.
    virtual void initializeGL ( );
    // paintGL - Mètode cridat cada cop que cal refrescar la finestra.
    // Tot el que es dibuixa es dibuixa aqui.
    virtual void paintGL ( );
    // resizeGL - És cridat quan canvia la mida del widget
    virtual void resizeGL (int width, int height);
    // keyPressEvent - Es cridat quan es prem una tecla
    virtual void keyPressEvent (QKeyEvent *event);
    
    virtual void mouseMoveEvent(QMouseEvent *e);

  private:
    void creaBuffers ();
    void carregaShaders ();
    void modelTransform ();
    void modelTransform2 ();
    void modelTransform3 ();
    void modelTransformSuelo ();
    void projectTransform ();
    void viewTransform ();
    void getMinBoxPatricio ();
    // attribute locations
    GLuint vertexLoc, colorLoc;
    // uniform locations
    GLuint transLoc;
    GLuint projLoc;
    GLuint viewLoc;
    //variable model
    Model m;//cargamos un solo modelo
    // VAO i VBO names
    //GLuint VAO_Casa;
    GLuint VAO_Patricio, VAO_Suelo;
    // Program
    QOpenGLShaderProgram *program;
    // Viewport
    GLint ample, alt;
    // Internal vars
    float scale;
    float anglegir = 0, anglegirTheta = 0.0, anglegirPsi = 0.0;
    glm::vec3 pos;
    glm::vec3 minPatricio;
    glm::vec3 maxPatricio;
    glm::vec3 centroPatricio;
    glm::vec3 centroBasePatricio;
    float x_anteriorMouse = 0.0, y_anteriorMouse = 0.0;
    /**
     * VARIABLES PARA LA CAMARA Y OBSERVADOR
     * */
    //CAJA minima contenedora de la escena
    glm::vec3 Pmin, Pmax, centro, VRP;
    
    //Datos relevantes esfera
    float radio, d;
    
    //Observador de la escena
    glm::vec3 OBS;
    
    float FOV, znear, zfar, ra;
};

