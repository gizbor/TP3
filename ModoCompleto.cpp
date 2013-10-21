#include "ModoCompleto.h"

ModoCompleto::ModoCompleto(){}
ModoCompleto::~ModoCompleto(){}

/**
Descripcion: imprime el nombre del archivo seguido de sus primeras
4 lineas.
Retorno: -
*/
void ModoCompleto::imprimir(Lista& documentos){
    Documento* doc;
    int i;

    for (i=0; i < documentos.getTamanio(); i++){
       doc=(Documento*)&(documentos.obtener(i));
       std::cout << doc->getNombre() << std::endl;
       doc->encabezado(4);
    }
}
