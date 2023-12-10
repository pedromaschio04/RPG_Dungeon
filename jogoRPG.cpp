#include <iostream>
#include "jogoRPG.h"
#include "inimigo.h"
using namespace std;

    jogoRPG::jogoRPG(){}
    void jogoRPG::setInimigosDerrotados(int ind){
        inimigosDerrotados = ind;
    }
    int jogoRPG::getInimigosDerrotados(){
        return inimigosDerrotados;
    }

    void jogoRPG::setTesourosEncontrados(int te){
        tesourosEcontrados = te;
    }
    int jogoRPG::getTesourosEncontrados(){
        return tesourosEcontrados;
    }

    void jogoRPG::batalhar(personagem *jogador){
        inimigo npc;
        int atacante = 0; //0 representa o jogador e 1 o npc
        char decisao;
        while(npc.getVida() > 0){

            cout<<"---------------------\n|vida do inimigo: "<<npc.getVida()<<"|\n---------------------\n";

            if(atacante == 0){
                cout<<"Deseja atacar?\n";
                cin>>decisao;
                cout<<"SINTA O GOSTO DA MORTE!!\n***voce chapocou o monstro***\n\n";
                npc.setVida((npc.getVida()-jogador->getAtaque()));
                atacante = 1;
            }
            else{
                cout<<"O ataque do monstro é de "<<npc.getAtaque()<<". Sua vida atual é de "<<jogador->getVida()<<".\n\nDeseja se defender ou contra atacar?\nD-Defender\nC-Contra Atacar\n";
                cin>>decisao;
                if(toupper(decisao)=='D'){
                    jogador->setVida(jogador->getVida()-(npc.getAtaque()-jogador->getDefesa()));
                }
                else if(toupper(decisao)=='C'){
                   npc.setVida((npc.getVida()-jogador->getAtaque()));
                   jogador->setVida(jogador->getVida()-npc.getAtaque());
                }

                atacante = 0;
            }
            //system("clear");
        }
    }
