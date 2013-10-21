#include "ModoResumen.h"

ModoResumen::ModoResumen(){}
ModoResumen::~ModoResumen(){}

/**
Descripcion: imprime los nombres de los documentos.
Retorno: -
*/
void ModoResumen::imprimir(Lista& documentos){
    Documento* doc;
    int i;
    for (i=0; i < documentos.getTamanio(); i++){
       doc=(Documento*)&(documentos.obtener(i));
       std::cout << doc->getNombre() << std::endl;
    }
}

