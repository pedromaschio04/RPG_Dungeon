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
        for(int i=0;i <13; i++){
            cout<<"\n";
            for(int j=0;j<23;j++){
                cout<<mapa[i][j];
            }
        }

        cout<<"\n";
    }

    void mapaJogo::andar(vector<int> ps){
        char key;
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
