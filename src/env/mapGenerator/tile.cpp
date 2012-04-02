#include "tile.h"
#include <QPixmap>
#include <sstream>
#include <qpalette.h>
#include <iostream>
#include <QtCore>
#include <QtXml/qdom.h>
#include <QtXml/QtXml>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>

std::vector<PhysicsType*> Tile::physicsTypes = std::vector<PhysicsType*>();
std::vector<GraphicsType*> Tile::graphicsTypes = std::vector<GraphicsType*>();

Tile::Tile(QWidget *parent): QPushButton(parent), x(0), y(0), physics(0), graphics(0) {
    init();
}

Tile::Tile(int _x, int _y): QPushButton(), x(_x), y(_y), physics(0), graphics(0){
    init();
}

void Tile::init() {
    connect(this, SIGNAL(clicked()), this, SLOT(update()));
    setCheckable(true);
    setAutoFillBackground(true);
    setFixedWidth(10);
    setFixedHeight(10);
    update();
}


void Tile::apply(int _physics, int _graphics, int _rotation) {
    if (isChecked()) {
        physics = _physics;
        graphics = _graphics;
        rotation = _rotation;
        clear();
        update();
    }
}

void Tile::clear() {
    setChecked(false);
    update();
}

void Tile::update() {
    if (exists()) {
        setStyleSheet("background-color:red;");
    } else {
        setStyleSheet("background-color:pink;");
    }
}

void Tile::print() {
    std::cout << "Tile " << x << "x" << y << " -> physics:" << physics << ", graphics:" << graphics << "&" << rotation << std::endl;
}

void Tile::reset() {
    setChecked(false);
    physics = 0;
    graphics = 0;
    rotation = 0;
    update();
}

void Tile::toggle() {
    setChecked(!isChecked());
    update();
}

bool Tile::exists() {
    return (physics > 0 || graphics > 0);
}

void Tile::genXML(QDomDocument *doc, QDomElement *map) {
    std::stringstream sString;
    if (exists()) {
        QDomElement tile_e = doc->createElement("tile");
        tile_e.setAttribute("x", x);
        tile_e.setAttribute("y", y);

        if (physics > 0) {
            QDomElement physics_e = doc->createElement("physics");
            PhysicsType *pType = physicsTypes[physics-1];
            physics_e.setAttribute("hit", pType->hit);
            tile_e.appendChild(physics_e);
        }

        if (graphics > 0) {
            QDomElement graphics_e = doc->createElement("graphics");
            GraphicsType *gType = graphicsTypes[graphics-1];
            graphics_e.setAttribute("source", gType->src);
            graphics_e.setAttribute("filename", gType->filename);
            graphics_e.setAttribute("rotation", rotation);
            // Bottom Left Horizontal
            sString.str("");
            sString << gType->x << "/" << gType->fileWidth;
            graphics_e.setAttribute("blh", QString(sString.str().c_str()));
            // Bottom Left Vertical
            sString.str("");
            sString << gType->y << "/" << gType->fileHeight;
            graphics_e.setAttribute("blv", QString(sString.str().c_str()));
            // Top Right Horizontal
            sString.str("");
            sString << gType->x+1 << "/" << gType->fileWidth;
            graphics_e.setAttribute("trh", QString(sString.str().c_str()));
            // Top Right Vertical
            sString.str("");
            sString << gType->y+1 << "/" << gType->fileHeight;
            graphics_e.setAttribute("trv", QString(sString.str().c_str()));
            tile_e.appendChild(graphics_e);
        }
        map->appendChild(tile_e);
    }
}
