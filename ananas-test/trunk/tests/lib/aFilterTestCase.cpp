/****************************************************************************
** $Id: aFilterTestCase.cpp,v 1.1 2007/03/17 11:31:39 gr Exp $
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
#include "aFilterTestCase.h"
#include "afilter.h"


using namespace com_uwyn_qtunit;

aFilterTest::aFilterTest()
{
	addTest(aFilterTest, testComplex);
	addTest(aFilterTest, testClear);
}

void aFilterTest::setUp()
{
	
}

void aFilterTest::testComplex()
{
	aFilter filter;
	Q_INT64 test = 31231232323ll;
	filter.Add("field_1", test, OperationEnumEquals, true);
	qassertEquals(filter.toString(), "field_1 = 31231232323 ");
	filter.Add("field_2", 12, OperationEnumEquals, true);
	qassertEquals(filter.toString(), "field_1 = 31231232323 AND field_2 = 12 ");
	filter.Add("field_3", "O'Connor > then O\"Relly", OperationEnumEquals, true);
	qassertEquals(filter.toString(), "field_1 = 31231232323 AND field_2 = 12 AND field_3 = \"O''Connor > then O\"\"Relly\" ");
	filter.Add("field_4", 13.3, OperationEnumLessThen, true);
	qassertEquals(filter.toString(), "field_1 = 31231232323 AND field_2 = 12 AND field_3 = \"O''Connor > then O\"\"Relly\" AND field_4 < 13.3 ");
	filter.Add("field_1", 120000, OperationEnumEquals, false, false);
	qassertEquals(filter.toString(), "field_1 = 31231232323 AND field_2 = 12 AND field_3 = \"O''Connor > then O\"\"Relly\" AND field_4 < 13.3 OR field_1 = 120000 ");
	filter.Add("field_2", 14, OperationEnumEquals, true, true );
	qassertEquals(filter.toString(), "field_1 = 31231232323 AND field_2 = 14 AND field_3 = \"O''Connor > then O\"\"Relly\" AND field_4 < 13.3 OR field_1 = 120000 ");
	filter.Clear();
	QDateTime now =  QDateTime::currentDateTime();
	filter.Add("field_5", now, OperationEnumGreaterThen, true);
	filter.Add("field_6", now.date(), OperationEnumLessOrEquals, true);
	qassertEquals(filter.toString(), QString("field_5 > \"%1\" AND field_6 <= \"%2\" ").arg(now.toString(Qt::ISODate)).arg(now.date().toString(Qt::ISODate)));
}


void aFilterTest::testClear()
{
	aFilter filter;
	filter.Add("qweqwe", "eqweqwe", OperationEnumEquals, true);
	qassertTrue(filter.toString() != QString::null);
	filter.Clear();
	qassertTrue(filter.toString() == QString::null);
	
}
