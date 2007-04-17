#project for Engine application from Ananas automation accounting system
TARGET	= ananas

# Add by DmP
DESTDIR = ../../bin
LIBS += -L../../lib

include ( ../ananas.pri )

SOURCES	= \
    main.cpp \
	mainform.cpp
	
HEADERS	= \
    mainform.h
	
load(qsa)

TRANSLATIONS = \
    ../../translations/ananas-engine-en.ts \
    ../../translations/ananas-engine-ru.ts 
	

unix {
	ananas.path = $(BINDIR)
	ananas.files = ananas
     }
win32{
#	ananas.path =.
#	ananas.extra = CALL create_base.bat
     }	

INSTALLS += ananas

#FORMS	= qadocjournal.ui

RESOURCE = \
    ananas.qrc
	
TEMPLATE	=app

INCLUDEPATH	+= ../lib ../lib/tmp/ui ../lib/.ui ../plugins
LIBS	+= -L$(QTDIR)/lib -lqsa1  -L../lib -lananas -L../plugins -lananasplugin # Why? -lqui
