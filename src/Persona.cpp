#include "../include/Persona.h"

Persona::Persona(int id, std::string nome) : id(id), nome(nome) {}

Persona::~Persona() {
    limparBaralho();
}

std::string Persona::getNome() {
    return nome;
}

int Persona::getId() {
    return id;
}

void Persona::setNome(std::string nome) {
    this->nome = nome;
}

void Persona::setId(int id) {
    this->id = id;
}
std::vector<Baralhos::Carta> Persona::getBaralho(){
    return this->baralho;
}
void Persona::receberBaralho(const std::vector<Baralhos::Carta>& baralho) {
    try {
        if (baralho.empty()) {
            throw std::runtime_error("O baralho recebido está vazio.");
        }
        this->baralho = baralho;
    } catch (const std::exception& e) {
        std::cerr << "Erro ao receber o baralho: " << e.what() << std::endl;
    }
}

void Persona::limparBaralho() {
    baralho.clear();
}

vector<Baralhos::Carta> Persona::exibirCartas(int quantidade) const{
    int maximal = min(int(this->baralho.size()), quantidade);
    vector<Baralhos::Carta> cartas = this->baralho;
    cartas.resize(maximal);
    return cartas;
};
