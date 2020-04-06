QT       += core gui widgets


CONFIG += c11 c++17
############################################################
CONFIG += debug

#CONFIG += release
############################################################

SOURCES += \
    main.cpp \
    ConverterWindow.cpp

HEADERS += \
    ConverterWindow.h

FORMS += \
    ConverterWindow.ui

DISTFILES += \

unix:!macx: LIBS += -L$$PWD/../Amber3D_SL/build/ -lAmber3D_SL

INCLUDEPATH += $$PWD/../Amber3D_SL
DEPENDPATH += $$PWD/../Amber3D_SL

unix:!macx: PRE_TARGETDEPS += $$PWD/../Amber3D_SL/build/libAmber3D_SL.a




# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target
