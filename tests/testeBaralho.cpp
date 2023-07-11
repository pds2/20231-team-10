#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../include/Baralho.h"

TEST_CASE("Testando Carta") {
    Baralhos::Carta carta1("Copas", "A", 0, 12);
    Baralhos::Carta carta2("Paus", "2", 1, 0);

    SUBCASE("Test getNaipe()") {
        CHECK(carta1.getNaipe() == "Copas");
        CHECK(carta2.getNaipe() == "Paus");
    }

    SUBCASE("Test getValor()") {
        CHECK(carta1.getValor() == "A");
        CHECK(carta2.getValor() == "2");
    }

    SUBCASE("Test getCodigo()") {
        CHECK(carta1.getCodigo() == 0);
        CHECK(carta2.getCodigo() == 1);
    }

    SUBCASE("Test getIndice()") {
        CHECK(carta1.getIndice() == 12);
        CHECK(carta2.getIndice() == 0);
    }

    SUBCASE("Test setNaipe()") {
        carta1.setNaipe("Espadas");
        carta2.setNaipe("Ouros");
        CHECK(carta1.getNaipe() == "Espadas");
        CHECK(carta2.getNaipe() == "Ouros");
    }

    SUBCASE("Test setValor()") {
        carta1.setValor("K");
        carta2.setValor("9");
        CHECK(carta1.getValor() == "K");
        CHECK(carta2.getValor() == "9");
    }

    SUBCASE("Test setCodigo()") {
        carta1.setCodigo(10);
        carta2.setCodigo(20);
        CHECK(carta1.getCodigo() == 10);
        CHECK(carta2.getCodigo() == 20);
    }

    SUBCASE("Test setIndice()") {
        carta1.setIndice(7);
        carta2.setIndice(4);
        CHECK(carta1.getIndice() == 7);
        CHECK(carta2.getIndice() == 4);
    }

    SUBCASE("Test getCarta()") {
        CHECK(carta1.getCarta() == "A de Copas");
        CHECK(carta2.getCarta() == "2 de Paus");
    }

    SUBCASE("Test getSimboloCarta()") {
        CHECK(carta1.getSimboloCarta() == "A ♥ | A de Copas");
        CHECK(carta2.getSimboloCarta() == "2 ♣ | 2 de Paus");
    }

    SUBCASE("Test operator>()") {
        //deve retornar falso, pois carta1.codigo == 0  e carta2.codigo == 1
        CHECK(carta2 > carta1);
        CHECK_FALSE(carta1 > carta2);
    }

    SUBCASE("Test operator<()") {
        CHECK(carta1 < carta2);
        CHECK_FALSE(carta2 < carta1);
    }
}

TEST_CASE("Testando BaralhoTotal") {
    Baralhos::BaralhoTotal baralho;

    SUBCASE("Test iniciarBaralho()") {
        baralho.iniciarBaralho();
        CHECK(baralho.getNumeroCartas() == 52);
        CHECK(baralho.getCartasRestantes() == 52);
    }

    SUBCASE("Test embaralhar()") {
        baralho.embaralhar();
        CHECK(baralho.getNumeroCartas() == 52);
        CHECK(baralho.getCartasRestantes() == 52);
    }

    SUBCASE("Test getCartas()") {
        int quantidade = 5;
        vector<Baralhos::Carta> cartas = baralho.getCartas(quantidade);
        CHECK(cartas.size() == quantidade);
        CHECK(baralho.getCartasRestantes() == 47);
    }

}