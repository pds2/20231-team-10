#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Baralho.h"
#include "Jogador.h"

using namespace std;
using namespace Baralhos;
using namespace Players;

Players::Dealer::Dealer(int id, std::string nome) {
    try {
        this->id = id;
        this->nome = nome;
        this->baralho = vector<Carta>();
    } catch (const exception& e) {
        cerr << "Ocorreu uma exceção: " << e.what() << endl;
    }
};

Players::Dealer::~Dealer() {
    try {
        this->limparBaralho();
    } catch (const exception& e) {
        cerr << "Ocorreu uma exceção: " << e.what() << endl;
    }
};

void Players::Dealer::limparBaralho() {
    try {
        this->baralho.clear();
    } catch (const exception& e) {
        cerr << "Ocorreu uma exceção: " << e.what() << endl;
    }
};

int Players::Dealer::getId() {
    return this->id;
};

string Players::Dealer::getNome() {
    return this->nome;
};

void Players::Dealer::setId(int id) {
    this->id = id;
};

void Players::Dealer::setNome(std::string nome) {
    this->nome = nome;
};

void Players::Dealer::receberBaralho(vector<Carta> baralho) {
    try {
        this->baralho = baralho;
    } catch (const exception& e) {
        cerr << "Ocorreu uma exceção: " << e.what() << endl;
    }
};  

vector<Carta> Players::Dealer::exibirCartas(int quantidade) {
    try {
        int maximal = min(int(this->baralho.size()), quantidade);
        vector<Carta> cartas = this->baralho;
        cartas.resize(maximal);
        return cartas;
    } catch (const exception& e) {
        cerr << "Ocorreu uma exceção: " << e.what() << endl;
        return vector<Carta>();
    }
};

Players::Jogador::Jogador(int id, bool bot, std::string nome) {
    try {
        this->id = id;
        this->bot = bot;
        this->atividade = true;
        this->nome = nome;
        this->fichas = 100; // Inicialização padrão do valor de fichas.
        this->fichas_apostadas = 0; // Inicialização padrão do valor de fichas.
        this->pontos = 0; //Inicialização padrão do valor de pontos
        this->baralho = vector<Carta>();
    } catch (const exception& e) {
        cerr << "Ocorreu uma exceção: " << e.what() << endl;
    }
};

Players::Jogador::~Jogador() {
    try {
        this->limparBaralho();
        this->bot = false;
        this->atividade = true;
        this->fichas = 0;
        this->fichas_apostadas = 0;
        this->pontos = 0;
    } catch (const exception& e) {
        cerr << "Ocorreu uma exceção: " << e.what() << endl;
    }
};

void Players::Jogador::limparBaralho() {
    try {
        this->baralho.clear();
    } catch (const exception& e) {
        cerr << "Ocorreu uma exceção: " << e.what() << endl;
    }
};

string Players::Jogador::getNome() {
    return this->nome;
};

int Players::Jogador::getId() {
    return this->id;
};

int Players::Jogador::getPontos() {
    return this->pontos;
};

bool Players::Jogador::getAtividade() {
    return this->atividade;
};

bool Players::Jogador::getBot() {
    return this->bot;
};

int Players::Jogador::getFichas() {
    return this->fichas;
};

int Players::Jogador::getFichasApostadas() {
    return this->fichas_apostadas;
};

void Players::Jogador::setFichasApostadas(int fichas) {
    this->fichas_apostadas = fichas;
};

void Players::Jogador::setPontos(int pontos) {
    this->pontos = pontos;
};

void Players::Jogador::setId(int id) {
    this->id = id;
};

void Players::Jogador::setFichas(int fichas) {
    this->fichas = fichas;
};

void Players::Jogador::setBot(bool bot) {
    this->bot = bot;
};

void Players::Jogador::setAtividade(bool ativadade) {
    this->atividade = ativadade;
};

void Players::Jogador::setNome(std::string nome) {
    this->nome = nome;
};

void Players::Jogador::adicionarFichas(int fichas) {
    this->fichas += fichas;
};

void Players::Jogador::apostarFichas(int fichas) {
    this->fichas -= fichas;
    this->fichas_apostadas += fichas;
};

void Players::Jogador::adicionarPontos(int pontos) {
    this->pontos += pontos;
};

void Players::Jogador::receberBaralho(vector<Carta> baralho) {
    try {
        this->baralho = baralho;
    } catch (const exception& e) {
        cerr << "Ocorreu uma exceção: " << e.what() << endl;
    }
};

vector<Carta> Players::Jogador::exibirCartas() {
    return this->baralho;
};

