#ifndef MODOCOMPLETO_H
#define MODOCOMPLETO_H

#include "ModoPresentacion.h"


class ModoCompleto : public ModoPresentacion
{
    public:
        ModoCompleto();
        virtual ~ModoCompleto();
        void imprimir(Lista& documentos);
    protected:
    private:
};

#endif // MODOCOMPLETO_H
