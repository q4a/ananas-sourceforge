/****************************************************************************
** $Id: deditrc.ui.h,v 1.6 2006/04/04 11:17:47 gr Exp $
**
** Code file of the Ananas edit resource file window
** of Ananas Designer and Engine applications
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

/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you wish to add, delete or rename functions or slots use
** Qt Designer which will update this file, preserving your code. Create an
** init() function in place of a constructor, and a destroy() function in
** place of a destructor.
*****************************************************************************/
#include <q3filedialog.h>
//#include <qstring.h>


void dEditRC::setdata(QString nameRC, rcListViewItem *item)
{
//	QFile f;
//	QString s, sv, sn;
//	char buf[1025];
	it = item;
	QMap<QString,QString> cfg;

	cfg = aTests::readConfig(QDir::convertSeparators(nameRC));
	eRCFile->setText(QDir::convertSeparators(nameRC));
	eDBType->setCurrentItem(0);

	eDBTitle->setText(cfg["dbtitle"]);
	eDBName->setText(cfg["dbname"]);
	eDBUserName->setText(cfg["dbuser"]);
	ePass->setText(cfg["dbpass"]);
	eDBHost->setText(cfg["dbhost"]);
	eDBPort->setText(cfg["dbport"]);
	eCfgName->setText(QDir::convertSeparators(cfg["configfile"]));
	if(cfg["dbtype"]=="postgres") eDBType->setCurrentItem(3);
	if(cfg["dbtype"]=="mysql") eDBType->setCurrentItem(2);
	if(cfg["dbtype"]=="internal") eDBType->setCurrentItem(1);
	eWorkDir->setText(QDir::convertSeparators(cfg["workdir"]));
}


void dEditRC::updatecfg()
{
	QMap<QString,QString> cfg;

	cfg["dbtitle"]	= eDBTitle->text();
	cfg["dbname"]	= eDBName->text();
	if(eDBType->currentItem()==1) cfg["dbtype"] ="internal";
	if(eDBType->currentItem()==2) cfg["dbtype"] ="mysql";
	if(eDBType->currentItem()==3) cfg["dbtype"]= "postgres";
	cfg["dbuser"]	= eDBUserName->text();
	cfg["dbpass"]	= ePass->text();
	cfg["dbhost"]	= eDBHost->text();
	cfg["dbport"]	= eDBPort->text();
	cfg["workdir"]	= QDir::convertSeparators(eWorkDir->text());
	cfg["configfile"]= QDir::convertSeparators(eCfgName->text());

	aTests::writeConfig(QDir::convertSeparators(eRCFile->text()),cfg);
}



void dEditRC::onOK()
{
	updatecfg();
	it->rcfile = QDir::convertSeparators(eRCFile->text());
	it->setText(0,eDBTitle->text());
	accept();
}


void dEditRC::onRCFile()
{
		Q3FileDialog fd( QString::null,
  			tr("ananas config resource (*.rc)"),
			0, 0, TRUE );
		fd. setMode ( Q3FileDialog::AnyFile );
		fd.setSelection( QDir::convertSeparators(eRCFile->text()));
		if ( fd.exec() == QDialog::Accepted ) {
			eRCFile->setText(QDir::convertSeparators(fd.selectedFile()));
			setdata(eRCFile->text(),it);
		} else {
			return;
		}
}


void dEditRC::onCFGFile()
{
		Q3FileDialog fd( QString::null,
  			tr("ananas config file (*.cfg)"),
			0, 0, TRUE );
		fd. setMode ( Q3FileDialog::AnyFile );
		fd.setSelection( QDir::convertSeparators(eCfgName->text()));
		if ( fd.exec() == QDialog::Accepted ) {
			eCfgName->setText(QDir::convertSeparators(fd.selectedFile()));
		} else {
			return;
		}
}
