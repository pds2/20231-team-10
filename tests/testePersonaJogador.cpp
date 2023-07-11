#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/Persona.h"
#include "../include/Jogador.h"

using namespace Baralhos;
using namespace std;

TEST_CASE("Testando a classe Persona") {
    Persona persona(1, "Alice");

    SUBCASE("Obtendo o ID e nome da Persona") {
        CHECK(persona.getId() == 1);
        CHECK(persona.getNome() == "Alice");
    }

    SUBCASE("Definindo um novo ID e nome para a Persona") {
        persona.setId(2);
        persona.setNome("Bob");
        CHECK(persona.getId() == 2);
        CHECK(persona.getNome() == "Bob");
    }

    SUBCASE("Recebendo e exibindo o baralho da Persona") {
        std::vector<Carta> baralho = {Carta("Ás", "Espadas"), Carta("Rei", "Copas")};
        persona.receberBaralho(baralho);
        CHECK(persona.exibirCartas().size() == 2);
        CHECK(persona.exibirCartas()[0].getNome() == "Ás");
        CHECK(persona.exibirCartas()[1].getNaipe() == "Copas");
    }
}

TEST_CASE("Testando a classe Jogador") {
    Jogador jogador(1, true, "Carol");

    SUBCASE("Obtendo os atributos do Jogador") {
        CHECK(jogador.getId() == 1);
        CHECK(jogador.getBot() == true);
        CHECK(jogador.getNome() == "Carol");
        CHECK(jogador.getAtividade() == true);
        CHECK(jogador.getFichas() == 100);
        CHECK(jogador.getFichasApostadas() == 0);
        CHECK(jogador.getPontos() == 0);
    }

    SUBCASE("Definindo novos valores para os atributos do Jogador") {
        jogador.setId(2);
        jogador.setBot(false);
        jogador.setNome("David");
        jogador.setAtividade(false);
        jogador.setFichas(200);
        jogador.setFichasApostadas(50);
        jogador.setPontos(10);

        CHECK(jogador.getId() == 2);
        CHECK(jogador.getBot() == false);
        CHECK(jogador.getNome() == "David");
        CHECK(jogador.getAtividade() == false);
        CHECK(jogador.getFichas() == 200);
        CHECK(jogador.getFichasApostadas() == 50);
        CHECK(jogador.getPontos() == 10);
    }

    SUBCASE("Adicionando fichas e realizando apostas") {
        jogador.adicionarFichas(100);
        jogador.apostarFichas(50);

        CHECK(jogador.getFichas() == 150);
        CHECK(jogador.getFichasApostadas() == 50);
    }
}
