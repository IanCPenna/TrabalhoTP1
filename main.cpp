#include <iostream>
#include "dominios/headers/tempo.hpp"




using namespace std;

int main()
{
    Tempo dominio;
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
