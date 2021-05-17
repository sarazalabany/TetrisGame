QT   += core gui opengl

LIBS += -lopengl32

TARGET = tetris_game

release:DESTDIR = release
debug:DESTDIR = debug

#Directory for logic files
LOGIC_DIR = logic

#Directroy for interfaces
INTERFACE_DIR = interface

#Directory for ui
UI_DIR = ui

INCLUDEPATH += $$PWD/header/$$LOGIC_DIR/ \
               $$PWD/header/$$INTERFACE_DIR/ \
               $$PWD/header/$$UI_DIR/

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    $$PWD/source/$$LOGIC_DIR/*.cpp \
    $$PWD/source/$$INTERFACE_DIR/*.cpp \
    $$PWD/source/$$UI_DIR/*.cpp \


HEADERS += \
    $$PWD/header/$$LOGIC_DIR/*.h \
    $$PWD/header/$$INTERFACE_DIR/*.h \
    $$PWD/header/$$UI_DIR/*.h \


FORMS += \
    #$$PWD/mainwindow.ui \
    #header/ui/TetrisUi.ui \
    $$PWD/*.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ui/emptyFile
