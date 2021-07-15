QT       += core gui
QT       += axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# More
RC_ICONS += ..\images\icon\icon.ico

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# QXlsx code for Application Qt project
QXLSX_PARENTPATH=./         # current QXlsx path is . (. means curret directory)
QXLSX_HEADERPATH=./header/  # current QXlsx header path is ./header/
QXLSX_SOURCEPATH=./source/  # current QXlsx source path is ./source/
include(./QXlsx.pri)

SOURCES += \
    autodocconfiguration.cpp \
    excelworker.cpp \
    facade.cpp \
    main.cpp \
    mainwindow.cpp \
    organisationschoicewindow.cpp \
    wordworker.cpp

HEADERS += \
    autodocconfiguration.hpp \
    excelworker.hpp \
    facade.hpp \
    mainwindow.hpp \
    organisationschoicewindow.hpp \
    wordworker.hpp

FORMS += \
    mainwindow.ui \
    organisationschoicewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
