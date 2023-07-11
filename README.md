#Index<br>
1.[Descrição](#Descrição)

2.[Funcionalidades](#funcionalidades) 

3.[Tecnologias Utilizadas](#tecnologias)

5.[Compilação](#status)

<h1 id = Descrição>Descrição</h1>  

Projeto feito para colocar em prática os conhecimentos adquiridos na disciplina de Programação e Desenvolvimento de Software da UFMG. Consiste em um jogo de Texas Holdem Poker, feito para até quatro jogadores, com um bot que faz contagem de cartas para determinar a melhor jogada.<br><br>

Projeto executado por:<br><br>

Daniel Moreira dos Santos<br>
Pedro Henrique Esteves Dalla-Lana<br>
Sarah Aline Caetano Cruz<br>
Sanny Cristiane Moreira de Sales

Vídeo com a explicação do trabalho: https://youtu.be/c66AD9EoAA0

<br><br><br>
<h1 id = funcionalidades>Funcionalidades</h1>

<h2>1- Guardar nome e valores de aposta de jogadores.<br></h2>
<br>
Para cada jogador da rodada, o sistema guarda o nome, a mão e os valores de aposta<br><br>

<h2>2- Apostar, correr, cobrir, aumentar</h2><br>
Em cada rodada, cada jogador tem a opção de correr e perder o valor apostado, continuar com a aposta feita ou aumentar a aposta.<br><br>

<h2>3- Comparar cartas e sets de cartas</h2> <br>
As funções comparam as cartas da mão e da mesa e selecionam a melhor combinação feita com até 5 delas.<br><br>


<h1 id = Tecnologias>Tecnologias Utilizadas</h1>

<h5>C++</h5>
<br><br>
<h1 id = compilação>Compilação</h1><br>

<h3> Jogo:</h3>
Para compilar o jogo é necessário executar o comando make e em seguida ./bin/main

<br><h3>Testes:</h3> <br>
Para rodar o teste é necessário executar os seguintes comandos:
<br>
g++ -c src/Contador.cpp
g++ -c src/Baralho.cpp

Baralho:
<br>

g++ tests/testeContadorBaralho.cpp Baralho.o -o testeBaralho
<br>
e em seguida
<br>
./testeBaralho

<br><br>

Contador:
<br>
g++ tests/testeContador.cpp Contador.o Baralho.o -o testeContador
<br>
e em seguida 
<br>
./testeContador




