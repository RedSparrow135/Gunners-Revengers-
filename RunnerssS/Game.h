#ifndef GAME_H
#define GAME_H

#include "Renderer.h"
#include "Plataforma.h" 
class Juego {
public:
	struct Jugador {
        float x, y;  // Posición del jugador
        float ancho, alto;  // Dimensiones del jugador (rectángulo)
        float velocidadX, velocidadY;  // Velocidad en cada dirección
    };
    Juego();
    void iniciar();
    void actualizar();
    void renderizar();

private:
    Jugador jugador; // El rectángulo que representa al jugador
    float gravedad;  // Fuerza de la gravedad
};

#endif

