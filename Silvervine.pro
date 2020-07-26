TEMPLATE = subdirs
VERSION = 0.0.1
DESTDIR = ../bin

SUBDIRS += \
    Silvervine \
    qml
Silvervine.file = src/Silvervine.pro

CONFIG += ordered
OTHER_FILES += common.pri
