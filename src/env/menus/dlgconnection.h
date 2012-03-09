#ifndef DLGCONNECTION_H
#define DLGCONNECTION_H

#include <QDialog>

namespace Ui {
class DlgConnection;
}

class DlgConnection : public QDialog
{
    Q_OBJECT
    
public:
    explicit DlgConnection(QWidget *parent = 0);
    ~DlgConnection();
    QString getIP();
    QString getPort();
    QString getUsername();

    void setIP(QString addr);
    void setPort(QString port);
    void setUsername(QString name);
    
private:
    Ui::DlgConnection *ui;
    QString server_port, server_addr, username;

public slots:
    void connectTo();
};

#endif // DLGCONNECTION_H
