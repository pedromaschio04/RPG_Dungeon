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
        cout<<"\n"<<jogador->getNome()<<" você acaba de econtrar um inimigo, se prepare para batalhar!!!\n";
        while(npc.getVida() > 0){
            
            npc.exibirStatus();
            jogador->exibirStatus();

            if(atacante == 0){
                cout<<"\nDeseja atacar?\n";
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
        string nome;
        mapaJogo mapa;

        vector <int> boss={3,22};

        cout<<"Qual é o seu nome jogador(a)?\n";
        cin>>nome;
        jogador->setNome(nome);
        system("clear");
        cout<<jogador->getNome()<<" ";
        jogador->escolherClasse();
        system("clear");
        vector <int> posicao;
        while(mapa.getPosicaoAtual()!=boss){
            system("clear");
            // monstros [3,1][3,13][11,14][11,16] 
            posicao = mapa.getPosicaoAtual();
            if((posicao[0]==3 && posicao[1]==1)||(posicao[0]==3 && posicao[1]==13)||(posicao[0]==11 && posicao[1]==14)||(posicao[0]==11 && posicao[1]==16)){
                batalhar(jogador);
            }
            mapa.exibirMapa();
            jogador->exibirStatus();
            mapa.andar(posicao);
        }
    }
    
    int jogoRPG::menu(){
        int decisao;
        system("clear");
        cout<<"-----------------------------------\n| Bem vindo(a) ao Dungeon Storm!! |\n|---------------------------------|\n| 1-Inciar partida                |\n| 2-Instruções                    |\n| 3-Sair                          |\n-----------------------------------\n"; 
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
