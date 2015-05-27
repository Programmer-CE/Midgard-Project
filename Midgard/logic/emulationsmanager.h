#ifndef EMULATIONSMANAGER_H
#define EMULATIONSMANAGER_H
#include <QString>
#include <list/DoubleList.h>
#include "emulator.h"
#include "idemulatormessage.h"
class EmulationsManager
{
    EmulationsManager();
    static EmulationsManager *_instance;
    DoubleList<Emulator*> _emulatorCollection;
    static int serial;
public:
    const QString ERROR_MAP_FILE = "El archivo de mapa es invalido o esta corrupto";
    const QString ERROR_CONFIGURATION_FILE= "El archivo de configuracion es invalido o esta corrupto";
    const QString SUCESS= "Se ha creado la emulacion correctamente";
    const QString SERVER_ERROR_COULD_NOT_START = "El servidor no pudo levantarse";
    static EmulationsManager *getInstance();
    IDEmulatorMessage createEmulation(QString pMapPath, QString pConfigurationPath,int pPort);
    bool runEmulation(QString id);
    bool stopEmulation(QString id);
    void changeState(QString id);
    bool removeEmulation(QString id);
    virtual ~EmulationsManager();
};

#endif // EMULATIONSMANAGER_H
