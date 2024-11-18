#ifndef RENDERER_H
#define RENDERER_H
#include "Renderer.h"
#include <GL/glut.h>

// Estructura para representar un rect�ngulo
struct Rectangulo {
    float x, y;         // Posici�n
    float ancho, alto;  // Dimensiones
    float vx, vy;       // Velocidad en x y en y
};
struct Plataforma_r{
	float x, y;         // Posici�n
    float ancho, alto;  // Dimensiones
    float r,g,b;
};

// Clase encargada de la renderizaci�n
class Renderer {
public:
    static void init();  // Inicializa la configuraci�n de OpenGL
    static void dibujarRectangulo(const Rectangulo& rect); // Dibuja un rect�ngulo
       // Nueva funci�n para dibujar una plataforma con color
    static void dibujarPlataforma(const Plataforma_r& rect);
    
};

#endif

