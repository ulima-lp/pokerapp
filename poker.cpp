#include "poker.hpp"

Carta::Carta(int numero, Simbolo simbolo)
{
    this->numero = numero;
    this->simbolo = simbolo;
    this->siguienteCarta = NULL;
}

void Carta::imprimir()
{
    std::cout << "Carta{" << "numero:" << this->numero 
                << ",simbolo:" <<  this->simbolo << "}" << std::endl;
}

Deck::Deck()
{
    this->numCartas = 0;
    this->primeraCarta = NULL;
}

void Deck::generar()
{
    Carta* cartaTemp = NULL;
    for (int j=0; j < 4; j++)
    {
        for (int i=1; i<14; i++)
        {
            Carta* carta = new Carta(i, (Simbolo) j);

            if (cartaTemp == NULL)
            {
                this->primeraCarta = carta;
            }else
            {
                cartaTemp->siguienteCarta = carta;
            }
            this->numCartas++;
            cartaTemp = carta;
        }
    }
}
void Deck::generarAleatorio(Deck* deck)
{

    int tam = 13 * 4;
    for (int i=0; i< tam; i++)
    {
        int posAleatoria = rand() % (tam - i);
        Carta* carta = deck->remove(posAleatoria);
        //carta->imprimir();
        this->agregar(carta);
    }
}

void Deck::agregar(Carta* carta)
{
    carta->siguienteCarta = NULL;
    if (this->primeraCarta == NULL)
    {
        // Caso no hay cartas aun en deck
        this->primeraCarta = carta;
        this->numCartas++;
    }else
    {
        Carta* cartaTemp = this->primeraCarta;
        while(true)
        {
            if (cartaTemp->siguienteCarta == NULL)
            {
                // Ultima carta
                cartaTemp->siguienteCarta = carta;
                this->numCartas++;
                break;
            }else
            {
                cartaTemp = cartaTemp->siguienteCarta;
            }
            
        }
    }
}

Carta* Deck::remove(int pos)
{
    Carta* cartaTemp = this->primeraCarta;
    Carta* cartaAnteriorTemp = NULL;
    int cont = 0;
    while(cartaTemp != NULL)
    {
        if (cont == pos)
        {
            // Llegamos a la posicion
            if (pos == 0)
            {
                // Caso al sacar la primera carta
                this->primeraCarta = this->primeraCarta->siguienteCarta;
            }else
            {
                cartaAnteriorTemp->siguienteCarta = cartaTemp->siguienteCarta;
            }
            this->numCartas--;
            return cartaTemp;
        }else
        {
            cartaAnteriorTemp = cartaTemp;
            cartaTemp = cartaTemp->siguienteCarta;
            cont++;
        }
    }
    return NULL;
}

void Deck::imprimir()
{
    Carta* carta = this->primeraCarta;

    while (carta != NULL)
    {
        carta->imprimir();
        carta = carta->siguienteCarta;
    }

}