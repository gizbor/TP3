#ifndef OCURRENCIA_H
#define OCURRENCIA_H

#include "Elemento.h"
#include "Documento.h"
#include "Termino.h"
#include "General.h"
#include <iostream>

class Ocurrencia : public Elemento
{
    public:
        Ocurrencia() {}
        Ocurrencia(Termino& t, Documento& d);
        virtual ~Ocurrencia();

        Termino& getTermino() { return *(this->termino); }
        Documento& getDocumento() { return *(this->documento); }
        void setTermino(Termino& t) { this->termino=&t; }
        void setDocumento(Documento& d) { this->documento=&d; }

        void imprimir();

        bool operator>(Elemento& e);
        bool operator==(Elemento& e);
        bool operator<(Elemento& e);

    protected:
    private:
        Documento* documento;
        Termino*  termino;
};

#endif // OCURRENCIA_H
