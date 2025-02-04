#version 330 core

in vec3 vertex;
in vec3 normal;

in vec3 matamb;
in vec3 matdiff;
in vec3 matspec;
in float matshin;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 TG;

// Valors per als components que necessitem dels focus de llum
vec3 colFocus = vec3(0.8, 0.8, 0.8); //color del foco
vec3 llumAmbient = vec3(0.2, 0.2, 0.2); //luz de ambiente
vec3 posFocus = vec3(1, 0, 1);  // en SCA posicion del foco

out vec3 fcolor;

vec3 Lambert (vec3 NormSCO, vec3 L) 
{
    // S'assumeix que els vectors que es reben com a paràmetres estan normalitzats

    // Inicialitzem color a component ambient
    vec3 colRes = llumAmbient * matamb;

    // Afegim component difusa, si n'hi ha
    if (dot (L, NormSCO) > 0)
      colRes = colRes + colFocus * matdiff * dot (L, NormSCO);
    return (colRes);
}

vec3 Phong (vec3 NormSCO, vec3 L, vec4 vertSCO) 
{
    // Els vectors estan normalitzats

    // Inicialitzem color a Lambert
    vec3 colRes = Lambert (NormSCO, L);

    // Calculem R i V
    if ((dot(NormSCO,L) < 0) || (matshin == 0))
      return colRes;  // no hi ha component especular

    vec3 R = reflect(-L, NormSCO); // equival a: 2.0*dot(NormSCO,L)*NormSCO - L;
    vec3 V = normalize(-vertSCO.xyz); // perquè la càmera està a (0,0,0) en SCO

    if (dot(R, V) < 0)
      return colRes;  // no hi ha component especular
    
    float shine = pow(max(0.0, dot(R, V)), matshin);
    return (colRes + matspec * colFocus * shine); 
}

void main()
{
    vec3 vertSCO = (view * TG * vec4(vertex, 1.0)).xyz;//SCO = sistema de coordenadas del observador
    
    //sca to sco::::
    //sca = Sistema de Coordenadas de la Aplicacion
    //SCO = sistema de coordenadas del observador
    vec3 NormalMatrix_sco = (inverse(transpose(mat3(view * TG)))) * normal;
    
    //posfocus de SCA a SCO
    vec3 posFocusSco = (view * vec4(posFocus, 1.0)).xyz;
    
    //direccion de la luz
    vec3 L_sco = posFocusSco - vertSCO;
    

    //normalizar vectores
    L_sco = normalize(L_sco);
    NormalMatrix_sco = normalize(NormalMatrix_sco);
    
    //fcolor = matdiff;
    //fcolor = Lambert(NormalMatrix_sco, L_sco);
    fcolor = Phong(NormalMatrix_sco, L_sco, vec4(vertSCO, 1.0));
    gl_Position = proj * view * TG * vec4 (vertex, 1.0);
}






