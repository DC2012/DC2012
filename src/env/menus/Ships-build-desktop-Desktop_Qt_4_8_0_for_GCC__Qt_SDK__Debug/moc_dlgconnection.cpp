/****************************************************************************
** Meta object code from reading C++ file 'dlgconnection.h'
**
** Created: Wed Mar 14 12:34:49 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Ships/dlgconnection.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlgconnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DlgConnection[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      53,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DlgConnection[] = {
    "DlgConnection\0\0port,ip\0"
    "connect_init(QString,QString)\0connectTo()\0"
};

void DlgConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DlgConnection *_t = static_cast<DlgConnection *>(_o);
        switch (_id) {
        case 0: _t->connect_init((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->connectTo(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DlgConnection::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DlgConnection::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DlgConnection,
      qt_meta_data_DlgConnection, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DlgConnection::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DlgConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DlgConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DlgConnection))
        return static_cast<void*>(const_cast< DlgConnection*>(this));
    return QDialog::qt_metacast(_clname);
}

int DlgConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void DlgConnection::connect_init(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
