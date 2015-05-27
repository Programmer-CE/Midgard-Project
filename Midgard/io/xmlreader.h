#include "qstring.h"
#include "logic/xmlconstanst.h"
#ifndef XMLREADER_H
#define XMLREADER_H

/**
 * @brief Clase XMLReader es la clase que se de leer las configuraciones de mapa y
 * de las configuraciones iniciales de clases.
 *
 */
class XMLReader
{
    QString _error;
    static bool **initToDefaultMatrix(int pWidth,int pHeight);
    static void deleteMatrix(bool **pMatrix, int pWidth,int pHeight);
public:
    /**
     * @brief Es el constructor por defecto
     *
     */
    XMLReader();
    /**
     * @brief Es eñ metodo que se encarga de verificar y leer el mapa
     *
     * @param pMapPath es la direccion del archivo
     * @return retorna una matriz de booleanos si la matriz es nula entonces el archivo
     * estaba corrupto o no pudo abrirse
     */
    static bool **readMap(QString pMapPath, XMLConstanst *pXMLconstants);
    /**
     * @brief Verifica es archivo de mapa si esta correcto
     *
     * @param pMapPath es la direccion del archivo
     * @return true si el archivo pasa las pruebas y es valido, false si el archivo
     * es invalido o corrupto
     */
    static bool verifyMapFile(QString pMapPath);
    /**
     * @brief verifica si el archivo de configuracion de las clases iniciales es valido
     *
     * @param pConfigurationPath es la direccion del archivo de configuracion
     * @return true si el archivo es correcto y valido, false si el archivo no lo es
     */
    static bool verifyConfiguration(QString pConfigurationPath);
    /**
     * @brief lee las configuraciones y las transcribe al parametro pXMLconstansts
     *
     * @param pConfigurationPath es la direccion del archivo de consfiguracion
     * @param pXMLconstants es en donde se transcriben las configuraciones del archivo
     * @return true si el archivo pudo leerse y es valido, false si no
     */
    static bool readConfiguration(QString pConfigurationPath, XMLConstanst *pXMLconstants);
    QString error() const;
};

#endif // XMLREADER_H
