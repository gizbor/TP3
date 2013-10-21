#ifndef NODO_H
#define NODO_H
#include "Elemento.h"
#include <stdlib.h>

class Nodo
{
    public:
        Nodo();
        virtual ~Nodo();

        void setSiguiente(Nodo& s) { this->siguiente= &s; }
        void setAnterior(Nodo& a){ this->anterior = &a; }

        void setDato(Elemento& e) { this->elemento= &e; }
        Elemento& getDato() { return *elemento; }
        Nodo& getSiguiente() { return *siguiente; }
        Nodo& getAnterior(){ return *anterior; }
        bool tieneSiguiente();
        bool esPrimero();
    protected:
    private:
        Nodo* siguiente, *anterior;
        Elemento *elemento;
};

#endif // NODO_H
