
#include <iostream>
#include <string>
#include "../include/Baralho.h"
#include "../include/Contador.h"

using namespace std;
using namespace Baralhos;
using namespace Contador;

bool ContadorDeBaralho::ocorreuStraightFlush(vector<Carta> cartas_jogador, vector<Carta> cartas_mesa) {
    bool resposta = false;

    try {
    vector<Carta> cartas = cartas_jogador;
    cartas.insert(cartas.end(), cartas_mesa.begin(), cartas_mesa.end());
     if (cartas.size() < 5) {
        throw std::runtime_error("Não há cartas suficientes para verificar Straight Flush.");
    }
        
    std::sort(cartas.begin(), cartas.end(), greater<Carta>());
    for (unsigned int i = 0; i < cartas.size() - 4; i++) {
        if (abs(cartas[i].getIndice() - cartas[i + 4].getIndice()) == 4) {
            if (cartas[i].getNaipe() == cartas[i + 1].getNaipe() &&
                cartas[i].getNaipe() == cartas[i + 2].getNaipe() &&
                cartas[i].getNaipe() == cartas[i + 3].getNaipe() &&
                cartas[i].getNaipe() == cartas[i + 4].getNaipe()) {
                resposta = true;
                break;
            }
        }
    }
    
    } catch (const std::exception& e) {
        std::cerr << "Ocorreu um erro ao verificar Straight Flush: " << e.what() << std::endl;
    }
    
    return resposta;
}

bool ContadorDeBaralho::ocorreuQuadra(vector<Carta> cartas_jogador, vector<Carta> cartas_mesa) {
    bool resposta = false;

    try {
    vector<Carta> cartas = cartas_jogador;
    cartas.insert(cartas.end(), cartas_mesa.begin(), cartas_mesa.end());
    if (cartas.size() < 4) {
        throw std::runtime_error("Não há cartas suficientes para verificar Quadra.");
    }
        
    std::sort(cartas.begin(), cartas.end(), greater<Carta>());
    for (unsigned int i = 0; i < cartas.size() - 3; i++) {
        if (cartas[i].getIndice() - cartas[i + 3].getIndice() == 0) {
            if (cartas[i].getNaipe() != cartas[i + 1].getNaipe() &&
                cartas[i].getNaipe() != cartas[i + 2].getNaipe() &&
                cartas[i].getNaipe() != cartas[i + 3].getNaipe() &&
                cartas[i+1].getNaipe() != cartas[i + 2].getNaipe() &&
                cartas[i+1].getNaipe() != cartas[i + 3].getNaipe() &&
                cartas[i+2].getNaipe() != cartas[i + 3].getNaipe()
            ) {
                resposta = true;
                break;
            }
        }
    }
        
    } catch (const std::exception& e) {
        std::cerr << "Ocorreu um erro ao verificar Quadra: " << e.what() << std::endl;
    }
    
    return resposta;
};

bool ContadorDeBaralho::ocorreuFullHouse(vector<Carta> cartas_jogador, vector<Carta> cartas_mesa) {
    bool resposta = false;

    try {
    vector<Carta> cartas = cartas_jogador;
    cartas.insert(cartas.end(), cartas_mesa.begin(), cartas_mesa.end());
    if (cartas.size() < 3) {
        throw std::runtime_error("Não há cartas suficientes para verificar Full House.");
    }
        
    std::sort(cartas.begin(), cartas.end(), greater<Carta>());
    for (unsigned int i = 0; i < cartas.size() - 2; i++) {
        if (cartas[i].getIndice() - cartas[i + 2].getIndice() == 0) {
            if (cartas[i].getNaipe() != cartas[i + 1].getNaipe() &&
                cartas[i].getNaipe() != cartas[i + 2].getNaipe() &&
                cartas[i+1].getNaipe() != cartas[i + 2].getNaipe()
            ) {
                int indice = cartas[i].getIndice();
                bool par_encontrado = false;
                for (unsigned int i = 0; i < cartas.size() - 1; i++) {
                    if (cartas[i].getIndice() - cartas[i + 1].getIndice() == 0) {
                        if (cartas[i].getIndice() != indice) {
                            par_encontrado = true;
                            break;
                        }
                    }
                }
                if (par_encontrado) {
                    resposta = true;
                    break;
                }
            }
        }
    }

    } catch (const std::exception& e) {
        std::cerr << "Ocorreu um erro ao verificar Full House: " << e.what() << std::endl;
    }
    
    return resposta;
};

