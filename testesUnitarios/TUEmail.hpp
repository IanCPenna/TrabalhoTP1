#ifndef TUEMAIL_HPP_INCLUDED
#define TUEMAIL_HPP_INCLUDED

#include "TUTemplate.hpp"
#include "../dominios/email.hpp"

class TUEmail : public TUTemplate<Email, std::string> {
public:
    TUEmail();
};

#endif // TUEMAIL_HPP_INCLUDED
