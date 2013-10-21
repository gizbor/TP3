#ifndef MODORESUMEN_H
#define MODORESUMEN_H

#include "ModoPresentacion.h"


class ModoResumen : public ModoPresentacion
{
    public:
        ModoResumen();
        virtual ~ModoResumen();
        void imprimir(Lista& documentos);
    protected:
    private:
};

#endif // MODORESUMEN_H
