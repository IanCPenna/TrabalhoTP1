#include <iostream>

#include <vector>
#include "dominios/data.hpp"

using namespace std;

int main()
{
    Data data;

    string entrada;

    cin >> entrada;

    data.setValor(entrada);

    cout << "Data:" << data.getValor() << "\n";

    return 0;
}
