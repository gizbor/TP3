#include "Txt.h"
#include <string>
Txt::~Txt(){
    cerrar();
}

/**
Descripcion: devuelve el siguiente termino del documento de texto plano.
Retorno: termino
*/
Txt& Txt::operator >>(std::string &termino){
    termino="";
    char c;
    while (!archivo.eof() && (c=archivo.get())!=' ' && c!='\n' && (int)c!=-1){
        termino.push_back(c);
    }
return *this;
}
