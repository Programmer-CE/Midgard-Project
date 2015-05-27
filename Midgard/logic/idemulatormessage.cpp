#include "idemulatormessage.h"


QString IDEmulatorMessage::getId() const
{
    return id;
}

void IDEmulatorMessage::setId(const QString &value)
{
    id = value;
}

QString IDEmulatorMessage::getMessage() const
{
    return message;
}

void IDEmulatorMessage::setMessage(const QString &value)
{
    message = value;
}

QString IDEmulatorMessage::getNameMap() const
{
    return nameMap;
}

void IDEmulatorMessage::setNameMap(const QString &value)
{
    nameMap = value;
}

QString IDEmulatorMessage::getNameConfig() const
{
    return nameConfig;
}

void IDEmulatorMessage::setNameConfig(const QString &value)
{
    nameConfig = value;
}
IDEmulatorMessage::IDEmulatorMessage()
{
}
