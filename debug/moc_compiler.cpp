/****************************************************************************
** Meta object code from reading C++ file 'compiler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../compiler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'compiler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_compiler_t {
    QByteArrayData data[9];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_compiler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_compiler_t qt_meta_stringdata_compiler = {
    {
QT_MOC_LITERAL(0, 0, 8), // "compiler"
QT_MOC_LITERAL(1, 9, 13), // "sendBuildInfo"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 13), // "amiGeneration"
QT_MOC_LITERAL(4, 38, 26), // "on_buildPushButton_clicked"
QT_MOC_LITERAL(5, 65, 26), // "on_closePushButton_clicked"
QT_MOC_LITERAL(6, 92, 17), // "updateProjectArch"
QT_MOC_LITERAL(7, 110, 17), // "projectTreeModel*"
QT_MOC_LITERAL(8, 128, 4) // "arch"

    },
    "compiler\0sendBuildInfo\0\0amiGeneration\0"
    "on_buildPushButton_clicked\0"
    "on_closePushButton_clicked\0updateProjectArch\0"
    "projectTreeModel*\0arch"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_compiler[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   44,    2, 0x08 /* Private */,
       4,    0,   45,    2, 0x08 /* Private */,
       5,    0,   46,    2, 0x08 /* Private */,
       6,    1,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void compiler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<compiler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendBuildInfo((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->amiGeneration(); break;
        case 2: _t->on_buildPushButton_clicked(); break;
        case 3: _t->on_closePushButton_clicked(); break;
        case 4: _t->updateProjectArch((*reinterpret_cast< projectTreeModel*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (compiler::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&compiler::sendBuildInfo)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject compiler::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_compiler.data,
    qt_meta_data_compiler,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *compiler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *compiler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_compiler.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int compiler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void compiler::sendBuildInfo(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
