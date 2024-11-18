#ifndef GAME_H
#define GAME_H

#include "Renderer.h"
#include "Plataforma.h" 
class Juego {
public:
	struct Jugador {
        float x, y;  // Posici�n del jugador
        float ancho, alto;  // Dimensiones del jugador (rect�ngulo)
        float velocidadX, velocidadY;  // Velocidad en cada direcci�n
    };
    Juego();
    void iniciar();
    void actualizar();
    void renderizar();

private:
    Jugador jugador; // El rect�ngulo que representa al jugador
    float gravedad;  // Fuerza de la gravedad
};

#endif

