#include <iostream>

#include <vector>
#include "dominios/senha.hpp"

using namespace std;

int main()
{
    Senha senha;

    string entrada;

    cin >> entrada;

    senha.setValor(entrada);

    return 0;
}
