#ifndef TEMPLATE_DOMINIOS_HPP_INCLUDED
#define TEMPLATE_DOMINIOS_HPP_INCLUDED

template <typename T>
class Dominio {
    private:
        T valor;
        virtual bool validar(T) = 0;

    public:
        bool setValor(T novoValor) {
            if (validar(novoValor)) {
                valor = novoValor;
                return true;
            }
            return false;
        }

        T getValor() const {
            return valor;
        }
};

#endif // TEMPLATE_DOMINIOS_HPP_INCLUDED
