#ifndef RENDERER_H
#define RENDERER_H
#include "Renderer.h"
#include <GL/glut.h>

// Estructura para representar un rectángulo
struct Rectangulo {
    float x, y;         // Posición
    float ancho, alto;  // Dimensiones
    float vx, vy;       // Velocidad en x y en y
};
struct Plataforma_r{
	float x, y;         // Posición
    float ancho, alto;  // Dimensiones
    float r,g,b;
};

// Clase encargada de la renderización
class Renderer {
public:
    static void init();  // Inicializa la configuración de OpenGL
    static void dibujarRectangulo(const Rectangulo& rect); // Dibuja un rectángulo
       // Nueva función para dibujar una plataforma con color
    static void dibujarPlataforma(const Plataforma_r& rect);
    
};

#endif

