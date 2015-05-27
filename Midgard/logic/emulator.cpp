#include "emulator.h"
#include "../io/xmlreader.h"


QString Emulator::getConfigurationPath() const
{
    return configurationPath;
}

void Emulator::setConfigurationPath(const QString &value)
{
    configurationPath = value;
}

QString Emulator::getMapPath() const
{
    return mapPath;
}

void Emulator::setMapPath(const QString &value)
{
    mapPath = value;
}

QString Emulator::getId() const
{
    return id;
}

void Emulator::setId(const QString &value)
{
    id = value;
}

bool Emulator::buildEmulation(int pPort)
{
    _xmlConstants = new XMLConstanst();
    XMLReader::readConfiguration(getConfigurationPath(),_xmlConstants);
    server->openConnection(pPort);
    if (!server->isListened())return false;
    //crear n poblaciones de razas
    //crear m poblaciones de sub clases y correrlas
    map = XMLReader::readMap(getMapPath(),_xmlConstants);
    MidgarDarwin *midgard = 0;
    VillagerCrosser *crosser= 0;
    VillagerFabric *fabric = 0;
    Poblation *_poblation;
    Raza *raza = 0;
    nameOfConfig = _xmlConstants->name();
    nameOfMap = _xmlConstants->nameOfMap();
    for (int x = 0; x < _xmlConstants->getRazaLenght();x++){
        raza = _xmlConstants->getRazaByIndex(x);
        for (int y=0; y < raza->lenghtFabric();y++){
            for (int z = 0; z < raza->lenghtVerificator();z++){
                crosser = new VillagerCrosser();
                fabric = raza->getFrabric(y)->clone();
                crosser->setIndividuousFabric(fabric);
                fabric->setVerificator(raza->getVerificator(z));
                _poblation = new Poblation(true);
                for (int w = 0; w < _xmlConstants->initialPoblation();w++){
                    _poblation->addIndividuous(fabric->create(0));
                }
                midgard = new MidgarDarwin(crosser,&_final,_poblation,_xmlConstants->barbarianEddaDuration());
                _midgardEmulation.add(midgard);
            }
        }
    }
    return true;
    //construye la emulacion, combina las fabricas y los verificadores por cada clase
    // corre el programa cuando se indica en la interfaz
    // incorpora el servidor

}

QString Emulator::getNameOfMap() const
{
    return nameOfMap;
}

void Emulator::setNameOfMap(const QString &value)
{
    nameOfMap = value;
}

QString Emulator::getNameOfConfig() const
{
    return nameOfConfig;
}

void Emulator::setNameOfConfig(const QString &value)
{
    nameOfConfig = value;
}
void Emulator::generatePoblationMessage()
{
    _message= "{\"poblation\":";
    _message.append(" [");
    Poblation * poblation = 0;
    Villager * currentVillager = 0;
    for(int x= 0;x<_midgardEmulation.getLenght();x++){
        poblation = _midgardEmulation.get(x)->getPoblation();
        for (int y = 0; y < poblation->getLenght();y++){
            currentVillager = (Villager*)poblation->getIndividuousByIndex(y);
            _message.append("{\"x\": ");
            _message.append(QVariant(currentVillager->x()).toString().toStdString());
            _message.append(", \"y\": ");
            _message.append(QVariant(currentVillager->y()).toString().toStdString());
            _message.append("},");
        }
    }

    _message.append("] }");
    server->send(_message.c_str());
}

Emulator::Emulator(QObject *parent):QThread(parent)
{
    server = new FServer();
}


bool Emulator::verifyMapDocument(QString ppath)
{
    return XMLReader::verifyMapFile(ppath);
}

bool Emulator::verifyConfigurationDocument(QString ppath)
{
    return XMLReader::verifyConfiguration(ppath);
}

void Emulator::run()
{
    IIterator<MidgarDarwin *> *iterator;
    iterator = _midgardEmulation.getIterator();
    std::cout << "barbarian: " << _xmlConstants->barbarianEddaDuration() << std::endl;
    for(int years=0;years < _xmlConstants->barbarianEddaDuration(); years++){
        iterator = _midgardEmulation.getIterator();
        for(int x = 0; x < _midgardEmulation.getLenght(); x++){
            iterator->getNext()->evolveStep();
        }
        if (years%24 == 0){
            generatePoblationMessage();
            server->send(_message.c_str());
        }
        delete iterator;
    }
    Poblation * poblation = 0;
    Villager * currentVillager = 0;
    for(int x= 0;x<_midgardEmulation.getLenght();x++){
        poblation = _midgardEmulation.get(x)->getPoblation();
        currentVillager = (Villager*)poblation->getIndividuousByIndex(0);
        if (currentVillager){
            ((VillagersVerificator*)currentVillager->fitnessverify())->nextStage();
        }
    }
    std::cout << "superstition: " << _xmlConstants->superstitionEddaDuration() << std::endl;
    for(int years=0;years < _xmlConstants->superstitionEddaDuration(); years++){
        iterator = _midgardEmulation.getIterator();
        for(int x = 0; x < _midgardEmulation.getLenght(); x++){
            iterator->getNext()->evolveStep();
        }
        delete iterator;
    }
    for(int x= 0;x<_midgardEmulation.getLenght();x++){
        poblation = _midgardEmulation.get(x)->getPoblation();
        currentVillager = (Villager*)poblation->getIndividuousByIndex(0);
        if (currentVillager){
            ((VillagersVerificator*)currentVillager->fitnessverify())->nextStage();
        }
    }
    std::cout << "science: " << _xmlConstants->scienceEddaDuration() << std::endl;
    for(int years=0;years < _xmlConstants->scienceEddaDuration(); years++){
        iterator = _midgardEmulation.getIterator();
        for(int x = 0; x < _midgardEmulation.getLenght(); x++){
            iterator->getNext()->evolveStep();
        }
        delete iterator;
    }
    for(int x= 0;x<_midgardEmulation.getLenght();x++){
        poblation = _midgardEmulation.get(x)->getPoblation();
        currentVillager = (Villager*)poblation->getIndividuousByIndex(0);
        if (currentVillager){
            ((VillagersVerificator*)currentVillager->fitnessverify())->nextStage();
        }
    }
    std::cout << "supremacy: " << _xmlConstants->supremacyEddaDuration()<< std::endl;
    for(int years=0;years < _xmlConstants->supremacyEddaDuration(); years++){
        iterator = _midgardEmulation.getIterator();
        for(int x = 0; x < _midgardEmulation.getLenght(); x++){
            iterator->getNext()->evolveStep();
        }
        delete iterator;
    }
    std::cout << "union: " << _xmlConstants->unionEddaDuration()<< std::endl;
    for(int years=0;years < _xmlConstants->unionEddaDuration(); years++){
        iterator = _midgardEmulation.getIterator();
        for(int x = 0; x < _midgardEmulation.getLenght(); x++){
            iterator->getNext()->evolveStep();
        }
        delete iterator;
    }
    std::cout << "end" << std::endl;
}

Emulator::~Emulator()
{
    delete _xmlConstants;
    while(!_midgardEmulation.isEmpty()){
        delete _midgardEmulation.get(0);
        _midgardEmulation.remove(0);
    }
    server->closeServer();
    //borrar el mapa

}

