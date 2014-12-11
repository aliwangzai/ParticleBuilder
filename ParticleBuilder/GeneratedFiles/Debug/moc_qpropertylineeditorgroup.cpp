/****************************************************************************
** Meta object code from reading C++ file 'qpropertylineeditorgroup.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Classes/qpropertylineeditorgroup.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qpropertylineeditorgroup.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QPropertyLineEditorGroup_t {
    QByteArrayData data[7];
    char stringdata[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QPropertyLineEditorGroup_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QPropertyLineEditorGroup_t qt_meta_stringdata_QPropertyLineEditorGroup = {
    {
QT_MOC_LITERAL(0, 0, 24),
QT_MOC_LITERAL(1, 25, 20),
QT_MOC_LITERAL(2, 46, 0),
QT_MOC_LITERAL(3, 47, 16),
QT_MOC_LITERAL(4, 64, 6),
QT_MOC_LITERAL(5, 71, 5),
QT_MOC_LITERAL(6, 77, 11)
    },
    "QPropertyLineEditorGroup\0propertyValueChanged\0"
    "\0IPropertyEditor*\0editor\0value\0"
    "changeValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QPropertyLineEditorGroup[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   29,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Double,    4,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    5,

       0        // eod
};

void QPropertyLineEditorGroup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QPropertyLineEditorGroup *_t = static_cast<QPropertyLineEditorGroup *>(_o);
        switch (_id) {
        case 0: _t->propertyValueChanged((*reinterpret_cast< IPropertyEditor*(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->changeValue((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< IPropertyEditor* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QPropertyLineEditorGroup::*_t)(IPropertyEditor * , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QPropertyLineEditorGroup::propertyValueChanged)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QPropertyLineEditorGroup::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QPropertyLineEditorGroup.data,
      qt_meta_data_QPropertyLineEditorGroup,  qt_static_metacall, 0, 0}
};


const QMetaObject *QPropertyLineEditorGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPropertyLineEditorGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QPropertyLineEditorGroup.stringdata))
        return static_cast<void*>(const_cast< QPropertyLineEditorGroup*>(this));
    return QWidget::qt_metacast(_clname);
}

int QPropertyLineEditorGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QPropertyLineEditorGroup::propertyValueChanged(IPropertyEditor * _t1, double _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
