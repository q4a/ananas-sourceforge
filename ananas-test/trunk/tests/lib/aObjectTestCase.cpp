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
#include "alog.h"



using namespace com_uwyn_qtunit;

aObjectTest::aObjectTest()
{
	_dbParams = 0;
	_dataBase = 0;
	addTest(aObjectTest, testCreateAbstractObject);
	addTest(aObjectTest, testCreateBadDataObject);
	addTest(aObjectTest, testCreateCatalogueDataObject);
	addTest(aObjectTest, testCreateDocumentDataObject);
	addTest(aObjectTest, testCreateDocJournalDataObject);
	addTest(aObjectTest, testCreateReportDataObject);
	addTest(aObjectTest, testCreateARegisterDataObject);
}

/**
 * 	Запускается перед каждым методом-тестом
 */
void aObjectTest::setUp()
{
	aLog::init();

	_dbParams = new aCfgRc;
	_dataBase = new aDatabase;

	_dbParams->setValue( "configfile" , "tests/lib/resources/inventory-demo.cfg");
	_dbParams->setValue( "dbhost" , "localhost");
	_dbParams->setValue( "dbname" , "tests_tmp_db");
	_dbParams->setValue( "dbuser" , "root");
	_dbParams->setValue( "dbpass" , "");
	_dbParams->setValue( "dbtype" , "mysql");

	// Устанавливаем соединение с базой данных dbname.
	//qassertEquals( _dataBase->init( _dbParams, ""), true);
	_dataBase->init( _dbParams, "");
	
	// Подгружаем содержимое файла метаданных в свойство cfg объекта доступа к БД
	_dataBase->cfg.read( _dbParams->value("configfile"));


}

/**
 * 	Запускается после каждого метода-теста
 */
void aObjectTest::tearDown()
{
	if ( _dbParams ) {
		delete _dbParams;
		_dbParams = 0;
	}
	if ( _dataBase ) {
		delete _dataBase;
		_dataBase = 0;
	}
}

void aObjectTest::testCreateAbstractObject()
{
	aObject* 	abstractObject;
	abstractObject = new aObject();
	
	// абстрактный объект должен быть успешно создан
	qassertNotEquals((int) abstractObject, 0);
	qassertEquals( abstractObject->LastErrorCode(), 0); 
	
	if ( abstractObject != 0) {
		delete abstractObject;
	}
}

void aObjectTest::testCreateBadDataObject()
{
	// Создаем объект для тестирования
	// Используем неправильные параметры.
	aObject* dataObject  = new aObject("", _dataBase);
	
	// получаем результаты теста
	qassertNotEquals((int) dataObject, 0);
	qassertEquals(dataObject->LastErrorCode(), err_objnotfound); 
	
	if ( dataObject != 0) {
		delete dataObject;
	}
	
}

void aObjectTest::testCreateCatalogueDataObject()
{
	// Создаем объект для тестирования
	aObject* dataObject  = new aObject("Catalogue.Каталог товаров", _dataBase);
	
	// Объект создан успешно и ошибок во время его инициализации не возникло 
	qassertNotEquals((int) dataObject, 0);
	qassertEquals(dataObject->LastErrorCode(), 0); 
	
	if ( dataObject != 0) {
		delete dataObject;
	}
}


void aObjectTest::testCreateDocumentDataObject()
{
	// Создаем объект для тестирования
	aObject* dataObject  = new aObject("Document.Расходная накладная", _dataBase);
	
	// Объект создан успешно и ошибок во время его инициализации не возникло 
	qassertNotEquals((int) dataObject, 0);
	qassertEquals(dataObject->LastErrorCode(), 0); 
	
	if ( dataObject != 0) {
		delete dataObject;
	}
}


void aObjectTest::testCreateDocJournalDataObject()
{
	// Создаем объект для тестирования
	aObject* dataObject  = new aObject("DocJournal.Журнал прихода", _dataBase);
	
	// Объект создан успешно и ошибок во время его инициализации не возникло 
	qassertNotEquals((int) dataObject, 0);
	qassertEquals(dataObject->LastErrorCode(), 0); 
	
	if ( dataObject != 0) {
		delete dataObject;
	}
}


void aObjectTest::testCreateReportDataObject()
{
	// Создаем объект для тестирования
	aObject* dataObject  = new aObject("Report.Движение товара", _dataBase);
	
	// Объект создан успешно и ошибок во время его инициализации не возникло 
	qassertNotEquals((int) dataObject, 0);
	qassertEquals(dataObject->LastErrorCode(), 0); 
	
	if ( dataObject != 0) {
		delete dataObject;
	}
}


void aObjectTest::testCreateARegisterDataObject()
{
	// Создаем объект для тестирования
	aObject* dataObject  = new aObject("AccumulationRegister.Главная книга", _dataBase);
	
	// Объект создан успешно и ошибок во время его инициализации не возникло 
	qassertNotEquals((int) dataObject, 0);
	qassertEquals(dataObject->LastErrorCode(), 0); 
	
	if ( dataObject != 0) {
		delete dataObject;
	}
}
