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
	qassertEquals( 
		aService::number2money(1001000.01, true, true, "рублей", "рубль", "рубля"), 
		"один миллион   одна тысяча    рублей   01 копейка");
	qassertEquals( 
		aService::number2money(1000001000.01, true, true, "рублей", "рубль", "рубля"), 
		"один миллиард   одна тысяча    рублей   01 копейка");
	qassertEquals( 
		aService::number2money(1000000001.00, true, true, "рублей", "рубль", "рубля"), 
		"один миллиард   один рубль   00 копеек");
		
// Преобразование в пропись для разных валют

	// РУБЛИ
	
	qassertEquals( aService::number2money("RUR",100.10), "Сто рублей 10 копеек");

  	qassertEquals( aService::number2money("RUR",0000.00), "Ноль рублей 0 копеек");
	qassertEquals( aService::number2money("RUR",1.01), "Один рубль 1 копейка");
	qassertEquals( aService::number2money("RUR",2.02), "Два рубля 2 копейки");
	qassertEquals( aService::number2money("RUR",3.03), "Три рубля 3 копейки");
	qassertEquals( aService::number2money("RUR",4.04), "Четыре рубля 4 копейки");
	qassertEquals( aService::number2money("RUR",5.05), "Пять рублей 5 копеек");
	qassertEquals( aService::number2money("RUR",1000.20), "Одна тысяча рублей 20 копеек");
	qassertEquals( aService::number2money("RUR",1002000.01), "Один миллион две тысячи рублей 1 копейка");
	qassertEquals( aService::number2money("RUR",1000001000.13), "Один миллиард одна тысяча рублей 13 копеек");
	qassertEquals( aService::number2money("RUR",1000000001.00), "Один миллиард один рубль 0 копеек");
	
	//Доллары США
	
	qassertEquals( aService::number2money("USD",100.10), "Сто долларов США 10 центов");
	qassertEquals( aService::number2money("USD",0000.00), "Ноль долларов США 0 центов");
	qassertEquals( aService::number2money("USD",1.01), "Один доллар США 1 цент");
	qassertEquals( aService::number2money("USD",2.02), "Два доллара США 2 цента");
	qassertEquals( aService::number2money("USD",3.03), "Три доллара США 3 цента");
	qassertEquals( aService::number2money("USD",4.04), "Четыре доллара США 4 цента");
	qassertEquals( aService::number2money("USD",5.05), "Пять долларов США 5 центов");
	qassertEquals( aService::number2money("USD",1000.20), "Одна тысяча долларов США 20 центов");
	qassertEquals( aService::number2money("USD",1002000.01), "Один миллион две тысячи долларов США 1 цент");
	qassertEquals( aService::number2money("USD",1000001000.13), "Один миллиард одна тысяча долларов США 13 центов");
	qassertEquals( aService::number2money("USD",1000000001.00), "Один миллиард один доллар США 0 центов");
	
	//ЕВРО
	
	qassertEquals( aService::number2money("EUR",100.10), "Сто евро 10 центов");
	qassertEquals( aService::number2money("EUR",0000.00), "Ноль евро 0 центов");
	qassertEquals( aService::number2money("EUR",1.01), "Один евро 1 цент");
	qassertEquals( aService::number2money("EUR",2.02), "Два евро 2 цента");
	qassertEquals( aService::number2money("EUR",3.03), "Три евро 3 цента");
	qassertEquals( aService::number2money("EUR",4.04), "Четыре евро 4 цента");
	qassertEquals( aService::number2money("EUR",5.05), "Пять евро 5 центов");
	qassertEquals( aService::number2money("EUR",1000.20), "Одна тысяча евро 20 центов");
	qassertEquals( aService::number2money("EUR",1002000.01), "Один миллион две тысячи евро 1 цент");
	qassertEquals( aService::number2money("EUR",1000001000.13), "Один миллиард одна тысяча евро 13 центов");
	qassertEquals( aService::number2money("EUR",1000000001.00), "Один миллиард один евро 0 центов");

}

