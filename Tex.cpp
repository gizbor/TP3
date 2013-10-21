#include "Tex.h"
#include <iostream>
#include <string>
Tex::~Tex(){
    cerrar();
}

/**
Descripcion: devuelve el siguiente termino del documento latex, ignorando tags.
Retorno: termino
*/
Tex& Tex::operator >>(std::string &termino){
    termino="";
    char c;
    while ((c=this->archivo.get()) && (c==' ' || c=='{' || c=='}' || c=='\n')){
        if (c=='{')
            while ((c=this->archivo.get())!='}') {}
    }
    while (!this->archivo.eof() && c!=' ' && c!='{'){
        termino.push_back(c);
        c=this->archivo.get();
    }
    this->archivo.unget();
return *this;
}

