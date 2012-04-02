#ifndef TILE_H
#define TILE_H

#include <QtCore>
#include <QtXml/QtXml>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <QPushButton>
#include <sstream>
#include <vector>

typedef struct {
    QString name;
    QString hit;
} PhysicsType;

typedef struct {
    QString name;
    QString src;
    QString filename;
    int x;
    int y;
    int fileWidth;
    int fileHeight;
} GraphicsType;

class Tile : public QPushButton
{
Q_OBJECT
private:
    int x;
    int y;
    int physics;
    int graphics;
    int rotation;
    void apply();
    void init();
    bool exists();
public:
    static std::vector<PhysicsType*> physicsTypes;
    static std::vector<GraphicsType*> graphicsTypes;
    explicit Tile(QWidget *parent = 0);
    Tile(int, int);
signals:

public slots:
    void update();
    void reset();
    void toggle();
    void apply(int, int, int);
    void print();
    void clear();
    void genXML(QDomDocument*, QDomElement*);
};

#endif // TILE_H
