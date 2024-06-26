#include <iostream>
#include "mapaJogo.h"

using namespace std;

    mapaJogo::mapaJogo(){}
    
    void mapaJogo::setPosicaoAtual(int ps[2]){
        this->mapa[posicaoAtual[0]][posicaoAtual[1]] =" ";
        this->mapa[ps[0]][ps[1]] = "X";
        this->posicaoAtual[0] = ps[0];
        this->posicaoAtual[1] = ps[1];
    }

    vector <int> mapaJogo::getPosicaoAtual(){
        vector <int> ps;
        ps = {posicaoAtual[0],posicaoAtual[1]};
        return ps;
    }

    void mapaJogo::exibirMapa(){
        for(int i=0;i <14; i++){
            cout<<"\n";
            for(int j=0;j<23;j++){
                cout<<mapa[i][j];
            }
        }

        cout<<"\n";
    }

    void mapaJogo::andar(vector<int> ps){
        char key;
        cout<<"\n";
        cin>>key;
        int posicao[2];
        if(toupper(key)=='W'){
            if(mapa[ps[0]-1][ps[1]] ==" " || mapa[ps[0]-1][ps[1]] =="?"){
                posicao[0] = ps[0]-1;
                posicao[1] = ps[1];
                setPosicaoAtual(posicao);
            }
        }
        if(toupper(key)=='S'){
            if(mapa[ps[0]+1][ps[1]] ==" " || mapa[ps[0]+1][ps[1]] =="?"){
                posicao[0] = ps[0]+1;
                posicao[1] = ps[1];
                setPosicaoAtual(posicao);
            }
        }
        if(toupper(key)=='A'){
            if(mapa[ps[0]][ps[1]-1] ==" " || mapa[ps[0]][ps[1]-1] =="?"){
                posicao[0] = ps[0];
                posicao[1] = ps[1]-1;
                setPosicaoAtual(posicao);
            }
        }
        if(toupper(key)=='D'){
            if(mapa[ps[0]][ps[1]+1] ==" " || mapa[ps[0]][ps[1]+1] =="?"){
                posicao[0] = ps[0];
                posicao[1] = ps[1]+1;
                setPosicaoAtual(posicao);
            }
        }
    }

    void mapaJogo::encontrouBau(personagem *jogador){
        char continuar;
        int item = 4;
        system("clear");
        cout<<jogador->getNome()<<" voce encontrou um bau misterioso!!\n";
        while(item<0 || item>3){
            item = rand()%20;
        }
        switch(item){
            case 1:
                jogador->setInventario("pocao_de_cura");
                cout<<"Foi adicionado ao seu inventario uma pocao_de_cura\n";
            break;
            case 2:
                jogador->setInventario("pocao_de_dano");
                cout<<"Foi adicionado ao seu inventario uma pocao_de_dano\n";
            break;
            case 3:
                jogador->setInventario("escudo");
                cout<<"Foi adicionado ao seu inventario um escudo\n";
            break;
        }
        cout<<"\nDigite c para continuar\n";
        cin>>continuar;
        system("clear");
    }

    string mapaJogo::getValor(vector <int> ps){
        return mapa[ps[0]][ps[1]];
    }
