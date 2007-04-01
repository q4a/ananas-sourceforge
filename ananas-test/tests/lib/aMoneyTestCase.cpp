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

#include "amoney.h"
#include "aMoneyTestCase.h"
#include <qtextcodec.h>

using namespace com_uwyn_qtunit;

aMoneyTest::aMoneyTest() {
	addTest(aMoneyTest, testToText);
}

void	
aMoneyTest::setUp(){
	QTextCodec::setCodecForCStrings( QTextCodec::codecForName("UTF8") );
}

void 	
aMoneyTest::testToText(){
	
	// РУБЛИ
	
	AMoney* money = new AMoney(100.10);
	qassertEquals( money->toText(), "Сто рублей 10 копеек");
	money->setAmount(0000.00);
	qassertEquals( money->toText(), "Ноль рублей 0 копеек");
	money->setAmount(1.01);
	qassertEquals( money->toText(), "Один рубль 1 копейка");
	money->setAmount(2.02);
	qassertEquals( money->toText(), "Два рубля 2 копейки");
	money->setAmount(3.03);
	qassertEquals( money->toText(), "Три рубля 3 копейки");
	money->setAmount(4.04);
	qassertEquals( money->toText(), "Четыре рубля 4 копейки");
	money->setAmount(5.05);
	qassertEquals( money->toText(), "Пять рублей 5 копеек");
	money->setAmount(1000.20);
	qassertEquals( money->toText(), "Одна тысяча рублей 20 копеек");
	money->setAmount(1002000.01);
	qassertEquals( money->toText(), "Один миллион две тысячи рублей 1 копейка");
	money->setAmount(1000001000.13);
	qassertEquals( money->toText(), "Один миллиард одна тысяча рублей 13 копеек");
	money->setAmount(1000000001.00);
	qassertEquals( money->toText(), "Один миллиард один рубль 0 копеек");
	
	//Доллары США
	
	money->setAmount(100.10, "USD");
	qassertEquals( money->toText(), "Сто долларов США 10 центов");
	money->setAmount(0000.00);
	qassertEquals( money->toText(), "Ноль долларов США 0 центов");
	money->setAmount(1.01);
	qassertEquals( money->toText(), "Один доллар США 1 цент");
	money->setAmount(2.02);
	qassertEquals( money->toText(), "Два доллара США 2 цента");
	money->setAmount(3.03);
	qassertEquals( money->toText(), "Три доллара США 3 цента");
	money->setAmount(4.04);
	qassertEquals( money->toText(), "Четыре доллара США 4 цента");
	money->setAmount(5.05);
	qassertEquals( money->toText(), "Пять долларов США 5 центов");
	money->setAmount(1000.20);
	qassertEquals( money->toText(), "Одна тысяча долларов США 20 центов");
	money->setAmount(1002000.01);
	qassertEquals( money->toText(), "Один миллион две тысячи долларов США 1 цент");
	money->setAmount(1000001000.13);
	qassertEquals( money->toText(), "Один миллиард одна тысяча долларов США 13 центов");
	money->setAmount(1000000001.00);
	qassertEquals( money->toText(), "Один миллиард один доллар США 0 центов");
	
	//ЕВРО
	
	money->setAmount(100.10, "EUR");
	qassertEquals( money->toText(), "Сто евро 10 центов");
	money->setAmount(0000.00);
	qassertEquals( money->toText(), "Ноль евро 0 центов");
	money->setAmount(1.01);
	qassertEquals( money->toText(), "Один евро 1 цент");
	money->setAmount(2.02);
	qassertEquals( money->toText(), "Два евро 2 цента");
	money->setAmount(3.03);
	qassertEquals( money->toText(), "Три евро 3 цента");
	money->setAmount(4.04);
	qassertEquals( money->toText(), "Четыре евро 4 цента");
	money->setAmount(5.05);
	qassertEquals( money->toText(), "Пять евро 5 центов");
	money->setAmount(1000.20);
	qassertEquals( money->toText(), "Одна тысяча евро 20 центов");
	money->setAmount(1002000.01);
	qassertEquals( money->toText(), "Один миллион две тысячи евро 1 цент");
	money->setAmount(1000001000.13);
	qassertEquals( money->toText(), "Один миллиард одна тысяча евро 13 центов");
	money->setAmount(1000000001.00);
	qassertEquals( money->toText(), "Один миллиард один евро 0 центов");
}

