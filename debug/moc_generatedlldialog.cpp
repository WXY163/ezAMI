/****************************************************************************
** Meta object code from reading C++ file 'generatedlldialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../generatedlldialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'generatedlldialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_generateDllDialog_t {
    QByteArrayData data[8];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_generateDllDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_generateDllDialog_t qt_meta_stringdata_generateDllDialog = {
    {
QT_MOC_LITERAL(0, 0, 17), // "generateDllDialog"
QT_MOC_LITERAL(1, 18, 11), // "generateDll"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 17), // "dllGenerateStatus"
QT_MOC_LITERAL(4, 49, 6), // "stdOut"
QT_MOC_LITERAL(5, 56, 6), // "stdErr"
QT_MOC_LITERAL(6, 63, 29), // "on_GeneratePushButton_clicked"
QT_MOC_LITERAL(7, 93, 26) // "on_ClosePushButton_clicked"

    },
    "generateDllDialog\0generateDll\0\0"
    "dllGenerateStatus\0stdOut\0stdErr\0"
    "on_GeneratePushButton_clicked\0"
    "on_ClosePushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_generateDllDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   35,    2, 0x08 /* Private */,
       6,    0,   40,    2, 0x08 /* Private */,
       7,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void generateDllDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<generateDllDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->generateDll(); break;
        case 1: _t->dllGenerateStatus((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: _t->on_GeneratePushButton_clicked(); break;
        case 3: _t->on_ClosePushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (generateDllDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&generateDllDialog::generateDll)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject generateDllDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_generateDllDialog.data,
    qt_meta_data_generateDllDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *generateDllDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *generateDllDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_generateDllDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int generateDllDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void generateDllDialog::generateDll()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
