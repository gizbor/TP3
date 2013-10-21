#include "funciones.h"
#include "General.h"
#include <fstream>
#include <string>
/* Funciones de uso general */
/**
Descripcion: recibe una cadena de caracteres con nombres de archivo
y retorna el siguiente al anterior consultado.
Retorno: nombre de archivo.
*/
std::string get_nombre(char* &nombres){
    char nombre[MAX_LONG_NOMBRE_ARCHIVO]="";
    int i=0;
    while (*nombres!=',' && *nombres!='\0')
        *(nombre+i++)=*(nombres++);

    *(nombre+i)='\0';
    if (*nombres!='\0') nombres++;
return std::string(nombre);
}

/**
Descripcion: recibe archivo con consultas y devuelve la siguiente
al anterior consultado.
Retorno: consulta
*/
std::string getConsulta(std::ifstream& archivo){
    char c;
    std::string consulta="";
    while (!archivo.eof() && archivo.get(c) && c != '\n')
        consulta.push_back(c);
return consulta;
}
