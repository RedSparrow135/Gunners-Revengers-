#include "Game.h"
#include "InputHandler.h" 
#include "Renderer.h"

#include "Plataforma.h"
#include <cmath>  // Para usar la función pow y sqrt


Juego::Juego() :jugador{0.0f, 0.0f, 100.0f, 100.0f, 0.0f, 0.0f}, 
gravedad{-0.1f}
{
	// Crear algunas plataformas al inicio
    //PlataformaHandler::agregarPlataforma(0.0f, -700.0f, 500.0f, 300.0f,1.0f,1.0f,1.0f);
	// Alejandrooooo, te estoy dejando estoooo, es para colocar plataformas, lo malo es que solo deja colocar la base invisible, pero y disminuye el salto, pero no tiene color ni limite de repos, osea el  cuadrado no puede quedarse alli, arreglalo, y si puedes mandalo a un rositorio plisss te lo dejo encargado
}  

void Juego::iniciar() {
    Renderer::init(); // Inicializa OpenGL
}

void Juego::actualizar() {
   jugador.velocidadY += gravedad;  // Aplicar gravedad
    
    if (ManejadorEntrada::teclaIzquierda) {
        jugador.velocidadX = -5.0f;
    } else if (ManejadorEntrada::teclaDerecha) {
        jugador.velocidadX = 5.0f;
    } else {
        jugador.velocidadX = 0.0f;  // Detener movimiento horizontal
    }

    if (ManejadorEntrada::teclaEspacio && jugador.y <= -950 + jugador.alto / 2) { 
        jugador.velocidadY = 15.0f;  // Salto
    }

    // Actualizar posición
    jugador.x += jugador.velocidadX;
    jugador.y += jugador.velocidadY;
    
	Jugador_Ref RectPlataform;
	RectPlataform.x = jugador.x;
	RectPlataform.y = jugador.y;
	RectPlataform.alto = jugador.alto;
	RectPlataform.ancho =jugador.ancho;
	
	// Chequear colisión con plataformas
    if (PlataformaHandler::chequearColisionJugadorConPlataforma(RectPlataform)) {
        jugador.velocidadY = 0.0f;  // Detener caída cuando el jugador toca la plataforma
        jugador.y = -950 + jugador.alto / 2;  // Asegurarse de que el jugador quede en la plataforma
    }


    // Limitar al suelo y borde
    if (jugador.y <= -1000 + jugador.alto / 2) {
        jugador.y = -1000 + jugador.alto / 2;
        jugador.velocidadY *= -0.8f;  // Rebote
    }

    if (jugador.x < -1000 + jugador.ancho / 2) {
        jugador.x = -1000 + jugador.ancho / 2;
    } else if (jugador.x > 1000 - jugador.ancho / 2) {
        jugador.x = 1000 - jugador.ancho / 2;
    }
}

void Juego::renderizar() {
	 // Creamos un Rectangulo temporal con los valores del Jugador
    Rectangulo rectJugador;
    rectJugador.x = jugador.x;
    rectJugador.y = jugador.y;
    rectJugador.ancho = jugador.ancho;
    rectJugador.alto = jugador.alto;
    
    // Dibuja el jugador como un rectángulo
    Renderer::dibujarRectangulo(rectJugador);
}
/*
void Juego::manejarEntrada(unsigned char tecla) {
    ManejadorEntrada::manejarEntradaJugador(tecla, jugador);
}*/
