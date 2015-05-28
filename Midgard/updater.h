#ifndef UPDATER_H
#define UPDATER_H
#include <QThread>
#include "logic/random.h"

class Updater : public QThread
{
    Q_OBJECT
    Random vrand;
    bool _execRand;
public:
    explicit Updater(QObject *parent = 0);
    void run();
    int getLenghtM();
    virtual ~Updater(){}
    bool execRand() const;
    void setExecRand(bool execRand);

signals:

public slots:

};

#endif // UPDATER_H
