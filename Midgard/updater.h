#ifndef UPDATER_H
#define UPDATER_H
#include <QThread>

class Updater : public QThread
{
    Q_OBJECT
public:
    explicit Updater(QObject *parent = 0);
    void run();
    int getLenghtM();
    virtual ~Updater(){}
signals:

public slots:

};

#endif // UPDATER_H
