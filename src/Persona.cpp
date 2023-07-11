#include "Persona.h"
/**
 * @brief Construct a new Persona:: Persona object
 * 
 * @param id 
 * @param nome 
 */
Persona::Persona(int id, std::string nome) : id(id), nome(nome) {}

/**
 * @brief Destroy the Persona:: Persona object
 * 
 */
Persona::~Persona() {
    limparBaralho();
}

/**
 * @brief retorna o nmoe
 * 
 * @return std::string 
 */
std::string Persona::getNome() {
    return nome;
}

/**
 * @brief retorna id
 * 
 * @return int 
 */
int Persona::getId() {
    return id;
}

/**
 * @brief seta o nome
 * 
 * @param nome 
 */
void Persona::setNome(std::string nome) {
    this->nome = nome;
}

/**
 * @brief seta a id
 * 
 * @param id 
 */
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

/**
 * @brief limpa o baralho
 * 
 */
void Persona::limparBaralho() {
    baralho.clear();
}

/**
 * @brief exibe as cartas
 * 
 * @param quantidade 
 * @return vector<Baralhos::Carta> 
 */
vector<Baralhos::Carta> Persona::exibirCartas(int quantidade) const{
    int maximal = min(int(this->baralho.size()), quantidade);
    vector<Baralhos::Carta> cartas = this->baralho;
    cartas.resize(maximal);
    return cartas;
};
