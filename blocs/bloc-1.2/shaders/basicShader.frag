#version 330 core

out vec4 FragColor;

void main() {
    FragColor = vec4(0, 0, 0, 1);
    if(gl_FragCoord.x < 354.) {//izquierda
        if(gl_FragCoord.y < 354.) FragColor = vec4(255, 255, 0, 1); //AMARILLO INFERIOR IZQUIERDA
        else FragColor = vec4(255, 0, 0, 1); //ROJO SUPERIOR IZQUIERDA
    } else {//derecha
        if(gl_FragCoord.y < 354.) FragColor = vec4(0, 255, 0, 1); //VERDE INFERIOR DERECHA
        else {
        FragColor = vec4(0, 0, 255, 1); //AZUL SUPERIOR DERECHA
        }
    }
    if(int(gl_FragCoord.y / 10) % 2 != 0) discard;
}

