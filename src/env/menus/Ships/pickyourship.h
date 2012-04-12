#ifndef PICKYOURSHIP_H
#define PICKYOURSHIP_H

#include <QDialog>
#include "client.h"

namespace Ui {
class PickYourShip;
}

class PickYourShip : public QDialog
{
    Q_OBJECT
    
public:
    explicit PickYourShip(QWidget *parent = 0);
    ~PickYourShip();

signals:
    void shipChosen(QString shipType);
    
private slots:
    void on_btnShip1_clicked();
    void on_btnShip2_clicked();
    void on_btnShip3_clicked();

private:
    Ui::PickYourShip*   ui;
    Client*             client_;
};

#endif // PICKYOURSHIP_H
