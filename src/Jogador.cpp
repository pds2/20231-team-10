#include "Jogador.h"
/**
 * @brief Construct a new Jogador:: Jogador object
 * 
 * @param id 
 * @param bot 
 * @param nome 
 */
Jogador::Jogador(int id, bool bot, std::string nome)
    : Persona(id, nome), bot(bot), atividade(true), fichas(100), fichas_apostadas(0), pontos(0) {}

/**
 * @brief Destroy the Jogador:: Jogador object
 * 
 */
Jogador::~Jogador() {}

/**
 * @brief retorna o bot que irá jogar
 * 
 * @return true 
 * @return false 
 */
bool Jogador::getBot() {
    return bot;
}

/**
 * @brief retorna a atividade do jogador
 * 
 * @return true 
 * @return false 
 */
bool Jogador::getAtividade() {
    return atividade;
}
/**
 * @brief retorna as fichas do jogador
 * 
 * @return int 
 */
int Jogador::getFichas() {
    return fichas;
}
/**
 * @brief retorna o numero de fichas apostadas
 * 
 * @return int 
 */
int Jogador::getFichasApostadas() {
    return fichas_apostadas;
}
/**
 * @brief retorna os pontos
 * 
 * @return int 
 */
int Jogador::getPontos() {
    return pontos;
}

/**
 * @brief seta o bot jogador
 * 
 * @param bot 
 */
void Jogador::setBot(bool bot) {
    this->bot = bot;
}

/**
 * @brief seta a atividade
 * 
 * @param atividade 
 */
void Jogador::setAtividade(bool atividade) {
    this->atividade = atividade;
}

/**
 * @brief seta as fichas do jogador
 * 
 * @param fichas 
 */
void Jogador::setFichas(int fichas) {
    this->fichas = fichas;
}

/**
 * @brief seta as fichas apostadasvpelo jogador
 * 
 * @param fichas 
 */
void Jogador::setFichasApostadas(int fichas) {
    this->fichas_apostadas = fichas;
}

/**
 * @brief seta os pontos do jogador
 * 
 * @param pontos 
 */
void Jogador::setPontos(int pontos) {
    this->pontos = pontos;
}

/**
 * @brief incrementa as fichas jogadas na rodada para o jogador
 * 
 * @param fichas 
 */
void Jogador::adicionarFichas(int fichas) {
    this->fichas += fichas;
}

/**
 * @brief aposta fichas
 * 
 * @param fichas 
 */
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

/**
 * @brief exibe as cartas
 * 
 * @return vector<Baralhos::Carta> 
 */
vector<Baralhos::Carta> Jogador::exibirCartas() {
    return this->getBaralho();
};

/**
 * @brief adiciona pontos ganhados na rodada
 * 
 * @param pontos 
 */
void Jogador::adicionarPontos(int pontos) {
    this->pontos += pontos;
}
