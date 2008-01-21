TEMPLATE	=	lib
INCLUDEPATH	=	../../include /usr/include/ananas

CONFIG		+=	qt warn_on plugin release thread

HEADERS	 	=	aCfgRcTestCase.h\
			aCfgTestCase.h\
			aFilterTestCase.h \
			aServiceTestCase.h \
			aMoneyTestCase.h \
			aDatabaseTestCase.h \
			aObjectTestCase.h \
			aTestSuite.h

SOURCES		=	aCfgRcTestCase.cpp\
			aCfgTestCase.cpp\
			aFilterTestCase.cpp\
			aServiceTestCase.cpp\
			aMoneyTestCase.cpp\
			aDatabaseTestCase.cpp\
			aObjectTestCase.cpp \
			aTestSuite.cpp\
			aTestModule.cpp

TARGET			=	coretest
DESTDIR			=	../../tests-bin
MOC_DIR			=	moc
OBJECTS_DIR		=	obj	
unix:LIBS		+=	-lqtunit -L../../lib -lananas
win32:LIBS		+=	..\..\lib\qtunit.lib -lananas
#//unix:LIBS		+=	-L/opt/mpatrol/lib -lmpatrol -lbfd -liberty