bool ContadorDeBaralho::ocorreuFlush(vector<Carta> cartas_jogador, vector<Carta> cartas_mesa) {
    bool resposta = false;

    try {
    vector<Carta> cartas = cartas_jogador;
    cartas.insert(cartas.end(), cartas_mesa.begin(), cartas_mesa.end());
    if (cartas.size() < 5) {
        throw std::runtime_error("Não há cartas suficientes para verificar Flush.");
    }
        
    int cartas_copas = 0;
    int cartas_espadas = 0;
    int cartas_ouros = 0;
    int cartas_paus = 0;
        
    // Copas", "Espadas", "Ouros", "Paus
    for (unsigned int i = 0; i < cartas.size(); i++) {
        if (cartas[i].getNaipe() == "Copas") {
            cartas_copas++;
        } else if (cartas[i].getNaipe() == "Espadas") {
            cartas_espadas++;
        } else if (cartas[i].getNaipe() == "Ouros") {
            cartas_ouros++;
        } else if (cartas[i].getNaipe() == "Paus") {
            cartas_paus++;
        }
    }
    if (cartas_copas >= 5 || cartas_espadas >= 5 || cartas_ouros >= 5 || cartas_paus >= 5) {
        resposta = true;
    }
        
    } catch (const std::exception& e) {
        std:: cerr << "Ocorreu um erro ao verificar o Flush: " << e.what() << std::endl;
    }
    
    return resposta;
};

bool ContadorDeBaralho::ocorreuSequencia(vector<Carta> cartas_jogador, vector<Carta> cartas_mesa) {
    bool resposta = false;

    try {
    vector<Carta> cartas = cartas_jogador;
    cartas.insert(cartas.end(), cartas_mesa.begin(), cartas_mesa.end());
     if (cartas.size() < 5) {
        throw std::runtime_error("Não há cartas suficientes para verificar Sequência.");
    }
        
    std::sort(cartas.begin(), cartas.end(), greater<Carta>());
    for (unsigned int i = 0; i < cartas.size() - 4; i++) {
        if (abs(cartas[i].getIndice() - cartas[i + 4].getIndice()) == 4) {
            resposta = true;
            break;
        }
    }

    if (!resposta) {
        bool tem_as = false;
        for (unsigned int i = 0; i < cartas.size(); i++) {
            if (cartas[i].getIndice() == 13) {
                tem_as = true;
                break;
            }
        }
        if (tem_as) {
            for (unsigned int i = 0; i < cartas.size() - 3; i++) {
                if (abs(cartas[i].getIndice() - cartas[i + 3].getIndice()) == 3 && cartas[i].getIndice() != 13) {
                    resposta = true;
                    break;
                }
            }
        }
    }
        
    } catch (const std::exception& e) {
        std::cerr << "Ocorreu um erro ao verificar Sequência: " << e.what() << std::endl;
    }
    
    return resposta;
}

