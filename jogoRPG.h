#include "personagem.h"

class jogoRPG{
    private:
        int inimigosDerrotados;
        int tesourosEcontrados;

    public:
        jogoRPG();
        void setInimigosDerrotados(int ind);
        int getInimigosDerrotados();
        
        void setTesourosEncontrados(int te);
        int getTesourosEncontrados();
        
        void batalhar(personagem *jogador);
        void run(personagem *jogador);
        int menu();

};