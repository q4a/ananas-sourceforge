/****************************************************************************
** $Id: aFilterTestCase.h,v 1.1 2007/03/17 11:31:39 gr Exp $
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

#ifndef QTUNIT_AFILTERTEST_H
#define QTUNIT_AFILTERTEST_H

#include "TestCase.h"

namespace com_uwyn_qtunit
{
	class aFilterTest : public TestCase
	{
	public:
		aFilterTest();
		void	setUp();
	protected:
		void	testClear();
		void 	testComplex();
	};
}

#endif

