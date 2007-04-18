TARGET = ananas
TEMPLATE = app

DESTDIR = ../../bin

INCLUDEPATH += ../lib ../../tmp/ui/lib ../plugins
LIBS += -L../../lib -lananas -lananasplugin -L$(QTDIR)/lib -lqsa1
#LIBS += -L$(QTDIR)/lib -lqsa1  -L../lib -lananas -L../plugins -lananasplugin # -lqui

MOC_DIR = ../../tmp/moc/$$TARGET
OBJECTS_DIR = ../../tmp/obj/$$TARGET
UI_DIR = ../../tmp/ui/$$TARGET

include ( ../ananas.pri )
load(qsa)

HEADERS = \
    mainform.h

SOURCES = \
    main.cpp \
    mainform.cpp

#FORMS = qadocjournal.ui

RESOURCE = \
    ananas.qrc
    
TRANSLATIONS = \
    ../../translations/ananas-engine-en.ts \
    ../../translations/ananas-engine-ru.ts 
    
unix {
    ananas.path = $(BINDIR)
    ananas.files = ananas
}
win32{
#    ananas.path =.
#    ananas.extra = CALL create_base.bat
}    

INSTALLS += ananas
