/****************************************************************************
** $Id: itemplate.cpp,v 1.5 2005/07/04 10:23:51 red75 Exp $
**
** Report metadata object header file of 
** Ananas application library
**
** Created : 20031201
**
** Copyright (C) 2003-2004 Leader InfoTech.  All rights reserved.
** Copyright (C) 2003-2005 Grigory Panov, Yoshkar-Ola.
**
** This file is part of the Designer application of the Ananas 
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

//#include <sys/types.h>
//#include <sys/stat.h>
//#include <stdlib.h>
//#include <qfile.h>

#include "itemplate.h"


iTemplate::iTemplate()
    : QObject()
{
}

iTemplate::~iTemplate()
{
}

bool
iTemplate::open( const QString &)
{
	return true;
}

void 
iTemplate::close()
{
}

QString 
iTemplate::getValue( const QString & )
{
	return "";
}


void
iTemplate::setValue( const QString &, const QString & )
{
}

    
bool
iTemplate::save( const QString & )
{
	return true;
}


QString
iTemplate::exec( const QString & )
{
	return "";
}

void 
iTemplate::clear()
{
}

QString 
iTemplate::result()
{
	return "";
}
void
iTemplate::cleanUpTags()
{
}
void
iTemplate::setDir(const QString &)
{
}

QString
iTemplate::getDir()
{
	return "";
}
