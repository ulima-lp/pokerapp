#pragma once

#include <cstdlib>
#include <iostream>

enum Simbolo {Diamante, Espada, Corazon, Trebol};

class Carta
{
    public:
    int numero;
    Simbolo simbolo;
    Carta* siguienteCarta;
    Carta(int, Simbolo);
    void imprimir();
    
};

class Deck
{
    public:
    int numCartas;
    Carta* primeraCarta;

    Deck();
    void generar();
    void generarAleatorio(Deck*);
    void agregar(Carta*);
    Carta* remove(int pos);
    void imprimir();
};