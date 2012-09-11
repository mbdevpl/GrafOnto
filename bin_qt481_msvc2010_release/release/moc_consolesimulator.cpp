/****************************************************************************
** Meta object code from reading C++ file 'consolesimulator.h'
**
** Created: Mon 10. Sep 01:15:44 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/gui/consolesimulator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'consolesimulator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ConsoleSimulator[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,
      46,   17,   17,   17, 0x05,
      72,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
     106,   98,   17,   17, 0x0a,
     123,   17,   17,   17, 0x0a,
     140,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ConsoleSimulator[] = {
    "ConsoleSimulator\0\0commandExecutionCompleted()\0"
    "commandExecutionSuccess()\0"
    "commandExecutionFailure()\0command\0"
    "execute(QString)\0executeCurrent()\0"
    "pasteLastCommand()\0"
};

void ConsoleSimulator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ConsoleSimulator *_t = static_cast<ConsoleSimulator *>(_o);
        switch (_id) {
        case 0: _t->commandExecutionCompleted(); break;
        case 1: _t->commandExecutionSuccess(); break;
        case 2: _t->commandExecutionFailure(); break;
        case 3: _t->execute((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->executeCurrent(); break;
        case 5: _t->pasteLastCommand(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ConsoleSimulator::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ConsoleSimulator::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ConsoleSimulator,
      qt_meta_data_ConsoleSimulator, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ConsoleSimulator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ConsoleSimulator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ConsoleSimulator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConsoleSimulator))
        return static_cast<void*>(const_cast< ConsoleSimulator*>(this));
    return QWidget::qt_metacast(_clname);
}

int ConsoleSimulator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ConsoleSimulator::commandExecutionCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void ConsoleSimulator::commandExecutionSuccess()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void ConsoleSimulator::commandExecutionFailure()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
