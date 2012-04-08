#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtXml/QtXml>
#include <QtXml/QDomDocument>
#include <QtXml/QDomElement>
#include <string>
#include <vector>
#include <list>
#include "tile.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    int width;
    int height;
    void getTileTypes();
public slots:
    void refreshMap();
    void apply();
    void save();
signals:
    void apply(int, int, int);
    void genXML(QDomDocument*, QDomElement*);
};

#endif // MAINWINDOW_H
