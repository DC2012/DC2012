/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Mar 20 13:56:29 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *main_layout;
    QVBoxLayout *map_layout;
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *map;
    QSpacerItem *horizontalSpacer;
    QGridLayout *properties_layout;
    QLabel *physics_label;
    QLabel *graphics_label;
    QComboBox *physics;
    QComboBox *graphics;
    QComboBox *rotation;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *apply;
    QPushButton *clear;
    QPushButton *reset;
    QPushButton *save;
    QGridLayout *settings_layout;
    QLabel *grid_width_label;
    QSpinBox *grid_width;
    QLabel *grid_heigh_label;
    QSpinBox *grid_height;
    QSpacerItem *settings_spacer;
    QLabel *tile_size_label;
    QSpinBox *tile_size;
    QPushButton *generate;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(514, 346);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        main_layout = new QHBoxLayout();
        main_layout->setSpacing(6);
        main_layout->setObjectName(QString::fromUtf8("main_layout"));
        map_layout = new QVBoxLayout();
        map_layout->setSpacing(6);
        map_layout->setObjectName(QString::fromUtf8("map_layout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        map = new QGridLayout();
        map->setSpacing(0);
        map->setObjectName(QString::fromUtf8("map"));

        horizontalLayout_3->addLayout(map);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        map_layout->addLayout(horizontalLayout_3);

        properties_layout = new QGridLayout();
        properties_layout->setSpacing(6);
        properties_layout->setObjectName(QString::fromUtf8("properties_layout"));
        physics_label = new QLabel(centralWidget);
        physics_label->setObjectName(QString::fromUtf8("physics_label"));

        properties_layout->addWidget(physics_label, 1, 0, 1, 1);

        graphics_label = new QLabel(centralWidget);
        graphics_label->setObjectName(QString::fromUtf8("graphics_label"));

        properties_layout->addWidget(graphics_label, 2, 0, 1, 1);

        physics = new QComboBox(centralWidget);
        physics->setObjectName(QString::fromUtf8("physics"));

        properties_layout->addWidget(physics, 1, 1, 1, 2);

        graphics = new QComboBox(centralWidget);
        graphics->setObjectName(QString::fromUtf8("graphics"));

        properties_layout->addWidget(graphics, 2, 1, 1, 1);

        rotation = new QComboBox(centralWidget);
        rotation->setObjectName(QString::fromUtf8("rotation"));

        properties_layout->addWidget(rotation, 2, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        properties_layout->addItem(verticalSpacer, 0, 1, 1, 1);


        map_layout->addLayout(properties_layout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        apply = new QPushButton(centralWidget);
        apply->setObjectName(QString::fromUtf8("apply"));

        horizontalLayout_2->addWidget(apply);

        clear = new QPushButton(centralWidget);
        clear->setObjectName(QString::fromUtf8("clear"));

        horizontalLayout_2->addWidget(clear);

        reset = new QPushButton(centralWidget);
        reset->setObjectName(QString::fromUtf8("reset"));

        horizontalLayout_2->addWidget(reset);

        save = new QPushButton(centralWidget);
        save->setObjectName(QString::fromUtf8("save"));

        horizontalLayout_2->addWidget(save);


        map_layout->addLayout(horizontalLayout_2);


        main_layout->addLayout(map_layout);

        settings_layout = new QGridLayout();
        settings_layout->setSpacing(6);
        settings_layout->setObjectName(QString::fromUtf8("settings_layout"));
        grid_width_label = new QLabel(centralWidget);
        grid_width_label->setObjectName(QString::fromUtf8("grid_width_label"));

        settings_layout->addWidget(grid_width_label, 0, 0, 1, 1);

        grid_width = new QSpinBox(centralWidget);
        grid_width->setObjectName(QString::fromUtf8("grid_width"));
        grid_width->setMinimum(1);
        grid_width->setMaximum(200);
        grid_width->setValue(20);

        settings_layout->addWidget(grid_width, 0, 1, 1, 1);

        grid_heigh_label = new QLabel(centralWidget);
        grid_heigh_label->setObjectName(QString::fromUtf8("grid_heigh_label"));

        settings_layout->addWidget(grid_heigh_label, 1, 0, 1, 1);

        grid_height = new QSpinBox(centralWidget);
        grid_height->setObjectName(QString::fromUtf8("grid_height"));
        grid_height->setMinimum(1);
        grid_height->setMaximum(200);
        grid_height->setValue(10);

        settings_layout->addWidget(grid_height, 1, 1, 1, 1);

        settings_spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        settings_layout->addItem(settings_spacer, 4, 0, 1, 2);

        tile_size_label = new QLabel(centralWidget);
        tile_size_label->setObjectName(QString::fromUtf8("tile_size_label"));

        settings_layout->addWidget(tile_size_label, 3, 0, 1, 1);

        tile_size = new QSpinBox(centralWidget);
        tile_size->setObjectName(QString::fromUtf8("tile_size"));
        tile_size->setMinimum(1);
        tile_size->setMaximum(100);
        tile_size->setValue(25);

        settings_layout->addWidget(tile_size, 3, 1, 1, 1);

        generate = new QPushButton(centralWidget);
        generate->setObjectName(QString::fromUtf8("generate"));

        settings_layout->addWidget(generate, 2, 0, 1, 2);


        main_layout->addLayout(settings_layout);


        horizontalLayout->addLayout(main_layout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 514, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(apply, SIGNAL(clicked()), MainWindow, SLOT(apply()));
        QObject::connect(generate, SIGNAL(clicked()), MainWindow, SLOT(refreshMap()));
        QObject::connect(save, SIGNAL(clicked()), MainWindow, SLOT(save()));
        QObject::connect(generate, SIGNAL(clicked()), MainWindow, SLOT(refreshMap()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        physics_label->setText(QApplication::translate("MainWindow", "physics", 0, QApplication::UnicodeUTF8));
        graphics_label->setText(QApplication::translate("MainWindow", "graphics", 0, QApplication::UnicodeUTF8));
        physics->clear();
        physics->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "space", 0, QApplication::UnicodeUTF8)
        );
        graphics->clear();
        graphics->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "space", 0, QApplication::UnicodeUTF8)
        );
        rotation->clear();
        rotation->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "90", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "180", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindow", "360", 0, QApplication::UnicodeUTF8)
        );
        apply->setText(QApplication::translate("MainWindow", "Apply", 0, QApplication::UnicodeUTF8));
        clear->setText(QApplication::translate("MainWindow", "Clear", 0, QApplication::UnicodeUTF8));
        reset->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
        save->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        grid_width_label->setText(QApplication::translate("MainWindow", "Grid Width", 0, QApplication::UnicodeUTF8));
        grid_heigh_label->setText(QApplication::translate("MainWindow", "Grid Height", 0, QApplication::UnicodeUTF8));
        tile_size_label->setText(QApplication::translate("MainWindow", "Tile Size", 0, QApplication::UnicodeUTF8));
        tile_size->setSuffix(QApplication::translate("MainWindow", "px", 0, QApplication::UnicodeUTF8));
        generate->setText(QApplication::translate("MainWindow", "Generate", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
