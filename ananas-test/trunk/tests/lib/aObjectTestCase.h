/****************************************************************************
** $Id: aCfgRcTestCase.h,v 1.2 2007/03/12 20:10:16 gr Exp $
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
#ifndef QTUNIT_AOBJECTTEST_H
#define QTUNIT_AOBJECTTEST_H

#include <qstring.h>

#include "TestCase.h"

namespace com_uwyn_qtunit
{
	class aObjectTest : public TestCase
	{
	protected:
		QString	rcFile;
		QString	rcFileTest;
	public:
		aObjectTest();
		void	setUp();
	protected:
		void 	testCreateAbstractObject();
		void	testCreateBadDataObject();
	};
}

#endif

