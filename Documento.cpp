#include "Documento.h"
#include <string>

/**
Descripcion: obtiene termino del documento dependiendo del
tipo de documento (metodo virtual)
Retorno: termino
*/
Documento& Documento::operator>>(std::string& termino){
    this->archivo >> termino;
return *this;
}

Documento::Documento(std::string nombre){
    this->nombre=nombre;
}

/**
Descripcion: imprime nombre y el idDoc
Retorno: -
*/
void Documento::imprimir(){
    std::cout << "Nombre: " << nombre << ", IdDoc: " << idDoc << std::endl;
}

/**
Descripcion: devuelve una linea del documentoterminada en '\n'.
Retorno: linea
*/
std::string Documento::get_linea(){
    char c;
    std::string linea="";

    while (!this->archivo.eof() && (c=this->archivo.get())
                    && c != '\n' && c!=-1)
        linea.push_back(c);
return linea;
}

/**
Descripcion: devuelve las primeras "cant_lineas" del documento o
todas en caso de no llegar a esa cantidad.
Retorno: -
*/
void Documento::encabezado(int cant_lineas){
    int i=0;
    std::string linea;
    archivo.clear();
    archivo.seekg(0, archivo.beg);
    while (i++<cant_lineas && (linea=get_linea())!="")
        std::cout << linea << std::endl;
}

/**
Descripcion: abre el archivo.
Retorno: true en caso de exito, false en caso contrario.
*/
bool Documento::abrir(){
   archivo.open(nombre.c_str());
   if (!archivo.good())
    return false;
return true;
}

/**
Descripcion: cierra el archivo en caso de estar abierto.
Retorno: -
*/
void Documento::cerrar(){
    if (archivo.is_open()) archivo.close();
}

/**
Descripcion: compara con documento en funcion de idDoc.
Retorno: true en caso de ser mayor, false en caso contrario.
*/
bool Documento::operator>(Elemento& e){
    Documento* o=(Documento*)&e;
    t_id_doc idDoc1=this->getIdDoc(), idDoc2=o->getIdDoc();
    return (idDoc1 > idDoc2);
}

/**
Descripcion: compara con documento en funcion de idDoc.
Retorno: true en caso de ser iguales, false en caso contrario.
*/
bool Documento::operator==(Elemento& e) {
    Documento* o=(Documento*)&e;
    t_id_doc idDoc1=this->getIdDoc(), idDoc2=o->getIdDoc();
    return (idDoc1 == idDoc2);
}
/**
Descripcion: compara con documento en funcion de idDoc.
Retorno: true en caso de ser menor, false en caso contrario.
*/
bool Documento::operator<(Elemento& e) {
    Documento* o=(Documento*)&e;
    t_id_doc idDoc1=this->getIdDoc(), idDoc2=o->getIdDoc();
    return (idDoc1 < idDoc2);
}
