/****************************************************************************
** Meta object code from reading C++ file 'media_handler.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/handler/media_handler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'media_handler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MediaHandler_t {
    const uint offsetsAndSize[74];
    char stringdata0[368];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MediaHandler_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MediaHandler_t qt_meta_stringdata_MediaHandler = {
    {
QT_MOC_LITERAL(0, 12), // "MediaHandler"
QT_MOC_LITERAL(13, 9), // "appending"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 2), // "id"
QT_MOC_LITERAL(27, 4), // "name"
QT_MOC_LITERAL(32, 6), // "artist"
QT_MOC_LITERAL(39, 4), // "year"
QT_MOC_LITERAL(44, 5), // "image"
QT_MOC_LITERAL(50, 8), // "duration"
QT_MOC_LITERAL(59, 17), // "completeAppending"
QT_MOC_LITERAL(77, 14), // "currentChanged"
QT_MOC_LITERAL(92, 11), // "typeChanged"
QT_MOC_LITERAL(104, 4), // "type"
QT_MOC_LITERAL(109, 15), // "positionChanged"
QT_MOC_LITERAL(125, 8), // "position"
QT_MOC_LITERAL(134, 14), // "shuffleChanged"
QT_MOC_LITERAL(149, 9), // "isShuffle"
QT_MOC_LITERAL(159, 11), // "sizeChanged"
QT_MOC_LITERAL(171, 4), // "play"
QT_MOC_LITERAL(176, 5), // "pause"
QT_MOC_LITERAL(182, 4), // "prev"
QT_MOC_LITERAL(187, 4), // "next"
QT_MOC_LITERAL(192, 18), // "mediaStatusChanged"
QT_MOC_LITERAL(211, 25), // "QMediaPlayer::MediaStatus"
QT_MOC_LITERAL(237, 6), // "status"
QT_MOC_LITERAL(244, 12), // "fileMetaData"
QT_MOC_LITERAL(257, 14), // "QMediaMetaData"
QT_MOC_LITERAL(272, 8), // "metaData"
QT_MOC_LITERAL(281, 6), // "choose"
QT_MOC_LITERAL(288, 12), // "changeSource"
QT_MOC_LITERAL(301, 9), // "getPlayer"
QT_MOC_LITERAL(311, 13), // "QMediaPlayer*"
QT_MOC_LITERAL(325, 7), // "request"
QT_MOC_LITERAL(333, 9), // "isPlaying"
QT_MOC_LITERAL(343, 13), // "toggleShuffle"
QT_MOC_LITERAL(357, 5), // "index"
QT_MOC_LITERAL(363, 4) // "size"

    },
    "MediaHandler\0appending\0\0id\0name\0artist\0"
    "year\0image\0duration\0completeAppending\0"
    "currentChanged\0typeChanged\0type\0"
    "positionChanged\0position\0shuffleChanged\0"
    "isShuffle\0sizeChanged\0play\0pause\0prev\0"
    "next\0mediaStatusChanged\0"
    "QMediaPlayer::MediaStatus\0status\0"
    "fileMetaData\0QMediaMetaData\0metaData\0"
    "choose\0changeSource\0getPlayer\0"
    "QMediaPlayer*\0request\0isPlaying\0"
    "toggleShuffle\0index\0size"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MediaHandler[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
      10,  175, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    6,  128,    2, 0x06,   11 /* Public */,
       9,    0,  141,    2, 0x06,   18 /* Public */,
      10,    0,  142,    2, 0x06,   19 /* Public */,
      11,    1,  143,    2, 0x06,   20 /* Public */,
      13,    1,  146,    2, 0x06,   22 /* Public */,
      15,    1,  149,    2, 0x06,   24 /* Public */,
      17,    0,  152,    2, 0x06,   26 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      18,    0,  153,    2, 0x0a,   27 /* Public */,
      19,    0,  154,    2, 0x0a,   28 /* Public */,
      20,    0,  155,    2, 0x0a,   29 /* Public */,
      21,    0,  156,    2, 0x0a,   30 /* Public */,
      22,    1,  157,    2, 0x0a,   31 /* Public */,
      25,    1,  160,    2, 0x0a,   33 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      28,    2,  163,    2, 0x02,   35 /* Public */,
      28,    1,  168,    2, 0x22,   38 /* Public | MethodCloned */,
      30,    0,  171,    2, 0x02,   40 /* Public */,
      32,    0,  172,    2, 0x02,   41 /* Public */,
      33,    0,  173,    2, 0x02,   42 /* Public */,
      34,    0,  174,    2, 0x02,   43 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::LongLong,    3,    4,    5,    6,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::ULongLong,   14,
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 23,   24,
    QMetaType::Void, 0x80000000 | 26,   27,

 // methods: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    3,   29,
    QMetaType::Void, QMetaType::Int,    3,
    0x80000000 | 31,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,

 // properties: name, type, flags
      12, QMetaType::Int, 0x00015103, uint(3), 0,
       8, QMetaType::LongLong, 0x00015001, uint(2), 0,
       7, QMetaType::QString, 0x00015001, uint(2), 0,
       4, QMetaType::QString, 0x00015001, uint(2), 0,
       5, QMetaType::QString, 0x00015001, uint(2), 0,
       6, QMetaType::Int, 0x00015001, uint(2), 0,
      35, QMetaType::Int, 0x00015001, uint(2), 0,
      14, QMetaType::LongLong, 0x00015103, uint(4), 0,
      16, QMetaType::Bool, 0x00015001, uint(5), 0,
      36, QMetaType::QSize, 0x00015001, uint(6), 0,

       0        // eod
};

void MediaHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MediaHandler *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->appending((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<qint64>>(_a[6]))); break;
        case 1: _t->completeAppending(); break;
        case 2: _t->currentChanged(); break;
        case 3: _t->typeChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->positionChanged((*reinterpret_cast< std::add_pointer_t<quint64>>(_a[1]))); break;
        case 5: _t->shuffleChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->sizeChanged(); break;
        case 7: _t->play(); break;
        case 8: _t->pause(); break;
        case 9: _t->prev(); break;
        case 10: _t->next(); break;
        case 11: _t->mediaStatusChanged((*reinterpret_cast< std::add_pointer_t<QMediaPlayer::MediaStatus>>(_a[1]))); break;
        case 12: _t->fileMetaData((*reinterpret_cast< std::add_pointer_t<QMediaMetaData>>(_a[1]))); break;
        case 13: _t->choose((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 14: _t->choose((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: { QMediaPlayer* _r = _t->getPlayer();
            if (_a[0]) *reinterpret_cast< QMediaPlayer**>(_a[0]) = std::move(_r); }  break;
        case 16: _t->request(); break;
        case 17: { bool _r = _t->isPlaying();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 18: _t->toggleShuffle(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QMediaMetaData >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MediaHandler::*)(int , QString , QString , int , QString , qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaHandler::appending)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MediaHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaHandler::completeAppending)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MediaHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaHandler::currentChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MediaHandler::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaHandler::typeChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MediaHandler::*)(quint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaHandler::positionChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MediaHandler::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaHandler::shuffleChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MediaHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MediaHandler::sizeChanged)) {
                *result = 6;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<MediaHandler *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->type(); break;
        case 1: *reinterpret_cast< qint64*>(_v) = _t->duration(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->image(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->artist(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->year(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->l_index(); break;
        case 7: *reinterpret_cast< qint64*>(_v) = _t->position(); break;
        case 8: *reinterpret_cast< bool*>(_v) = _t->isShuffle(); break;
        case 9: *reinterpret_cast< QSize*>(_v) = _t->size(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<MediaHandler *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setType(*reinterpret_cast< int*>(_v)); break;
        case 7: _t->setPosition(*reinterpret_cast< qint64*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject MediaHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_MediaHandler.offsetsAndSize,
    qt_meta_data_MediaHandler,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MediaHandler_t
, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<qint64, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<qint64, std::true_type>, QtPrivate::TypeAndForceComplete<bool, std::true_type>, QtPrivate::TypeAndForceComplete<QSize, std::true_type>, QtPrivate::TypeAndForceComplete<MediaHandler, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<qint64, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<quint64, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMediaPlayer::MediaStatus, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QMediaMetaData, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QMediaPlayer *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>

>,
    nullptr
} };


const QMetaObject *MediaHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MediaHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MediaHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MediaHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void MediaHandler::appending(int _t1, QString _t2, QString _t3, int _t4, QString _t5, qint64 _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MediaHandler::completeAppending()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MediaHandler::currentChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MediaHandler::typeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MediaHandler::positionChanged(quint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MediaHandler::shuffleChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MediaHandler::sizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
