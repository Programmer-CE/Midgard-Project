#include "xmlreader.h"

#include <QDomElement>
#include <QtXmlPatterns/QXmlSchema>
#include <QtXmlPatterns/QXmlSchemaValidator>
#include <QtXml/QtXml>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <QtXml/QtXml>
#include <QtXmlPatterns/QAbstractUriResolver>


QString XMLReader::error() const
{
    return _error;
}


XMLReader::XMLReader()
{
}

bool **XMLReader::readMap(QString pMapPath, XMLConstanst *pXMLconstants)
{
    QFile file(pMapPath);
    QFile filescheme(":/schema/esquema.xsd");
    QXmlSchema schema;
    QDomDocument qdd;
    QString nametmp;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return 0;
    }
    else{
        if (!filescheme.open(QIODevice::ReadOnly | QIODevice::Text)){
            return 0;
        }
        else{
            schema.load(&filescheme);
            if ( schema.isValid() ) {
                QXmlSchemaValidator validator(schema);
                if ( validator.validate(QUrl::fromLocalFile(pMapPath))) {
                    if (!qdd.setContent(&file)){
                        return 0;
                    }
                    else{
                        QDomElement root = qdd.firstChildElement();
                        nametmp = root.attributes().namedItem("name").nodeValue();
                        QString s;
                        QVariant qv;
                        QDomNodeList node = root.elementsByTagName("row");
                        int width = root.attributes().namedItem("width").nodeValue().toInt();
                        int height = root.attributes().namedItem("height").nodeValue().toInt();
                        bool **xmlMap = initToDefaultMatrix(height,width);
                        bool error = false;
                        for (int x = 0; x < height; x++){
                            s =node.at(x).attributes().item(0).nodeValue();
                            if (s.size() == width){
                                for (int y = 0; y < s.size(); y++){
                                    if (s.at(y) == QChar('0')){
                                        xmlMap[y][x] = false;
                                    }
                                    else{
                                        xmlMap[y][x] = true;
                                    }
                                }
                            }
                            else{
                                error = 0;
                                break;
                            }
                        }
                        if (!error){
                            pXMLconstants->setNameOfMap(nametmp);
                            pXMLconstants->setMapHeight(height);
                            pXMLconstants->setMapWidth(width);
                            return xmlMap;
                        }

                    }
                } else {
                    return 0;
                }
            } else {
                return 0;
            }
        }
    }
    return 0;
}

bool XMLReader::verifyMapFile(QString pMapPath)
{
    bool sucess = true;
    QFile file(pMapPath);
    QFile filescheme(":/schema/esquema.xsd");
    QXmlSchema schema;
    QDomDocument qdd;
    QString nametmp;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        //em.showMessage("error, no se pudo abrir el archivo");
        sucess = false;
    }
    else{
        if (!filescheme.open(QIODevice::ReadOnly | QIODevice::Text)){
            sucess = false;
        }
        else{
            schema.load(&filescheme);
            if ( schema.isValid() ) {
                QXmlSchemaValidator validator( schema );

                if ( validator.validate(QString("file://").append(pMapPath))) {
                    if (!qdd.setContent(&file)){
                        sucess = false;
                    }
                    else{
                        QDomElement root = qdd.firstChildElement();
                        nametmp = root.attributes().namedItem("name").nodeValue();
                        QString s;
                        QVariant qv;
                        QDomNodeList node = root.elementsByTagName("row");
                        int width = root.attributes().namedItem("width").nodeValue().toInt();
                        int height = root.attributes().namedItem("height").nodeValue().toInt();
                        bool **xmlMap = initToDefaultMatrix(height,width);
                        for (int x = 0; x < height; x++){
                            s =node.at(x).attributes().item(0).nodeValue();
                            if (s.size() == width){
                                for (int y = 0; y < s.size(); y++){
                                    if (s.at(y) == QChar('0')){
                                        xmlMap[y][x] = false;
                                    }
                                    else{
                                        xmlMap[y][x] = true;
                                    }
                                }
                            }
                            else{
                                sucess = false;
                                break;
                            }
                        }
                        deleteMatrix(xmlMap,height,width);
                        xmlMap = 0;

                    }
                } else {
                    sucess = false;
                }
            } else {
                sucess = false;
            }
        }
    }
    return sucess;
}


bool **XMLReader::initToDefaultMatrix(int pWidth,int pHeight)
{
    bool **pMatrix = 0;
    pMatrix = new bool*[pHeight];
    for (int x = 0; x < pHeight; x++){
        pMatrix[x] = new bool[pWidth];
        for (int y = 0; y < pWidth; y++){
            pMatrix[x][y] = false;
        }
    }
    return pMatrix;
}

bool XMLReader::verifyConfiguration(QString pConfigurationPath)
{
    bool sucess = true;
    QFile file(pConfigurationPath);
    QFile filescheme(":/schema/configscheme.xsd");
    QXmlSchema schema;
    QDomDocument qdd;
    if (file.exists())std::cout << "the file exist" << std::endl;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        //em.showMessage("error, no se pudo abrir el archivo");
        sucess = false;
    }
    else{
        if (!filescheme.open(QIODevice::ReadOnly | QIODevice::Text)){
            sucess = false;
        }
        else{
            std::cout << "cargando esquema" << std::endl;
            schema.load(&filescheme);
            if ( schema.isValid() ) {
                std::cout << "es valido el esquema" << std::endl;
                QXmlSchemaValidator validator( schema );
                if ( validator.validate(QString("file://").append(pConfigurationPath))) {
                    std::cout << "validacion existosa" << std::endl;
                    if (!qdd.setContent(&file)){
                        sucess = false;
                    }
                } else {
                    sucess = false;
                }
            } else {
                std::cout << "es invalido el esquema" << std::endl;
                sucess = false;
            }
        }
    }
    file.close();
    filescheme.close();
    return sucess;
}

