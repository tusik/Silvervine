TEMPLATE = subdirs
VERSION = 0.0.1
DESTDIR = ../bin

SUBDIRS += \
    Silvervine
Silvervine.file = src/Silvervine.pro

CONFIG += ordered
OTHER_FILES += common.pri
