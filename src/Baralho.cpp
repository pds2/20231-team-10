
#include "../include/Baralho.h"
using namespace std;
using namespace Baralhos;
/**
 * @brief Construct a new Baralhos:: Carta:: Carta object
 * 
 */
Baralhos::Carta::Carta() {
    this->naipe = "";
    this->valor = "";
    this->codigo = -1;
    this->indice = -1;
}
/**
 * @brief Construct a new Baralhos:: Carta:: Carta object
 * 
 * @param naipe 
 * @param valor 
 * @param codigo 
 * @param indice 
 */
Baralhos::Carta::Carta(string naipe, string valor, int codigo, int indice) {
    this->naipe = naipe;
    this->valor = valor;
    this->codigo = codigo;
    this->indice = indice;
}
/**
 * @brief retorna o naipe da carta
 * 
 * @return string 
 */
string Baralhos::Carta::getNaipe() {
    return this->naipe;
}
/**
 * @brief retorna o valor da carta
 * 
 * @return string 
 */
string Baralhos::Carta::getValor() {
    return this->valor;
}
/**
 * @brief rtorna o codigo da carta
 * 
 * @return int 
 */
int Baralhos::Carta::getCodigo() {
    return this->codigo;
}
/**
 * @brief retorna o indice da carta
 * 
 * @return int 
 */
int Baralhos::Carta::getIndice() {
    return this->indice;
}
/**
 * @brief seta o naipe da carta
 * 
 * @param naipe 
 */
void Baralhos::Carta::setNaipe(string naipe) {
    this->naipe = naipe;
}
/**
 * @brief seta o valor da carta
 * 
 * @param valor 
 */
void Baralhos::Carta::setValor(string valor) {
    this->valor = valor;
}
/**
 * @brief seta o código da carta
 * 
 * @param codigo 
 */
void Baralhos::Carta::setCodigo(int codigo) {
    this->codigo = codigo;
}
/**
 * @brief seta o índice da carta
 * 
 * @param valor 
 */
void Baralhos::Carta::setIndice(int valor) {
    this->indice = valor;
}
/**
 * @brief retorna o valor e naipe da carta
 * 
 * @return string 
 */
string Baralhos::Carta::getCarta(){ 
    return this->valor + " de " + this->naipe;
}
/**
 * @brief retorna o símbolo da carta
 * 
 * @return string 
 */
string Baralhos::Carta::getSimboloCarta(){ 
    string simbolo =  "";
    if (this->naipe == "Copas") {
        simbolo = "♥";
    } else if (this->naipe == "Espadas") {
        simbolo = "♠";
    } else if (this->naipe == "Ouros") {
        simbolo = "♦";
    } else if (this->naipe == "Paus") {
        simbolo = "♣";
    }
    return this->valor + " " + simbolo + " | " + this->valor + " de " + this->naipe;
}
/**
 * @brief sobrecarrega o operador >
 * 
 * @param str 
 * @return true 
 * @return false 
 */
bool Baralhos::Carta::operator > (const Carta& str) const {
    return (this->codigo > str.codigo);

};
/**
 * @brief sobrecarrega o operador ==
 * 
 * @param str 
 * @return true 
 * @return false 
 */
bool Baralhos::Carta::operator == (const Carta& str) const {
    return (this->codigo == str.codigo);

};
/**
 * @brief sobrecarrega o operador <
 * 
 * @param str 
 * @return true 
 * @return false 
 */
bool Baralhos::Carta::operator < (const Carta& str) const {
    return (this->codigo < str.codigo);
};
/**
 * @brief Construct a new Baralhos:: Baralho Total:: Baralho Total object
 * 
 */
Baralhos::BaralhoTotal::BaralhoTotal() {
    this->iniciarBaralho();
}
/**
 * @brief Destroy the Baralhos:: Baralho Total:: Baralho Total object
 * 
 */
Baralhos::BaralhoTotal::~BaralhoTotal() {
    this->todas_cartas.clear();
    this->cartas_usadas = 0;
}
/**
 * @brief seta baralho
 * 
 */
void Baralhos::BaralhoTotal::iniciarBaralho() {
    this->todas_cartas = vector<Carta>();
    this->cartas_usadas = 0;

    string naipes[4] = {"Copas", "Espadas", "Ouros", "Paus"};
    int valores_indices[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    string valores[13] = {"2", "3", "4", "5", "6", "7", "8","9", "10", "J", "Q", "K", "A"};
    int codigo = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++, codigo++) {
            this->todas_cartas.push_back(Carta(naipes[i], valores[j], codigo, valores_indices[j]));
        }
    }
    reverse(this->todas_cartas.begin(), this->todas_cartas.end());
}
/**
 * @brief embaralha as cartas
 * 
 */
void Baralhos::BaralhoTotal::embaralhar() {
    random_device rd;
    mt19937 generator(rd());
    shuffle(this->todas_cartas.begin(), this->todas_cartas.end(), generator);
}
/**
 * @brief retorna numero total de cartas
 * 
 * @return int 
 */
int Baralhos::BaralhoTotal::getNumeroCartas()
{
    return this->numero_cartas;
}
vector<Carta> Baralhos::BaralhoTotal::getCartas(int quantidade)
{
    vector<Carta> cartas = this->todas_cartas;

try {
        if (quantidade > this->todas_cartas.size()) {
            throw std::runtime_error("Não há cartas suficientes no baralho.");
        }
    
    // Resize the vector to the desired sample size
    cartas.resize(quantidade);

    auto removePredicate = [cartas](const Carta& c) {
            return std::find(cartas.begin(), cartas.end(), c) != cartas.end();
        };
    
    for (Carta carta : cartas) {
        int code = carta.getCodigo();
        this->todas_cartas.erase(remove_if(this->todas_cartas.begin(), this->todas_cartas.end(), [code](Carta c) {
            return c.getCodigo() == code;
        }), this->todas_cartas.end());
    }
    this->cartas_usadas += quantidade;
} catch (const std::exception& e) {
        std::cerr << "Ocorreu um erro ao obter as cartas: " << e.what() << std::endl;
    }
    return cartas;
}
/**
 * @brief printa o baralho
 * 
 */
void Baralhos::BaralhoTotal::printBaralho() {
    for (int i = 0; i < this->todas_cartas.size(); i++) {
        cout << this->todas_cartas[i].getCarta() << endl;
    }
}
/**
 * @brief retorna cartas não distribuidas
 * 
 * @return int 
 */
int Baralhos::BaralhoTotal::getCartasRestantes() {
    return this->numero_cartas - this->cartas_usadas; 
}
