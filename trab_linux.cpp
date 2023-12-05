#include <iostream>
#include <string>
#include <list>

using namespace std;


class no{
    public:
        string nome;
        no *proximo;

        no(string nome){
            this->nome = nome;
        }
};

class JogadoresDerrotados{
    public:
        no *primeiro = NULL, *ultimo=NULL;
        void adicionar(string nome){
            no *novo = new no(nome);
            if(primeiro == NULL){
              primeiro = novo;
              ultimo = novo;      
            }
            else{
                ultimo->proximo = novo;
                ultimo = novo;
            }
        }
        void printar(){
            no *atual = primeiro;
            while(atual !=NULL){
                cout<<atual->nome<< " | ";
                atual = atual->proximo;
            }
        }
};

class Personagem{

    public:
        string nome;
        string tipo;
        double vid = 25;
        double atq = 0;
        double def = 0;
        double danoCausado = 0;
        int sangramento = 0; 
        string especial;
        int qtdEspeciais=0;

		Personagem(string nm){
			nome = nm;
		}

        void printStatus(){
            cout<<"\n"<<nome<<"|vida: "<<vid<<"|atq: "<<atq<<"|def: "<<def<<"|qtd. de especiais: "<< qtdEspeciais<<"|dano causado: "<<danoCausado;
        }
};

class Arqueiro: public Personagem{
	public:
        
        Arqueiro(string nm):Personagem(nm){
            nome = nm;
            def = 3;
            atq = 3;
            especial = " Flechada na Lata ";
            tipo = "Arqueiro";
        }
};

class Ladino: public Personagem{
    public:
        
        Ladino(string nm):Personagem(nm){
            nome = nm;
            def = 2;
            atq = 4;
            especial = " Deixa o bolso moscando dnv ";
            tipo = "Ladino";
        }
};

class Bardo: public Personagem{
    public:
        Bardo(string nm):Personagem(nm){
            nome = nm;
            def = 2;
            atq = 4;
            especial = "-> Tocando o Terror <-";
            tipo = "Bardo";
        }
};

class Berserker: public Personagem{
    public:
        Berserker(string nm):Personagem(nm){
            nome = nm;
            def = 1;
            atq = 5;
            especial = "Corte Destruidor de Mundos";
            tipo = "Berserker";
        }
};

class Druida: public Personagem{
    public:
        Druida(string nm):Personagem(nm){
            nome = nm;
            def = 4;
            atq = 3;
            especial = "Espinhos da morte";
            tipo = "Druida";
        }
};

class Curandeiro : public Personagem{
    public:
        Curandeiro(string nm):Personagem(nm){
            nome = nm;
            def = 5;
            atq = 2;
            especial = "Escudo Ofensivo";
            tipo = "Curandeiro";
        }
};


class JogoRPG{
    public:
        void escolherClasse(string nm, Personagem *j){
        int opcao;
        cout<<"Escolha uma classe para o "<< nm <<":\n1-Arqueiro\n2-Ladino\n3-Bardo\n4-Berserker\n5-Druida\n6-Curandeiro"<< endl;
        cin >> opcao;
        system("clear");
        switch(opcao){
            case 1:{
                Arqueiro arq(nm);
                *j = arq;
                break;
            }
            case 2:{
                Ladino lad(nm);
                *j = lad; 
                break;
            }
            case 3:{
                Bardo bard(nm);
                *j = bard;
                break;
            }
            case 4:{
                Berserker berse(nm);
                *j = berse;
                break;
            }
            case 5:{
                Druida drui(nm);
                *j = drui; 
                break;
            }
            case 6:{
                Curandeiro cur(nm);
                *j = cur;
                break;
            }
        }

    }

    int sangrar(){
        int sangramentoRounds=0;
        
        while(sangramentoRounds <2){
            sangramentoRounds = rand()%7;
        }
        return sangramentoRounds;
        
    }

    double ataqueespecial(){
        double especial;
        int chance = rand()%100;
        if(chance%2 == 0){
            especial = rand()%10;
            while(especial < 6){
                especial = rand()%10;
            }
            return especial;
        }
        return 0;
    } 

    void batalhar(Personagem *jatq, Personagem *jdef, int rd){

        char decisao;
        double especial;
        int sangramento;

        if(jatq->sangramento > 0){
            jatq->vid-=1;
            jatq->sangramento-=1;
        }
        if(jdef->sangramento > 0){
            jdef->vid-=1;
            jdef->sangramento-=1;
        }

        cout<<"<<<<<<<<<< ROUND "<< rd <<" ATACANTE DA VEZ "<<jatq->nome<<" >>>>>>>>>>\n"<<jatq->nome<<" - vida atual: "<<jatq->vid<<" | Atq: "<<jatq->atq<<" | Def: "<<jatq->def<<" | Sangramento Rounds: "<<jatq->sangramento<<"\n";
        cout<<jdef->nome<<" - vida atual: "<<jdef->vid<<" | Atq: "<<jdef->atq<<" | Def: "<<jdef->def<< " | Sangramento Rounds: "<<jdef->sangramento<<"\n<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
        especial = ataqueespecial();
        if(especial > 0){
            sangramento = sangrar();
            jdef->sangramento += sangramento;
            cout<<"\nAtaque especial "<<jatq->especial<<"| dano: "<<especial<<" | sangramento causado: "<<sangramento<<endl;
        }
        cout<<"\n"<<jdef->nome<<" deseja contra atacar?\nS-Sim\nN-Nao\n";
        cin >> decisao;
        system("clear");
        
        if(especial > 0){

            if(decisao == 'S' || decisao == 's'){
                jatq->vid = jatq->vid - jdef->atq;
                jdef->vid = jdef->vid  - especial;

                jatq->danoCausado += especial;
                jdef->danoCausado += jdef->atq;

                jatq->qtdEspeciais++;
                
            }
            else{
                jdef->vid = jdef->vid - (especial -jdef->def);
                jatq->danoCausado += especial-jdef->def;   
            }
        }
        else{
            if(decisao == 'S' || decisao == 's'){
                
                jatq->vid = jatq->vid - jdef->atq;
                jdef->vid = jdef->vid  - jatq->atq;

                jatq->danoCausado += jatq->atq;
                jdef->danoCausado += jdef->atq;
            }
            else{
                jdef->vid = jdef->vid - (jatq->atq -jdef->def);
                jatq->danoCausado += jatq->atq -jdef->def;   
            }   
        }
        
        
    }

