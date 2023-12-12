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
        cout<<"\n"<<jogador->getNome()<<" você acaba de econtrar um inimigo, se prepare para batalhar!!!\n\n";
        while(npc.getVida() > 0){
            if(jogador->getSangramento()>0){
                jogador->setVida(jogador->getVida()-1);
                jogador->setSangramento(jogador->getSangramento()-1);
            }
            npc.exibirStatus();
            jogador->exibirStatus();

            if(atacante == 0){
                cout<<"\n\nDeseja atacar?\n";
                cin>>decisao;
                cout<<"SINTA O GOSTO DA MORTE!!\n";
                npc.setVida((npc.getVida()-jogador->getAtaque()));
                atacante = 1;
            }
            else{
                cout<<"\nMonstro desfere um ataque em sua direção\nDeseja se defender ou contra atacar?\nD-Defender\nC-Contra Atacar\n";
                cin>>decisao;
                if(toupper(decisao)=='D'){
                    jogador->setVida(jogador->getVida()-(npc.getAtaque()-jogador->getDefesa()));
                }
                else if(toupper(decisao)=='C'){
                   npc.setVida((npc.getVida()-jogador->getAtaque()));
                   jogador->setVida(jogador->getVida()-npc.getAtaque());
                }
                sangrar(jogador);
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
            if(jogador->getSangramento()>0){
                jogador->setVida(jogador->getVida()-1);
                jogador->setSangramento(jogador->getSangramento()-1);
            }
            posicao = mapa.getPosicaoAtual();
            if((posicao[0]==3 && posicao[1]==1)||(posicao[0]==3 && posicao[1]==13)||(posicao[0]==11 && posicao[1]==14)||(posicao[0]==11 && posicao[1]==16)){
                batalhar(jogador);
            }
            mapa.exibirMapa();
            jogador->exibirStatus();
            mapa.andar(posicao);
        }
    }
    
    int jogoRPG::menu(personagem *jogador){
        int decisao;
        system("clear");
        cout<<"-----------------------------------\n| Bem vindo(a) ao Dungeon Storm!! |\n|---------------------------------|\n| 1-Inciar partida                |\n| 2-Instruções                    |\n| 3-Sair                          |\n-----------------------------------\n"; 
        cin>>decisao;
        system("clear");

        if(decisao == 1){
            run(jogador);
        }
        else if(decisao==2){
            char key;
            while(toupper(key)!='Q'){
                cout<<"\n-----------------------------------\n|           COMO JOGAR            |\n|---------------------------------|\n| >Para caminhar pelo mapa basta  |\n|  digitar a tecla que represanta |\n|  a direção que desja andar e em |\n|                                 |\n| >Digite q para voltar para      |\n|  voltar para o menu principal.  | \n-----------------------------------\n";                  
                //                                                                                      
                //                                            
                //                                            
                //

                cin>> key;
                system("clear");
            }
            menu(jogador);                                       
        }
        return decisao;
    }
     void jogoRPG::sangrar(personagem *jogador){
        int possibilidade;
        int sangramentoRounds;

        possibilidade = rand()%50;
        if(possibilidade %2 == 0){
            while(sangramentoRounds<0 || sangramentoRounds>5){
                sangramentoRounds = rand()%5;
            }
            jogador->setSangramento(jogador->getSangramento()+sangramentoRounds);
        }
     }