#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <vector>
#include "Baralho.h"

class Persona {
    private:
        int id;
        std::string nome;
        std::vector<Baralhos::Carta> baralho;

    public:
        Persona(int id, std::string nome);
        virtual ~Persona();
        std::string getNome();
        int getId();
        std::vector<Baralhos::Carta> getBaralho();
        void setNome(std::string nome);
        void setId(int id);
        void receberBaralho(const std::vector<Baralhos::Carta>& baralho);
        void limparBaralho();
        std::vector<Baralhos::Carta> exibirCartas(int quantidade) const;
};

#endif
