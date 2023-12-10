#include <iostream>
#include <string>
#include "inimigo.h"
#include "jogoRPG.h"
using namespace std;

int main(){
    personagem jogador,*jg;
    jg = &jogador;
    jogoRPG partida;
    string nome;
    cout<<"Bem vindo(a) ao Dungeon Storm!\n>Qual é o seu nome: ";
    cin>>nome;
    system("clear");
    jogador.setNome(nome);
    jogador.escolherClasse();
    //cout<<jogador.getNome()<<" seus atributos são: |Vida = "<<jogador.getVida()<<"| Ataque = "<<jogador.getAtaque()<<"| Defesa = "<<jogador.getDefesa()<<"|\n";
    cout<<jogador.getNome()<<" voce acaba de encontrar um monstro e o primeiro golpe será seu!!!\n";
    partida.batalhar(jg);
    return 0;
}