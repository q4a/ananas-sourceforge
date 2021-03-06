/****************************************************************************
** $Id: atime.h,v 1.4 2006/08/23 08:30:04 app Exp $
**
** Header file of the Accumulation Register of Ananas
** Engine applications
**
** Created : 20031201
**
** Copyright (C) 2003-2004 Leader InfoTech.  All rights reserved.
**
** This file is part of the Library of the Ananas
** automation accounting system.
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

#ifndef ATIME_H
#define ATIME_H

#include	<qobject.h>
#include	<qdatetime.h>
//#include	"airegister.h"
#include "ananas.h"




/*!
 *\en
 *\_en
 *\ru
 *	\brief Сервисный класс для работы с объектом Время
 *\_ru
 */
class ANANAS_EXPORT aTime : public QObject
{
	Q_OBJECT
public:
	aTime();
	~aTime();
protected:
	QTime *time;
public slots:

	virtual void start();
	virtual int restart();
	virtual int elapsed();
	virtual QString CurrentDate();
};

#endif// ATIME_H
