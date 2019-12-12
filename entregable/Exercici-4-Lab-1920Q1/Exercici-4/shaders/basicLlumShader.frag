#version 330 core

in vec3 vertexO;
in vec3 normalO;

in vec3 matambO;
in vec3 matdiffO;
in vec3 matspecO;
in float matshinO;

uniform vec3 posFocus;

// Valors per als components que necessitem dels focus de llum
vec3 llumAmbient = vec3(0.2, 0.2, 0.2);
vec3 colFocus = vec3(1,1,1);

out vec4 FragColor;

vec3 Lambert (vec3 NormSCO, vec3 L) 
{
    // S'assumeix que els vectors que es reben com a paràmetres estan normalitzats

    // Inicialitzem color a component ambient
    vec3 colRes = llumAmbient * matambO;

    // Afegim component difusa, si n'hi ha
    if (dot (L, NormSCO) > 0)
      colRes = colRes + colFocus * matdiffO * dot (L, NormSCO);
    return (colRes);
}

vec3 Phong (vec3 NormSCO, vec3 L, vec4 vertSCO) 
{
    // Els vectors estan normalitzats

    // Inicialitzem color a Lambert
    vec3 colRes = Lambert (NormSCO, L);

    // Calculem R i V
    if (dot(NormSCO,L) < 0)
      return colRes;  // no hi ha component especular

    vec3 R = reflect(-L, NormSCO); // equival a: normalize (2.0*dot(NormSCO,L)*NormSCO - L);
    vec3 V = normalize(-vertSCO.xyz);

    if ((dot(R, V) < 0) || (matshinO == 0))
      return colRes;  // no hi ha component especular
    
    // Afegim la component especular
    float shine = pow(max(0.0, dot(R, V)), matshinO);
    return (colRes + matspecO * colFocus * shine); 
}

void main()
{	
    //dirección de la luz
    vec3 L_sco = posFocus - vertexO.xyz;
        
    //normalizar vectores
    L_sco = normalize(L_sco);
    vec3 NormalMatrix_sco = normalize(normalO);
    
    vec3 fcolor = Phong(NormalMatrix_sco, L_sco, vec4(vertexO, 1.0));

    FragColor = vec4(fcolor,1);	
}
