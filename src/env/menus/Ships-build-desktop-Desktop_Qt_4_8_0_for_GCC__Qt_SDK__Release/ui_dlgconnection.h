/********************************************************************************
** Form generated from reading UI file 'dlgconnection.ui'
**
** Created: Wed Mar 14 12:21:37 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLGCONNECTION_H
#define UI_DLGCONNECTION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgConnection
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_connect;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineServerIP;
    QLineEdit *lineServerPort;
    QLineEdit *lineUsername;

    void setupUi(QDialog *DlgConnection)
    {
        if (DlgConnection->objectName().isEmpty())
            DlgConnection->setObjectName(QString::fromUtf8("DlgConnection"));
        DlgConnection->resize(195, 174);
        layoutWidget = new QWidget(DlgConnection);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 130, 168, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_cancel = new QPushButton(layoutWidget);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));

        horizontalLayout->addWidget(pushButton_cancel);

        pushButton_connect = new QPushButton(layoutWidget);
        pushButton_connect->setObjectName(QString::fromUtf8("pushButton_connect"));

        horizontalLayout->addWidget(pushButton_connect);

        widget = new QWidget(DlgConnection);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(21, 11, 154, 88));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineServerIP = new QLineEdit(widget);
        lineServerIP->setObjectName(QString::fromUtf8("lineServerIP"));

        verticalLayout->addWidget(lineServerIP);

        lineServerPort = new QLineEdit(widget);
        lineServerPort->setObjectName(QString::fromUtf8("lineServerPort"));

        verticalLayout->addWidget(lineServerPort);

        lineUsername = new QLineEdit(widget);
        lineUsername->setObjectName(QString::fromUtf8("lineUsername"));

        verticalLayout->addWidget(lineUsername);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(DlgConnection);
        QObject::connect(pushButton_cancel, SIGNAL(clicked()), DlgConnection, SLOT(close()));
        QObject::connect(pushButton_connect, SIGNAL(clicked()), DlgConnection, SLOT(connectTo()));

        QMetaObject::connectSlotsByName(DlgConnection);
    } // setupUi

    void retranslateUi(QDialog *DlgConnection)
    {
        DlgConnection->setWindowTitle(QApplication::translate("DlgConnection", "Connect To Server", 0, QApplication::UnicodeUTF8));
        pushButton_cancel->setText(QApplication::translate("DlgConnection", "Cancel", 0, QApplication::UnicodeUTF8));
        pushButton_connect->setText(QApplication::translate("DlgConnection", "Connect", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DlgConnection", "Server IP:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DlgConnection", "Port:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DlgConnection", "Username", 0, QApplication::UnicodeUTF8));
        lineServerIP->setInputMask(QApplication::translate("DlgConnection", "000.000.000.000; ", 0, QApplication::UnicodeUTF8));
        lineServerPort->setInputMask(QApplication::translate("DlgConnection", "99999; ", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgConnection: public Ui_DlgConnection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLGCONNECTION_H
