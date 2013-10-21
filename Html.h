#ifndef HTML_H
#define HTML_H

#include "Documento.h"
#include <string>

class Html : public Documento
{
    public:
        explicit Html(std::string nombre) { this->nombre =nombre; }
        virtual ~Html();

        Html& operator >>(std::string &termino);
    protected:
    private:
};

#endif
