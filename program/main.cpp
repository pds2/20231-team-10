#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <random>
#include <algorithm>
#include <chrono>
#include <thread>
#include "Jogador.h"
#include "Baralho.h"
#include "Automation.h"
#include "Contador.h"
#include "utils.h"
#include "jogoAuto.h"

using namespace std;
using namespace Baralhos;
using namespace Automations;
using namespace Contador;


int main() {
    
    unsigned int NUM_MAX_PLAYERS = 3;
    int PRECO_BLIND = 10;
    int DIFICULDADE;
    int TEMPO_DE_DORMIR = 1;
    bool DORMIR = true;

    Persona dealer = Persona(0, "James-san");
    vector<Jogador> jogadores;
    for (unsigned int  i = 0; i <NUM_MAX_PLAYERS-1; i++) {
        jogadores.push_back(Jogador(i, true, "BOT " + std::to_string(i)));
    }
    
    Baralhos::BaralhoTotal baralho_jogo = BaralhoTotal();

    std::cout << dealer.getNome() <<": Bom dia! Tudo bem ? Bem vindo ao Casino DDC Texas Hold! Eu me chamo James-san, serei o Dealer de hoje. Está preparado para apostar tudo ? " << std::endl;
    sleep(DORMIR, TEMPO_DE_DORMIR);
    std::cout << dealer.getNome() << ": Digite 1 para começar o jogo ou 0 para sair." << std::endl;
    sleep(DORMIR, TEMPO_DE_DORMIR);
    int opcao;
    std::cin >> opcao;
    if (opcao == 1) {
        jogoAuto jogo;
        jogo.executaJogo(dealer, jogadores, baralho_jogo);

        } else {
    std::cout << "                 ⢀⣀⣤⣤⣶⡶⠶⠶⠿⠿⠿⠛⠛⠛⠻⠿⠿⣶⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀"<< std::endl;
    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣶⣶⠾⠿⠟⠛⠉⠁⠀ ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<< std::endl;
    std::cout << "⠀⠀⠀⠀⠀⠀⣠⣾⠟⠋⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠿⣶⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<< std::endl;
    std::cout << "⠀⠀⠀⠀⢠⣾⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⢿⣦⡀⠀⠀⠀⠀⠀⠀⠀"<< std::endl;
    std::cout << "⠀⠀⠀⣴⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣷⡄⠀⠀⠀⠀⠀⠀"<< std::endl;
    std::cout << "⠀⢀⣾⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⡄⠀⠀⠀⠀⠀"<< std::endl;
    std::cout << "⠀⣾⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⡄⠀⠀⠀⠀"<< std::endl;
    std::cout << "⢸⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣷⡀⠀⠀⠀"<< std::endl;
    std::cout << "⢸⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⢀⣀⣀⣀⠀⠀⠀⠀⢻⣧⠀⠀⠀"<< std::endl;
    std::cout << "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠸⠿⣿⣿⣤⠀⠀⠀⠀⢿⣆⠀⠀"<< std::endl;
    std::cout << "⢸⡇⠀⠀⠀⠀⠀⠀⠀⣠⣴⣦⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⠀⠀⠘⣿⡀⠀"<< std::endl;
    std::cout << "⢸⡇⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠀⠀⠀⠀⢻⣧⠀"<< std::endl;
    std::cout << "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠀⠀⠀   ⠀⠘⣿⡀"<< std::endl;
    std::cout << "⢸⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠀⠀⠀⠀⣀⣠⣤⣴⣶⣶⣶⣶⡶⠀ ⢻⣗"<< std::endl;
    std::cout << "⣼⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⠀⠀⠀⠀⣀⣀⣀⣀⣤⣤⣤⣤⣶⣶⣿⠿⠿⠛⠋⠉⠁⠀⠀⠀⠀ ⠀⢸⣿" << std::endl;
    std::cout << "⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣀⣤⣤⣤⣶⣶⣾⠿⠿⠿⠛⠛⠛⠉⠉⣉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀⢸⣿"<< std::endl;
    std::cout << "⣿⡇⠀⠀⠀⠀⠀⢀⣤⣤⣶⣶⣿⠿⠿⠟⠛⠛⠋⠉⠉⠁⠀⠀⠀⣀⣀⣠⣤⣤⣴⣶⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿"<< std::endl;
    std::cout << "⢻⣇⠀⠀⠀⠀⠀⠈⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠺⠛⠛⠉⠉⠀⠀⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿"<< std::endl;
    std::cout << "⠘⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿"<< std::endl;
    std::cout << "⠀⠹⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿"<< std::endl;
    std::cout << "⠀⠀⢹⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⡏"<< std::endl;
    std::cout << "⠀⠀⠀⢿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⠃"<< std::endl;
    std::cout << "⠀⠀⠀⠈⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡟⠀"<< std::endl;
    std::cout << "⠀⠀⠀⠀⠘⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⡿⠁⠀"<< std::endl;
    std::cout << "⠀⠀⠀⠀⠀⠈⠻⣧⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⠟⠁⠀⠀"<< std::endl;
    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠈⠻⢷⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⡾⠟⠁⠀⠀⠀⠀"<< std::endl;
    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠻⢿⣶⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣾⠟⠉⠀⠀⠀⠀⠀⠀⠀"<< std::endl;
    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠛⠿⣷⣦⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"<< std::endl;
    std::cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠙⠛⠿⠷⢶⣶⣶⣦⣤⣤⣤⣤⣤⣴⣶⠾⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀"<< std::endl;
    std::cout << std::endl;
    std::cout << "Até a próxima, perdedor!!!!" << std::endl;
        }

}