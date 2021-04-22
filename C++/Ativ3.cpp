#include <iostream>
#include <string>

using namespace std;

class Empregado{
public:

    string nome;
    float salario;

    void aumento(float porcentagem){
        salario = (salario*((porcentagem/100)+1));
    }

    void mostraDados(){
        cout << "nome: " << nome << endl;
        cout << "salario: " << salario << endl;
    }

};

int main(){

    Empregado empre;

    empre.nome = "joao";
    empre.salario = 300;

    empre.mostraDados();
    empre.aumento(30);
    empre.mostraDados();

    return 0;
}