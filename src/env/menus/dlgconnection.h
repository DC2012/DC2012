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
    std::string getIP();
    std::string getPort();
    
private:
    Ui::DlgConnection *ui;
    QString port, name;

private slots:

};

#endif // DLGCONNECTION_H
