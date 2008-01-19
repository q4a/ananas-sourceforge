/****************************************************************************
** $Id: aServiceTestCase.cpp,v 1.2 2007/03/26 14:14:38 app Exp $
**
** This file is part of unit-tests Ananas application 
**
** Created : 2007-03-12
**
** Copyright (C) 2007 Ananas Project
** Copyright (C) 2007 Andrey Paskal
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
**********************************************************************/
#include <qapplication.h>
#include "adatabase.h"
#include "acfgrc.h"
#include "aDatabaseTestCase.h"
// #include <qtextcodec.h>

using namespace com_uwyn_qtunit;

aDatabaseTest::aDatabaseTest() 
{
	addTest(aDatabaseTest, testDb);
}

void	
aDatabaseTest::setUp()
{
	qApp->addLibraryPath( "/usr/lib/ananas/qt3plugins" );
// 	QTextCodec::setCodecForCStrings( QTextCodec::codecForName("UTF8") );
}

void 	
aDatabaseTest::testDb()
{
	aCfgRc *dbParams = new aCfgRc;
	aDatabase* dataBase = new aDatabase;

	dbParams->setValue( "configfile" , "resourses/inventory-demo.cfg");
	dbParams->setValue( "dbhost" , "localhost");
	dbParams->setValue( "dbname" , "tests_tmp_db");
	dbParams->setValue( "dbuser" , "root");
	dbParams->setValue( "dbpass" , "");
	dbParams->setValue( "dbtype" , "mysql");

	qassertEquals( dataBase->init( dbParams, ""), true);

}

