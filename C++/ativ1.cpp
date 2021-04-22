#include <iostream>
#include <string>

using namespace std;
using std::string;

class ComboProduto;

class Produto
{
private:
    float preco;
    string nome;

public:
    float getPreco() { return preco; }
    string getNome() { return nome; }

    void setNome(string nome) { this->nome = nome; }
    void setPreco(float preco) { this->preco = preco; }

    friend ComboProduto combinarProdutos(Produto &a, Produto &b);
};

class ComboProduto
{
private:
    float totalValor;
    int quantidadeItens;

public:
    float getTotalValor() { return totalValor; }
    int getQuantidadeItens() { return quantidadeItens; }

    friend ComboProduto combinarProdutos(Produto &a, Produto &b);
};

ComboProduto combinarProdutos(Produto &a, Produto &b)
{

    ComboProduto combo;

    combo.totalValor = (0.85 * (a.preco + b.preco));

    combo.quantidadeItens = 2;

    return (combo);
}

int main()
{

    Produto prod1, prod2;

    prod1.setNome("hamburguer");
    prod2.setNome("fritas");

    prod1.setPreco(65);
    prod2.setPreco(65);

    ComboProduto combo = combinarProdutos(prod1, prod2);

    cout << "Preco total = " << combo.getTotalValor() << endl;
    cout << "Quantidade total = " << combo.getQuantidadeItens() << endl;

    return 0;
}