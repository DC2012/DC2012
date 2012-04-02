#include <QtCore>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <QFile>
#include <sstream>
#include <QFileDialog>
#include <iostream>
#include <QTextStream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tile.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow), width(0), height(0){
    ui->setupUi(this);
    getTileTypes();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::getTileTypes() {
    PhysicsType *pType;
    GraphicsType *gType;
    QDomDocument doc;
    QFile file("types.xml");
    if (!file.open(QIODevice::ReadOnly)) {
        cerr << "Cannot open file" << endl;
        return;
    }
    if (!doc.setContent(&file)) {
        cerr << "Unusable file" << endl;
        file.close();
        return;
    }
    file.close();
    QDomElement types_e = doc.documentElement();
    if (types_e.tagName() != "types") {
        cerr << "Not a types element" << endl;
        return;
    }

    // Read physics types
    QDomNodeList physics_l = types_e.elementsByTagName("physics");
    for (int pi=0; pi < physics_l.count(); ++pi) {
        QDomElement physics_e = physics_l.item(pi).toElement();
        QDomNodeList pType_list = physics_e.elementsByTagName("physics_type");
        for (int pti=0; pti < pType_list.count(); ++pti) {
            QDomElement pType_e = pType_list.item(pti).toElement();
            pType = new PhysicsType;
            pType->hit  = pType_e.attribute("hit");
            pType->name = pType_e.attribute("name");
            Tile::physicsTypes.push_back(pType);
            ui->physics->addItem(pType->name, QVariant());
        }
    }

    // Read graphics types
    QDomNodeList graphics_l = types_e.elementsByTagName("graphics");
    for (int gi=0; gi < graphics_l.count(); ++gi) {
        QDomElement graphics_e = graphics_l.item(gi).toElement();
        QDomNodeList gSrc_l = graphics_e.elementsByTagName("src");
        for (int gsi=0; gsi < gSrc_l.count(); ++gsi) {
            QDomElement gSrc_e = gSrc_l.item(gsi).toElement();
            QDomNodeList gFile_l = gSrc_e.elementsByTagName("file");
            for (int gfi=0; gfi < gFile_l.count(); ++gfi) {
                QDomElement gFile_e = gFile_l.item(gfi).toElement();
                QDomNodeList gType_l = gFile_e.elementsByTagName("graphics_type");
                for (int gti=0; gti < gType_l.count(); ++gti) {
                    QDomElement gType_e = gType_l.item(gti).toElement();
                    gType = new GraphicsType;
                    gType->src        = gSrc_e.attribute("value");
                    gType->filename   = gFile_e.attribute("filename");
                    gType->fileWidth  = gFile_e.attribute("width").toInt();
                    gType->fileHeight = gFile_e.attribute("height").toInt();
                    gType->name       = gType_e.attribute("name");
                    gType->x          = gType_e.attribute("x").toInt();
                    gType->y          = gType_e.attribute("y").toInt();
                    Tile::graphicsTypes.push_back(gType);
                    ui->graphics->addItem(gType->name, QVariant());
                }
            }
        }
    }
}

void MainWindow::refreshMap() {
    Tile *tile;
    int width = ui->grid_width->value();
    int height = ui->grid_height->value();
    for (int x=0; x < width; ++x) {
        for (int y=0; y < height; ++y) {
            tile = new Tile(x, y);      // create new tile
            ui->map->addWidget(tile, y, x); // grid's x,y coords are backwards and upside down, DO NOT CHANGE!!!
            connect(ui->reset, SIGNAL(clicked()), tile, SLOT(reset()));
            connect(ui->clear, SIGNAL(clicked()), tile, SLOT(clear()));
            connect(this, SIGNAL(genXML(QDomDocument*,QDomElement*)), tile, SLOT(genXML(QDomDocument*,QDomElement*)));
            connect(this, SIGNAL(apply(int, int, int)), tile, SLOT(apply(int, int, int)));
        }
    }
}

void MainWindow::apply() {
    emit apply(ui->physics->currentIndex(), ui->graphics->currentIndex(), ui->rotation->currentIndex());
}

void MainWindow::save() {
    QDomDocument doc("Map");
    QDomElement map = doc.createElement("map");
    map.setAttribute("height", ui->grid_height->value());
    map.setAttribute("width", ui->grid_width->value());
    map.setAttribute("tileSize", ui->tile_size->value());
    emit genXML(&doc, &map);
    doc.appendChild(map);
    QFile file(QFileDialog::getSaveFileName(this, tr("Save Map File"), "./map.xml", tr("XML (*.xml)")));

    if(!file.open(QIODevice::WriteOnly)) {
      cerr << "Failed to open file." << endl;
      return;
    }
    QTextStream fileStream(&file);
    fileStream << doc.toString() << endl;
    file.close();
    cout << doc.toString().toStdString() << endl;
}
