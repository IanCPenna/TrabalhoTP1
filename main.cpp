#include <iostream>
#include "dominios/papel.hpp"




using namespace std;

int main()
{

    Papel dominio;
    string valor = "PROPRIETARIO DE PRODUTO";
    try{
        dominio.setValor(valor);
        cout << "Valor = " << dominio.getValor() << "\n";
    }
    catch(invalid_argument& e){
        cout << "Erro: " << e.what() << "\n";
    }

    return 0;
}
