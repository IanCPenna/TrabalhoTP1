#include <iostream>
#include "dominios/headers/papel.hpp"




using namespace std;

int main()
{
    Papel dominio;
    int valor;
    cin >> valor;
    try{
        dominio.setValor(valor);
        cout << "Valor = " << dominio.getValor() << "\n";
    }
    catch(invalid_argument& e){
        cout << "Erro: " << e.what() << "\n";
    }


    return 0;
}
