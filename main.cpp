#include "poker.hpp"

int main()
{
    Deck* deckOrdenado = new Deck();
    deckOrdenado->generar();
    Deck* deckDesordenado = new Deck();
    
    deckDesordenado->generarAleatorio(deckOrdenado);
    deckDesordenado->imprimir();
    return 0;
}