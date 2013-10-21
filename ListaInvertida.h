#ifndef LISTAINVERTIDA_H
#define LISTAINVERTIDA_H
#include "General.h"
#include "Elemento.h"
#include "Termino.h"
#include "Documento.h"
#include "Lista.h"
class ListaInvertida : public Elemento
{
    public:
        ListaInvertida();
        virtual ~ListaInvertida();

        void setTermino(Termino& termino){ this->termino=&termino; }
        Termino& getTermino() { return *(this->termino); }
        void addDocumento(Documento& doc);
        Documento* buscarDocumento(t_id_doc idDoc);
        Documento& getDocumento(t_index i);

        int getTamanio() { return this->documentos.getTamanio(); }


        void imprimir();


        bool operator>(Elemento& e);
        bool operator==(Elemento& e);
        bool operator<(Elemento& e);

    protected:
    private:
        Termino* termino;
        Lista documentos;
};

#endif // LISTAINVERTIDA_H
