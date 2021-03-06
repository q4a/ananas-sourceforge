/****************************************************************************
** $Id: alog.h,v 1.7 2006/08/23 07:57:21 app Exp $
**
** Log functions header file of
** Ananas application library
**
** Created : 20051024
**
** Copyright (C) 2003-2005 Grigory Panov, Yoshkar-Ola.
**
** This file is part of the Designer application of the Ananas
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

#ifndef ALOG_H
#define ALOG_H

//#include	"ananas.h"
#include	"ananasglobal.h"
#include 	<qstring.h>
#include 	<qfile.h>


// for bcc32.exe compatibility
// in file wingdi.h
// #define ERROR 0

#ifdef Q_OS_WIN32
#define ERROR IRROR
#endif

/*!
 *	\~english
 *	Class contain static functions for log system
 *	\~russian
 *	\brief Класс содержит статические функции для записи сообщений в лог файл Ананаса.
 *	\~
*/
class ANANAS_EXPORT aLog
{
	public:

//	enum status {
		/*!
		 * \~english Error
		 * \~russian Сообщение об ошибке
		 * \~
		 */
#ifdef Q_OS_WIN32
	static const int IRROR;//,
#else
	static const int ERROR;
#endif
		/*!
		 * \~english Info
		 * \~russian Информационное сообщение
		 * \~
		 */
	static const int INFO;//,
		/*!
		 * \~english Info
		 * \~russian Отладочное сообщение
		 * \~
		 */
	static const int DEBUG;// };

	static void 	print( int status, const QString &text);
	static void 	printr(	const QString &text);
	static void	init( const QString &logname="", int loglevel=0);
	static void 	close();
	static QString 	getLogName();


	private:
	aLog();
	static QString logName;
	static int logLevel;
	static QFile f;
	static bool msg_was_show;

};
#endif// ALOG_H
