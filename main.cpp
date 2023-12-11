#include <iostream>
#include <string>
#include <ncurses.h>
#include "inimigo.h"
#include "jogoRPG.h"
using namespace std;

int main(){
    personagem jogador,*jg;
    jg = &jogador;
    jogoRPG partida;
    string nome;
    int decisao;
    decisao = partida.menu();
    if(decisao == 1){
        partida.run(jg);
    }
    cout<<">Obrigado por jogar\n>Esperamos te ver aqui novamente\n";
    return 0;
}