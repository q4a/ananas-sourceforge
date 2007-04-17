TEMPLATE = lib 
CONFIG += warn_on link_prl
shared:CONFIG += qt dll
unix:VERSION = 1.0.1

TARGET = ananas

# Add by DmP
DLLDESTDIR = ../../bin
DESTDIR = ../../lib
LIBS += -L../../lib

SOURCES	= \
    aaregister.cpp \
	acalctemplate.cpp \
	acatalogue.cpp \
	acfg.cpp \
	acfgrc.cpp \
	acmanifest.cpp \
	acontainer.cpp \
	adatabase.cpp \
	adataexchange.cpp \
	adatafield.cpp \
	adocjournal.cpp \
	adocument.cpp \
	aextension.cpp \
	afilter.cpp \
	airegister.cpp \
	alog.cpp \
	amenubar.cpp \
	amoney.cpp \
	ananas.cpp \
	aobject.cpp \
	aobjectlist.cpp \
	aootemplate.cpp \
	areport.cpp \
	arole.cpp \
	aservice.cpp \
	asqlfield.cpp \
	asqltable.cpp \
	atemplate.cpp \
	atests.cpp \
	atime.cpp \
	auser.cpp \
	awidget.cpp \
	awindowslist.cpp \
	deditrc.cpp \
	dhelpcfgform.cpp \
	dimportdb.cpp \
	dlogin.cpp \
	dselectdb.cpp \
	itemplate.cpp \
	messageswindow.cpp \
	rclistviewitem.cpp

	
HEADERS	= \
    aaregister.h \
	acalctemplate.h \
	acatalogue.h \
	acfg.h \
	acfgrc.h \
	acmanifest.h \
	acontainer.h \
	adatabase.h \
	adataexchange.h \
	adatafield.h \
	adocjournal.h \
	adocument.h \
	aextension.h \
	afilter.h \
	airegister.h \
	alog.h \
	amenubar.h \
	amoney.h \
	ananas.h \
	ananasglobal.h \
	aobject.h \
	aobjectlist.h \
	aootemplate.h \
	areport.h \
	arole.h \
	aservice.h \
	asqlfield.h \
	asqltable.h \
	atemplate.h \
	atests.h \
	atime.h \
	auser.h \
	awidget.h \
	awindowslist.h \
	deditrc.h \
	deditrc.ui.h \
	dhelpcfgform.h \
	dhelpcfgform.ui.h \
	dimportdb.h \
	dlogin.h \
	dlogin.ui.h \
	dselectdb.h \
	dselectdb.ui.h \
	itemplate.h \
	messageswindow.h \
	rclistviewitem.h

	
unix{
	alib.path = $(LIBDIR) 
	alib.files = libananas.so.$$VERSION
	alib.extra = cp -df libananas.so* $(INSTALL_ROOT)$(LIBDIR)

	alibheader.path = $(INCLUDEDIR)
	alibheader.files = $$HEADERS
	alibheader.files += .ui/*h
    }

win32 {
	alib.path = $(QTDIR)\lib
	alib.files += ananas.dll
	alib.files += ananas.lib
#	alibheader.path = $(INCLUDEDIR)
#	alibheader.files = $$HEADERS
#	alibheader.files += tmp\ui\*h
      }

INSTALLS += alib
unix{
	INSTALLS += alibheader
}


shared {
	win32:DEFINES	+= ANANAS_DLL
} else {
	win32:DEFINES   += ANANAS_NO_DLL
}

# prodject file of Ananas Library
include ( ../ananas.pri )


win32 {
  CONFIG -= console
#  CONFIG += dll
}

TRANSLATIONS = \
    ../../translations/ananas-lib-en.ts \
    ../../translations/ananas-lib-ru.ts 


FORMS = \
    deditrc.ui \
	dhelpcfgform.ui \
	dlogin.ui \
	dselectdb.ui
	
RESOURCE = \
    lib.qrc

#INCLUDEPATH	+= ../plugins
LANGUAGE	= C++
LIBS		+= -L$(QTDIR)/plugins/designer -lqsa  # Why? -L../designer -lformdesigner
unix{
LIBS		+=  -L/usr/X11R6/lib/
}
win32 {
#LIBS		+= -L..\..\plugins -lananasplugin
}
