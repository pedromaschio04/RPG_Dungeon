#include <string>
#include <vector>
using namespace std;

class personagem{
    private:
        string nome;
        int vida = 100;
        int ataque;
        int defesa;
        int sangramento=0;
        int classe;
        vector <string> inventario = {""};
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

        void setInventario(string item); 
        vector <string> getInventario();
        string getInventarioItem(int posicao);
        
        void escolherClasse();

        void exibirStatus();

        void exibirInventario();
};