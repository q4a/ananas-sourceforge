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
#ifndef ASERVICETESTCASE_H_
#define ASERVICETESTCASE_H_

#include "TestCase.h"

namespace com_uwyn_qtunit
{
	class aServiceTest : public TestCase
	{
	protected:
		float digit;
		QString spellRubKop;
		QString spellRubOnly;
	public:
		aServiceTest();
		void	setUp();
	protected:
		void 	testNumber2money();
	};
}


#endif /*ASERVICETESTCASE_H_*/
