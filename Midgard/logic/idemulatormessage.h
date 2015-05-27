#ifndef IDEMULATORMESSAGE_H
#define IDEMULATORMESSAGE_H
#include <QString>

class IDEmulatorMessage
{
    QString message,id,nameMap,nameConfig;

public:
    IDEmulatorMessage();
    QString getId() const;
    void setId(const QString &value);
    QString getMessage() const;
    void setMessage(const QString &value);
    QString getNameMap() const;
    void setNameMap(const QString &value);
    QString getNameConfig() const;
    void setNameConfig(const QString &value);
};

#endif // IDEMULATORMESSAGE_H
