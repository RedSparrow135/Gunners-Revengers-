#include "Plataforma.h"
#include "Renderer.h"  // Para usar la funcion de renderizado
#include <vector>  // Para usar std::vector

#include "Game.h" 
std::vector<Plataforma> PlataformaHandler::plataformas;  // Inicializamos el vector de plataformas

void PlataformaHandler::agregarPlataforma(float x, float y, float ancho, float alto, float r, float g, float b) {
    Plataforma nuevaPlataforma = {x, y, ancho, alto};
    plataformas.push_back(nuevaPlataforma);  // Agregamos la nueva plataforma al vector
    renderizarPlataformas();
}

void PlataformaHandler::renderizarPlataformas() {
    for (const Plataforma& p : plataformas) {
        // Usamos la funciÃ³n de renderizado para dibujar la plataforma
        Renderer::dibujarPlataforma({p.x, p.y, p.ancho, p.alto,p.r,p.g,p.b});
    }
}

// FunciÃ³n para chequear si el jugador estÃ¡ sobre una plataforma
bool PlataformaHandler::chequearColisionJugadorConPlataforma(const Jugador_Ref& jugador) {
    for (const Plataforma& p : plataformas) {
        // Verifica si el jugador está dentro de los límites horizontales de la plataforma
        if (jugador.x + jugador.ancho / 2 > p.x - p.ancho / 2 &&
            jugador.x - jugador.ancho / 2 < p.x + p.ancho / 2 &&
            // Verifica si el jugador está justo encima de la plataforma (colisión vertical)
            jugador.y - jugador.alto / 2 <= p.y + p.alto / 2 &&
            jugador.y - jugador.alto / 2 > p.y) {
            return true;  // Si el jugador está sobre la plataforma, devuelve true
        }
    }
    return false;  // Si no hay colisión, devuelve false
}
