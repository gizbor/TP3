#include "IndiceInvertido.h"
#include <string>
#include <algorithm>
#include "Tex.h"
#include "Html.h"
#include "Txt.h"


IndiceInvertido::~IndiceInvertido(){
    int i;
    ListaInvertida* p_l_inv=NULL;
    Ocurrencia* p_ocurrencia=NULL;
    Documento* p_documento=NULL;
    this->cerrar_documentos();
    for (i=0; i<this->listas_invertidas.getTamanio(); i++){
        p_l_inv=(ListaInvertida*)&(this->listas_invertidas.obtener(i));
        delete p_l_inv;
    }

    for (i=0; i<this->ocurrencias.getTamanio(); i++){
        p_ocurrencia=(Ocurrencia*)&(this->ocurrencias.obtener(i));
        delete p_ocurrencia;
    }

    for (i=0; i<this->documentos.getTamanio(); i++){
        p_documento=(Documento*)&(this->documentos.obtener(i));
        delete p_documento;
    }
}

/**
Descripcion: abre el archivo a indexar pasado por parametro.
Retorno: puntero al handler del documento que ha sido abierto
o NULL en caso de error.
*/
Documento* IndiceInvertido::abrirDocumento(std::string nombre_archivo){
            Documento* p_documento=NULL;
            if (es_tex(nombre_archivo)){
                p_documento= new Tex(nombre_archivo);
            } else if (es_txt(nombre_archivo)){
                p_documento= new Txt(nombre_archivo);
            } else if (es_html(nombre_archivo)){
                p_documento= new Html(nombre_archivo);
            }

            if (p_documento==NULL){
             std::cerr << "Error al parsear archivo: " << nombre_archivo
                           << std::endl;
             return NULL;
            } else {
                if (!p_documento->abrir()){
                    std::cerr << "Error al parsear archivo: " <<
                    p_documento->getNombre() << std::endl;
                    delete p_documento;
                    return NULL;
                }
            }
return p_documento;
}

/**
Descripcion: agrega al indice las ocurrencias de los terminos contenidos
en el archivo a indexar pasado por parametro. En caso de contener terminos
inexistentes, los agrega al diccionario interno. Una vez procesados todos
los archivos se debe llamar a "crearListas()" para finalizar el indice.
Retorno: devuelve -1 en caso de error al procesar el archivo o 0 en caso
contrario.
*/
int IndiceInvertido::procesarDocumento(std::string nombre_archivo){
    std::string termino, termino_normalizado;
    t_id_t idT;
    Termino* otermino=NULL;
    Ocurrencia* ocurrencia=NULL;
    Documento* p_documento= abrirDocumento(nombre_archivo);

    if (MODO_DEBUG==1)
        std::cout << "Indexando: " << nombre_archivo << std::endl;

    if (p_documento==NULL)
        return -1;

    Documento& documento=*p_documento;
    documento >> termino;
    getIdDoc(documento);

    while (termino!=""){
        otermino=new Termino();
        termino_normalizado=normalizar(termino);
        otermino->setTermino(termino_normalizado);
        idT= this->getIdT(*otermino);
        otermino->setIdT(idT);
        ocurrencia= new Ocurrencia(*otermino, documento);
        agregarOcurrencia(*ocurrencia);
       documento >> termino;
    }
    if (MODO_DEBUG==1){
        std::cout << std::endl << ">> Archivo procesado >> " <<
         documento.getNombre() << std::endl;
        std::cout << "> Diccionario: " << std::endl;
        diccionario.imprimir();
        std::cout << "> Ocurrencias.: " << std::endl;
        ocurrencias.imprimir();
    }
return 0;
}

/**
Descripcion: normaliza el termino pasado por parametro. Lo
convierte a minusculas.
Retorno: cadena de caracteres en minusculas.
*/
std::string IndiceInvertido::normalizar(std::string data){
    transform(data.begin(), data.end(), data.begin(), ::tolower);
return data;
}

