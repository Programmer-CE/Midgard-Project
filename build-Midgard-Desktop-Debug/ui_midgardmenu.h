/********************************************************************************
** Form generated from reading UI file 'midgardmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MIDGARDMENU_H
#define UI_MIDGARDMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MidgardMenu
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *clienteservidor;
    QWidget *servidores;
    QVBoxLayout *verticalLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *servers;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpinBox *portget;
    QPushButton *insertar;
    QPushButton *borrar;
    QPushButton *ver;
    QPushButton *playOrPause;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MidgardMenu)
    {
        if (MidgardMenu->objectName().isEmpty())
            MidgardMenu->setObjectName(QStringLiteral("MidgardMenu"));
        MidgardMenu->resize(631, 589);
        MidgardMenu->setMinimumSize(QSize(600, 0));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/freedroid.svg"), QSize(), QIcon::Normal, QIcon::Off);
        MidgardMenu->setWindowIcon(icon);
        centralWidget = new QWidget(MidgardMenu);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        clienteservidor = new QTabWidget(centralWidget);
        clienteservidor->setObjectName(QStringLiteral("clienteservidor"));
        servidores = new QWidget();
        servidores->setObjectName(QStringLiteral("servidores"));
        verticalLayout_4 = new QVBoxLayout(servidores);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        scrollArea = new QScrollArea(servidores);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 600, 1500));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        servers = new QTableWidget(scrollAreaWidgetContents);
        if (servers->columnCount() < 3)
            servers->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        servers->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        servers->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        servers->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        servers->setObjectName(QStringLiteral("servers"));
        servers->setMinimumSize(QSize(600, 1500));
        servers->setColumnCount(3);
        servers->horizontalHeader()->setDefaultSectionSize(160);

        verticalLayout_2->addWidget(servers);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(scrollArea);

        clienteservidor->addTab(servidores, QString());

        verticalLayout_3->addWidget(clienteservidor);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        portget = new QSpinBox(centralWidget);
        portget->setObjectName(QStringLiteral("portget"));
        portget->setMinimum(1);
        portget->setMaximum(99999);

        horizontalLayout->addWidget(portget);

        insertar = new QPushButton(centralWidget);
        insertar->setObjectName(QStringLiteral("insertar"));

        horizontalLayout->addWidget(insertar);


        verticalLayout->addLayout(horizontalLayout);

        borrar = new QPushButton(centralWidget);
        borrar->setObjectName(QStringLiteral("borrar"));

        verticalLayout->addWidget(borrar);

        ver = new QPushButton(centralWidget);
        ver->setObjectName(QStringLiteral("ver"));

        verticalLayout->addWidget(ver);

        playOrPause = new QPushButton(centralWidget);
        playOrPause->setObjectName(QStringLiteral("playOrPause"));

        verticalLayout->addWidget(playOrPause);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_2);

        MidgardMenu->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MidgardMenu);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 631, 25));
        MidgardMenu->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MidgardMenu);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MidgardMenu->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MidgardMenu);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MidgardMenu->setStatusBar(statusBar);

        retranslateUi(MidgardMenu);

        clienteservidor->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MidgardMenu);
    } // setupUi

    void retranslateUi(QMainWindow *MidgardMenu)
    {
        MidgardMenu->setWindowTitle(QApplication::translate("MidgardMenu", "MidgardMenu", 0));
#ifndef QT_NO_WHATSTHIS
        scrollArea->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        QTableWidgetItem *___qtablewidgetitem = servers->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MidgardMenu", "Puerto", 0));
        QTableWidgetItem *___qtablewidgetitem1 = servers->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MidgardMenu", "Configuracion", 0));
        QTableWidgetItem *___qtablewidgetitem2 = servers->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MidgardMenu", "Mapa", 0));
        clienteservidor->setTabText(clienteservidor->indexOf(servidores), QApplication::translate("MidgardMenu", "servidores", 0));
        label_2->setText(QApplication::translate("MidgardMenu", "port:", 0));
        insertar->setText(QApplication::translate("MidgardMenu", "insertar", 0));
        borrar->setText(QApplication::translate("MidgardMenu", "borrar", 0));
        ver->setText(QApplication::translate("MidgardMenu", "ver", 0));
        playOrPause->setText(QApplication::translate("MidgardMenu", "play/pause", 0));
    } // retranslateUi

};

namespace Ui {
    class MidgardMenu: public Ui_MidgardMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MIDGARDMENU_H
