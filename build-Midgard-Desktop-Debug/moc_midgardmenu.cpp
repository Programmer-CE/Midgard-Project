/****************************************************************************
** Meta object code from reading C++ file 'midgardmenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Midgard/midgardmenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'midgardmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MidgardMenu_t {
    QByteArrayData data[6];
    char stringdata[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MidgardMenu_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MidgardMenu_t qt_meta_stringdata_MidgardMenu = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MidgardMenu"
QT_MOC_LITERAL(1, 12, 19), // "on_insertar_clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 17), // "on_borrar_clicked"
QT_MOC_LITERAL(4, 51, 14), // "on_ver_clicked"
QT_MOC_LITERAL(5, 66, 22) // "on_playOrPause_clicked"

    },
    "MidgardMenu\0on_insertar_clicked\0\0"
    "on_borrar_clicked\0on_ver_clicked\0"
    "on_playOrPause_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MidgardMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MidgardMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MidgardMenu *_t = static_cast<MidgardMenu *>(_o);
        switch (_id) {
        case 0: _t->on_insertar_clicked(); break;
        case 1: _t->on_borrar_clicked(); break;
        case 2: _t->on_ver_clicked(); break;
        case 3: _t->on_playOrPause_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MidgardMenu::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MidgardMenu.data,
      qt_meta_data_MidgardMenu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MidgardMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MidgardMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MidgardMenu.stringdata))
        return static_cast<void*>(const_cast< MidgardMenu*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MidgardMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
