/****************************************************************************
** Meta object code from reading C++ file 'filecheking.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../client/filecheking.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'filecheking.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FileCheking_t {
    QByteArrayData data[5];
    char stringdata0[52];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileCheking_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileCheking_t qt_meta_stringdata_FileCheking = {
    {
QT_MOC_LITERAL(0, 0, 11), // "FileCheking"
QT_MOC_LITERAL(1, 12, 12), // "loadFinished"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 16), // "CheckingThisFile"
QT_MOC_LITERAL(4, 43, 8) // "FileSize"

    },
    "FileCheking\0loadFinished\0\0CheckingThisFile\0"
    "FileSize"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileCheking[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       3,    1,   32,    2, 0x06 /* Public */,
       4,    1,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::Float,    2,

       0        // eod
};

void FileCheking::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FileCheking *_t = static_cast<FileCheking *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->CheckingThisFile((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->FileSize((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FileCheking::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FileCheking::loadFinished)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FileCheking::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FileCheking::CheckingThisFile)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (FileCheking::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FileCheking::FileSize)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject FileCheking::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_FileCheking.data,
      qt_meta_data_FileCheking,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FileCheking::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileCheking::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FileCheking.stringdata0))
        return static_cast<void*>(const_cast< FileCheking*>(this));
    return QThread::qt_metacast(_clname);
}

int FileCheking::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void FileCheking::loadFinished(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FileCheking::CheckingThisFile(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FileCheking::FileSize(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
