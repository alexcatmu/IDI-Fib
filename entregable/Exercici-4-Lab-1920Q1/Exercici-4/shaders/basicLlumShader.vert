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
uniform vec3 posFocus;

// Valors per als components que necessitem dels focus de llum

out vec3 vertexO;
out vec3 normalO;

out vec3 matambO;
out vec3 matdiffO;
out vec3 matspecO;
out float matshinO;

void main()
{	
    vertexO = (view * TG * vec4(vertex, 1.0)).xyz;//SCO = Sistema de Coordenadas del Observador
    
    //de SCA a SCO
    vec3 NormalMatrix_sco = (inverse(transpose(mat3(view * TG)))) * normal;
    normalO = NormalMatrix_sco;
    
    matambO = matamb;
    matdiffO = matdiff;
    matspecO = matspec;
    matshinO = matshin;

    
    gl_Position = proj * view * TG * vec4 (vertex, 1.0);
}
