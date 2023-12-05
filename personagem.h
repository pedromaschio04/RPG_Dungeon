#include <string>
class personagem{

    private:
        string nome;
        string tipo;
        double vid = 25;
        double atq = 0;
        double def = 0;
        double danoCausado = 0;
        int sangramento = 0; 
        string especial;
    
        int qtdEspeciais=0;
    public:

		Personagem(string nm);

        void printStatus();
};