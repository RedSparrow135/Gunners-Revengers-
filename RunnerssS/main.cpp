#include <GL/glut.h>
#include "Game.h"
#include "InputHandler.h"

Juego juego;

void mostrar() {
    glClear(GL_COLOR_BUFFER_BIT);
    juego.actualizar();
    juego.renderizar();
    glutSwapBuffers();
}
/*
void actualizar(int valor) {
    juego.actualizar();
    glutPostRedisplay();
    glutTimerFunc(16, actualizar, 0); // Aproximadamente 60 FPS
}*/

void tecladoPresionado(unsigned char key, int x, int y) {
    ManejadorEntrada::manejarEntrada(key, x, y);
}

void tecladoLiberado(unsigned char key, int x, int y) {
    ManejadorEntrada::manejarLiberacion(key, x, y);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Rectángulo Centrado");

    // Pantalla completa
    glutFullScreen();

    juego.iniciar();

    glutDisplayFunc(mostrar);
    
    glutIdleFunc(mostrar);  // Llama constantemente a la función de renderizado

    glutKeyboardFunc(tecladoPresionado);
    glutKeyboardUpFunc(tecladoLiberado);

    glutMainLoop();
    return 0;
}