/**
Descripcion: cierra todos los documentos procesados.
Retorno: -
*/
void IndiceInvertido::cerrar_documentos(){
    int i;
    Documento* doc;
    for (i=0; i<documentos.getTamanio(); i++){
        doc=(Documento*)&(documentos.obtener(i));
        if (MODO_DEBUG==1){
            std::cout << "Cerrando Documento: ";
            doc->imprimir();
        }
        doc->cerrar();
    }
}

/**
Descripcion: obtiene el identificados "idT" del termino pasado por
parametro. En caso de no existir lo agrega al diccionario con un
identificador.
PRE: el objeto Termino pasado por parametro debe tener seteado
el atributo "termino" previamente.
Retorno: idT del termino.
*/
t_id_t IndiceInvertido::getIdT(Termino& otermino){
    t_index pos=diccionario.buscarElemento(otermino);
    t_id_t idT;
    if (pos==-1){
        idT=diccionario.getTamanio();
        otermino.setIdT(idT);
        diccionario.addOrdenado(otermino);
    } else {
        idT=((Termino*)&diccionario.obtener(pos))->getIdT();
    }

return idT;
}

/**
Descripcion: agrega a los archivos procesados el documento
pasado por parametro.
Retorno: identificador interno asociado al documento.
*/
t_id_doc IndiceInvertido::getIdDoc(Documento& doc){
    doc.setIdDoc(this->documentos.add(doc));
return doc.getIdDoc();
}

/**
Descripcion: agrega ocurrencia ordenada al indice.
Retorno: -
*/
void IndiceInvertido::agregarOcurrencia(Ocurrencia& o){
    ocurrencias.addOrdenado(o);
}

/**
Descripcion: recorre todas las ocurrencias procesadas al momento
de llamarla (por medio de procesarDocumento) y crea las listas
invertidas de cada termino.
Retorno: -
*/
void IndiceInvertido::crearListas(){
    Ocurrencia* p_ocurrencia=NULL;
    ListaInvertida* lista_invertida= NULL;
    t_index nro_ocurrencia;
    t_id_t idT;
    t_id_doc idDoc;
    t_index tamanio;

    tamanio=ocurrencias.getTamanio();
    if (tamanio > 0){
        nro_ocurrencia=1;
        p_ocurrencia= (Ocurrencia*)&(ocurrencias.obtener(0));

        bool fin=false;
        do {
            lista_invertida= new ListaInvertida();
            lista_invertida->setTermino(p_ocurrencia->getTermino());

            idT= p_ocurrencia->getTermino().getIdT();
            while ((nro_ocurrencia<=ocurrencias.getTamanio() &&
                        p_ocurrencia->getTermino().getIdT()==idT && !fin)){
                idDoc= p_ocurrencia->getDocumento().getIdDoc();
                lista_invertida->addDocumento(p_ocurrencia->getDocumento());
                if (nro_ocurrencia==ocurrencias.getTamanio())
                    fin=true;

                while (nro_ocurrencia<ocurrencias.getTamanio() &&
                            p_ocurrencia->getDocumento().getIdDoc()==idDoc &&
                            p_ocurrencia->getTermino().getIdT()==idT){
                      p_ocurrencia= (Ocurrencia*)&(ocurrencias.siguiente());
                      nro_ocurrencia++;
                }
            }
            if (MODO_DEBUG==1)
                lista_invertida->imprimir();

            this->listas_invertidas.add(*lista_invertida);
        } while (nro_ocurrencia<=ocurrencias.getTamanio() && !fin);
    }
}

