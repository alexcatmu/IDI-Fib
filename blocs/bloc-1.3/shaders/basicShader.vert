#version 330 core

in vec3 vertex;
uniform float val;
uniform mat4 TG;
in vec3 colores;
out vec4 fcolor;

void main()  {
    gl_Position = TG * vec4 (vertex * val, 1.0);
    fcolor = vec4(colores, 1.0);
}
