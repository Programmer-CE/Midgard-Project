/****************************************************************************
** Meta object code from reading C++ file 'fclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Midgard/logic/connectionManager/fclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FClient_t {
    QByteArrayData data[9];
    char stringdata[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FClient_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FClient_t qt_meta_stringdata_FClient = {
    {
QT_MOC_LITERAL(0, 0, 7), // "FClient"
QT_MOC_LITERAL(1, 8, 14), // "messageReceive"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 14), // "connectionOpen"
QT_MOC_LITERAL(4, 39, 16), // "connectionClosed"
QT_MOC_LITERAL(5, 56, 11), // "onConnected"
QT_MOC_LITERAL(6, 68, 6), // "unplug"
QT_MOC_LITERAL(7, 75, 11), // "ReadyToRead"
QT_MOC_LITERAL(8, 87, 4) // "send"

    },
    "FClient\0messageReceive\0\0connectionOpen\0"
    "connectionClosed\0onConnected\0unplug\0"
    "ReadyToRead\0send"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FClient[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FClient *_t = static_cast<FClient *>(_o);
        switch (_id) {
        case 0: _t->messageReceive(); break;
        case 1: _t->connectionOpen(); break;
        case 2: _t->connectionClosed(); break;
        case 3: _t->onConnected(); break;
        case 4: _t->unplug(); break;
        case 5: _t->ReadyToRead(); break;
        case 6: _t->send(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FClient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FClient::messageReceive)) {
                *result = 0;
            }
        }
        {
            typedef void (FClient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FClient::connectionOpen)) {
                *result = 1;
            }
        }
        {
            typedef void (FClient::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FClient::connectionClosed)) {
                *result = 2;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject FClient::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_FClient.data,
      qt_meta_data_FClient,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FClient::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FClient.stringdata))
        return static_cast<void*>(const_cast< FClient*>(this));
    return QObject::qt_metacast(_clname);
}

int FClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void FClient::messageReceive()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void FClient::connectionOpen()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void FClient::connectionClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
