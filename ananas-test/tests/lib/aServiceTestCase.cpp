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

#include "aservice.h"
#include "aServiceTestCase.h"

using namespace com_uwyn_qtunit;

aServiceTest::aServiceTest() {
	addTest(aServiceTest, testNumber2money);
}

void	
aServiceTest::setUp(){
	digit= 134.50;
	spellRubKop= "сто тридцать четыре рубля   50 копеек"; 
	spellRubOnly= "сто тридцать четыре рубля"; 
//	printf("result='%s'\n", (const char*) aService::number2money(
//		digit, true, false, "рублей", "рубль", "рубля" ));
}

void 	
aServiceTest::testNumber2money(){
	qassertEquals( aService::number2money(
		digit, true, true, "рублей", "рубль", "рубля" ), spellRubKop);
	qassertEquals( aService::number2money(
		digit, true, false, "рублей", "рубль", "рубля" ), spellRubKop);
	qassertEquals( aService::number2money(
		digit, false, true, "рублей", "рубль", "рубля" ), spellRubOnly);
	qassertEquals( aService::number2money(
		digit, false, false, "рублей", "рубль", "рубля" ), spellRubOnly);
}

