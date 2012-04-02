/****************************************************************************
** Meta object code from reading C++ file 'tile.h'
**
** Created: Tue Mar 20 14:48:14 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "tile.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Tile[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x0a,
      15,    5,    5,    5, 0x0a,
      23,    5,    5,    5, 0x0a,
      35,   32,    5,    5, 0x0a,
      54,    5,    5,    5, 0x0a,
      62,    5,    5,    5, 0x0a,
      72,   70,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Tile[] = {
    "Tile\0\0update()\0reset()\0toggle()\0,,\0"
    "apply(int,int,int)\0print()\0clear()\0,\0"
    "genXML(QDomDocument*,QDomElement*)\0"
};

void Tile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Tile *_t = static_cast<Tile *>(_o);
        switch (_id) {
        case 0: _t->update(); break;
        case 1: _t->reset(); break;
        case 2: _t->toggle(); break;
        case 3: _t->apply((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->print(); break;
        case 5: _t->clear(); break;
        case 6: _t->genXML((*reinterpret_cast< QDomDocument*(*)>(_a[1])),(*reinterpret_cast< QDomElement*(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Tile::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Tile::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_Tile,
      qt_meta_data_Tile, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Tile::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Tile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Tile::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tile))
        return static_cast<void*>(const_cast< Tile*>(this));
    return QPushButton::qt_metacast(_clname);
}

int Tile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
