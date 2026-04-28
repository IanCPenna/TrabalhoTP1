#ifndef TEMPLATE_DOMINIOS_HPP_INCLUDED
#define TEMPLATE_DOMINIOS_HPP_INCLUDED


#include <stdexcept>

using namespace std;
template <typename T>
class Dominio {
    private:
        T valor;
        virtual void validar(T) = 0;

    public:
        void setValor(T novoValor) {
            validar(novoValor);
            valor = novoValor;
        }

        T getValor() const {
            return valor;
        }
};

#endif // TEMPLATE_DOMINIOS_HPP_INCLUDED
