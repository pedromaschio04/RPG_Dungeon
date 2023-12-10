#include <string>
using namespace std;

class personagem{
    private:
        string nome;
        int vida = 100;
        int ataque;
        int defesa;
        int sangramento;
        int classe;
    public:
        personagem();
        void setNome(string nm);
        string getNome();

        void setVida(int vd);
        int getVida();

        void setAtaque(int at);
        int getAtaque();

        void setDefesa(int df);
        int getDefesa();

        void setSangramento(int sg);
        int getSangramento();

        void setClasse(int cl);
        int getClasse();
        
        void escolherClasse();
};