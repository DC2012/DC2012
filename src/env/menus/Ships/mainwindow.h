#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "dlgconnection.h"
#include "../../../net/client.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
        
public slots:
    void connect_accept(QString port, QString ip, QString username);
    void assignShip(QString shipType);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void dialog_popup();

private:
    Ui::MainWindow *ui;
    DlgConnection mDialog;
    Client* client_;
    QString shipType_;
};

#endif // MAINWINDOW_H
