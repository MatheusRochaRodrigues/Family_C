#include <iostream>
#include <string>

using namespace std;
using std::string;

class FormaGeometrica
{
public:
    // virtual void calculaArea() = 0;

    virtual string oi()
    {
        cout << "oi, sou uma forma geometrica" << endl;
    }
};

class Retangulo : public FormaGeometrica
{
private:
    float largura, altura;

public:
    string oi() override
    {
        cout << "oi, sou um retangulo" << endl;
    }
};

int main()
{

    FormaGeometrica *form;

    Retangulo retan;

    form = &retan;

    cout << form->oi() << endl;

    return 0;
}