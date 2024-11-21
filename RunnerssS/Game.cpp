#include "Game.h"
#include "InputHandler.h" 
#include "Renderer.h"
#include "Plataforma.h"
#include "iostream"
#include <cmath>  // Para usar la función pow y sqrt
using namespace std;

Juego::Juego() :jugador{0.0f, 0.0f, 50.0f, 100.0f, 0.0f, 0.0f}, 
gravedad{-0.1f}
{
	// Crear algunas plataformas al inicio
	
    PlataformaHandler::agregarPlataforma(100.0f, -.0f, 600.0f, 500.0f,1.0f,1.0f,1.0f);
    
    
    
	// Alejandrooooo, te estoy dejando estoooo, es para colocar plataformas, lo malo es que solo deja colocar la base invisible, pero y disminuye el salto, pero no tiene color ni limite de repos, osea el  cuadrado no puede quedarse alli, arreglalo, y si puedes mandalo a un rositorio plisss te lo dejo encargado
}  

void Juego::iniciar() {
    Renderer::init(); // Inicializa OpenGL
}

void Juego::actualizar() {
   jugador.velocidadY += gravedad;  // Aplicar gravedad
    Plataforma plataformaColisionada;
    Choque choque_r;
    bool choco_int=false;
    Rectangulo Jugador_Rec;
    Jugador_Rec.x = jugador.x;
    Jugador_Rec.y = jugador.y;
    Jugador_Rec.ancho = jugador.ancho;
    Jugador_Rec.alto = jugador.alto;
    Jugador_Rec.vx = jugador.velocidadX;
    Jugador_Rec.vy = jugador.velocidadY;
    
    if (ManejadorEntrada::teclaIzquierda) {
        jugador.velocidadX = -0.50f;
    } else if (ManejadorEntrada::teclaDerecha) {
        jugador.velocidadX = 0.50f;
    } else {
        jugador.velocidadX = 0.0f;  // Detener movimiento horizontal
    }

  

 

    // Si el jugador está en una plataforma, ajusta su posición
   
    // Actualizar posición
    jugador.x += jugador.velocidadX;
    jugador.y += jugador.velocidadY;
  
    
    
	if (PlataformaHandler::chequearColisionJugadorConPlataforma(Jugador_Rec, plataformaColisionada,choque_r)) {
            // Manejo de colisión lateral
        /*if (Jugador_Rec.x < plataformaColisionada.x) { // Colisión con el lado izquierdo
            jugador.x = plataformaColisionada.x - plataformaColisionada.ancho / 2 - jugador.ancho / 2;
            jugador.velocidadX = 0.0f;
        } else if (Jugador_Rec.x > plataformaColisionada.x) { // Colisión con el lado derecho
            jugador.x = plataformaColisionada.x + plataformaColisionada.ancho / 2 + jugador.ancho / 2;
            jugador.velocidadX = 0.0f;
        }*/
        /*if (jugador.x < -1000 + jugador.ancho / 2) {
        jugador.x = -1000 + jugador.ancho / 2;
  		} else if (jugador.x > 1000 - jugador.ancho / 2) {
        jugador.x = 1000 - jugador.ancho / 2;
    	}*/
    	// [arriba, abajo, izquierda, derecha]
         if(jugador.x +jugador.ancho >= plataformaColisionada.x - plataformaColisionada.ancho/2 /*&& choque_r.derecha==false*/){
         	jugador.x = (plataformaColisionada.x-plataformaColisionada.ancho/2)-jugador.ancho;
		 }else if(jugador.x-jugador.ancho <= plataformaColisionada.x + plataformaColisionada.ancho/2 && choque_r.izquierda==false){
         	jugador.x = (plataformaColisionada.x+plataformaColisionada.ancho/2)+jugador.ancho;
         	
            cout<<"Choco a la derecha"<<endl;
		 }
		 
		 if (jugador.y > plataformaColisionada.y && choque_r.izquierda==false && choque_r.derecha==false) {
            // Jugador está encima de la plataforma
            cout<<"Choco con la plataforma por arriba"<<endl;
            choco_int=true;
            jugador.y = plataformaColisionada.y + plataformaColisionada.alto / 2 + jugador.alto / 2;
            jugador.velocidadY = 0.8f;  // Detener caída
        } else if (jugador.y < plataformaColisionada.y && choque_r.izquierda==false && choque_r.derecha==false) {
            // Jugador está debajo de la plataforma
            cout<<"choco abajo"<<endl;
            jugador.y = plataformaColisionada.y - plataformaColisionada.alto / 2 - jugador.alto / 2;
            jugador.velocidadY = 0.0f;  // Evitar que el jugador suba a través de la plataforma
        }
       
        
        
        
    }

// Saltar si se presiona la tecla espacio y el jugador está en el suelo o en una plataforma
    if (ManejadorEntrada::teclaEspacio ) {
       //jugador.y - jugador.alto / 2 >= (plataformaColisionada.y +20) +plataformaColisionada.alto / 2
	    if(choco_int==true){
	    	
		
			jugador.velocidadY = 15.0f;  // Impulso de salto
		}
		else{
			if((jugador.y <= -950 + jugador.alto / 2 ))
			{	
			
			jugador.velocidadY = 15.0f;  // Impulso de salto
			
			}
		}
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
    
    PlataformaHandler::renderizarPlataformas();
}
/*
void Juego::manejarEntrada(unsigned char tecla) {
    ManejadorEntrada::manejarEntradaJugador(tecla, jugador);
}*/
