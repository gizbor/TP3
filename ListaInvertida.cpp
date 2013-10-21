#include "ListaInvertida.h"

ListaInvertida::ListaInvertida(){}
ListaInvertida::~ListaInvertida(){}

void ListaInvertida::imprimir(){
    std::cout << "> Lista: "  << std::endl;
    this->getTermino().imprimir();
    std::cout << "--> Documentos:" << std::endl;
    int i;
    for (i=0; i<this->documentos.getTamanio(); i++)
        this->documentos.obtener(i).imprimir();
}

void ListaInvertida::addDocumento(Documento& doc){
    documentos.addOrdenado(doc);
}

Documento* ListaInvertida::buscarDocumento(t_id_doc idDoc){
    Documento doc;
    doc.setIdDoc(idDoc);
    t_index pos=documentos.buscarElemento(doc);
    if (pos != -1)
        return (Documento*)&(documentos.obtener(pos));
    else
        return NO_EXISTE_DOCUMENTO;
return 0;
}

Documento& ListaInvertida::getDocumento(t_index index){
return *((Documento*)&(documentos.obtener(index)));
}

bool ListaInvertida::operator>(Elemento& e){
    ListaInvertida* o=(ListaInvertida*)&e;
    t_id_t idT1= this->getTermino().getIdT(), idT2=o->getTermino().getIdT();
    return (idT1 > idT2);
}

bool ListaInvertida::operator==(Elemento& e) {
    ListaInvertida* o=(ListaInvertida*)&e;
    t_id_t idT1= this->getTermino().getIdT(), idT2=o->getTermino().getIdT();
    return (idT1 == idT2);
}

bool ListaInvertida::operator<(Elemento& e) {
    ListaInvertida* o=(ListaInvertida*)&e;
    t_id_t idT1= this->getTermino().getIdT(), idT2=o->getTermino().getIdT();
    return (idT1 < idT2);
}
