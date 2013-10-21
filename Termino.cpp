#include "Termino.h"
#include <string>
Termino::Termino(){}
Termino::~Termino(){}

/**
Descripcion: setea el termino.
Retorno: -
*/
void Termino::setTermino(std::string termino){
    this->termino=termino;
}

/**
Descripcion: setea el idT.
Retorno: -
*/
void Termino::setIdT(t_id_t idt){
    this->idT=idt;
}

/**
Descripcion: devuelve el idT.
Retorno: idT
*/
t_id_t Termino::getIdT(){
    return this->idT;
}

/**
Descripcion: devuelve el termino.
Retorno: termino
*/
std::string Termino::getTermino(){
    return this->termino;
}

/**
Descripcion: imprime el idT y el termino del Termino.
Retorno: -
*/
void Termino::imprimir(){
    std::cout << "IDT: " << idT << ", Termino: " << termino<< std::endl;
}

/**
Descripcion: compara con otro Termino, basandose en el termino.
Retorno: true en caso de ser mayor, false en caso contrario.
*/
bool Termino::operator>(Elemento& e){
    Termino *t=(Termino*)&e;
return  (this->getTermino() > t->getTermino());
}

/**
Descripcion: compara con otro Termino, basandose en el termino.
Retorno: true en caso de ser igual, false en caso contrario.
*/
bool Termino::operator==(Elemento& e){
    Termino *t=(Termino*)&e;
return  (this->getTermino() == t->getTermino());
}

/**
Descripcion: compara con otro Termino, basandose en el termino.
Retorno: true en caso de ser menor, false en caso contrario.
*/
bool Termino::operator<(Elemento& e){
    Termino *t=(Termino*)&e;
return  (this->getTermino() < t->getTermino());
}


