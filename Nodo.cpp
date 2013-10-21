#include "Nodo.h"
#include <iostream>

Nodo::Nodo()
{
    this->elemento=NULL;
    this->siguiente=NULL;
    this->anterior=NULL;
}

Nodo::~Nodo(){}

/**
Descripcion: verifica la existencia de otro nodo siguiente a este.
Retorno: true encaso de tener uno, false en caso contrario.
*/
bool Nodo::tieneSiguiente(){
return (this->siguiente!=NULL);
}

/**
Descripcion: verifica si el nodo es el primero de la lista.
Retorno: true si es el primero, false en caso contrario.
*/
bool Nodo::esPrimero(){
return (&(this->getAnterior())==NULL);
}
