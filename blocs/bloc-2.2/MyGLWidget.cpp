#include "MyGLWidget.h"

#include <iostream>

MyGLWidget::MyGLWidget (QWidget* parent) : QOpenGLWidget(parent), program(NULL)
{
  setFocusPolicy(Qt::StrongFocus);  // per rebre events de teclat
  scale = 1.0f;
}

MyGLWidget::~MyGLWidget ()
{
  if (program != NULL)
    delete program;
}

void MyGLWidget::initializeGL ()
{
  // Cal inicialitzar l'ús de les funcions d'OpenGL
  initializeOpenGLFunctions();  
    /**
     * Cargamos el modelo
     * */
    //Model m;//cargamos un solo modelo
    m.load("../models/HomerProves.obj");
    
    /**
     * 
     * INITIALIZAR VARIABLES PARA EL OBSERVADOR Y CAMARA
     * */
    
        //float maxY = -1;
    //for(unsigned int i = 0; i < m.vertices().size(); i+=3) if(m.vertices()[i+1] > maxY) maxY = m.vertices()[i+1];
    
    Pmin = glm::vec3(-1,-1,-1);//minimo esquina del suelo, conocido
    Pmax = glm::vec3(1, 1,1);//maximo esquina del suelo, conocido, falta el alto del homer
    
    //Centro de la caja mínima contenedora de la escena, centro = VRP
    centro = (Pmin + Pmax) / glm::vec3(2.0,2.0,2.0);
    VRP = centro;
    //std::cout << "maxY: " << maxY << std::endl;
    
    //radio de la caja minima contenedora
    radio = glm::distance(Pmin, Pmax)/2.0;
    
    //distancia de pmin a pmax = 2R
    d = 2.0 * radio;
    
    
    //observador de la escena, VRP+d(0,0,1)
    OBS = glm::vec3(0,0,d);
    
    FOV = 2 * asin(radio / d);
    
    znear = d-radio;
    zfar = d+radio;
    /**
     * FIN INICIALIZAR VARIABLES PARA EL OBSERVADOR Y CAMARA
    */
    
    glEnable(GL_DEPTH_TEST);
    /** 
     * Fin carga del modelo
     * */
  glClearColor(0.5, 0.7, 1.0, 1.0); // defineix color de fons (d'esborrat)
  carregaShaders();
  creaBuffers();
}

void MyGLWidget::paintGL () 
{
// Aquest codi és necessari únicament per a MACs amb pantalla retina.
#ifdef __APPLE__
  GLint vp[4];
  glGetIntegerv (GL_VIEWPORT, vp);
  ample = vp[2];
  alt = vp[3];
#endif

// En cas de voler canviar els paràmetres del viewport, descomenteu la crida següent i
// useu els paràmetres que considereu (els que hi ha són els de per defecte)
//  glViewport (0, 0, ample, alt);
  
  // Esborrem el frame-buffer
  glClear (GL_COLOR_BUFFER_BIT);

  // Carreguem la transformació de model
  modelTransform ();
  //carreguem la projecció del model
  projectTransform();
  //carreguem el view del model
  viewTransform();
  // Activem el VAO per a pintar la caseta 
  glBindVertexArray (VAO_Homer);

  // pintem
  glDrawArrays(GL_TRIANGLES, 0, m.faces().size() * 3);

  
  
    modelTransformSuelo();
  // Activem el VAO per a pintar la caseta 
  glBindVertexArray (VAO_Suelo);

  // pintem
  glDrawArrays(GL_TRIANGLES, 0, 6);
  
  
  glBindVertexArray (0);
}

