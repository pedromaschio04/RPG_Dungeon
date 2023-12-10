#include <iostream>
#include "inimigo.h"
using namespace std;

    void inimigo::setVida(int vd){
        vida = vd;
    }
    int inimigo::getVida(){
        return vida;
    }

    void inimigo::setAtaque(int at){
        ataque = at;
    }
    int inimigo::getAtaque(){
        return ataque;
    }

    void inimigo::setDefesa(int df){
        defesa = df;
    }
    int inimigo::getDefesa(){
        return defesa;
    }

    inimigo::inimigo(){
        vida = 10;
        defesa = 5;
        ataque = 3;
    }