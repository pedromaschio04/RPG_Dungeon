#include <iostream>
#include <string>
#include "personagem.h"
using namespace std;
     
    personagem::personagem(){};

    void personagem::setNome(string nm){
        nome = nm;
    }
    string personagem::getNome(){
        return nome;
    }
    void personagem::setVida(int vd){
        vida = vd;
    }
    int personagem::getVida(){
        return vida;
    }

    void personagem::setAtaque(int at){
        ataque = at;
    }
    int personagem::getAtaque(){
        return ataque;
    }

    void personagem::setDefesa(int df){
        defesa = df;
    }
    int personagem::getDefesa(){
        return defesa;
    }

     void personagem::setSangramento(int sg){
        sangramento = sg;
    }
    int personagem::getSangramento(){
        return sangramento;
    }

    void personagem::setClasse(int cl){
        classe = cl;
    }
    
    int personagem::getClasse(){
        return classe;
    }

    void personagem::escolherClasse(){
        int classeTipo;
        cout<<"Digite o identificado para escolher sua classe:\n1-Arqueiro:|Ataque = 3| Defesa = 3|\n2-Ladino:|Ataque = 4| Defesa = 2|\n3-Bardo:|Ataque = 4| Defesa = 2|\n4-Berserker:|Ataque = 5| Defesa = 1|\n5-Druida:|Ataque = 3| Defesa = 4|\n";
        cin>> classeTipo;
        switch(classeTipo){
            case 1:
                this->setAtaque(3);
                this->setDefesa(3);
                this->setClasse(1);
            break;
            case 2:
                this->setAtaque(4);
                this->setDefesa(2);
                this->setClasse(2);
            break;
            case 3:
                this->setAtaque(4);
                this->setDefesa(2);
                this->setClasse(3);
            break;
            case 4:
                this->setAtaque(5);
                this->setDefesa(1);
                this->setClasse(4);
            break;
            case 5:
                this->setAtaque(3);
                this->setDefesa(4);
                this->setClasse(5);
            break;
        }
    }
    
  

