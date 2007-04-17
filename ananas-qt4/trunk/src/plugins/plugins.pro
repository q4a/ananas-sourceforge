TARGET    = ananasplugin

# Add by DmP
DLLDESTDIR = ../../bin
DESTDIR = ../../lib
LIBS += -L../../lib

SOURCES	= \
    acombobox.cpp \
	acombobox_plugin.cpp \
	addfdialog.cpp \
	aform.cpp \
	atoolbar.cpp \
	awidgets_plugin.cpp \
	catalogform.cpp \
	catalogformwidgets.cpp \
	eactionbutton.cpp \
	eaddobj.cpp \
	ecatalogue.cpp \
	edbfield.cpp \
	edbtable.cpp \
	edocument.cpp \
	efield.cpp \
	ejournal.cpp \
	engine.cpp \
	ereport.cpp \
	eselectdoctype.cpp \
	etable.cpp \
	wactionbutton.cpp \
	wactionbutton_plugin.cpp \
	wcatalogeditor.cpp \
	wcatalogue.cpp \
	wcatalogue_plugin.cpp \
	wdateedit.cpp \
	wdbfield.cpp \
	wdbfield_plugin.cpp \
	wdbtable.cpp \
	wdbtable_plugin.cpp \
	wdocument.cpp \
	wdocument_plugin.cpp \
	wfield.cpp \
	wfield_plugin.cpp \
	wgrouptree.cpp \
	wgrouptree_plugin.cpp \
	wjournal.cpp \
	wjournal_plugin.cpp \
	wreport.cpp \
	wreport_plugin.cpp \
	wtable.cpp \
	wtable_plugin.cpp
				
HEADERS	= \
    acombobox.h \
	acombobox_plugin.h \
	addfdialog.h \
	addfdialog.ui.h \
	aform.h \
	atoolbar.h \
	awidgets_plugin.h \
	catalogform.h \
	catalogform.ui.h \
	catalogformwidgets.h \
	eactionbutton.h \
	eactionbutton.ui.h \
	eaddobj.h \
	eaddobj.ui.h \
	ecatalogue.h \
	ecatalogue.ui.h \
	edbfield.h \
	edbfield.ui.h \
	edbtable.h \
	edbtable.ui.h \
	edocument.h \
	edocument.ui.h \
	efield.h \
	efield.ui.h \
	ejournal.h \
	ejournal.ui.h \
	engine.h \
	ereport.h \
	ereport.ui.h \
	eselectdoctype.h \
	eselectdoctype.ui.h \
	etable.h \
	etable.ui.h \
	qwidgetplugin.h \
	wactionbutton.h \
	wactionbutton_plugin.h \
	wcatalogeditor.h \
	wcatalogue.h \
	wcatalogue_plugin.h \
	wdateedit.h \
	wdbfield.h \
	wdbfield_plugin.h \
	wdbtable.h \
	wdbtable_plugin.h \
	wdocument.h \
	wdocument_plugin.h \
	wfield.h \
	wfield_plugin.h \
	wgrouptree.h \
	wgrouptree_plugin.h \
	wjournal.h \
	wjournal_plugin.h \
	wreport.h \
	wreport_plugin.h \
	wtable.h \
	wtable_plugin.h

# project file of Ananas plugins
unix {
    #INCLUDEPATH	+=../designer/.ui
    #system($QTDIR/bin/uic ../designer/mainform.ui -o mainform.h)
    #system($QTDIR/bin/uic ../designer/cfgform.ui -o cfgform.h)
}
win32 {
    #INCLUDEPATH	+=..\designer\tmp\ui
    #system(%QTDIR%\bin\uic ..\designer\mainform.ui -o mainform.h)
    #system(%QTDIR%\bin\uic ..\designer\cfgform.ui -o cfgform.h)
}

include ( ../ananas.pri )
#SLASH = /
unix {
	lplugin.path = $(QTDIR)/plugins/designer
	lplugin.files = libananasplugin.so
	lplugin.extra = cp -f libananasplugin.so $(INSTALL_ROOT)$(LIBDIR) || true
	lpluginheader.path = $(INCLUDEDIR)
	lpluginheader.files = $$HEADERS
}  

win32 {
	target.path = $(QTDIR)\plugins\designer
	lplugin.path = $(QTDIR)\plugins\designer
	lplugin.files = ananasplugin.*
	lplugin.extra = copy ananasplugin.* $(QTDIR)\lib
     }  

INSTALLS    += lplugin 
unix{
	INSTALLS += lpluginheader
}


shared {
win32:DEFINES+= QT_PLUGIN # ANANAS_DLL
} else {
win32:DEFINES   += ANANAS_NO_DLL
}

TRANSLATIONS = \
    ../../translations/ananas-plugins-en.ts \
    ../../translations/ananas-plugins-ru.ts 
	
FORMS = \
    addfdialog.ui \
	catalogform.ui \
	eactionbutton.ui \
	eaddobj.ui \
	ecatalogue.ui \
	edbfield.ui \
	edbtable.ui \
	edocument.ui \
	efield.ui \
	ejournal.ui \
	ereport.ui \
	eselectdoctype.ui \
	etable.ui
	
RESOURCE = \
    plugins.qrc
	
TEMPLATE	=lib
CONFIG	+= plugin
INCLUDEPATH	+= ../designer/formdesigner ../lib ../designer
LIBS	+= -L../lib -lananas -L$(QTDIR)/lib  -lqsa1 # Why? -L../designer -lformdesigner -lqassistantclient
unix{
LIBS	+=  -L/usr/X11R6/lib/
}
LIBS	-= -L..\..\plugins -lananasplugin
LANGUAGE	= C++
