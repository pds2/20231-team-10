#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/Contador.h"

using namespace Contador;
using namespace Baralhos;

TEST_CASE("Testando ContadorDeBaralho") {
    SUBCASE("Test ocorreuStraightFlush()") {
        vector<Carta> cartas_jogador1 = {
            Carta("Copas", "A", 12, 12),
            Carta("Copas", "K", 11, 11)
        };
        vector<Carta> cartas_mesa1 = {
            Carta("Copas", "Q", 10, 10),
            Carta("Copas", "J", 9, 9),
            Carta("Copas", "10", 8, 8),
            Carta("Copas", "9", 7, 7)
        };
        CHECK(ContadorDeBaralho::ocorreuStraightFlush(cartas_jogador1, cartas_mesa1));

        vector<Carta> cartas_jogador2 = {
            Carta("Copas", "A", 12, 12),
            Carta("Copas", "2", 0, 0)
        };
        vector<Carta> cartas_mesa2 = {
            Carta("Espadas", "3", 1, 1),
            Carta("Espadas", "4", 2, 2),
            Carta("Copas", "5", 3, 3),
            Carta("Copas", "6", 4, 4)
        };
        CHECK_FALSE(ContadorDeBaralho::ocorreuStraightFlush(cartas_jogador2, cartas_mesa2));
    }

     SUBCASE("Test ocorreuQuadra()") {
        vector<Carta> cartas_jogador = {
            Carta("Copas", "A", 12, 12),
            Carta("Espadas", "A", 13, 12),
            Carta("Ouros", "A", 26, 12),
            Carta("Paus", "A", 39, 12),
            Carta("Copas", "5", 3, 3)
        };
        vector<Carta> cartas_mesa = {
            Carta("Copas", "6", 4, 4),
            Carta("Espadas", "7", 5, 5),
            Carta("Espadas", "8", 6, 6),
            Carta("Espadas", "9", 7, 7),
            Carta("Espadas", "10", 8, 8)
        };
        CHECK(ContadorDeBaralho::ocorreuQuadra(cartas_jogador, cartas_mesa));

        vector<Carta> cartas_jogador2 = {
            Carta("Copas", "A", 12, 12),
            Carta("Espadas", "A", 13, 12),
            Carta("Ouros", "A", 26, 12),
            Carta("Paus", "2", 39, 0),
            Carta("Copas", "5", 3, 3)
        };
        vector<Carta> cartas_mesa2 = {
            Carta("Copas", "6", 4, 4),
            Carta("Espadas", "7", 5, 5),
            Carta("Espadas", "8", 6, 6),
            Carta("Espadas", "9", 7, 7),
            Carta("Espadas", "J", 8, 9)
        };
        CHECK_FALSE(ContadorDeBaralho::ocorreuQuadra(cartas_jogador2, cartas_mesa2));
    }

    SUBCASE("Test ocorreuFullHouse()") {
        vector<Carta> cartas_jogador = {
            Carta("Copas", "A", 12, 12),
            Carta("Espadas", "A", 13, 12),
            Carta("Ouros", "2", 26, 0),
            Carta("Espadas", "4", 39, 3),
            Carta("Copas", "4", 3, 3)
        };
        vector<Carta> cartas_mesa = {
            Carta("Copas", "6", 4, 5),
            Carta("Espadas", "6", 5, 5),
            Carta("Espadas", "6", 6, 5),
            Carta("Espadas", "9", 7, 8),
            Carta("Espadas", "10", 8, 9)
        };
        CHECK_FALSE(ContadorDeBaralho::ocorreuFullHouse(cartas_jogador, cartas_mesa));
    }


    
     SUBCASE("Test ocorreuFlush()") {
        vector<Carta> cartas_jogador = {
            Carta("Copas", "A", 12, 12),
            Carta("Copas", "2", 0, 0)
        };
        vector<Carta> cartas_mesa = {
            Carta("Copas", "3", 1, 1),
            Carta("Copas", "4", 2, 2),
            Carta("Copas", "5", 3, 3),
            Carta("Copas", "6", 4, 4)
        };
        CHECK(ContadorDeBaralho::ocorreuFlush(cartas_jogador, cartas_mesa));
    }

    SUBCASE("Test ocorreuSequencia()") {
        vector<Carta> cartas_jogador = {
            Carta("Copas", "A", 12, 12),
            Carta("Espadas", "2", 13, 0),
            Carta("Ouros", "3", 26, 1),
            Carta("Paus", "4", 39, 2),
            Carta("Copas", "5", 3, 3)
        };
        vector<Carta> cartas_mesa = {
            Carta("Copas", "6", 4, 4),
            Carta("Espadas", "7", 5, 5),
            Carta("Espadas", "8", 6, 6),
            Carta("Espadas", "9", 7, 7),
            Carta("Espadas", "10", 8, 8)
        };
        CHECK(ContadorDeBaralho::ocorreuSequencia(cartas_jogador, cartas_mesa));


       vector<Carta> cartas_jogador2 = {
            Carta("Copas", "A", 12, 12),
            Carta("Espadas", "2", 13, 0),
            Carta("Ouros", "3", 26, 1),
            Carta("Paus", "4", 39, 2),
            Carta("Copas", "10", 3, 8)
        };
        vector<Carta> cartas_mesa2 = {
            Carta("Copas", "6", 4, 4),
            Carta("Espadas", "7", 5, 5),
            Carta("Espadas", "8", 6, 6),
            Carta("Espadas", "9", 7, 7),
            Carta("Espadas", "J", 8, 9)
        };
        CHECK_FALSE(ContadorDeBaralho::ocorreuSequencia(cartas_jogador2, cartas_mesa2));
    }

    SUBCASE("Test ocorreuDoisPares()") {
        vector<Carta> cartas_jogador = {
            Carta("Copas", "A", 0, 12),
            Carta("Espadas", "A", 1, 12)
        };
        vector<Carta> cartas_mesa = {
            Carta("Ouros", "K", 2, 11),
            Carta("Paus", "K", 3, 11),
            Carta("Copas", "Q", 4, 10)
        };
        CHECK(ContadorDeBaralho::ocorreuDoisPares(cartas_jogador, cartas_mesa));

    }

    SUBCASE("Test ocorreuPares()") {
        vector<Carta> cartas_jogador = {
            Carta("Copas", "A", 12, 12),
            Carta("Espadas", "A", 13, 12),
            Carta("Ouros", "2", 26, 0),
            Carta("Espadas", "4", 39, 3),
            Carta("Copas", "5", 3, 4)
        };
        vector<Carta> cartas_mesa = {
            Carta("Copas", "6", 4, 5),
            Carta("Espadas", "7", 5, 6),
            Carta("Espadas", "8", 6, 7),
            Carta("Espadas", "9", 7, 8),
            Carta("Espadas", "10", 8, 9)
        };
        CHECK(ContadorDeBaralho::ocorreuPares(cartas_jogador, cartas_mesa));
    }

    SUBCASE("Test nomearJogada()") {
        CHECK(ContadorDeBaralho::nomearJogada(20) == "Straight Flush");
        CHECK(ContadorDeBaralho::nomearJogada(19) == "Quadra");
        CHECK(ContadorDeBaralho::nomearJogada(18) == "Full House");
        CHECK(ContadorDeBaralho::nomearJogada(17) == "Flush");
        CHECK(ContadorDeBaralho::nomearJogada(16) == "Sequencia");
        CHECK(ContadorDeBaralho::nomearJogada(15) == "Dois Pares");
        CHECK(ContadorDeBaralho::nomearJogada(14) == "Par");
        CHECK(ContadorDeBaralho::nomearJogada(13) == "Carta Alta");
    }
}
