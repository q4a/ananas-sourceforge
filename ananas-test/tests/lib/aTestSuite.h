/*
 *  $Id: aTestSuite.h,v 1.4 2007/03/25 16:23:02 app Exp $
 *
 *  This file is part of QtUnit.
 *
 *  QtUnit is a unit testing framework for c++ which compiles into a shared
 *  library. It uses the Qt 3.x library for platform independence.
 *
 *  Copyright (C) 2002, G.Bevin
 *  Copyright (C) 2007 Ananas Project
 *  Copyright (C) 2007 Grigory Panov <grigory.panov at gmail.com>, Moscow
 * 
 *  gbevin@uwyn.com
 *  http://www.uwyn.com/projects/qtunit
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef QTUNIT_ATESTSUITE_H
#define QTUNIT_ATESTSUITE_H

#include "aCfgRcTestCase.h"
#include "aCfgTestCase.h"
#include "aFilterTestCase.h"
#include "aServiceTestCase.h"
#include "aMoneyTestCase.h"
#include "TestSuite.h"

namespace com_uwyn_qtunit
{
	class aTestSuite : public TestSuite
	{
	public:
		aTestSuite();
	
	private:
		aCfgRcTest	m_aCfgRcTestCase;
		aCfgTest	m_aCfgTestCase;
		aFilterTest 	m_aFilterTestCase;
		aServiceTest	m_aServiceTestCase;
		aMoneyTest	m_aMoneyTestCase;
	};
}

#endif
