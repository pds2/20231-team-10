#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <random>
#include <algorithm>
#include <chrono>
#include <thread>
#include <stdlib.h>

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
    //int PRECO_BLIND = 10;
    //int DIFICULDADE;
    int TEMPO_DE_DORMIR = 1;
    bool DORMIR = true;

    Persona dealer = Persona(0, "James-san");
    vector<Jogador> jogadores;
    for (unsigned int  i = 0; i <NUM_MAX_PLAYERS-1; i++) {
        jogadores.push_back(Jogador(i, true, "BOT " + std::to_string(i)));
    }
    
    Baralhos::BaralhoTotal baralho_jogo = BaralhoTotal();

    std::cout <<"                                                       bbbbbbbb                         " << std::endl;
std::cout <<"WWWWWWWW                           WWWWWWWW                b::::::b                         " << std::endl; 
std::cout <<"W::::::W                           W::::::W                b::::::b                         " << std::endl; 
std::cout <<"W::::::W                           W::::::W                b::::::b                         " << std::endl;
std::cout <<"W::::::W                           W::::::W                b:::::b                          " << std::endl;
std::cout <<" W:::::W           WWWWW           W:::::W eeeeeeeeeeee    b:::::bbbbbbbbb                  " << std::endl;
std::cout <<"  W:::::W         W:::::W         W:::::Wee::::::::::::ee  b::::::::::::::bb                " << std::endl;
std::cout <<"   W:::::W       W:::::::W       W:::::We::::::eeeee:::::eeb::::::::::::::::b               " << std::endl;
std::cout <<"    W:::::W     W:::::::::W     W:::::We::::::e     e:::::eb:::::bbbbb:::::::b              " << std::endl;
std::cout <<"     W:::::W   W:::::W:::::W   W:::::W e:::::::eeeee::::::eb:::::b    b::::::b              " << std::endl;
std::cout <<"      W:::::W W:::::W W:::::W W:::::W  e:::::::::::::::::e b:::::b     b:::::b              " << std::endl;
std::cout <<"       W:::::W:::::W   W:::::W:::::W   e::::::eeeeeeeeeee  b:::::b     b:::::b              " << std::endl;
std::cout <<"        W:::::::::W     W:::::::::W    e:::::::e           b:::::b     b:::::b              " << std::endl;
std::cout <<"         W:::::::W       W:::::::W     e::::::::e          b:::::bbbbbb::::::b              " << std::endl;
std::cout <<"          W:::::W         W:::::W       e::::::::eeeeeeee  b::::::::::::::::b               " << std::endl;
std::cout <<"           W:::W           W:::W         ee:::::::::::::e  b:::::::::::::::b                " << std::endl;
std::cout <<"            WWW             WWW            eeeeeeeeeeeeee  bbbbbbbbbbbbbbbb                 " << std::endl;
std::cout <<"PPPPPPPPPPPPPPPPP                   kkkkkkkk                                                " << std::endl;
std::cout <<"P::::::::::::::::P                  k::::::k                                                " << std::endl;
std::cout <<"P::::::PPPPPP:::::P                 k::::::k                                                " << std::endl;
std::cout <<"PP:::::P     P:::::P                k::::::k                                                " << std::endl;
std::cout <<"  P::::P     P:::::P  ooooooooooo    k:::::k    kkkkkkk eeeeeeeeeeee    rrrrr   rrrrrrrrr   " << std::endl;
std::cout <<"  P::::P     P:::::Poo:::::::::::oo  k:::::k   k:::::kee::::::::::::ee  r::::rrr:::::::::r  " << std::endl;
std::cout <<"  P::::PPPPPP:::::Po:::::::::::::::o k:::::k  k:::::ke::::::eeeee:::::eer:::::::::::::::::r " << std::endl;
std::cout <<"  P:::::::::::::PP o:::::ooooo:::::o k:::::k k:::::ke::::::e     e:::::err::::::rrrrr::::::r" << std::endl;
std::cout <<"  P::::PPPPPPPPP   o::::o     o::::o k::::::k:::::k e:::::::eeeee::::::e r:::::r     r:::::r" << std::endl;
std::cout <<"  P::::P           o::::o     o::::o k:::::::::::k  e:::::::::::::::::e  r:::::r     rrrrrrr" << std::endl;
std::cout <<"  P::::P           o::::o     o::::o k:::::::::::k  e::::::eeeeeeeeeee   r:::::r" << std::endl;
std::cout <<"  P::::P           o::::o     o::::o k::::::k:::::k e:::::::e            r:::::r" << std::endl;
std::cout <<"PP::::::PP         o:::::ooooo:::::ok::::::k k:::::ke::::::::e           r:::::r" << std::endl;
std::cout <<"P::::::::P         o:::::::::::::::ok::::::k  k:::::ke::::::::eeeeeeee   r:::::r" << std::endl; 
std::cout <<"P::::::::P          oo:::::::::::oo k::::::k   k:::::kee:::::::::::::e   r:::::r" << std::endl;
std::cout <<"PPPPPPPPPP            ooooooooooo   kkkkkkkk    kkkkkkk eeeeeeeeeeeeee   rrrrrrr" << std::endl;
std::cout << std::endl;
    std::cout << dealer.getNome() <<": Bom dia! Tudo bem ? Bem vindo ao Casino DDC Texas Hold! Eu me chamo James-san, serei o Dealer de hoje. Está preparado para apostar tudo ? " << std::endl;
    sleep(DORMIR, TEMPO_DE_DORMIR);
    std::cout << dealer.getNome() << ": Digite 1 para começar o jogo." << std::endl;
    std::cout << dealer.getNome() << ": Digite 2 para ver as regras." << std::endl;
    std::cout << dealer.getNome() << ": Digite 3 para sair." << std::endl;
    sleep(DORMIR, TEMPO_DE_DORMIR);
    int opcao;
    std::cin >> opcao;

    system("cls");
    
    if (opcao == 1) {
        jogoAuto jogo;
        jogo.executaJogo(dealer, jogadores, baralho_jogo);

        }
    else if (opcao == 2){
    std::cout <<" ##### ###### #    #   ##    ####     #    #  ####  #      #####  ### ###### #    # " << std::endl;
    std::cout <<"   #   #       #  #   #  #  #         #    # #    # #      #    #  #  #      ##  ## " << std::endl;
    std::cout <<"   #   #####    ##   #    #  ####     ###### #    # #      #    # #   #####  # ## # " << std::endl;
    std::cout <<"   #   #        ##   ######      #    #    # #    # #      #    #     #      #    # " << std::endl;
    std::cout <<"   #   #       #  #  #    # #    #    #    # #    # #      #    #     #      #    # " << std::endl;
    std::cout <<"   #   ###### #    # #    #  ####     #    #  ####  ###### #####      ###### #    # " << std::endl;
    
    std::cout << std::endl;

    std::cout <<"O Texas Hold'em é jogado com um baralho completo de 52 cartas sem coringas. Cada jogador faz o seu “buy-in” para entrar na partida (no nosso jogo, um valor padronizado) e recebe uma quantidade pré-determinada de fichas. Aí começa o jogo." << std::endl;
    std::cout <<"A cada mão, um novo jogador vai embaralhar e distribuir as cartas. Ele ficará conhecido nessa mão como o 'dealer'." << std::endl;
    std::cout <<"O parceiro à sua esquerda deve colocar no escuro o 'small blind', uma pré-aposta cujo valor é estabelecido antes do início do jogo, e o jogador à esquerda dele vai postar também no escuro o 'big blind', que é o dobro. "<< std::endl;
    std::cout <<"Ao longo da partida, os 'blinds' vão subindo gradativamente de valor. Quando você perde todas suas fichas, está eliminado. " << std::endl;
    std::cout <<"O jogo termina quando algum dos participantes acumular todas as fichas da mesa." << std::endl;
    }
    
    else if (opcao == 3){
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
