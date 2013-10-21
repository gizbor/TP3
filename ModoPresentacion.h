#ifndef MODOPRESENTACION_H
#define MODOPRESENTACION_H
#include "Documento.h"
#include "Lista.h"
class ModoPresentacion
{
    public:
        ModoPresentacion();
        virtual ~ModoPresentacion();
        virtual void imprimir(Lista& documentos) {}

    protected:
    private:
};

#endif // MODOPRESENTACION_H
