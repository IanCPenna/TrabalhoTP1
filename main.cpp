#include <iostream>
#include "dominios/texto.hpp"

#include <vector>


using namespace std;

int main()
{
    vector<string> casos_teste = {
    "12345678901234567890123456789012345678901",
    " Texto",
    ",Texto",
    ".Texto",
    "Texto ",
    "Texto,",
    "Texto.",
    "Texto@123",
    "Olá!",
    "Texto,,abc",
    "Texto,.abc",
    "Texto..abc",
    "Texto.,abc",
    "Texto ,abc",
    "Texto .abc",
    "Texto  abc",
    };

    Texto dominio;
    for (auto s : casos_teste)
    {
        try{
            dominio.setValor(s);
            cout << "Valor = " << dominio.getValor() << "\n";
        }
        catch(invalid_argument& e){
            cout << "Erro: " << e.what() << "\n";
        }
    }

    return 0;
}
