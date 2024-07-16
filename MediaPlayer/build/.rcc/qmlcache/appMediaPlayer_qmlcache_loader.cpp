#include <QtQml/qqmlprivate.h>
#include <QtCore/qdir.h>
#include <QtCore/qurl.h>

namespace QmlCacheGeneratedCode {
namespace _0x5f_MediaPlayer_main_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _0x5f_MediaPlayer_screen_features_MusicPlayer_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _0x5f_MediaPlayer_screen_components_music_Controller_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _0x5f_MediaPlayer_screen_components_music_List_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _0x5f_MediaPlayer_screen_components_music_Player_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _0x5f_MediaPlayer_screen_components_music_IconButton_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _0x5f_MediaPlayer_screen_utils_js { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}

}
namespace {
struct Registry {
    Registry();
    ~Registry();
    QHash<QString, const QQmlPrivate::CachedQmlUnit*> resourcePathToCachedUnit;
    static const QQmlPrivate::CachedQmlUnit *lookupCachedUnit(const QUrl &url);
};

Q_GLOBAL_STATIC(Registry, unitRegistry)


Registry::Registry() {
        resourcePathToCachedUnit.insert(QStringLiteral("/MediaPlayer/main.qml"), &QmlCacheGeneratedCode::_0x5f_MediaPlayer_main_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/MediaPlayer/screen/features/MusicPlayer.qml"), &QmlCacheGeneratedCode::_0x5f_MediaPlayer_screen_features_MusicPlayer_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/MediaPlayer/screen/components/music/Controller.qml"), &QmlCacheGeneratedCode::_0x5f_MediaPlayer_screen_components_music_Controller_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/MediaPlayer/screen/components/music/List.qml"), &QmlCacheGeneratedCode::_0x5f_MediaPlayer_screen_components_music_List_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/MediaPlayer/screen/components/music/Player.qml"), &QmlCacheGeneratedCode::_0x5f_MediaPlayer_screen_components_music_Player_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/MediaPlayer/screen/components/music/IconButton.qml"), &QmlCacheGeneratedCode::_0x5f_MediaPlayer_screen_components_music_IconButton_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/MediaPlayer/screen/utils.js"), &QmlCacheGeneratedCode::_0x5f_MediaPlayer_screen_utils_js::unit);
    QQmlPrivate::RegisterQmlUnitCacheHook registration;
    registration.structVersion = 0;
    registration.lookupCachedQmlUnit = &lookupCachedUnit;
    QQmlPrivate::qmlregister(QQmlPrivate::QmlUnitCacheHookRegistration, &registration);
}

Registry::~Registry() {
    QQmlPrivate::qmlunregister(QQmlPrivate::QmlUnitCacheHookRegistration, quintptr(&lookupCachedUnit));
}

const QQmlPrivate::CachedQmlUnit *Registry::lookupCachedUnit(const QUrl &url) {
    if (url.scheme() != QLatin1String("qrc"))
        return nullptr;
    QString resourcePath = QDir::cleanPath(url.path());
    if (resourcePath.isEmpty())
        return nullptr;
    if (!resourcePath.startsWith(QLatin1Char('/')))
        resourcePath.prepend(QLatin1Char('/'));
    return unitRegistry()->resourcePathToCachedUnit.value(resourcePath, nullptr);
}
}
int QT_MANGLE_NAMESPACE(qInitResources_qmlcache_appMediaPlayer)() {
    ::unitRegistry();
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_qmlcache_appMediaPlayer))
int QT_MANGLE_NAMESPACE(qCleanupResources_qmlcache_appMediaPlayer)() {
    return 1;
}
