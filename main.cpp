#include <iostream>
#include <string>
#include "inimigo.h"
#include "jogoRPG.h"
using namespace std;

int main(){
    personagem jogador,*jg;
    jg = &jogador;
    jogoRPG partida;
    partida.menu(jg);
    cout<<"\n\n>Obrigado por jogar\n>Esperamos te ver aqui novamente\n";
    return 0;
}