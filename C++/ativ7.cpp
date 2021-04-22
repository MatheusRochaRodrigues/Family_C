#include <iostream>
#include <string>
#include <vector>

using namespace std;

class VeiculoAVenda {
private:
    string marca;
    string modelo;
    int ano;
    float precoVenda;

protected:
    

public:

    VeiculoAVenda() : marca("Nenhuma"), modelo("Nenhum"), ano(0), precoVenda(0) {};
    //VeiculoAVenda() : default;
    VeiculoAVenda(string marca, string modelo, int ano, float precoVenda) : marca(marca), modelo(modelo), ano(ano), precoVenda(precoVenda) {};

    void setMarca(string marca) {this->marca = marca;}
    void setModelo(string modelo) {this->modelo = modelo;}
    void setAno(int ano) {this->ano = ano;}
    void setPrecoVenda(float precoVenda) {this->precoVenda = precoVenda;}

    string getMarca() {return marca;}
    string getModelo() {return modelo;}
    int getAno() {return ano;}
    float getPrecoVenda() {return precoVenda;}

    virtual void mostraDados(){
        cout << marca << endl;
        cout << modelo << endl;
        cout << ano << endl;
        cout << precoVenda << "\n" << endl;
    }


};

class AutomovelAVenda : public VeiculoAVenda{
private:
    float potenciaMotor;
    bool cambioAuto;
    int numPortas;

public:

    //AutomovelAVenda(): VeiculoAVenda(marca, modelo, ano, precoVenda), potenciaMotor(0.0), cambioAuto(false), numPortas(0) {};
    AutomovelAVenda(string marca, string modelo, int ano, float precoVenda, float potenciaMotor, bool cambioAuto, int numPortas): VeiculoAVenda(marca, modelo, ano, precoVenda), potenciaMotor(potenciaMotor),cambioAuto(cambioAuto), numPortas(numPortas) {};
    
    void setPotenciaMotor(float potenciaMotor){this->potenciaMotor = potenciaMotor;}
    void setCambioAuto(bool cambioAuto){this->cambioAuto = cambioAuto;}
    void setNumPortas(int numPortas){this->numPortas = numPortas;}

    float getPotenciaMotor(){return potenciaMotor;}
    bool getCambioAuto(){return cambioAuto;}
    int getNumPortas(){return numPortas;}

    void mostraDados() override {

        cout << "marca " << getMarca() << endl;
        cout << "modelo " << getModelo() << endl;
        cout << "ano " << getAno() << endl;
        cout << "preco de venda " << getPrecoVenda() << endl;
        cout << "motor " << getPotenciaMotor() << endl;

        if(getCambioAuto()){
            cout << "cambioAutomatico" << endl;
        }else{
            cout << "cambioManual" << endl;
        }
        
        cout << "numero de portas " << getNumPortas() << "\n" << endl;
        

    }

};

class MotocicletaAVenda : public VeiculoAVenda{
private:
    float cilindradaMotor;
    //double cilindradaMotor

public:

    MotocicletaAVenda(string marca, string modelo, int ano, float precoVenda, float cilindradaMotor): VeiculoAVenda(marca, modelo, ano, precoVenda), cilindradaMotor(cilindradaMotor) {};
    
    void setCilindradaMotor(float cilindradaMotor){this->cilindradaMotor = cilindradaMotor;}

    double getCilindradaMotor(){return cilindradaMotor;}

    void mostraDados() override {

        cout << "marca " << getMarca() << endl;
        cout << "modelo " << getModelo() << endl;
        cout << "ano " << getAno() << endl;
        cout << "preco de venda " << getPrecoVenda() << endl;
        cout << "cilindradas " << getCilindradaMotor() << "\n" << endl;
    }

};

int main()
{

    AutomovelAVenda carro1("renan", "a418", 2020, 8.000, 4.0, true, 4);
    //carro1.mostraDados();

    AutomovelAVenda carro2("renalt", "b300", 2021, 12.000, 5.0, true, 2);
    //carro2.mostraDados();

    MotocicletaAVenda moto1("suzuki", "a321", 2016, 4.100, 6.20);
    //moto1.mostraDados();

    MotocicletaAVenda moto2("suzuki-B", "a324", 2018, 5.100, 7.510);
    //moto2.mostraDados();

    double totalPreco = 0.0;
    vector <VeiculoAVenda*> venda;
    venda.push_back(&carro1);
    venda.push_back(&carro2);
    venda.push_back(&moto1);
    venda.push_back(&moto2);

    for (auto v : venda){
        v->mostraDados();
        totalPreco += v->getPrecoVenda();
    }

    cout << "preca de venda total = " << totalPreco << endl;


    return 0;
}
