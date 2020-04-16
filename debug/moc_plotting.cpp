/****************************************************************************
** Meta object code from reading C++ file 'plotting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../plotting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plotting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_plotting_t {
    QByteArrayData data[16];
    char stringdata0[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_plotting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_plotting_t qt_meta_stringdata_plotting = {
    {
QT_MOC_LITERAL(0, 0, 8), // "plotting"
QT_MOC_LITERAL(1, 9, 15), // "plotBtn_clicked"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 15), // "stopBtn_clicked"
QT_MOC_LITERAL(4, 42, 12), // "dialogClosed"
QT_MOC_LITERAL(5, 55, 13), // "waveFormReady"
QT_MOC_LITERAL(6, 69, 15), // "QVector<qreal>*"
QT_MOC_LITERAL(7, 85, 10), // "XaxisSetup"
QT_MOC_LITERAL(8, 96, 20), // "on_buttonBox_clicked"
QT_MOC_LITERAL(9, 117, 16), // "QAbstractButton*"
QT_MOC_LITERAL(10, 134, 6), // "button"
QT_MOC_LITERAL(11, 141, 15), // "coordinateSetup"
QT_MOC_LITERAL(12, 157, 22), // "QHash<QString,QString>"
QT_MOC_LITERAL(13, 180, 14), // "excitationInfo"
QT_MOC_LITERAL(14, 195, 16), // "addSimulatedWave"
QT_MOC_LITERAL(15, 212, 9) // "simulated"

    },
    "plotting\0plotBtn_clicked\0\0stopBtn_clicked\0"
    "dialogClosed\0waveFormReady\0QVector<qreal>*\0"
    "XaxisSetup\0on_buttonBox_clicked\0"
    "QAbstractButton*\0button\0coordinateSetup\0"
    "QHash<QString,QString>\0excitationInfo\0"
    "addSimulatedWave\0simulated"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_plotting[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   60,    2, 0x08 /* Private */,
       8,    1,   63,    2, 0x08 /* Private */,
      11,    1,   66,    2, 0x08 /* Private */,
      14,    1,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::UChar,    2,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 6,   15,

       0        // eod
};

void plotting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<plotting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->plotBtn_clicked(); break;
        case 1: _t->stopBtn_clicked(); break;
        case 2: _t->dialogClosed(); break;
        case 3: _t->waveFormReady((*reinterpret_cast< QVector<qreal>*(*)>(_a[1]))); break;
        case 4: _t->XaxisSetup((*reinterpret_cast< uchar(*)>(_a[1]))); break;
        case 5: _t->on_buttonBox_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 6: _t->coordinateSetup((*reinterpret_cast< QHash<QString,QString>(*)>(_a[1]))); break;
        case 7: _t->addSimulatedWave((*reinterpret_cast< QVector<qreal>*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (plotting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&plotting::plotBtn_clicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (plotting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&plotting::stopBtn_clicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (plotting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&plotting::dialogClosed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (plotting::*)(QVector<qreal> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&plotting::waveFormReady)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject plotting::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_plotting.data,
    qt_meta_data_plotting,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *plotting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *plotting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_plotting.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int plotting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void plotting::plotBtn_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void plotting::stopBtn_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void plotting::dialogClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void plotting::waveFormReady(QVector<qreal> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
