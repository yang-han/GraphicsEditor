#-------------------------------------------------
#
# Project created by QtCreator 2017-07-09T09:12:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GraphicsHandler
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


LIBS += /usr/local/lib/libopencv_highgui.so \
        /usr/local/lib/libopencv_core.so    \
        /usr/local/lib/libopencv_imgproc.so \
        /usr/local/lib/libopencv_imgcodecs.so

CONFIG += c++14



SOURCES += \
        main.cpp \
        view.cpp \
    common.cpp \
    viewmodel.cpp \
    model.cpp \
    parameters.cpp \
    command.cpp \
    command.cpp \
    common.cpp \
    main.cpp \
    model.cpp \
    parameters.cpp \
    view.cpp \
    viewmodel.cpp \
    command.cpp \
    common.cpp \
    main.cpp \
    model.cpp \
    parameters.cpp \
    view.cpp \
    viewmodel.cpp \
    command.cpp \
    common.cpp \
    main.cpp \
    model.cpp \
    parameters.cpp \
    view.cpp \
    viewmodel.cpp \
    command.cpp \
    common.cpp \
    main.cpp \
    model.cpp \
    parameters.cpp \
    view.cpp \
    viewmodel.cpp \
    command.cpp \
    common.cpp \
    main.cpp \
    model.cpp \
    parameters.cpp \
    view.cpp \
    viewmodel.cpp \
    Commands/open_file_command.cpp \
    command.cpp \
    common.cpp \
    main.cpp \
    model.cpp \
    parameters.cpp \
    view.cpp \
    viewmodel.cpp \
    app.cpp \
    notification.cpp

HEADERS += \
        view.h \
    common.h \
    viewmodel.h \
    model.h \
    parameters.h \
    command.h \
    command.h \
    common.h \
    model.h \
    parameters.h \
    view.h \
    viewmodel.h \
    command.h \
    common.h \
    model.h \
    parameters.h \
    view.h \
    viewmodel.h \
    command.h \
    common.h \
    model.h \
    parameters.h \
    view.h \
    viewmodel.h \
    command.h \
    common.h \
    model.h \
    parameters.h \
    view.h \
    viewmodel.h \
    command.h \
    common.h \
    model.h \
    parameters.h \
    view.h \
    viewmodel.h \
    Commands/open_file_command.h \
    command.h \
    common.h \
    model.h \
    parameters.h \
    view.h \
    viewmodel.h \
    app.h \
    notification.h

FORMS += \
        view.ui
