#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include "Renderer.h"  // Para usar la funcion de renderizado
#include <vector>  // Para usar std::vector
// Estructura para representar una plataforma



struct Plataforma {
    float x, y;         // Posicion de la plataforma
    float ancho, alto;  // Dimensiones de la plataforma
    float r,g,b;
};
struct Jugador_Ref{
	float x, y;         // Posicion de la plataforma
    float ancho, alto; 
};

// Clase encargada de manejar plataformas
class PlataformaHandler {
public:
    // Lista de plataformas
    static std::vector<Plataforma> plataformas;

    // Función para agregar una plataforma
    static void agregarPlataforma(float x, float y, float ancho, float alto, float r, float g, float b);

    // Función para renderizar todas las plataformas
    static void renderizarPlataformas();

    // Función para manejar la colisión del jugador con las plataformas
    static bool chequearColisionJugadorConPlataforma(const Jugador_Ref& jugador);
};

#endif	
