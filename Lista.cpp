#include "Lista.h"
#include <stdlib.h>
#include <iostream>


Lista::Lista(){
    this->primero=NULL;
    this->ultimo=NULL;
    this->actual=NULL;
    this->tamanio= 0;
}

Lista::~Lista(){
    Nodo* nodo= this->primero, *sig;
    while (nodo!= NULL){
        sig=&(nodo->getSiguiente());
        delete nodo;
        nodo=sig;
    }
}

t_index Lista::add(Elemento& e){
    Nodo& nodo= crearNodo(e);
    if (this->primero == NULL){
        this->primero = &nodo;
        this->ultimo = &nodo;
     } else {
       nodo.setAnterior(*(this->ultimo));
       this->ultimo->setSiguiente(nodo);
       this->ultimo = &nodo;
     }
    this->tamanio++;
return this->tamanio-1;
}

/**
Descripcion: agrega ordenado el elemento pasado por parametro a la lista.
Retorno: -
*/
void Lista::addOrdenado(Elemento& e){
  Nodo* nodo=NULL;
  t_index pos_a_insertar=0;
  buscar(e, nodo, pos_a_insertar);
  if (pos_a_insertar==this->tamanio)
    this->add(e);
   else
    insertar(e, pos_a_insertar);
}

/**
Descripcion: realiza una busqueda binaria en la lista del elemento.
PRE: los elementos de la lista debieron ser agregados ordenados con
el metodo addOrdenado.
Retorno: retorna la posicion del elemento o -1 en caso de no existir.
En caso de no existir devuelve en la referencia "insertion_pos" la
posicion donde debe insertarse el elemento.
*/
t_index Lista::buscar(Elemento& elemento, Nodo* nodo, t_index &insertion_pos){
  t_index arriba = this->tamanio-1;
  t_index abajo = 0;
  t_index centro=0;
  Nodo *_nodo=NULL;
  Elemento* elem=NULL;
  t_index element_pos=-1;
  bool mayor=false;
  while (abajo <= arriba && element_pos==-1){
      centro = (arriba + abajo)/2;
      _nodo=&getNodo(centro);
      elem=&(_nodo->getDato());
      if (*elem == elemento){
        nodo=_nodo;
        element_pos= centro;
      } else {
        mayor=false;
      }
        if (elemento < _nodo->getDato()){
            arriba=centro-1;
        } else {
            abajo=centro+1;
            mayor=true;
        }
    }
    insertion_pos=centro;
    if (mayor && element_pos==-1)
        insertion_pos++;

return element_pos;
}

/**
Descripcion: retorna la cantidad de elementos almacenados.
Retorno: -
*/
t_index Lista::getTamanio(){
    return this->tamanio;
}

/**
Descripcion: busca el elemento pasado por parametro.
PRE: el elemento debe tener seteados los atributos necesarios
para su comparacion.
Retorno: la posicion del elemento.
*/
t_index Lista::buscarElemento(Elemento& elemento){
    t_index i, pos;
    Nodo* pnodo=NULL;
    pos=buscar(elemento, pnodo, i);
return pos;
}

/**
Descripcion: inserta el elemento e en la posicion pos desplazando hacia
adelante el elemento que esta ubicado en esa posicion.
Retorno: en caso de pasar por parametro una posicion inexistente lanza
una excepcion.
*/
void Lista::insertar(Elemento& e, t_index pos){
    Nodo *viejo;
    if (tamanio==0){
        add(e);
        return;
    }
    if (pos<=tamanio-1){
        Nodo& nuevo=crearNodo(e);
        viejo=&getNodo(pos);
        if (pos!=0){
            nuevo.setAnterior(viejo->getAnterior());
            viejo->setAnterior(nuevo);
            nuevo.setSiguiente(*viejo);
            nuevo.getAnterior().setSiguiente(nuevo);
        } else {
            viejo->setAnterior(nuevo);
            nuevo.setSiguiente(*viejo);
            this->primero=&nuevo;
        }
        this->tamanio++;
    } else {
        throw "Posicion invalida";
    }
}

/**
Descripcion: devuelve el nodo ubicado en la posicion "index".
Retorno: referencia al nodo o lanza excepcion encaso de que
"index" sea una posicion inexistente.
*/
Nodo& Lista::getNodo(t_index index){
    int i;
    Nodo* nodo= this->primero;
    if (index <= this->tamanio-1){
        for (i=0; i< index; i++)
            nodo=&(nodo->getSiguiente());
    } else {
        throw "Error: elemento inexistente!";
    }
return *nodo;
}

/**
Descripcion: imprime los elementos de la lista llamando a su
metodo imprimir().
Retorno: -
*/
void Lista::imprimir(){
    int i;
    Elemento* e;
    for (i=0; i<tamanio; i++){
        std::cout << i << "> ";
        e=&obtener(i);
        e->imprimir();
    }
}

/**
Descripcion: Devuelve el elemento ubicado en la posicion "index".
Puede usarse junto con siguiente() para obtener un recorrido mas
eficiente (evitando recorrer todos los nodos previos al consultado).
PRE: "index" debe ser una posicion valida.
Retorno: referencia al elemento.
*/
Elemento& Lista::obtener(t_index index){
    this->actual=&getNodo(index);
return this->actual->getDato();
}

/**
Descripcion: devuelve referencia al elemento siguiente al consultado
anteriormente.
PRE: debe verificarse mediante tieneSiguiente() la existencia de otro
elemento.
Retorno: referencia al elemento. Si no hay elemento siguiente se lanza
una excepcion.
*/
Elemento& Lista::siguiente(){
    if (!this->actual->tieneSiguiente())
        throw "No hay mas elementos!";

    Nodo& nodo=this->actual->getSiguiente();
    this->actual=&nodo;
return nodo.getDato();
}

/**
Descripcion: verifica si hay otro elemento siguiente al anterior consultado.
Retorno: true en caso de haber otro elemento, false en caso contrario.
*/
bool Lista::haySiguiente(){
  return (this->actual->tieneSiguiente());
}

/**
Descripcion: instancia un objeto Nodo con el elemento pasado por parametro.
Retorno: referencia al nodo instanciado.
*/
Nodo& Lista::crearNodo(Elemento& e){
    Nodo* nodo=new Nodo();
    nodo->setDato(e);
return *nodo;
}

