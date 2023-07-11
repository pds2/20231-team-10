#include "../include/Jogador.h"

Jogador::Jogador(int id, bool bot, std::string nome)
    : Persona(id, nome), bot(bot), atividade(true), fichas(100), fichas_apostadas(0), pontos(0) {}

Jogador::~Jogador() {}

bool Jogador::getBot() {
    return bot;
}

bool Jogador::getAtividade() {
    return atividade;
}

int Jogador::getFichas() {
    return fichas;
}

int Jogador::getFichasApostadas() {
    return fichas_apostadas;
}

int Jogador::getPontos() {
    return pontos;
}

void Jogador::setBot(bool bot) {
    this->bot = bot;
}

void Jogador::setAtividade(bool atividade) {
    this->atividade = atividade;
}

void Jogador::setFichas(int fichas) {
    this->fichas = fichas;
}

void Jogador::setFichasApostadas(int fichas) {
    this->fichas_apostadas = fichas;
}

void Jogador::setPontos(int pontos) {
    this->pontos = pontos;
}

void Jogador::adicionarFichas(int fichas) {
    this->fichas += fichas;
}

void Jogador::apostarFichas(int fichas) {
    try {
        if (fichas < 0) {
            throw std::invalid_argument("A quantidade de fichas apostadas deve ser não negativa.");
        }
        if (fichas > this->fichas) {
            throw std::runtime_error("Quantidade de fichas insuficiente para a aposta.");
        }
        
        this->fichas -= fichas;
        this->fichas_apostadas += fichas;
    } catch (const std::exception& e) {
        std::cerr << "Erro ao apostar fichas: " << e.what() << std::endl;
    }
}

vector<Baralhos::Carta> Jogador::exibirCartas() {
    return this->getBaralho();
};

void Jogador::adicionarPontos(int pontos) {
    this->pontos += pontos;
}
