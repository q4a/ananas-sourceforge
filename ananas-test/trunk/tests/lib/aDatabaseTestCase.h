/****************************************************************************
** $Id: aServiceTestCase.h,v 1.2 2007/03/26 14:14:38 app Exp $
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
#ifndef ADATABASETESTCASE_H_
#define ADATABASETESTCASE_H_

#include "TestCase.h"

namespace com_uwyn_qtunit
{
	class aDatabaseTest : public TestCase {
	
	protected:
	public:
		aDatabaseTest();
		void	setUp();
	protected:
		void 	testDb();
	};
}


#endif /*AMONEYTESTCASE_H_*/
