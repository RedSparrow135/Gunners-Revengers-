#include "Renderer.h"
#include "Plataforma.h" 
void Renderer::init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1000, 1000, -1000, 1000); // Sistema de coordenadas ortográficas
    glMatrixMode(GL_MODELVIEW);
}

void Renderer::dibujarRectangulo(const Rectangulo& rect) {
    glLoadIdentity();
    glColor3f(0.0f, 1.0f, 0.0f); // Color verde para diferenciar
    glBegin(GL_QUADS);
        glVertex2f(rect.x - rect.ancho / 2, rect.y - rect.alto / 2);
        glVertex2f(rect.x + rect.ancho / 2, rect.y - rect.alto / 2);
        glVertex2f(rect.x + rect.ancho / 2, rect.y + rect.alto / 2);
        glVertex2f(rect.x - rect.ancho / 2, rect.y + rect.alto / 2);
    glEnd();
}
void Renderer::dibujarPlataforma(const Plataforma_r& rect) {
    glLoadIdentity();
    glColor3f(rect.r, rect.g, rect.b);  // Usamos los colores de la plataforma
    glBegin(GL_QUADS);
        glVertex2f(rect.x - rect.ancho / 2, rect.y - rect.alto / 2);
        glVertex2f(rect.x + rect.ancho / 2, rect.y - rect.alto / 2);
        glVertex2f(rect.x + rect.ancho / 2, rect.y + rect.alto / 2);
        glVertex2f(rect.x - rect.ancho / 2, rect.y + rect.alto / 2);
    glEnd();
}
