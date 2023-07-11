#ifndef JOGADOR_H
#define JOGADOR_H

#include <string>
#include "Persona.h"

class Jogador : public Persona {
    private:
        bool bot;
        bool atividade;
        int fichas;
        int fichas_apostadas;
        int pontos;

    public:
        Jogador(int id, bool bot, std::string nome);
        ~Jogador();
        bool getBot();
        bool getAtividade();
        int getFichas();
        int getFichasApostadas();
        int getPontos();
        void setBot(bool bot);
        void setAtividade(bool atividade);
        void setFichas(int fichas);
        void setFichasApostadas(int fichas);
        void setPontos(int pontos);
        void adicionarFichas(int fichas);
        void apostarFichas(int fichas);
        void adicionarPontos(int pontos);
        vector<Baralhos::Carta> exibirCartas();
};

#endif
