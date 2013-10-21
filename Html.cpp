#include "Html.h"
#include <string>


Html::~Html(){
    cerrar();
}

/**
Descripcion: devuelve el siguiente termino del documento html, ignorando tags.
Retorno: termino
*/
Html& Html::operator >>(std::string &termino){
    termino="";
    char c;
    while ((c=this->archivo.get()) && (c==' ' || c=='<' || c=='>' || c=='\n')){
        if (c=='<')
            while ((c=this->archivo.get())!='>') {}
    }
    while (!this->archivo.eof() && c!=' ' && c!='<'){
        termino.push_back(c);
        c=this->archivo.get();
    }
    this->archivo.unget();
return *this;
}
