#ifndef TEX_H
#define TEX_H
#include <string>
#include "Documento.h"
class Tex : public Documento
{
    public:
        explicit Tex(std::string nombre) { this->nombre = nombre; }
        virtual ~Tex();

        Tex& operator >>(std::string &termino);
    protected:
    private:
};

#endif // TEX_H

