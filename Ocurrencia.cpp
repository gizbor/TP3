#include "Ocurrencia.h"

Ocurrencia::Ocurrencia(Termino& t, Documento& d){
       this->documento=&d;
       this->termino=&t;
}

Ocurrencia::~Ocurrencia(){
     delete this->termino;
}

/**
Descripcion: imprime el idDoc y el idT de la ocurrencia.
Retorno: -
*/
void Ocurrencia::imprimir(){
   std::cout << "IdDoc: " << documento->getIdDoc() << ", IdT: "
   << termino->getIdT() << std::endl;
}

/**
Descripcion: compara con otra ocurrencia.
Retorno: true en caso de ser mayor, false en caso contrario.
*/
bool Ocurrencia::operator>(Elemento& e){
    Ocurrencia* o=(Ocurrencia*)&e;
    t_id_doc idDoc1=this->documento->getIdDoc(),
                  idDoc2=o->getDocumento().getIdDoc();
    t_id_t idT1= this->getTermino().getIdT(),
              idT2=o->getTermino().getIdT();
    return ((idT1 > idT2) || (idT1 == idT2  && idDoc1 > idDoc2));
}

/**
Descripcion: compara con otra ocurrencia.
Retorno: true en caso de ser igual, false en caso contrario.
*/
bool Ocurrencia::operator==(Elemento& e) {
    Ocurrencia* o=(Ocurrencia*)&e;
    t_id_doc idDoc1=this->documento->getIdDoc(),
                  idDoc2=o->getDocumento().getIdDoc();
    t_id_t idT1= this->getTermino().getIdT(),
              idT2=o->getTermino().getIdT();
    return ((idDoc1 == idDoc2) && (idT1 == idT2));
}

/**
Descripcion: compara con otra ocurrencia.
Retorno: true en caso de ser menor, false en caso contrario.
*/
bool Ocurrencia::operator<(Elemento& e) {
    Ocurrencia* o=(Ocurrencia*)&e;
    t_id_doc idDoc1=this->documento->getIdDoc(),
                  idDoc2=o->getDocumento().getIdDoc();
    t_id_t idT1= this->getTermino().getIdT(),
              idT2=o->getTermino().getIdT();
    return ((idT1 < idT2) || (idT1 == idT2 && idDoc1 < idDoc2));
}

