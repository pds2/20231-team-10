
#ifndef BARALHO_H
#define BARALHO_H

#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <vector>

using namespace std;

namespace Baralhos {
    class Carta {
        private:
            string naipe;
            string valor;
            int codigo;
            int indice;
        public:
            Carta();
            Carta(string naipe, string valor, int codigo, int indice);
            string getNaipe();
            string getValor();
            int getIndice();
            int getCodigo();
            void setNaipe(string naipe);
            void setIndice(int valor);
            void setValor(string valor);
            void setCodigo(int codigo);
            string getCarta();
            string getSimboloCarta();
            bool operator > (const Carta& str) const;
            bool operator < (const Carta& str) const;
    };

    class BaralhoTotal {
        private:
            int numero_cartas = 52;
            vector<Carta> todas_cartas;
            int cartas_usadas = 0;
        public:
            BaralhoTotal();
            ~BaralhoTotal();
            void iniciarBaralho();
            void embaralhar();
            int getNumeroCartas( );
            int getCartasRestantes( );
            void printBaralho();
            vector<Carta> getCartas(int quantidade);
    };
}
#endif