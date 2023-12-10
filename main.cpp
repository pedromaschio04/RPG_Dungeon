#include <iostream>
#include <string>
#include "personagem.h"
using namespace std;

int main(){
    personagem jogador1;
    jogador1.setNome("Pedro");
    jogador1.escolherClasse();
    cout<<"Bem vindo(a) "<< jogador1.getNome()<<"\nSeus atributos são: |Vida = "<<jogador1.getVida()<<"| Ataque = "<<jogador1.getAtaque()<<"| Defesa = "<<jogador1.getDefesa()<<"|\n";
    return 0;
}