void MyGLWidget::modelTransform () 
{
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  transform = glm::scale(transform, glm::vec3(scale));
  transform = glm::rotate (transform, anglegir,glm::vec3(0.0, 1.0, 0.0));
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::modelTransformSuelo () 
{
  // Matriu de transformació de model
  glm::mat4 transform (1.0f);
  glUniformMatrix4fv(transLoc, 1, GL_FALSE, &transform[0][0]);
}

void MyGLWidget::resizeGL (int w, int h) 
{
  ample = w;
  alt = h;
  ra = float(ample)/float(alt);
  
  if(ra < 1){
      FOV = 2* atan(tan(asin(radio / d))/ra);
    }
    projectTransform();
}
/*
void MyGLWidget::keyPressEvent(QKeyEvent* event) 
{
  makeCurrent();
  switch (event->key()) {
    case Qt::Key_S: { // escalar a més gran
      scale += 0.05;
      break;
    }
    case Qt::Key_D: { // escalar a més petit
      scale -= 0.05;
      break;
    }
    case Qt::Key_R: {
        anglegir += M_PI/4;
        break;
    }
    default: event->ignore(); break;
  }
  
  update();
}*/

void MyGLWidget::creaBuffers () 
{
  // Dades de la caseta
  // Dos VBOs, un amb posició i l'altre amb color
  // Creació del Vertex Array Object per pintar
  glGenVertexArrays(1, &VAO_Homer);
  glBindVertexArray(VAO_Homer);

  GLuint VBO_Homer[2];
  glGenBuffers(2, VBO_Homer);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_Homer[0]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * m.faces().size() * 3 * 3, m.VBO_vertices(), GL_STATIC_DRAW);

  // Activem l'atribut vertexLoc
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);

  glBindBuffer(GL_ARRAY_BUFFER, VBO_Homer[1]);
  glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * m.faces().size() * 3 * 3, m.VBO_matdiff(), GL_STATIC_DRAW);

  // Activem l'atribut colorLoc
  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);

  
  
  glm::vec3 Vertices[6];  // Tres vèrtexs amb X, Y i Z
  Vertices[0] = glm::vec3(1.0, -1.0, 1.0);
  Vertices[1] = glm::vec3(1.0, -1.0, -1.0);
  Vertices[2] = glm::vec3(-1.0, -1.0, -1.0);
  Vertices[3] = glm::vec3(1.0, -1.0, 1.0);
  Vertices[4] = glm::vec3(-1.0, -1.0, -1.0);
  Vertices[5] = glm::vec3(-1.0, -1.0, 1.0);
  
  glm::vec3 colores[6];
  colores[0] = glm::vec3(1, 0, 0);
    colores[1] = glm::vec3(0, 0, 1);
    colores[2] = glm::vec3(0, 1, 0);
  colores[3] = glm::vec3(1, 0, 0);
    colores[4] = glm::vec3(0, 1, 0);
    colores[5] = glm::vec3(0, 0, 1);
  
    glGenVertexArrays(1, &VAO_Suelo);
  glBindVertexArray(VAO_Suelo);
  
  GLuint VBO_Suelo;
  glGenBuffers(1, &VBO_Suelo);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_Suelo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
  // Activem l'atribut que farem servir per vèrtex (només el 0 en aquest cas)	
  glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(vertexLoc);
  
  
    GLuint VBO_SueloColor;
  glGenBuffers(1, &VBO_SueloColor);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_SueloColor);
  glBufferData(GL_ARRAY_BUFFER, sizeof(colores), colores, GL_STATIC_DRAW);
  // Activem l'atribut que farem servir per vèrtex (només el 0 en aquest cas)	
  glVertexAttribPointer(colorLoc, 3, GL_FLOAT, GL_FALSE, 0, 0);
  glEnableVertexAttribArray(colorLoc);
  
  glBindVertexArray (0);
}

void MyGLWidget::viewTransform(){
    //lookAt(OBS,VRP, up)
    glm::mat4 View = glm::lookAt(OBS, VRP, glm::vec3(0,1,0));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &View[0][0]);
}

void MyGLWidget::projectTransform(){
    
    //FOV = 2*asin(radio/d);
    
    //perspective(FOV, ra, znear, zfar);
    glm::mat4 Proj = glm::perspective(FOV, ra, znear, zfar);
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, &Proj[0][0]);
}

void MyGLWidget::carregaShaders()
{
  // Creem els shaders per al fragment shader i el vertex shader
  QOpenGLShader fs (QOpenGLShader::Fragment, this);
  QOpenGLShader vs (QOpenGLShader::Vertex, this);
  // Carreguem el codi dels fitxers i els compilem
  fs.compileSourceFile("shaders/basicShader.frag");
  vs.compileSourceFile("shaders/basicShader.vert");
  // Creem el program
  program = new QOpenGLShaderProgram(this);
  // Li afegim els shaders corresponents
  program->addShader(&fs);
  program->addShader(&vs);
  // Linkem el program
  program->link();
  // Indiquem que aquest és el program que volem usar
  program->bind();

  // Obtenim identificador per a l'atribut “vertex” del vertex shader
  vertexLoc = glGetAttribLocation (program->programId(), "vertex");
  // Obtenim identificador per a l'atribut “color” del vertex shader
  colorLoc = glGetAttribLocation (program->programId(), "color");
  // Uniform locations
  transLoc = glGetUniformLocation(program->programId(), "TG");
  projLoc = glGetUniformLocation(program->programId(), "proj");
  viewLoc = glGetUniformLocation(program->programId(), "view");
}
