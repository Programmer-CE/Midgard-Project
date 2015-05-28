#include "emulationsmanager.h"
#include <QVariant>

EmulationsManager *EmulationsManager::_instance = 0;
int EmulationsManager::serial = 0;

EmulationsManager::EmulationsManager()
{
}

EmulationsManager *EmulationsManager::getInstance()
{
    if (!_instance){
        _instance  = new EmulationsManager();
    }
    return _instance;
}

IDEmulatorMessage EmulationsManager::createEmulation(QString pMapPath, QString pConfigurationPath, int pPort)
{
    IDEmulatorMessage message;
    if(!Emulator::verifyMapDocument(pMapPath)){
        std::cout << "Mapa invalido" << std::endl;
        message.setId("-1");
        message.setMessage(ERROR_MAP_FILE);
        return message;
    }
    if (!Emulator::verifyConfigurationDocument(pMapPath)){
        std::cout << "config invalido" << std::endl;
        IDEmulatorMessage message;
        message.setId("-1");
        message.setMessage(ERROR_CONFIGURATION_FILE);
        return message;

    }
    std::cout << "valids invalido" << std::endl;
    Emulator *emulation = new Emulator();
    emulation->setConfigurationPath(pConfigurationPath);
    emulation->setMapPath(pMapPath);
    emulation->setId(QString("emulation@").append(QVariant(serial++).toString()));
    if (emulation->buildEmulation(pPort)){
        _emulatorCollection.add(emulation);
        message.setMessage(SUCESS);
        message.setId(emulation->getId());
        message.setNameConfig(emulation->getNameOfConfig());
        message.setNameMap(emulation->getNameOfMap());
    }
    else{
        delete emulation;
        emulation = 0;
        message.setId("-1");
        message.setMessage(SERVER_ERROR_COULD_NOT_START);
    }
    return message;
}

bool EmulationsManager::runEmulation(QString id)
{
    IIterator<Emulator*> *iterator = _emulatorCollection.getIterator();
    bool toReturn = true;
    for (int x =0; x < _emulatorCollection.getLenght();x++){
        if(id.compare(iterator->getCurrent()->getId()) == 0){
            break;
        }
        iterator->getNext();
    }
    if (iterator->getCurrent()->isRunning()){
        toReturn = false;
    }
    iterator->getCurrent()->start();
    delete iterator;
    return toReturn;
}

bool EmulationsManager::stopEmulation(QString id)
{
    IIterator<Emulator*> *iterator = _emulatorCollection.getIterator();
    for (int x =0; x < _emulatorCollection.getLenght();x++){
        if(id.compare(iterator->getCurrent()->getId()) == 0){
            break;
        }
        iterator->getNext();
    }
    if (!iterator->getCurrent()->isRunning()){
        delete iterator;
        return false;
    }
    iterator->getCurrent()->quit();
    delete iterator;
    return true;
}

void EmulationsManager::changeState(QString id)
{
    IIterator<Emulator*> *iterator = _emulatorCollection.getIterator();
    int x =0;
    for (; x < _emulatorCollection.getLenght();x++){
        if(id.compare(iterator->getCurrent()->getId()) == 0){
            break;
        }
        iterator->getNext();
    }
    if (x != _emulatorCollection.getLenght()){
        if (!iterator->getCurrent()->isRunning()){
            iterator->getCurrent()->quit();
        }else{
            iterator->getCurrent()->start();
        }
    }
    delete iterator;
}

bool EmulationsManager::removeEmulation(QString id)
{
    Emulator* emul = 0;
    for (int x =0; x < _emulatorCollection.getLenght();x++){
        emul = _emulatorCollection.get(x);
        if(id.compare(emul->getId()) == 0){
            if (emul->isRunning()){
                qDebug() << "El thread esta corriendo";
                //emul->quit();
                //emul->exit(-1);
                while(!emul->isFinished())emul->terminate();
                qDebug() << "El thread esta corriendo";
            }
            delete emul;
            qDebug() << "la emulacion se ha borrado";
            _emulatorCollection.remove(x);
            break;
        }
    }
    return true;
}

EmulationsManager::~EmulationsManager()
{
    Emulator* emul = 0;
    while(_emulatorCollection.getLenght() != 0){
        emul = _emulatorCollection.get(0);
        emul->quit();
        delete emul;
        _emulatorCollection.remove(0);
    }
}
