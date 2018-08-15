#-------------------------------------------------
#
# Project created by QtCreator 2018-08-10T00:01:05
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = I3S
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17

SOURCES += \
        main.cpp \
    pattern/patternwindow.cpp \
    patternplus/patternpluswindow.cpp \
    straighten/straightenwindow.cpp \
    classic/classicwindow.cpp \
    contour/contourwindow.cpp \
    spot/spotwindow.cpp \
    startupselector.cpp \
    pattern/optionsgeneral.cpp \
    pattern/optionsresults.cpp \
    pattern/database.cpp \
    pattern/editmetadata.cpp \
    pattern/databaselist.cpp \
    tinyxml2/tinyxml2.cpp \
    pattern/renamedatabase.cpp \
    pattern/settings.cpp \
    pattern/metadata.cpp \
    esj/main.cpp \
    classic/classicwindow.cpp \
    contour/contourwindow.cpp \
    esj/main.cpp \
    pattern/database.cpp \
    pattern/databaselist.cpp \
    pattern/editmetadata.cpp \
    pattern/individual.cpp \
    pattern/metadata.cpp \
    pattern/optionsgeneral.cpp \
    pattern/optionsresults.cpp \
    pattern/patternwindow.cpp \
    pattern/record.cpp \
    pattern/renamedatabase.cpp \
    pattern/settings.cpp \
    patternplus/patternpluswindow.cpp \
    spot/spotwindow.cpp \
    straighten/straightenwindow.cpp \
    tinyxml2/tinyxml2.cpp \
    main.cpp \
    startupselector.cpp

HEADERS += \
    pattern/patternwindow.h \
    patternplus/patternpluswindow.h \
    straighten/straightenwindow.h \
    classic/classicwindow.h \
    contour/contourwindow.h \
    spot/spotwindow.h \
    startupselector.h \
    pattern/optionsgeneral.h \
    pattern/optionsresults.h \
    pattern/database.h \
    pattern/editmetadata.h \
    pattern/databaselist.h \
    tinyxml2/tinyxml2.h \
    pattern/renamedatabase.h \
    pattern/settings.h \
    pattern/metadata.h \
    esj/arm/convert.h \
    esj/arm/json_ex.h \
    esj/osx/convert.h \
    esj/osx/json_ex.h \
    esj/windows/convert.h \
    esj/windows/json_ex.h \
    esj/json_adapter.h \
    esj/json_lexer.h \
    esj/json_reader.h \
    esj/json_writer.h \
    esj/platform_selector.h \
    esj/pt.h \
    esj/stringer.h \
    classic/classicwindow.h \
    contour/contourwindow.h \
    esj/arm/convert.h \
    esj/arm/json_ex.h \
    esj/osx/convert.h \
    esj/osx/json_ex.h \
    esj/windows/convert.h \
    esj/windows/json_ex.h \
    esj/json_adapter.h \
    esj/json_lexer.h \
    esj/json_reader.h \
    esj/json_writer.h \
    esj/platform_selector.h \
    esj/pt.h \
    esj/stringer.h \
    pattern/database.h \
    pattern/databaselist.h \
    pattern/editmetadata.h \
    pattern/individual.h \
    pattern/metadata.h \
    pattern/optionsgeneral.h \
    pattern/optionsresults.h \
    pattern/patternwindow.h \
    pattern/record.h \
    pattern/renamedatabase.h \
    pattern/settings.h \
    patternplus/patternpluswindow.h \
    spot/spotwindow.h \
    straighten/straightenwindow.h \
    tinyxml2/tinyxml2.h \
    startupselector.h

FORMS += \
    pattern/patternwindow.ui \
    patternplus/patternpluswindow.ui \
    straighten/straightenwindow.ui \
    classic/classicwindow.ui \
    contour/contourwindow.ui \
    spot/spotwindow.ui \
    startupselector.ui \
    pattern/optionsgeneral.ui \
    pattern/optionsresults.ui \
    pattern/editmetadata.ui \
    pattern/databaselist.ui \
    pattern/renamedatabase.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    esj/doc/chrome-console.jpg \
    esj/doc/esj1.png \
    esj/doc/esj2.png \
    esj/doc/esj1.cleaned.svg \
    esj/doc/esj1.svg \
    esj/doc/esj2.svg \
    esj/doc/esj.html \
    esj/README.md \
    esj/build/esj.sln \
    esj/build/esj.vcxproj \
    esj/build/startup_MK64F12.s \
    esj/LICENSE \
    esj/build/esj.xcodeproj/project.pbxproj

RESOURCES += \
    resources.qrc
