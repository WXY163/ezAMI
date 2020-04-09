/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[402];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 25), // "on_simulateButton_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 28), // "on_generateAmiButton_clicked"
QT_MOC_LITERAL(4, 67, 24), // "on_compileButton_clicked"
QT_MOC_LITERAL(5, 92, 21), // "on_saveButton_clicked"
QT_MOC_LITERAL(6, 114, 22), // "on_amiInit_textChanged"
QT_MOC_LITERAL(7, 137, 25), // "on_amiGetWave_textChanged"
QT_MOC_LITERAL(8, 163, 23), // "on_amiClose_textChanged"
QT_MOC_LITERAL(9, 187, 29), // "on_actionExcitation_triggered"
QT_MOC_LITERAL(10, 217, 22), // "on_actionAMI_triggered"
QT_MOC_LITERAL(11, 240, 23), // "on_actionPlot_triggered"
QT_MOC_LITERAL(12, 264, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(13, 289, 24), // "on_actionClose_triggered"
QT_MOC_LITERAL(14, 314, 24), // "on_checkBox_stateChanged"
QT_MOC_LITERAL(15, 339, 4), // "arg1"
QT_MOC_LITERAL(16, 344, 16), // "on_doubleClicked"
QT_MOC_LITERAL(17, 361, 8), // "position"
QT_MOC_LITERAL(18, 370, 15), // "receiveWaveForm"
QT_MOC_LITERAL(19, 386, 15) // "QVector<qreal>*"

    },
    "MainWindow\0on_simulateButton_clicked\0"
    "\0on_generateAmiButton_clicked\0"
    "on_compileButton_clicked\0on_saveButton_clicked\0"
    "on_amiInit_textChanged\0on_amiGetWave_textChanged\0"
    "on_amiClose_textChanged\0"
    "on_actionExcitation_triggered\0"
    "on_actionAMI_triggered\0on_actionPlot_triggered\0"
    "on_actionAbout_triggered\0"
    "on_actionClose_triggered\0"
    "on_checkBox_stateChanged\0arg1\0"
    "on_doubleClicked\0position\0receiveWaveForm\0"
    "QVector<qreal>*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    1,  101,    2, 0x08 /* Private */,
      16,    1,  104,    2, 0x08 /* Private */,
      18,    1,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::QPointF,   17,
    QMetaType::Void, 0x80000000 | 19,    2,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_simulateButton_clicked(); break;
        case 1: _t->on_generateAmiButton_clicked(); break;
        case 2: _t->on_compileButton_clicked(); break;
        case 3: _t->on_saveButton_clicked(); break;
        case 4: _t->on_amiInit_textChanged(); break;
        case 5: _t->on_amiGetWave_textChanged(); break;
        case 6: _t->on_amiClose_textChanged(); break;
        case 7: _t->on_actionExcitation_triggered(); break;
        case 8: _t->on_actionAMI_triggered(); break;
        case 9: _t->on_actionPlot_triggered(); break;
        case 10: _t->on_actionAbout_triggered(); break;
        case 11: _t->on_actionClose_triggered(); break;
        case 12: _t->on_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_doubleClicked((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 14: _t->receiveWaveForm((*reinterpret_cast< QVector<qreal>*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