bool XMLReader::readConfiguration(QString pConfigurationPath, XMLConstanst *pXMLconstants)
{
    bool sucess = verifyConfiguration(pConfigurationPath);
    if (sucess){
        QFile file(pConfigurationPath);
        QDomDocument qdd;
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        qdd.setContent(&file);
        QDomElement root = qdd.firstChildElement();
        pXMLconstants->setName(root.attribute("name"));
        std::cout << root.attribute("name").toStdString() << std::endl;
        std::cout << root.attribute("initial-poblation").toStdString() <<std::endl;
        pXMLconstants->setInitialPoblation(root.attribute("initial-poblation").toInt());
        pXMLconstants->setBarbarianEddaDuration(root.attribute("years-of-barbarian-age").toInt());
        pXMLconstants->setSuperstitionEddaDuration(root.attribute("years-of-superstition-age").toInt());
        pXMLconstants->setSupremacyEddaDuration(root.attribute("years-of-supremacy-age").toInt());
        pXMLconstants->setScienceEddaDuration(root.attribute("years-of-science-age").toInt());
        pXMLconstants->setUnionEddaDuration(root.attribute("years-of-union-age").toInt());
        std::cout << "barbarian age "<< root.attribute("years-of-barbarian-age").toInt() << std::endl;
        QDomNodeList razas = root.elementsByTagName("class");
        Raza *raza =  0;
        VillagersVerificator *verificator =0 ;
        VillagerFabric *fabric = 0;
        QDomElement xmlRazaElement;
        QDomElement bonoDeRaza;
        QDomNode xmlRazaNode,xmlSubclassNode;
        QDomNodeList xmlSubClassNodeList;
        QDomElement base;
        for (int x = 0; x < razas.length();x++){
            raza = new Raza();
            xmlRazaNode = razas.at(x);
            fabric = new VillagerFabric();
            xmlSubClassNodeList = xmlRazaElement.elementsByTagName("sub-classbound");
            xmlRazaElement = xmlRazaNode.toElement();
            raza->setName(xmlRazaElement.attribute("name"));
            std::cout << "raza name is: " << xmlRazaElement.attribute("name").toStdString() << std::endl;
            base = xmlRazaElement.elementsByTagName("classbond").at(0).toElement();

            //lectura de las estadisticas basicas
            fabric->setAttack(base.attribute("atk").toInt());
            std::cout << base.attribute("atk").toInt() << std::endl;
            fabric->setDefense(base.attribute("def").toInt());
            fabric->setBlot(base.attribute("blot").toInt());
            fabric->setIntelligence(base.attribute("int").toInt());
            fabric->setMagic(base.attribute("magic").toInt());
            fabric->setMaximunLife(base.attribute("maximunLife").toInt());
            fabric->setRunes(base.attribute("runes").toInt());
            fabric->setSuperstition(base.attribute("superstition").toInt());
            fabric->setVelocity(base.attribute("vel").toInt());
            fabric->setVitalEnergy(base.attribute("vital-energy").toInt());
            raza->addVillagerFabric(fabric);

            bonoDeRaza = xmlRazaElement.elementsByTagName("important-characteristics").at(0).toElement();
            for (int y=0;y <xmlSubClassNodeList.length();y++){
                verificator = new VillagersVerificator();
                xmlSubclassNode = xmlSubClassNodeList.at(y);
                QDomNode atributes = xmlSubclassNode.attributes().item(x);
                verificator->setAttack(atributes.namedItem("atk").nodeValue().toInt() + bonoDeRaza.attribute("atk").toInt());
                verificator->setDefense(atributes.namedItem("def").nodeValue().toInt()+ bonoDeRaza.attribute("def").toInt());
                verificator->setBlot(atributes.namedItem("blot").nodeValue().toInt()+ bonoDeRaza.attribute("blot").toInt());
                verificator->setIntelligence(atributes.namedItem("int").nodeValue().toInt()+ bonoDeRaza.attribute("int").toInt());
                verificator->setMagic(atributes.namedItem("magic").nodeValue().toInt()+ bonoDeRaza.attribute("magic").toInt());
                verificator->setMaxlife(atributes.namedItem("maximunLife").nodeValue().toInt()+ bonoDeRaza.attribute("maximunLife").toInt());
                verificator->setRune(atributes.namedItem("runes").nodeValue().toInt()+ bonoDeRaza.attribute("runes").toInt());
                verificator->setSuperstition(atributes.namedItem("superstition").nodeValue().toInt()+ bonoDeRaza.attribute("superstition").toInt());
                verificator->setVelocity(atributes.namedItem("vel").nodeValue().toInt()+ bonoDeRaza.attribute("vel").toInt());
                verificator->setVitalEnergy(atributes.namedItem("vital-energy").nodeValue().toInt()+ bonoDeRaza.attribute("vital-energy").toInt());
                raza->addVillagerVerificator(verificator);
            }
            pXMLconstants->addRaza(raza);
        }
    }
    return sucess;
}


void XMLReader::deleteMatrix(bool **pMatrix, int pWidth,int pHeight)
{
    for (int x = 0; x < pHeight; x++){
        delete [] pMatrix[x];
        pMatrix[x] = 0;
    }
    delete [] pMatrix;
}
