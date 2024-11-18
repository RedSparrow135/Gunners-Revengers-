#include "InputHandler.h"

#include <GL/glut.h>


bool ManejadorEntrada::teclaIzquierda = false;
bool ManejadorEntrada::teclaDerecha = false;
bool ManejadorEntrada::teclaEspacio = false;

void ManejadorEntrada::manejarEntrada(unsigned char key, int x, int y) {
    switch (key) {
        case 'a': // Flecha izquierda (o 'a')
            teclaIzquierda = true;
            break;
        case 'd': // Flecha derecha (o 'd')
            teclaDerecha = true;
            break;
        case ' ': // Barra espaciadora para saltar
            teclaEspacio = true;
            break;
    }
}

void ManejadorEntrada::manejarLiberacion(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
            teclaIzquierda = false;
            break;
        case 'd':
            teclaDerecha = false;
            break;
        case ' ':
            teclaEspacio = false;
            break;
    }
}

