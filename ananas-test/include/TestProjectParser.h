/*
 *  $Id: TestProjectParser.h,v 1.1 2007/02/28 21:55:19 gr Exp $
 *
 *  This file is part of QtUnit.
 *
 *  QtUnit is a unit testing framework for c++ which compiles into a shared
 *  library. It uses the Qt 3.x library for platform independence.
 *
 *  Copyright (C) 2002, G.Bevin
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

#ifndef QTUNIT_TESTPROJECTPARSER_H
#define QTUNIT_TESTPROJECTPARSER_H

#include <qxml.h>

#include "Guards.h"

class QString;

namespace com_uwyn_qtunit
{
	class TestProject;
	
	class TestProjectParser : public QXmlDefaultHandler
	{
		REFERENCEOBJECT (TestProjectParser)
	
	public:
						TestProjectParser();
		virtual			~TestProjectParser();
	
		bool			startDocument();
		bool			startElement(const QString& rNamespaceURI, const QString& rLocalName, const QString& rQualifiedName, const QXmlAttributes& rAttributes);
		bool			characters(const QString& rCharacters);
		bool			endElement(const QString& rNamespaceURI, const QString& rLocalName, const QString& rQualifiedName);
		TestProject*	transferTestProject();
	
	private:
		void			cleanupTestProject();
	
		TestProject*	mpTestProject;
		QString			mModuleFilepath;
		QString			mModuleSourcepath;
		QString			mCharacterData;
	};                   
}

#endif 