    int sortearInicio(){
        int result;
        result = rand()%50;
        if(result%2==0){
            return 2;
        }
        else{
            return 1;
        }
    }
    void partida(Personagem *j1, Personagem *j2, JogadoresDerrotados *d1, JogadoresDerrotados *d2){
        
        Personagem *jogador1, *jogador2;
        jogador1 = j1;
        jogador2 = j2;
        string personagemNome;
        bool continuaRound = true;

        int jogadorInicia, proximoAtacar=0, round = 0;
        system("clear");
        cout << "\n>Jogador 1 escolha o nome do seu personagem" << endl;
        cin >> personagemNome;
        system("clear");
        escolherClasse(personagemNome, jogador1);
        cout << "\n>Jogador 2 escolha o nome do seu personagem" << endl;
        cin >> personagemNome;
        system("clear");
        escolherClasse(personagemNome, jogador2);

        jogadorInicia = sortearInicio();
        system("clear");
        
        while(continuaRound){
        
            if(proximoAtacar > 0){
                if(proximoAtacar == 1){
                    batalhar(jogador1, jogador2, round);
                    proximoAtacar = 2;
                }
                else{
                    batalhar(jogador2,jogador1, round);
                    proximoAtacar = 1;
                }
            }

            if(jogadorInicia < 3){
                if(jogadorInicia == 1){
                    batalhar(jogador1,jogador2, round);
                    proximoAtacar = 2;
                    jogadorInicia = 4;
                }
                else{
                    batalhar(jogador2,jogador1, round);
                    proximoAtacar = 1;
                    jogadorInicia = 4;
                }
            }

            round ++; 

            if(round ==10 || j1->vid <= 0 || j2->vid <= 0){
                continuaRound = false;
            }
        }
        
        system("clear");
        if(round == 10){
            cout<<"----- PARTIDA ENCERRADA POR QUANTIDADE DE ROUNDS -----\n";
            if(jogador1->danoCausado > jogador2->danoCausado){
                cout<< "O Vencedor foi: "<< jogador1->nome<<" com o total de "<<jogador1->danoCausado<<" dano causado!!\n";
                d1->adicionar(jogador2->nome);
                
            }
            else{
                cout<< "O Vencedor foi: "<< jogador2->nome<<" com o total de "<<jogador2->danoCausado<<" dano causado!!\n";
                d2->adicionar(jogador1->nome);
            }
        }
        else if(jogador1->vid <= 0 || jogador2->vid <=0){
            if(jogador1->vid <=0 && jogador1->danoCausado < jogador2->danoCausado){
                cout<< "O Vencedor foi: "<< jogador2->nome<<" com o total de "<<jogador2->danoCausado<<" dano causado!!\n\n";
                d2->adicionar(jogador1->nome);
            }
            else{
                cout<< "O Vencedor foi: "<< jogador1->nome<<" com o total de "<<jogador1->danoCausado<<" dano causado!!\n\n";
                d1->adicionar(jogador2->nome);
            }
        }
        cout<<"------------------------ STATUS DA BATALHA ------------------------ \n";
        jogador1->printStatus();
        jogador2->printStatus();
        cout<<"\n\n------------------------ STATUS DA BATALHA ------------------------ \n\n";

        cout <<"Personagens derrotados pelos Jogador 1: ";
        d1->printar();

        cout <<"\nPersonagens derrotados pelos Jogador 2: ";
        d2->printar();
        
        char op;
        cout << "\nDeseja jogar novamente?\nS-Sim\nN-Nao\n";
        cin >> op;
        if(op == 'S' || op =='s'){
            partida(j1,j2,d1,d2);
        }   
    }
};

int main(){
    JogoRPG jogo,*jogoAtual;
    jogoAtual = &jogo;
    JogadoresDerrotados derotados1,derrotados2, *derrot1, *derrot2;
    derrot1 = &derotados1;
    derrot2 = &derrotados2;

    Personagem *jg1,*jg2,jogador1(""),jogador2("");
    jg1 = &jogador1;
    jg2 = &jogador2;
    cout<<"-----BEM VINDO(A), VAMOS BATALHAR?----"; 
    jogoAtual->partida(jg1,jg2,derrot1,derrot2);
    cout<<"-----OBRIGADO POR JOGAR, VOLTE SEMPRE!----\n"; 
    return 0;
}
