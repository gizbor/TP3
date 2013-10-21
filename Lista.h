#ifndef LISTA_H
#define LISTA_H
#include "Elemento.h"
#include "Nodo.h"
#include <iostream>
typedef int t_index;

class Lista {
    public:
        Lista();
        virtual ~Lista();
        t_index add(Elemento& e);
        void addOrdenado(Elemento& e);
        void imprimir();
        Elemento& obtener(t_index index);
        Elemento& siguiente();
        bool haySiguiente();
        void insertar(Elemento& e, t_index pos);
        Nodo& getNodo(t_index index);
        t_index buscarElemento(Elemento& elemento);
        t_index getTamanio();
    protected:
    private:
        Nodo *primero, *ultimo, *actual;
        Nodo& crearNodo(Elemento& e);
        t_index buscar(Elemento& elemento, Nodo* nodo, t_index &ultima_leida);
        int tamanio;
};

#endif // LISTA_H
