/*
 *  $Id: QtUnitException.h,v 1.1 2007/02/28 21:55:19 gr Exp $
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

#ifndef QTUNITEXCEPTION_H
#define QTUNITEXCEPTION_H

#include <stdexcept>
#include <qstring.h>

namespace com_uwyn_qtunit
{
	class QtUnitException : public std::exception
	{
	public:
							QtUnitException(const QString& rMessage = "");
							QtUnitException(const QtUnitException& rOther);
	
		virtual             ~QtUnitException() throw();
		
		QtUnitException&	operator= (const QtUnitException& rOther);
		
		const char*			what() const throw();
	
	private:
		QString				mMessage;
	};
}

#endif
