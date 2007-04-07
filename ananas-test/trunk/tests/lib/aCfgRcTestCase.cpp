/****************************************************************************
** $Id: aCfgRcTestCase.cpp,v 1.2 2007/03/12 20:10:16 gr Exp $
**
** This file is part of unit-tests Ananas application 
**
** Created : 2007-03-12
**
** Copyright (C) 2007 Ananas Project
** Copyright (C) 2007 Grigory Panov <grigory.panov at gmail.com>, Moscow
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
#include "aCfgRcTestCase.h"
#include "acfgrc.h"


using namespace com_uwyn_qtunit;

aCfgRcTest::aCfgRcTest()
{
	addTest(aCfgRcTest, testRead);
	addTest(aCfgRcTest, testWrite);
	addTest(aCfgRcTest, testValue);
	addTest(aCfgRcTest, testSetValue);
	addTest(aCfgRcTest, testCount);
	addTest(aCfgRcTest, testComplex);
}

void aCfgRcTest::setUp()
{
	rcFile = "tests/lib/test.rc";
	rcFileTest = "tests/lib/testTest.rc";
}

void aCfgRcTest::testRead()
{
	aCfgRc rc;
	qassertTrue(!rc.read(this->rcFile));
}

void aCfgRcTest::testWrite()
{
	aCfgRc rc;
	qassertTrue(!rc.read(this->rcFile));
	qassertTrue(!rc.write(this->rcFileTest));
}

void aCfgRcTest::testValue()
{
	aCfgRc rc;
	qassertTrue(!rc.read(this->rcFile));
	qassertEquals(rc.value("dbhost"), "localhost" );
	qassertEquals(rc.value("dbport"), "3306" );
	qassertEquals(rc.value("dbtype"), "mysql" );
	qassertEquals(rc.value("dbuser"), "root" );
	qassertEquals(rc.value("dbpass"), "" );
	qassertEquals(rc.value("dbtitle"), "testdb" );
	qassertEquals(rc.value("dbname"), "ananas_inventory_test" );
	qassertEquals(rc.value("configfile"), "tests/lib/test.cfg" );
	qassertEquals(rc.value("workdir"), "tests/lib/" );
	qassertEquals(rc.value("workdirFailed"), "" );

}

void aCfgRcTest::testSetValue()
{
	aCfgRc rc;
	qassertTrue(!rc.read(this->rcFile));

	rc.setValue("dbhost", "127.0.0.1" );
	rc.setValue("dbport", "3307" );
	rc.setValue("dbtype", "internal" );
	rc.setValue("dbuser", "root_ok" );
	rc.setValue("dbpass", "ok" );
	rc.setValue("dbtitle", "testdb_ok" );
	rc.setValue("dbname", "ananas_inventory_test_ok" );
	rc.setValue("configfile", "tests/lib/test_ok.cfg" );
	rc.setValue("workdir", "tests/lib/" );
	rc.setValue("workdirFailed", "boo!" );

	qassertEquals(rc.value("dbhost"), "127.0.0.1" );
	qassertEquals(rc.value("dbport"), "3307" );
	qassertEquals(rc.value("dbtype"), "internal" );
	qassertEquals(rc.value("dbuser"), "root_ok" );
	qassertEquals(rc.value("dbpass"), "ok" );
	qassertEquals(rc.value("dbtitle"), "testdb_ok" );
	qassertEquals(rc.value("dbname"), "ananas_inventory_test_ok" );
	qassertEquals(rc.value("configfile"), "tests/lib/test_ok.cfg" );
	qassertEquals(rc.value("workdir"), "tests/lib/" );
	qassertEquals(rc.value("workdirFailed"), "boo!" );

}

void aCfgRcTest::testCount()
{
	aCfgRc rc;
	qassertTrue(!rc.read(this->rcFile));
	qassertEquals(rc.count(), 9);
}

void aCfgRcTest::testComplex()
{
	aCfgRc rc;
	qassertTrue(!rc.read(this->rcFile));
	qassertEquals(rc.count(), 9);

	rc.setValue("dbhost", "127.0.0.1" );
	rc.setValue("dbport", "3307" );
	rc.setValue("dbtype", "internal" );
	rc.setValue("dbuser", "root_ok" );
	rc.setValue("dbpass", "ok" );
	rc.setValue("dbtitle", "testdb_ok" );
	rc.setValue("dbname", "ananas_inventory_test_ok" );
	rc.setValue("configfile", "test_ok.cfg" );
	rc.setValue("workdir", ".." );
	rc.setValue("workdirFailed", "boo!" );
	
	qassertTrue(!rc.write(this->rcFileTest));

	aCfgRc rc2;
	qassertTrue(!rc2.read(this->rcFileTest));
	qassertEquals(rc.count(), 10);

	qassertEquals(rc2.value("dbhost"), "127.0.0.1" );
	qassertEquals(rc2.value("dbport"), "3307" );
	qassertEquals(rc2.value("dbtype"), "internal" );
	qassertEquals(rc2.value("dbuser"), "root_ok" );
	qassertEquals(rc2.value("dbpass"), "ok" );
	qassertEquals(rc2.value("dbtitle"), "testdb_ok" );
	qassertEquals(rc2.value("dbname"), "ananas_inventory_test_ok" );
	qassertEquals(rc2.value("configfile"), "test_ok.cfg" );
	qassertEquals(rc2.value("workdir"), ".." );
	qassertEquals(rc2.value("workdirFailed"), "boo!" );
	qassertNotEquals(QString(rc2.value("workdirFailed1")), QString("boo!"));

}

