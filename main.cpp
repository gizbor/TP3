#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "ModoPresentacion.h"
#include "ModoCompleto.h"
#include "ModoResumen.h"
#include "funciones.h"
#include "Documento.h"
#include "IndiceInvertido.h"
#include "Lista.h"
#include "Ocurrencia.h"
#define ERROR_ARCH_CONSULTAS 1
#define ERROR_FALTA_PARAMENTRO 2

int main(int argc, char** argv){
        char* archivos_indexado;
        std::string nombre, consulta;
        std::ifstream *f_consultas=NULL, f_indexar;
        int i, error;

        i=1, error=0;
        bool modo_seteado=false, consultas_por_param=false;
        bool archivos_a_indexar=false;
        ModoPresentacion* modo_presentacion=NULL;
        while (i<argc-1 && error==0){
            if (strcmp(argv[i], "-m")==0){
               if (strcmp(argv[i+1], MODO_RESUMEN)==0){
                 modo_seteado=true;
                 modo_presentacion= new ModoResumen();
               }
            } else if (strcmp(argv[i], "-q")==0){
                consultas_por_param=true;
                f_consultas=new std::ifstream();
                f_consultas->open(argv[i+1]);
                if (!f_consultas->good())
                    error= ERROR_ARCH_CONSULTAS;
            } else if (strcmp(argv[i], "-d")==0){
                archivos_a_indexar=true;
                archivos_indexado=argv[i+1];
            }
        i+=2;
        }

        if (error==0){
                if (!archivos_a_indexar)
                    error= ERROR_FALTA_PARAMENTRO;
                if (error== 0){
                        if (!modo_seteado)
                            modo_presentacion=new ModoCompleto();
                        if (!consultas_por_param)
                            f_consultas= (std::ifstream*)&std::cin;

                        IndiceInvertido indice(*modo_presentacion);

                        while ((nombre=get_nombre(archivos_indexado))!=""){
                             indice.procesarDocumento(nombre);
                        }
                        indice.crearListas();

                        while ((consulta=getConsulta(*f_consultas))!="")
                            indice.consultar(consulta);
                }
        }

       delete modo_presentacion;
       if (consultas_por_param){
          f_consultas->close();
          delete f_consultas;
       }

return error;
}

