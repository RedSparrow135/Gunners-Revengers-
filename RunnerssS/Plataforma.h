#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include "Renderer.h"
#include <vector>



// Estructura para representar una plataforma
struct Plataforma {
    float x, y;         // Posición de la plataforma
    float ancho, alto;  // Dimensiones de la plataforma
    float r, g, b;      // Color de la plataforma
};
struct Choque{
	bool arriba;
    bool abajo;
    bool izquierda;
    bool derecha;
};

// Clase para manejar las plataformas
class PlataformaHandler {
public:
    static void agregarPlataforma(float x, float y, float ancho, float alto, float r, float g, float b);
    static void renderizarPlataformas();
    static bool chequearColisionJugadorConPlataforma(const Rectangulo& jugador,Plataforma& plataformaColisionada,Choque& choque );

private:
    static std::vector<Plataforma> plataformas;  // Lista de plataformas
};

#endif

