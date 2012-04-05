#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dlgconnection.h"
#include "../../../graphics/gamewindow.h"
#include "pickyourship.h"

#include <QtCore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&mDialog, SIGNAL(connect_init(QString, QString)), this, SLOT(connect_accept(QString, QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dialog_popup()
{
    mDialog.setModal(true);
    mDialog.exec();
}

void MainWindow::assignShip(QString shipType)
{
    userName_ = "kendra";
    shipType_ = shipType;
}

void MainWindow::connect_accept(QString port, QString ip)
{
    std::string i;
    int         p;

    i = ip.toUtf8().constData();
    p = port.toInt();

    //if (client_->connectClient(p, i))
    //{
    mDialog.close();
    this->hide();
    PickYourShip shipDialog;
    connect(&shipDialog, SIGNAL(shipChosen(QString)), this, SLOT(assignShip(QString)));
    shipDialog.exec();

    Message msg;
    msg.setType(Message::CONNECTION);
    msg.setData((shipType_ + " " + userName_).toStdString());

    //client_->write(&msg);

    GameWindow *gameWindow = new GameWindow();
    gameWindow->setFocus();
    gameWindow->start();


    //}
}

