/****************************************************************************
** $Id: acfgrc.cpp,v 1.8 2005/07/24 00:56:10 leader Exp $
**
** Code file of the recorse work file of Ananas
** Designer and Engine applications
**
** Created : 20031201
**
** Copyright (C) 2003-2004 Leader InfoTech.  All rights reserved.
**
** This file is part of the Library of the Ananas
** automation accounting system.
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.leaderit.ru/page=ananas or email sales@leaderit.ru
** See http://www.leaderit.ru/gpl/ for GPL licensing information.
**
** Contact org@leaderit.ru if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

#include <stdlib.h>
#include <qfile.h>
#include <qstringlist.h>
#include <qtextstream.h>
#include <qpixmap.h>
#include <qdragobject.h>

#include "acfg.h"
#include "acfgrc.h"
#include "messageswindow.h"

QPixmap
rcIcon(const char *name){
	QPixmap pm;
	const QMimeSource *e;
	e=QMimeSourceFactory::defaultFactory()->data(QString(name));
	QImageDrag::decode(e, pm);
	return pm;
}



void
aMessageOutput( QtMsgType type, const char *msg )
{
	switch ( type ) {
	case QtDebugMsg:
		cfg_message( 0, "%s\n", msg );
        	break;
        case QtWarningMsg:
                cfg_message( 1, "%s\n", msg );
                break;
        case QtFatalMsg:
                cfg_message( 2, "%s\n", msg );
                abort();                    // deliberately core dump
        }
}

void
setMessageHandler( bool ) // GUI )
{
//	qInstallMsgHandler( aMessageOutput );
//	if ( GUI ) {
//		cfg_messageproc = messageproc;
//		cfg_message( 0, "<img source=\"a_system.png\">");
//	}
}

void
unsetMessageHandler()
{
	qInstallMsgHandler( 0 );
	cfg_messageproc = 0;
}

/*!
Ananas resource file object.
*/
aCfgRc::aCfgRc()
{
	values.setAutoDelete( TRUE );
}

int
aCfgRc::read(const QString &fname)
{
	QStringList l;
	QFile file( fname );

	filename = fname;
	values.clear();
	if ( file.open( IO_ReadOnly ) )
	{
		QTextStream stream( &file );
		QString line, k, v;

		stream.setEncoding(QTextStream::UnicodeUTF8);
		while ( !stream.eof() ) {
			line = stream.readLine(); // line of text excluding '\n'
			k = line.section("=",0,0);
			v = line.section("=",1,100); if ( v.isNull() ) v = "";
			values.insert( k, new QString( v ) );
		}
		file.close();
		return 0;
	}
	return 1;
}


int
aCfgRc::write(const QString &fname)
{
	QFile file( fname );
//	int i;

	if ( file.open( IO_WriteOnly ) )
	{
		QTextStream stream( &file );
		QDictIterator<QString> it( values );
//		int i, vc;

		stream.setEncoding(QTextStream::UnicodeUTF8);
		for( ; it.current(); ++it )
		stream << it.currentKey() << "=" << *it.current() << endl;
//			cout << endl;
//		vc = values.count();
//		for ( i = 0; i< vc; i++) stream << *it << "\n";
		file.close();
		return 0;
	}
	return 1;
}


int
aCfgRc::write()
{
	return write( filename );
}


QString
aCfgRc::value(const QString &name)
{
	QString *s;
	s = values.find( name );
	if ( s ) return *s; else return "";
}


void
aCfgRc::setValue(const QString &name, const QString &value)
{
	if (values.find( name )) values.replace( name, new QString( value ));
	else values.insert( name, new QString( value ));
}


int
aCfgRc::count()
{
	return ( int ) values.count();
}
