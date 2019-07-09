#pragma once

#include <iostream>
#include "poker.hpp"

class Jugador
{
    public:
    Jugador* siguienteJugador;
    std::string nombre;
    int cantPartidasGanadas;
    int sumaCartas;
};

class Crupier
{
    public:
    int cantPartidasGanadas;
    int sumaCartas;
};

class Mesa
{
    public:
    int numJugadores;
    Jugador* primerJugador;
    Jugador* ultimoJugador;
    
    Mesa();
    void agregarJugador(Jugador*);
    bool eliminarJugador(std::string nombre);
    Jugador* obtener(int pos);
};

class Juego
{
    public:
    Mesa* mesa;
    Crupier* crupier;
    Deck* deck;

    void agregarJugador();
    void mostrarJugadorMayor();
    void eliminarJugador();
    void mostrarMenu();
    void jugar();
};