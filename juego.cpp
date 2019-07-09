#include "juego.hpp"

Mesa::Mesa()
{
    this->numJugadores = 0;
    this->primerJugador = NULL;
    this->ultimoJugador = NULL;
}

void Mesa::agregarJugador(Jugador* jugador)
{
    this->ultimoJugador = jugador;
    if (this->primerJugador == NULL){
        this->primerJugador = jugador;
    }else{
        Jugador* jugTemp = this->primerJugador;
        while(jugTemp->siguienteJugador != NULL)
        {
            jugTemp = jugTemp->siguienteJugador;   
        }
        jugTemp->siguienteJugador = jugador;   
    }
    this->numJugadores++;
}

bool Mesa::eliminarJugador(std::string nombre)
{

    Jugador* jugTemp = this->primerJugador;
    Jugador* jugAnterior = NULL;

    while(jugTemp != NULL)
    {
        if (jugTemp->nombre == nombre)
        {
            if (jugAnterior == NULL)
            {
                // Significa que estamos en el primer jugador
                this->primerJugador = jugTemp->siguienteJugador;
            }else
            {
                jugAnterior->siguienteJugador = jugTemp->siguienteJugador;
                if (jugTemp->siguienteJugador == NULL)
                {
                    // Nos encontramos en el ultimo
                    this->ultimoJugador = jugTemp;
                }
            }
            delete jugTemp;
            this->numJugadores--;
            return true;
        }else
        {
            jugAnterior = jugTemp;
            jugTemp = jugTemp->siguienteJugador;
        }
    }
    return false;
}

Jugador* Mesa::obtener(int pos)
{
    Jugador* jug = this->primerJugador;
    int cont=0;
    while(jug != NULL)
    {
        if (cont == pos)
        {
            return jug;
        }
        jug = jug->siguienteJugador;
        cont++;
    }
    return NULL;
}


void Juego::jugar()
{
    while(true)
    {
        // Loop general
        if (this->deck->numCartas <= 20)
        {
            break;
        }
        // Loop por ronda

        Jugador* jugador = NULL;
        for (int i=0; i < this->mesa->numJugadores; i++)
        {
            Jugador* jug = this->mesa->obtener(i);
            jug->sumaCartas = 0;
    
            // Loop por jugador
            while(jug->sumaCartas < 17)
            {
                Carta* carta = this->deck->remove(this->deck->numCartas-1);
                jug->sumaCartas += carta->numero;
            }
            
        }

        // Loop del Crupier (se entrega sus carta)
        this->crupier->sumaCartas = 0;
        while(this->crupier->sumaCartas < 17)
        {
            Carta* carta = this->deck->remove(this->deck->numCartas-1);
            this->crupier->sumaCartas += carta->numero;
        }

        //Verificaciones

        // Caso Crupier pierde con todos
        if (this->crupier->sumaCartas > 21)
        {
            for (int i=0; i < this->mesa->numJugadores; i++)
            {
                Jugador* jug = this->mesa->obtener(i);
                jug->cantPartidasGanadas++;
            }
        }

        // Verificacione uno x uno
        for (int i=0; i < this->mesa->numJugadores; i++)
        {
            Jugador *jug = this->mesa->obtener(i);
            if (jug->sumaCartas <= 21)
            {
                if (this->crupier->sumaCartas > 17 
                    && this->crupier->sumaCartas <=21
                    && this->crupier->sumaCartas < jug->sumaCartas )
                {
                    jug->cantPartidasGanadas++;
                }
            }
        }
    }
}