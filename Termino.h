#ifndef TERMINO_H
#define TERMINO_H
#include "Elemento.h"
#include <string>
#include <iostream>
#include "General.h"



class Termino: public Elemento
{
    public:
        Termino();
        virtual ~Termino();
        void setTermino(std::string termino);
        void setIdT(t_id_t idt);
        t_id_t getIdT();
        std::string getTermino();

        void imprimir();



        bool operator>(Elemento& e);
        bool operator==(Elemento& e);
        bool operator<(Elemento& e);

    protected:
    private:
        std::string termino;
        unsigned int idT;
};

#endif // TERMINO_H
