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
    connect(server,SIGNAL(connectionAppear()),this,SLOT(sendMapMessage()));
    //crear n poblaciones de razas
    //crear m poblaciones de sub clases y correrlas
    map = XMLReader::readMap(getMapPath(),_xmlConstants);
    _finder = new APathFinder(map,_xmlConstants->mapWidth(),_xmlConstants->mapHeight());
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
                //ubicar los individuos
                for (int w = 0; w < _xmlConstants->initialPoblation();w++){
                    _poblation->addIndividuous(fabric->create(0));
                }
                midgard = new MidgarDarwin(crosser,&_final,_poblation,_xmlConstants->barbarianEddaDuration());
                _midgardEmulation.add(midgard);
            }
        }
    }
    generateMapMessage();
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
void Emulator::war(int pAttackersIndex, int pAttakedIndex)
{
    DoubleList<Comparer<Individuo>> * poblationAttaker =_midgardEmulation.get(pAttackersIndex)->getPoblation()->getDataList();
    DoubleList<int> attakers;
    DoubleList<Comparer<Individuo>> * poblationAttaked =_midgardEmulation.get(pAttakedIndex)->getPoblation()->getDataList();
    DoubleList<int> attakeds;
    for (int x = 0; x < poblationAttaker->getLenght(); x++){
        if (x%2 == 0){
            attakers.add(x);
        }
    }
    for (int x = 0; x < poblationAttaker->getLenght(); x++){
        if (x%2 == 0){
            attakeds.add(x);
        }
    }
    UDoubleList<Queue<PathPoint >* > _paths;
    Villager *_currentVillager = 0;
    for (int x = 0; x < attakeds.getLenght(); x++){
        // al centro del mapa
        _currentVillager = (Villager *)poblationAttaked->get(attakeds.get(x)).getData();
        _paths.add(_finder->PathFinder(_currentVillager->x(),_currentVillager->y(), _xmlConstants->mapWidth()/2, _xmlConstants->mapHeight()/2));
    }
    for (int x = 0; x < attakers.getLenght(); x++){
        // al centro del mapa
        _currentVillager = (Villager *)poblationAttaker->get(attakers.get(x)).getData();
        _paths.add(_finder->PathFinder(_currentVillager->x(),_currentVillager->y(), _xmlConstants->mapWidth()/2, _xmlConstants->mapHeight()/2));
    }
    bool executeMove = true;
    Queue<PathPoint> *_currentPath = 0;
    PathPoint _currentPoint;
    int _queueEmpty = 0;
    while(executeMove){
        for (int x = 0; x < attakers.getLenght();x++){
            _currentPath = _paths.get(x);
            if (!_currentPath->isEmpty()){
                _currentVillager = (Villager *)poblationAttaker->get(attakers.get(x)).getData();
                _currentPoint = _currentPath->dequeue();
                _currentVillager->setX(_currentPoint.x());
                _currentVillager->setY(_currentPoint.y());
            }
            else{
                _queueEmpty++;
            }

        }
        for (int x = 0; x < attakeds.getLenght();x++){
            _currentPath = _paths.get(x);
            if (!_currentPath->isEmpty()){
                _currentVillager = (Villager *)poblationAttaked->get(attakeds.get(x)).getData();
                _currentPoint = _currentPath->dequeue();
                _currentVillager->setX(_currentPoint.x());
                _currentVillager->setY(_currentPoint.y());

            }
            else{
                _queueEmpty++;
            }

        }
        if (_queueEmpty == attakeds.getLenght() + attakers.getLenght()){
            break;
        }
        else{
            _queueEmpty = 0;
        }

        generatePoblationMessage();
        server->setToSend(_message.c_str());
        emit prepareMessage();
        //server->send(_message.c_str());
    }


    // batallas
    while(!_paths.isEmpty()){
        delete _paths.get(0);
        _paths.remove(0);
    }
    // enviar los datos por socket
}
/*
void Emulator::invade(int pAttackersIndex)
{
    DoubleList<Comparer<Individuo>> * poblationAttaker =_midgardEmulation.get(pAttackersIndex)->getPoblation()->getDataList();
    DoubleList<int> attakers;
    for (int x = 0; x < poblationAttaker->getLenght(); x++){
        if (x%2 == 0){
            attakers.add(x);
        }
    }
    for (int x = 0; x < attakers.getLenght(); x++){
        if (x%2 == 0){
            attakers.add(x);

        }
    }


    //hacer la invacion con path finding
    //enviar los datos por socket
}
*/

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
            if (x == _midgardEmulation.getLenght()-1 && y == poblation->getLenght()-1){
                _message.append("}");
            }
            else _message.append("},");
        }
    }

    _message.append("] }");
    server->send(_message.c_str());
}

void Emulator::sendMapMessage()
{
    server->send(_mapMessage);
}

Emulator::Emulator(QObject *parent):QThread(parent)
{
    server = new FServer();
    connect(this,SIGNAL(prepareMessage()),server,SLOT(send()));
}


bool Emulator::verifyMapDocument(QString ppath)
{
    return XMLReader::verifyMapFile(ppath);
}

bool Emulator::verifyConfigurationDocument(QString ppath)
{
    return XMLReader::verifyConfiguration(ppath);
}

