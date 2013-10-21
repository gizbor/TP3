#ifndef DOCUMENTO_H
#define DOCUMENTO_H
#include <fstream>
#include <iostream>
#include <string>
#include "Elemento.h"
#include "General.h"

#define NO_EXISTE_DOCUMENTO NULL


class Documento: public Elemento
{
    public:
        Documento() {}
        explicit Documento(std::string nombre);
        virtual ~Documento() {}

        /* Getter y Setters */
        void setNombre(std::string nombre) { this->nombre = nombre; }
        std::string getNombre(){ return nombre; }
        t_id_doc getIdDoc() { return this->idDoc; }
        void setIdDoc(t_id_doc idDoc) { this->idDoc= idDoc; }

        /* Métodos generales */
        bool abrir();
        void cerrar();
        void imprimir();
        std::string get_linea();
        void encabezado(int cant_lineas);

        /* Operadores */
        virtual Documento& operator >>(std::string &termino);
        virtual bool operator==(Elemento& e);
        virtual bool operator>(Elemento& e);
        virtual bool operator<(Elemento& e);

    protected:
        std::ifstream archivo;
        std::string nombre;
        t_id_doc idDoc;
    private:
};

#endif // DOCUMENTO_H
