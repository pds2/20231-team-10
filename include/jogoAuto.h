#ifndef JOGOAUTO_H
#define JOGOAUTO_H

#include "utils.h"

class jogoAuto{
    public:
    jogoAuto();
    void executaJogo(Persona& dealer, vector<Jogador>& jogadores, BaralhoTotal& baralho_jogo);  // Função para executar o jogo automático
    //void sleep(bool pode, int tempo);
};

#endif