/**
Descripcion: imprime por pantalla el resultado de la consulta
pasada por parametro. El formato responde al modo de
presentacion seteado en el indice (resumen o completo).
Retorno: 1 si no se hallaron coincidencias o 0 en caso contrario.
*/
int IndiceInvertido::consultar(std::string consulta){
   std::string termino;
   std::stringstream q;
   Termino otermino, *p_termino;
   ListaInvertida lista_invertida, *p_l_inv;
   Lista listas_invertidas_consulta, documentos_consulta;

   int i;

    if (MODO_DEBUG==1){
            std::cout << "<< << Documentos indexados >>>> " << std::endl;
            for (i=0; i<this->documentos.getTamanio(); i++)
                ((Documento*)&(this->documentos.obtener(i)))->imprimir();
            std::cout << "<<<< Listas invertidas >>>> " << std::endl;
            for (i=0; i<this->listas_invertidas.getTamanio(); i++)
                ((ListaInvertida*)&(this->listas_invertidas.obtener(i)))
                    ->imprimir();
    }
        std::cout << "busqueda:\"" << consulta << "\"" << std::endl;

        q << normalizar(consulta);

        while (q >> termino){
            otermino.setTermino(termino);
            t_index pos=this->diccionario.buscarElemento(otermino);
            if (pos!=-1){
                p_termino=(Termino*)&(this->diccionario.obtener(pos));
                lista_invertida.setTermino(*p_termino);
                pos= this->listas_invertidas.buscarElemento(lista_invertida);
                if (pos != -1){
                    p_l_inv=((ListaInvertida*)
                                    &(this->listas_invertidas.obtener(pos)));
                    listas_invertidas_consulta.add(*p_l_inv);
                }
            }
        }
        if (listas_invertidas_consulta.getTamanio()>0){
            this->interseccion(listas_invertidas_consulta, documentos_consulta);
        } else {
            return 1;
        }

        this->imprimirResultado(documentos_consulta);
return 0;
}

/**
Descripcion: imprime los documentos contenidos en la lista pasada
por parametro de acuerdo al modo de presentacion.
Retorno: -
*/
void IndiceInvertido::imprimirResultado(Lista& documentos_consulta){
    this->modo_presentacion->imprimir(documentos_consulta);
}

/**
Descripcion: realiza la interseccion de los documentos de las listas
pasada por parametro.
Retorno: documentos que estan en todas las listas invertidas
agregadas a la lista referenciada en el 2do. parametro.
*/
void IndiceInvertido::interseccion(Lista& listas_invertidas_consulta,
                                            Lista& documentos){
    t_index i,j;
    ListaInvertida* primer_lista, *p_l_inv;
    Documento* doc, *_doc;
    bool tienen_termino;
    primer_lista= (ListaInvertida*)&(listas_invertidas_consulta.obtener(0));
    for (i=0; i<primer_lista->getTamanio(); i++){
            doc=&(primer_lista->getDocumento(i));
            tienen_termino=true;
            for (j=1; j<listas_invertidas_consulta.getTamanio(); j++){
                p_l_inv= (ListaInvertida*)
                                &(listas_invertidas_consulta.obtener(j));
                _doc= p_l_inv->buscarDocumento(doc->getIdDoc());
                if (_doc==NO_EXISTE_DOCUMENTO)
                    tienen_termino=false;
            }
            if (tienen_termino)
                documentos.add(*doc);
    }
}
/**
Descripcion: evalua el formato del nombre de archivo pasado
por parametro basado en su extension.
Retorno: true en caso de ser texto plano, false en caso contrario.
*/
bool IndiceInvertido::es_txt(std::string nombre){
    return (nombre.substr(nombre.length()-4, 4) == ".txt");
}

/**
Descripcion: evalua el formato del nombre de archivo pasado
por parametro basado en su extension.
Retorno: true en caso de ser Latex, false en caso contrario.
*/
bool IndiceInvertido::es_tex(std::string nombre){
    return (nombre.substr(nombre.length()-4, 4) == ".tex");
}

/**
Descripcion: evalua el formato del nombre de archivo pasado
por parametro basado en su extension.
Retorno: true en caso de ser HTML, false en caso contrario.
*/
bool IndiceInvertido::es_html(std::string nombre){
    return (nombre.substr(nombre.length()-5, 5) == ".html");
}


