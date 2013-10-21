#ifndef TXT_H
#define TXT_H
#include <string>
#include "Documento.h"


class Txt : public Documento
{
    public:
        explicit Txt(std::string nombre) { this->nombre =nombre; }
        virtual ~Txt();

        Txt& operator >>(std::string &termino);
    protected:
    private:
};

#endif // TXT_H
