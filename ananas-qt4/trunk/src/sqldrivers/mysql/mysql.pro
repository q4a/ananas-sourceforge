TARGET = qsqlmysql4
TEMPLATE = lib

QT = core sql
CONFIG += qt plugin

DESTDIR = ../../../lib
DLLDESTDIR = ../../../bin/plugins/sqldrivers

DEFINES += QT_NO_CAST_TO_ASCII QT_NO_CAST_FROM_ASCII

MOC_DIR = ../../../tmp/moc/$$TARGET
OBJECTS_DIR = ../../../tmp/obj/$$TARGET
UI_DIR = ../../../tmp/ui/$$TARGET

HEADERS = \
    qsql_mysql.h
SOURCES	= \
    main.cpp \
    qsql_mysql.cpp

win32 {
#    CONFIG += debug_and_release
    CONFIG += release
    LIBS *= -lmysql    
}
unix {
    INCLUDEPATH += $$system(mysql_config --cflags|sed s/"-I"//)

	!contains( LIBS, .*mysql.* ) {
	    LIBS    *= $$system(mysql_config --libs) -lmysqlclient 
	}
}

#include (../../ananas.pri)
#unix:target.path  = .
#win32:target.path = $(QTDIR)\plugins\sqldrivers
#$(LIBDIR) = /usr/lib
#system(test -d $(LIBDIR)) {
# 	$(LIBDIR)=/usr/lib
#}	
win32 {
	sqlplugin.path = $(QTDIR)/plugins/sqldrivers
	sqlplugin.files = qsqlmysql4.*
}		
unix  {
	sqlplugin.path = $(QTDIR)/plugins/sqldrivers
	sqlplugin.files = libqsqlmysql4.so
}	

#INSTALLS += sqlplugin