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
            
            npc.exibirStatus();
            jogador->exibirStatus();

            if(atacante == 0){
                cout<<"Deseja atacar?\n";
                cin>>decisao;
                cout<<"SINTA O GOSTO DA MORTE!!\n";
                npc.setVida((npc.getVida()-jogador->getAtaque()));
                atacante = 1;
            }
            else{
                cout<<"Monstro desfere um ataque em sua direção\nDeseja se defender ou contra atacar?\nD-Defender\nC-Contra Atacar\n";
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
            system("clear");
        }
    }

    void jogoRPG::run(personagem *jogador){

    }
    
    int jogoRPG::menu(){
        int decisao;
        cout<<"Bem vindo(a) ao Dungeon Storm!!\n1-Inciar partida\n2-Instruções\n3-Sair\n";
        cin>>decisao;
        system("clear");
        if(decisao==2){
            char key;
            while(toupper(key)!='Q'){
                cout<<"\n-----------------------------------\n| >Para jogar Dungeon Storm basta |\n|  utilizar as setinhas para se   |\n|  moviventar pelo labirinto.     |\n|                                 |\n| >Pressione ESC para voltar para |\n|  voltar para o menu principal.  | \n-----------------------------------\n";                                                         
                cin>> key;
                system("clear");
            }
            menu();                                       
        }
        return decisao;
    }
