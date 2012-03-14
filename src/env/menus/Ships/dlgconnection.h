#ifndef DLGCONNECTION_H
#define DLGCONNECTION_H

#include <QDialog>

namespace Ui {
class DlgConnection;
}

class DlgConnection : public QDialog
{
    Q_OBJECT
    
signals:
    void connect_init(QString port, QString ip);

public:
    explicit DlgConnection(QWidget *parent = 0);
    ~DlgConnection();
    QString getIP();
    int getPort();
    QString getUsername();

    void setIP(QString addr);
    void setPort(int port);
    void setUsername(QString name);
    
private:
    Ui::DlgConnection *ui;
    QString server_addr, username;
    int server_port;

public slots:
    void connectTo();
};

#endif // DLGCONNECTION_H
