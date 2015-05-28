/********************************************************************************
** Form generated from reading UI file 'mapselector.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPSELECTOR_H
#define UI_MAPSELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MapSelector
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *geneticconfigure;
    QPushButton *cargarConfig;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *mapconfig;
    QPushButton *cargarMapaConfig;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *MapSelector)
    {
        if (MapSelector->objectName().isEmpty())
            MapSelector->setObjectName(QStringLiteral("MapSelector"));
        MapSelector->resize(580, 206);
        verticalLayout_3 = new QVBoxLayout(MapSelector);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(MapSelector);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        geneticconfigure = new QLineEdit(MapSelector);
        geneticconfigure->setObjectName(QStringLiteral("geneticconfigure"));
        geneticconfigure->setReadOnly(true);

        horizontalLayout->addWidget(geneticconfigure);

        cargarConfig = new QPushButton(MapSelector);
        cargarConfig->setObjectName(QStringLiteral("cargarConfig"));

        horizontalLayout->addWidget(cargarConfig);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(MapSelector);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        mapconfig = new QLineEdit(MapSelector);
        mapconfig->setObjectName(QStringLiteral("mapconfig"));
        mapconfig->setReadOnly(true);

        horizontalLayout_2->addWidget(mapconfig);

        cargarMapaConfig = new QPushButton(MapSelector);
        cargarMapaConfig->setObjectName(QStringLiteral("cargarMapaConfig"));

        horizontalLayout_2->addWidget(cargarMapaConfig);


        verticalLayout_2->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout_2);

        buttonBox = new QDialogButtonBox(MapSelector);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(MapSelector);
        QObject::connect(buttonBox, SIGNAL(accepted()), MapSelector, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), MapSelector, SLOT(reject()));
        QObject::connect(cargarMapaConfig, SIGNAL(clicked()), MapSelector, SLOT(cargarMapa()));
        QObject::connect(cargarConfig, SIGNAL(clicked()), MapSelector, SLOT(cargarConfiguracion()));

        QMetaObject::connectSlotsByName(MapSelector);
    } // setupUi

    void retranslateUi(QDialog *MapSelector)
    {
        MapSelector->setWindowTitle(QApplication::translate("MapSelector", "Dialog", 0));
        label->setText(QApplication::translate("MapSelector", "configuraci\303\263n del algoritmo genetico:", 0));
        cargarConfig->setText(QApplication::translate("MapSelector", "buscar", 0));
        label_2->setText(QApplication::translate("MapSelector", "Mapa a seleccionar:", 0));
        cargarMapaConfig->setText(QApplication::translate("MapSelector", "buscar", 0));
    } // retranslateUi

};

namespace Ui {
    class MapSelector: public Ui_MapSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPSELECTOR_H
