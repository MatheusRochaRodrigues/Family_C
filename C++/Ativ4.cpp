#include <iostream>
#include <string>

using namespace std;

class Partida{
public:

    string nomeDoTimeMand;
    int numeroGolsMand;
    int pontuacaoMand = 0;

    string nomeDoTimeVisi;
    int numeroGolsVisi;
    int pontuacaoVisi = 0;

    void resultado(string home, int goalHome, string visitor, int goalVisitor){
        nomeDoTimeMand = home;
        numeroGolsMand = goalHome;

        nomeDoTimeVisi = visitor;
        numeroGolsVisi = goalVisitor;
    }

    void calculaPontos(){
        if(numeroGolsMand > numeroGolsVisi){
            pontuacaoMand = 1;
             
        }
        if(numeroGolsMand < numeroGolsVisi){
            pontuacaoVisi = 1;     
        }
    }

    void mostraResultado(){
        if(numeroGolsMand == numeroGolsVisi){
            cout << "\n" << nomeDoTimeMand << " " << numeroGolsMand << " X " <<  numeroGolsVisi << " " << nomeDoTimeVisi << endl;
            cout << "Ninguem pontuou" <<endl;
        }
        if(numeroGolsMand > numeroGolsVisi){
            cout << "\n" << nomeDoTimeMand << " " << numeroGolsMand << " X " <<  numeroGolsVisi << " " << nomeDoTimeVisi << endl;
            cout << nomeDoTimeMand << " tem " << pontuacaoMand << " pontos" <<endl;
            cout << nomeDoTimeVisi << " tem " << pontuacaoVisi << " pontos" <<endl;
        }
        if(numeroGolsMand < numeroGolsVisi){
            cout << "\n" << nomeDoTimeVisi << " " << numeroGolsVisi << " X " << numeroGolsMand << " " << nomeDoTimeMand << endl;
            cout << nomeDoTimeVisi << " tem " << pontuacaoVisi << " pontos" <<endl;
            cout << nomeDoTimeMand << " tem " << pontuacaoMand << " pontos" <<endl;
        }
         
    }

};

int main(){

    Partida part1, part2;

    part1.nomeDoTimeMand;
    part1.nomeDoTimeVisi;

    string nome1, nome2;
    int quant1, quant2;

    string nome3, nome4;
    int quant3, quant4;


    cout << "\nnome do time: ";
	cin >> nome1;

    cout << "\nquantide de gols: "; 
	cin >> quant1;
	
	cout << "\nnome do time visitante: "; 	
	cin >> nome2;
	
	cout << "\nquantide de gols: "; 
	cin >> quant2;


    part1.resultado(nome1, quant1, nome2, quant2);
    part1.calculaPontos();
    part1.mostraResultado();


    cout << "\nnome do time: ";
	cin >> nome3;

    cout << "\nquantide de gols: "; 
	cin >> quant3;
	
	cout << "\nnome do time visitante: "; 	
	cin >> nome4;
	
	cout << "\nquantide de gols: "; 
	cin >> quant4;



    part2.resultado(nome3, quant3, nome4, quant4);
    part2.calculaPontos();
    part2.mostraResultado();

    return 0;
}