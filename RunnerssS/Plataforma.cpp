#include "Plataforma.h"
#include "Renderer.h"
#include "iostream"
using namespace std;
std::vector<Plataforma> PlataformaHandler::plataformas;

void PlataformaHandler::agregarPlataforma(float x, float y, float ancho, float alto, float r, float g, float b) {
    plataformas.push_back({x, y, ancho, alto, r, g, b});
}

void PlataformaHandler::renderizarPlataformas() {
    for (const Plataforma& p : plataformas) {
        Renderer::dibujarPlataforma({p.x, p.y, p.ancho, p.alto, p.r, p.g, p.b});
    }
}

bool PlataformaHandler::chequearColisionJugadorConPlataforma( const Rectangulo& jugador,Plataforma& plataformaColisionada,Choque& choque) {
  Rectangulo jugadorModificado = jugador;
   choque.abajo = false; // arriba	
    choque.abajo = false; // abajo
    choque.izquierda = false; // izquierda
    choque.derecha= false; // derecha
    for (auto& plataforma : plataformas) {
        // Verificar si el jugador está colisionando con la plataforma
        if (jugador.x + jugador.ancho / 2 > plataforma.x - plataforma.ancho / 2 &&
            jugador.x - jugador.ancho / 2 < plataforma.x + plataforma.ancho / 2 &&
            jugador.y + jugador.alto / 2 > plataforma.y - plataforma.alto / 2 &&
            jugador.y - jugador.alto / 2 < plataforma.y + plataforma.alto / 2) {

            // Detectar colisión lateral izquierda
            if (jugador.x < plataforma.x && (jugador.x - jugador.ancho / 2 <  plataforma.x - plataforma.ancho / 2)&& jugador.y<plataforma.y) {
                plataformaColisionada = plataforma;
                cout<<"borde izquierdo"<<plataforma.x-plataforma.ancho/2<<"  y el jugador ="<<jugador.x - jugador.ancho/2<<" y plataforma x "<<plataforma.x<<endl;
                choque.izquierda = true; // izquierda
            }

            // Detectar colisión lateral derecha
            if (jugador.x > plataforma.x && jugador.x + jugador.ancho / 2 > plataforma.x + plataforma.ancho / 2) {
                plataformaColisionada = plataforma;
                cout<<"borde derecho"<<plataforma.x+plataforma.ancho/2<<"  y el jugador x="<< jugador.x-jugador.ancho<<" y plataforma x "<<plataforma.x<<endl;
                choque.derecha = true; // derecha
            }

            // Detectar colisión por la parte inferior
            if (jugador.y < plataforma.y && jugador.y + jugador.alto / 2 > plataforma.y - plataforma.alto / 2) {
                plataformaColisionada = plataforma;
                
                choque.abajo = true; // abajo
            }

            // Detectar colisión por la parte superior
            if (jugador.y > plataforma.y && jugador.y - jugador.alto / 2 < plataforma.y + plataforma.alto / 2) {
                plataformaColisionada = plataforma;
                 choque.arriba = true; // arriba
            }
            return true;
        }
    }

    return false;  // No hubo colisión

}

