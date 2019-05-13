/****************************************************************************
** Meta object code from reading C++ file 'processesinputform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../MemoryAllocationGUI/processesinputform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'processesinputform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_processesinputform_t {
    QByteArrayData data[11];
    char stringdata0[304];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_processesinputform_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_processesinputform_t qt_meta_stringdata_processesinputform = {
    {
QT_MOC_LITERAL(0, 0, 18), // "processesinputform"
QT_MOC_LITERAL(1, 19, 31), // "on_addProcessPushButton_clicked"
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 31), // "on_addSegmentPushButton_clicked"
QT_MOC_LITERAL(4, 84, 31), // "on_deallocatePushButton_clicked"
QT_MOC_LITERAL(5, 116, 29), // "on_allocatePushButton_clicked"
QT_MOC_LITERAL(6, 146, 25), // "on_drawPushButton_clicked"
QT_MOC_LITERAL(7, 172, 32), // "on_firstFitCheckBox_stateChanged"
QT_MOC_LITERAL(8, 205, 31), // "on_bestFitCheckBox_stateChanged"
QT_MOC_LITERAL(9, 237, 32), // "on_worstFitCheckBox_stateChanged"
QT_MOC_LITERAL(10, 270, 33) // "on_deallocatePushButton_2_cli..."

    },
    "processesinputform\0on_addProcessPushButton_clicked\0"
    "\0on_addSegmentPushButton_clicked\0"
    "on_deallocatePushButton_clicked\0"
    "on_allocatePushButton_clicked\0"
    "on_drawPushButton_clicked\0"
    "on_firstFitCheckBox_stateChanged\0"
    "on_bestFitCheckBox_stateChanged\0"
    "on_worstFitCheckBox_stateChanged\0"
    "on_deallocatePushButton_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_processesinputform[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

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

       0        // eod
};

void processesinputform::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<processesinputform *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_addProcessPushButton_clicked(); break;
        case 1: _t->on_addSegmentPushButton_clicked(); break;
        case 2: _t->on_deallocatePushButton_clicked(); break;
        case 3: _t->on_allocatePushButton_clicked(); break;
        case 4: _t->on_drawPushButton_clicked(); break;
        case 5: _t->on_firstFitCheckBox_stateChanged(); break;
        case 6: _t->on_bestFitCheckBox_stateChanged(); break;
        case 7: _t->on_worstFitCheckBox_stateChanged(); break;
        case 8: _t->on_deallocatePushButton_2_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject processesinputform::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_processesinputform.data,
    qt_meta_data_processesinputform,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *processesinputform::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *processesinputform::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_processesinputform.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int processesinputform::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
