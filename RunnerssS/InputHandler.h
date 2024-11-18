#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

// Clase que maneja las entradas del teclado
class ManejadorEntrada {
public:
    static bool teclaIzquierda;
    static bool teclaDerecha;
    static bool teclaEspacio;

    static void manejarEntrada(unsigned char key, int x, int y);
    static void manejarLiberacion(unsigned char key, int x, int y);
};

#endif

