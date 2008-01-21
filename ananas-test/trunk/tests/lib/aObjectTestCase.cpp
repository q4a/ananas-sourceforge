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
#include "aObjectTestCase.h"
#include "aobject.h"
#include "adatabase.h"
#include "acfgrc.h"



using namespace com_uwyn_qtunit;

aObjectTest::aObjectTest()
{
	addTest(aObjectTest, testCreateAbstractObject);
	addTest(aObjectTest, testCreateBadDataObject);

}

void aObjectTest::setUp()
{
	//rcFile = "tests/lib/test.rc";
	//rcFileTest = "tests/lib/testTest.rc";
}

void aObjectTest::testCreateAbstractObject()
{
	aObject* abstractObject;
	abstractObject = new aObject();
	qassertNotEquals((int) abstractObject, 0);
	if ( abstractObject != 0) {
		delete abstractObject;
	}
}

void aObjectTest::testCreateBadDataObject()
{
	aCfgRc*		dbParams = new aCfgRc;
	aDatabase*	dataBase = new aDatabase;

	dbParams->setValue( "configfile" , "resourses/inventory-demo.cfg");
	dbParams->setValue( "dbhost" , "localhost");
	dbParams->setValue( "dbname" , "tests_tmp_db");
	dbParams->setValue( "dbuser" , "root");
	dbParams->setValue( "dbpass" , "");
	dbParams->setValue( "dbtype" , "mysql");

	// Устанавливаем соединение с базой данных dbname.
	qassertEquals( dataBase->init( dbParams, ""), true);

	// Создаем объект для тестирования
	// Используем неправильные параметры.
	aObject* dataObject  = new aObject("", dataBase, 0, "");
	
	// получаем результаты теста
	qassertNotEquals((int) dataObject, 0);
	qassertEquals(dataObject->LastErrorCode(), err_objnotfound); 
	
	if ( dataObject != 0) {
		delete dataObject;
	}
	
}
