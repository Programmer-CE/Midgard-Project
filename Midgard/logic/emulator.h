#include "customgenetics/midgardarwin.h"
#include <QThread>
#include "xmlconstanst.h"
#include "list/DoubleList.h"
#include "customgenetics/villagercrosser.h"
#include "customgenetics/villagerfinalstate.h"
#include <QtNetwork/QTcpServer>
#include "logic/connectionManager/fserver.h"
#include <string>
#ifndef EMULATOR_H
#define EMULATOR_H

class Emulator:public QThread
{
    Q_OBJECT
    XMLConstanst *_xmlConstants;
    QString configurationPath;
    QString mapPath;
    QString id, nameOfMap,nameOfConfig;
    UDoubleList<MidgarDarwin *> _midgardEmulation;
    VillagerFinalState _final;
    QString ip;
    FServer *server;
    bool ** map;

    std::string _message;
private slots:
    void generatePoblationMessage();
public:
    explicit Emulator(QObject *parent = 0);
    static bool verifyMapDocument(QString ppath);
    static bool verifyConfigurationDocument(QString ppath);
    void run();
    virtual ~Emulator();
    QString getConfigurationPath() const;
    void setConfigurationPath(const QString &value);
    QString getMapPath() const;
    void setMapPath(const QString &value);
    QString getId() const;
    void setId(const QString &value);
    bool buildEmulation(int pPort);
    QString getNameOfMap() const;
    void setNameOfMap(const QString &value);
    QString getNameOfConfig() const;
    void setNameOfConfig(const QString &value);
};

#endif // EMULATOR_H
