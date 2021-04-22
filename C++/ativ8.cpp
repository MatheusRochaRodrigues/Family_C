#include <iostream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

class ObjetoGeometrico {
private:
  float dimension1, dimension2;

public:
  ObjetoGeometrico(float dimension1, float dimension2):
  dimension1(dimension1), dimension2(dimension2) {}

  float getDimension1 () {return dimension1;}
  float getDimension2 () {return dimension2;}
  
  void setDimension1 (float dimension1) {this->dimension1 = dimension1;}
  void setDimension2 (float dimension2) {this->dimension2 = dimension2;}

  virtual float calculaPerimetro() {return dimension1 + dimension2;}
  virtual float calculaArea() {return dimension1 * dimension2;}
};

class Triangulo : public ObjetoGeometrico {
private:
  float dimension3;

public:
  Triangulo(float dimension1, float dimension2, float dimension3): ObjetoGeometrico(dimension1, dimension2), dimension3(dimension3){}

  float getDimension3 () {return dimension3;}
    
  void setDimension3 (float dimension3) {this->dimension3 = dimension3;}

  float calculaPerimetro() override {return getDimension1() + getDimension2() + dimension3;}

  float calculaArea() override {
    float result = calculaPerimetro()/2;
    float expression = result*(result - getDimension1())*(result - getDimension2())*(result - dimension3);

    return sqrt(expression);
  }
  
};

class Circulo : public ObjetoGeometrico {
private:
  float raio;

public:
  Circulo(float dimension1, float dimension2,float raio) : ObjetoGeometrico(dimension1, dimension2), raio(raio) {}

  float getRaio() {return raio;}

  void setRaio(float raio) {this->raio = raio;}

  float calculaPerimetro() override {return 2*3.1415*raio;}

  float calculaArea() override {return 3.1415*(pow(raio, 2));}

};

class Retangulo : public ObjetoGeometrico {
public:

  Retangulo(float dimension1, float dimension2): ObjetoGeometrico(dimension1, dimension2) {}

  float calculaPerimetro() override {return (getDimension1()*2) * (getDimension2()*2);}

};

int main() {

  Triangulo T1(4.2, 4.2, 4.2);

  Retangulo R1(6, 3);

  Circulo C1(6.0, 6.0, 6.0);

  vector<ObjetoGeometrico*> forma;
  forma.push_back(&T1);
  forma.push_back(&R1);
  forma.push_back(&C1);

  for (auto f : forma) {
    float area = f->calculaArea();
    float perimetro = f -> calculaPerimetro();
    
    cout << "Area " << area << endl;
    cout << "Perimetro " << perimetro << "\n" << endl;

  }


}