bool ContadorDeBaralho::ocorreuDoisPares(vector<Carta> cartas_jogador, vector<Carta> cartas_mesa) {
    bool resposta = false;

    try {
    vector<Carta> cartas = cartas_jogador;
    cartas.insert(cartas.end(), cartas_mesa.begin(), cartas_mesa.end());
     if (cartas.size() < 2) {
        throw std::runtime_error("Não há cartas suficientes para verificar Dois Pares.");
    }
        
    std::sort(cartas.begin(), cartas.end(), greater<Carta>());
    for (unsigned int i = 0; i < cartas.size() - 1; i++) {
        if (abs(cartas[i].getIndice() - cartas[i + 1].getIndice()) == 1) {
            int indice = cartas[i].getIndice();
            if (i + 2 < cartas.size()) {
                for (unsigned int j = i + 1; j < cartas.size() - 1; j++) {
                    if (abs(cartas[j].getIndice() - cartas[j + 1].getIndice()) == 1 && cartas[j].getIndice() != indice) {
                        resposta = true;
                        break;
                    }
                }
            }
        }
    }

    } catch (const std::exception& e) {
        std::cerr << "Ocorreu um erro ao verificar Dois Pares: " << e.what() << std::endl;
    }
    
    return resposta;
}

bool ContadorDeBaralho::ocorreuPares(vector<Carta> cartas_jogador, vector<Carta> cartas_mesa) {
    bool resposta = false;

    try {
    vector<Carta> cartas = cartas_jogador;
    cartas.insert(cartas.end(), cartas_mesa.begin(), cartas_mesa.end());
    if (cartas.size() < 2) {
        throw std::runtime_error("Não há cartas suficientes para verificar Pares.");
    }
        
    std::sort(cartas.begin(), cartas.end(), greater<Carta>());
    for (unsigned int i = 0; i < cartas.size() - 1; i++) {
        if (abs(cartas[i].getIndice() - cartas[i + 1].getIndice()) == 1) {
            resposta = true;
            break;
        }
    }
        
    } catch (const std::exception& e) {
        std::cerr << "Ocorreu um erro ao verificar Pares: " << e.what() << std::endl;
    }
    
    return resposta;
}


int ContadorDeBaralho::pontuarJogada(vector<Carta> cartas_jogador, vector<Carta> cartas_mesa) {
    int pontos = 0;
    vector<Carta> cartas = cartas_jogador;
    cartas.insert(cartas.end(), cartas_mesa.begin(), cartas_mesa.end());
    std::sort(cartas.begin(), cartas.end(), greater<Carta>());

    for (unsigned int i = 0; i < cartas.size() - 1; i++) {
        if (cartas[i].getIndice() > pontos) {
            pontos = cartas[i].getIndice();
        }
    }
    if (ContadorDeBaralho::ocorreuStraightFlush(cartas_jogador,cartas_mesa)) {
        pontos = 20;
    }
    else if (ContadorDeBaralho::ocorreuQuadra(cartas_jogador,cartas_mesa)) {
        pontos = 19;
    }
    else if (ContadorDeBaralho::ocorreuFullHouse(cartas_jogador,cartas_mesa)) {
        pontos = 18;
    }
    else if (ContadorDeBaralho::ocorreuFlush(cartas_jogador,cartas_mesa)) {
        pontos = 17;
    }
    else if (ContadorDeBaralho::ocorreuSequencia(cartas_jogador,cartas_mesa)) {
        pontos = 16;
    }
    else if (ContadorDeBaralho::ocorreuDoisPares(cartas_jogador,cartas_mesa)) {
        pontos = 15;
    }
    else if (ContadorDeBaralho::ocorreuPares(cartas_jogador,cartas_mesa)) {
        pontos = 14;
    }
    return pontos;
}

std::string ContadorDeBaralho::nomearJogada(int pontuacao) {
    std::string nome = "Carta Alta";
    if (pontuacao == 20) {
        nome = "Straight Flush";
    }
    else if (pontuacao == 19) {
        nome = "Quadra";
    }
    else if (pontuacao == 18) {
        nome = "Full House";
    }
    else if (pontuacao == 17) {
        nome = "Flush";
    }
    else if (pontuacao == 16) {
        nome = "Sequencia";
    }
    else if (pontuacao == 15) {
        nome = "Dois Pares";
    }
    else if (pontuacao == 14) {
        nome = "Par";
    }
    return nome;
}
