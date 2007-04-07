/****************************************************************************
** $Id: aCfgTestCase.cpp,v 1.4 2007/03/25 14:04:06 app Exp $
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
**********************************************************************/

#include "aCfgTestCase.h"
#include "acfg.h"


using namespace com_uwyn_qtunit;

aCfgTest::aCfgTest()
{
	addTest(aCfgTest, testRead);
	addTest(aCfgTest, testWrite);
	addTest(aCfgTest, testReadRc);
	addTest(aCfgTest, testWriteRc);
	addTest(aCfgTest, testModified);
	addTest(aCfgTest, testUnModified);
	addTest(aCfgTest, testInsertDocument);
	addTest(aCfgTest, testInsertCatalogue);
	addTest(aCfgTest, testComplex);
}

void aCfgTest::setUp()
{
	cfgFile = "tests/lib/test.cfg";
	cfgFileTest = "tests/lib/testTest.cfg";
	rcFile = "tests/lib/test.rc";
	rcFileTest = "tests/lib/testTest.rc";
}

void aCfgTest::testRead()
{
	aCfg cfg;
	qassertTrue(!cfg.read(this->cfgFile));
}

void aCfgTest::testWrite()
{
	aCfg cfg;
	qassertTrue(!cfg.read(this->cfgFile));
	qassertTrue(!cfg.write(this->cfgFileTest));
}

void aCfgTest::testReadRc()
{
	aCfg cfg;
	qassertTrue(!cfg.readrc(this->rcFile));
}

void aCfgTest::testWriteRc()
{
	aCfg cfg;
	qassertTrue(!cfg.readrc(this->rcFile));
	qassertTrue(!cfg.writerc(this->rcFileTest));
}

void aCfgTest::testModified()
{
	aCfg cfg;
	cfg.createNew();
	qassertTrue(cfg.modified());
}

void aCfgTest::testUnModified()
{
	aCfg cfg;
	qassertTrue(!cfg.read(this->cfgFile));
	qassertTrue(!cfg.write(this->cfgFileTest));
	qassertTrue(!cfg.modified());

}

void aCfgTest::testNew()
{
	aCfg cfg;
	cfg.createNew();
	qassertEquals(cfg.info(md_info_name), "New configuration");
	qassertEquals(cfg.info(md_info_lastid), "0");
	qassertEquals(cfg.info(md_info_author), "unnamed");
	qassertEquals(cfg.info(md_info_lastid), "0");
	qassertEquals(cfg.info(md_info_name), "New configuration");
}

void aCfgTest::testInsertDocument()
{
	aCfg cfg;
	qassertTrue(!cfg.read(this->cfgFile));
	qassertTrue(!cfg.insertDocument("test doc1").isNull());
}

void aCfgTest::testInsertCatalogue()
{
}


void aCfgTest::testComplex()
{

}

