#ifndef MAPSELECTOR_H
#define MAPSELECTOR_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class MapSelector;
}

class MapSelector : public QDialog
{
    Q_OBJECT
    QFileDialog fileDialog;
    QString mapPath;
    QString geneticConfigurationPath;
    QMessageBox _warningMessage;
    QString idEmulation;
    QString mapName;
    QString configName;
    int _portConector;
public:
    explicit MapSelector(QWidget *parent = 0);
    ~MapSelector();

    QString getMapPath() const;
    void setMapPath(const QString &value);

    QString getGeneticConfigurationPath() const;
    void setGeneticConfigurationPath(const QString &value);

    QString getIdEmulation() const;
    void setIdEmulation(const QString &value);

    QString getMapName() const;
    void setMapName(const QString &value);

    QString getConfigName() const;
    void setConfigName(const QString &value);

    int portConector() const;
    void setPortConector(int portConector);

private slots:

public slots:
    void accept();
    void reject();
    void cargarMapa();
    void cargarConfiguracion();
private:
    Ui::MapSelector *ui;
};

#endif // MAPSELECTOR_H
