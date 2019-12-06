/****************************************************************************
** Meta object code from reading C++ file 'MyLabel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "MyLabel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyLabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyLabel_t {
    QByteArrayData data[11];
    char stringdata0[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyLabel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyLabel_t qt_meta_stringdata_MyLabel = {
    {
QT_MOC_LITERAL(0, 0, 7), // "MyLabel"
QT_MOC_LITERAL(1, 8, 7), // "addMoto"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 8), // "addCoche"
QT_MOC_LITERAL(4, 26, 9), // "addCamion"
QT_MOC_LITERAL(5, 36, 11), // "recaudacion"
QT_MOC_LITERAL(6, 48, 9), // "clickOpen"
QT_MOC_LITERAL(7, 58, 10), // "clickClose"
QT_MOC_LITERAL(8, 69, 11), // "aumentaMoto"
QT_MOC_LITERAL(9, 81, 12), // "aumentaCoche"
QT_MOC_LITERAL(10, 94, 13) // "aumentaCamion"

    },
    "MyLabel\0addMoto\0\0addCoche\0addCamion\0"
    "recaudacion\0clickOpen\0clickClose\0"
    "aumentaMoto\0aumentaCoche\0aumentaCamion"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyLabel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       3,    1,   62,    2, 0x06 /* Public */,
       4,    1,   65,    2, 0x06 /* Public */,
       5,    1,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   71,    2, 0x0a /* Public */,
       7,    0,   72,    2, 0x0a /* Public */,
       8,    0,   73,    2, 0x0a /* Public */,
       9,    0,   74,    2, 0x0a /* Public */,
      10,    0,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyLabel *_t = static_cast<MyLabel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addMoto((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->addCoche((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->addCamion((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->recaudacion((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->clickOpen(); break;
        case 5: _t->clickClose(); break;
        case 6: _t->aumentaMoto(); break;
        case 7: _t->aumentaCoche(); break;
        case 8: _t->aumentaCamion(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyLabel::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyLabel::addMoto)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MyLabel::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyLabel::addCoche)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MyLabel::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyLabel::addCamion)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MyLabel::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyLabel::recaudacion)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject MyLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_MyLabel.data,
      qt_meta_data_MyLabel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyLabel.stringdata0))
        return static_cast<void*>(const_cast< MyLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int MyLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MyLabel::addMoto(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyLabel::addCoche(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyLabel::addCamion(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyLabel::recaudacion(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
