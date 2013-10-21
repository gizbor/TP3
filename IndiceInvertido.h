#ifndef INDICEINVERTIDO_H
#define INDICEINVERTIDO_H
#include "Documento.h"
#include "ModoPresentacion.h"
#include <algorithm>
#include <sstream>
#include <string>
#include "Lista.h"
#include "Ocurrencia.h"
#include "Termino.h"
#include "ListaInvertida.h"
class IndiceInvertido
{
    public:
        explicit IndiceInvertido(ModoPresentacion& modo) {
            setModoPresentacion(modo);
        }
        virtual ~IndiceInvertido();

        int procesarDocumento(std::string nombre_archivo);
        Documento* abrirDocumento(std::string nombre_archivo);
        void setModoPresentacion(ModoPresentacion& modo)
                        { this->modo_presentacion=&modo; }
        void crearListas();
        int consultar(std::string consulta);
        void cerrar_documentos();
        void imprimirResultado(Lista& documentos_consulta);

    protected:
    private:
        Lista ocurrencias, diccionario, documentos;
        Lista listas_invertidas;
        ModoPresentacion* modo_presentacion;
        void agregarOcurrencia(Ocurrencia& o);
        t_id_t getIdT(Termino& termino);
        void interseccion(Lista& listas_invertidas, Lista& documentos);
        t_id_doc getIdDoc(Documento& doc);
        std::string normalizar(std::string data);
        bool es_txt(std::string nombre);
        bool es_tex(std::string nombre);
        bool es_html(std::string nombre);
};

#endif // INDICEINVERTIDO_H