void Emulator::generateMapMessage()
{
    _mapMessage= "{";
    _mapMessage.append("\"width\":");
    _mapMessage.append(std::to_string(_xmlConstants->mapWidth()).c_str());
    _mapMessage.append(", \"height\":");
    _mapMessage.append(std::to_string(_xmlConstants->mapHeight()).c_str());
    _mapMessage.append(",\"map\":");
    _mapMessage.append(" [");
    QString row = "";
    for(int x= 0;x<_xmlConstants->mapHeight()-1;x++){
        row.append("\"");
        for (int y = 0; y < _xmlConstants->mapWidth();y++){
            if (map[x][y]){
                row.append("1");
            }
            else row.append("0");
        }
        _mapMessage.append(row);
        _mapMessage.append("\",");
        row = "";
    }
    row = "\"";
    for (int y = 0; y < _xmlConstants->mapWidth();y++){
        if (map[_xmlConstants->mapHeight()-1][y]){
            row.append("1");
        }
        else row.append("0");
    }
    _mapMessage.append(row);
    _mapMessage.append("\"");

    _mapMessage.append("] }");

}

void Emulator::run()
{
    IIterator<MidgarDarwin *> *iterator = 0;
    Poblation * poblation = 0;
    Villager * currentVillager = 0;

    // print inicial
    for(int x= 0;x<_midgardEmulation.getLenght();x++){
        poblation = _midgardEmulation.get(x)->getPoblation();
        for (int y = 0; y < poblation->getLenght();y++){
            currentVillager = (Villager*)poblation->getIndividuousByIndex(y);
            std::cout << "fit " << currentVillager->fitness() <<
                         " edad-max: " << currentVillager->ageToDeath() <<
                    " atk: " << currentVillager->attack()
                 << " def: " << currentVillager->defense()
                 << " vel: " << currentVillager->velocity()
                 << " vida-max: " <<currentVillager->maximunLife()
                 << " blot: " << currentVillager->blot()
                 << " rns: "<< currentVillager->runes()
                 << " sprtn: " << currentVillager->superstition()
                 << " int: " << currentVillager->intelligence()
                 << " mag:"<< currentVillager->magic() << endl;
        }
        std::cout << "------------------------------------------------------------------------------" << endl;
    }
    std::cout << "##################################################################################" << endl;
    // duracion de las eddas segun el indice
    int eddas[5] = {_xmlConstants->barbarianEddaDuration(),
                    _xmlConstants->superstitionEddaDuration(),
                    _xmlConstants->scienceEddaDuration(),
                    _xmlConstants->supremacyEddaDuration(),
                    _xmlConstants->unionEddaDuration()
                   };
    Random vrand;
    //probablidad de batallas por edda, segun indice
    int warProbability[5] = {(vrand.random()%50)+1, (vrand.random()%50)+1,
                             (vrand.random()%100)+1, (vrand.random()%50)+1,
                             0
                            };
    //diez dias maximo para las batallas
    //un dia dura 10 segundos
    int warDuration = vrand.random()%10;
    int atacantes, atacados;
    for (int edda = 0;edda <5; edda++){
        std::cout << "edda: " << edda  << " edda duration: " << eddas[edda]<< std::endl;
        for(int years=0;years < eddas[edda]; years++){
            //std::cout << "years: "<< years << std::endl;
            iterator = _midgardEmulation.getIterator();
            for(int x = 0; x < _midgardEmulation.getLenght(); x++){
                //std::cout << "poblacion: " << iterator->getCurrent()->getPoblation()->getLenght()<< endl;
                iterator->getNext()->evolveStep();
                if (vrand.random() >vrand.random()%1000){
                    atacantes = vrand.random()%(_midgardEmulation.getLenght()/2);
                    atacados =(vrand.random()%_midgardEmulation.getLenght()/2)+_midgardEmulation.getLenght()/2;
                    for (int diasDeGuerra = 0; diasDeGuerra < warDuration; diasDeGuerra++){
                        war(atacantes, atacados);
                    }
                }
            }
            if (years%24 == 0){
                generatePoblationMessage();
                server->setToSend(_message.c_str());
                emit prepareMessage();
                //server->send(_message.c_str());
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
    }
    for(int x= 0;x<_midgardEmulation.getLenght();x++){
        poblation = _midgardEmulation.get(x)->getPoblation();
        for (int y = 0; y < poblation->getLenght();y++){
            currentVillager = (Villager*)poblation->getIndividuousByIndex(y);
            std::cout << "fit " << currentVillager->fitness() <<
                         " edad-max: " << currentVillager->ageToDeath() <<
                    " atk: " << currentVillager->attack()
                 << " def: " << currentVillager->defense()
                 << " vel: " << currentVillager->velocity()
                 << " vida-max: " <<currentVillager->maximunLife()
                 << " blot: " << currentVillager->blot()
                 << " rns: "<< currentVillager->runes()
                 << " sprtn: " << currentVillager->superstition()
                 << " int: " << currentVillager->intelligence()
                 << " mag:"<< currentVillager->magic() << endl;
        }
        std::cout << "------------------------------------------------------------------------------" << endl;
    }
    std::cout << "end" << std::endl;
}

Emulator::~Emulator()
{
    std::cout << "emulator is delete" << std::endl;
    delete _xmlConstants;
    while(!_midgardEmulation.isEmpty()){
        std::cout << "borrando Emulador" << std::endl;
        delete _midgardEmulation.get(0);
        _midgardEmulation.remove(0);
    }
    server->closeServer();
    delete server;
    for (int x = 0; x < _xmlConstants->mapHeight(); x++){
        delete [] map[x];
        map[x] = 0;
    }
    delete [] map;

}

