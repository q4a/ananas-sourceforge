/****************************************************************************
** $Id: deditdialog.ui.h,v 1.39 2006/04/05 12:25:50 gr Exp $
**
** Code file of the Edit Form view window
** of Ananas Designer applications
**
** Created : 20031201
**
** Copyright (C) 2003-2004 Leader InfoTech.  All rights reserved.
**
** This file is part of the Designer application  of the Ananas
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
#include <qstring.h>
#include <qfile.h>
#include <qstatusbar.h>
#include "acfg.h"
#include "qsproject.h"
#include "qsscript.h"
#include <qsinterpreter.h>
#include <qdialog.h>
//--#include <qwidgetfactory.h>
#include <QFormBuilder>
#include <qobject.h>
#include <q3textstream.h>
#include <qbuffer.h>
#include <qsinterpreter.h>
#include <qseditor.h>
#include <q3process.h>
#include <qapplication.h>

#include "formdesigner.h"
#include "mainform.h"
#include "alog.h"

//#include "qananastable.h"
//#include <unistd.h>

//extern QApplication *application;

void dEditDialog::init()
{
	delete statusBar();
	eModule->setInterpreter(new QSInterpreter());
//	fd = new aFormDesigner();
}


void dEditDialog::destroy()
{
    updateMD();
    ( (MainForm*)this->topLevelWidget() )->wl->remove( this );
    ( (MainForm*)this->topLevelWidget() )->removeTab(name());
}


void dEditDialog::setData( aListViewItem *o )
{
	item=NULL;
	QString parentClass;
	if (o) {
		item = o;
		aCfg *md = o->md;
		aCfgItem obj = o->obj;
		aAliasEditor *a = new aAliasEditor( md, obj, tAliases );
		al = a;
		al->setData();
		eName->setText( md->attr( obj, mda_name ) );
		eDescription->setText( md->sText( obj, md_description ) );
		eModule->setText( md->sText( obj, md_sourcecode ) );
		eFormFile->setText( QString("inputform_")+QString::number(item->id)+QString(".ui"));
		setCaption( tr("Form:") + eName->text() );
		parentClass = md->objClass( md->parent ( md->parent( obj ) ) );
		if ( parentClass == md_document ) {
//			cbFormMode->insertItem(QObject::tr("Document"));
		}
		if ( parentClass == md_catalogue ) {
//			cbDefault->insertItem(QObject::tr("selection"));
			cbFormMode->clear();
			cbFormMode->insertItem(QObject::tr("Elements list dialog"));
			cbFormMode->insertItem(QObject::tr("Element dialog"));
			cbFormMode->insertItem(QObject::tr("Group dialog"));
		}
		else cbSelect->setHidden( true );
		int i = md->sText(obj, md_defaultmod).toInt();
		cbNew->setChecked( (i>>md_form_new)%2 );
		cbView->setChecked( (i>>md_form_view)%2 );
		cbEdit->setChecked( (i>>md_form_edit)%2 );
		cbSelect->setChecked( (i>>md_form_select)%2 );
		i = md->attr( obj, mda_type ).toInt();
		cbFormMode->setCurrentItem( i );
		i = md->attr( obj, mda_readonly ).toInt();
		cbReadOnly->setChecked( i );
		QString ui= md->sText( obj, md_formdesign );
//		bPreview->setDisabled(ui.isEmpty());
	}
}

//#include "mainform.h"
//#include <formwindow.h>
//extern MainForm *mainform;

void dEditDialog::EditForm()
{

	aCfg *md = item->md;
	aCfgItem obj = item->obj, o;
	QString ui, s, tpl_name = "inputform.ui.tpl", tpldir;
	QFile f( eFormFile->text() );
//	char* arg;
//	int rc;
	aLog::print(aLog::DEBUG,tr("dEditDialog edit form"));
	//MainForm *mw = (MainForm*) topLevelWidget();
	//printf("end getting pointer to Main form\n");
	QStringList env;
//	QProcess proc( this );

#ifdef Q_OS_WIN32
	tpldir = qApp->applicationDirPath()+"/templates/";
#else
	tpldir = "/usr/share/ananas/templates/";
#endif

/*
	int rc;
	char* arg;
	QFile f;
	QString s;
	const char *ui;
	int fc=0;

    if (cfg_rcfile()) {
	setenv("ANANASRCFILE",cfg_rcfile(),1);
    } else {
	cfg_message(1, "????????????! ???? ?????????????? ???????????????? ???????????????? ?????? ???????????? ?? ANANASRCFILE\n");
    }
*/

   if (!f.exists())
   {
	aLog::print(aLog::DEBUG,tr("dEditDialog form file does not exists"));
	ui= md->sText( obj, md_formdesign );
	if (!ui.isEmpty())
	{

		aLog::print(aLog::DEBUG, tr("dEditDialog create form file from metadata"));
		QFile f1(eFormFile->text());
		f1.open(QIODevice::WriteOnly);
		f1.writeBlock(ui, strlen(ui));
		f1.close();

	}
	else
	{
		aLog::print(aLog::DEBUG, tr("dEditDialog create new form file from template"));
		o = md->parent( md->parent( obj ) );
		if ( md->objClass( o ) == md_document ) tpl_name = "inputformdoc.ui.tpl";
		if ( md->objClass( o ) == md_catalogue ) tpl_name = "inputformcat.ui.tpl";
		if ( md->objClass( o ) == md_journal ) tpl_name = "inputformjourn.ui.tpl";
		if ( md->objClass( o ) == md_report ) tpl_name = "inputformrep.ui.tpl";
		QFile fi( tpldir+tpl_name );
		if ( fi.open( QIODevice::ReadOnly ))
		{
			if(f.open( QIODevice::WriteOnly ))
			{
				Q3TextStream tso( &f );
				tso.setEncoding( Q3TextStream::UnicodeUTF8 );
				QString form = fi.readAll();
//			printf("obj id = %i\n", md->id( o ) );
				form.replace( QString("$$$id$$$"), QString("%1").arg( md->id( o ) ) );
				form.replace( QString("$$$name$$$"), QString("") );
				form.replace( QString("$$$caption$$$"), md->attr( o, mda_name ) );
				tso << form; //tsi.read();
				fi.close();
				f.close();
			}
			else
			{
				aLog::print(aLog::ERROR, tr("dEditDialog open file %1 for write").arg(f.name()));
			}
		}
		else
		{
			aLog::print(aLog::ERROR,tr("dEditDialog open file %1 for read from templates directory %2").arg(tpl_name).arg(tpldir));
		}
//		s=QString("cp inputform.ui.tpl ")+  eFormFile->text();
// 		system((const char *)s);
	}
   }

   	if(!QFile(eFormFile->text()).exists())
   	{

		aLog::print(aLog::ERROR, tr("dEditDialog file %1 not exists").arg(eFormFile->text()));
   	}
	formdesigner->fileOpen( eFormFile->text() );
   	aLog::print(aLog::DEBUG, tr("dEditDialog show formdesigner"));
	formdesigner->show();

//	}


//
//	if (!proc.start()) {
//		printf("Error running qt designer\n");
//	}
//CHECK_POINT
/*
    if ((rc=fork())==0) {
	arg = strdup( (const char *) eFormFile->text() );
	execlp("designer","designer","-client",arg,0);
	printf("Error running qt designer: errno=%d\terror=%s\n",
		      errno,strerror(errno));
    } else if (rc==-1) {
	printf("Error while fork: errno=%d\terror=%s\n",
		      errno,strerror(errno));
    }
*/
}


void dEditDialog::EditModule()
{
//	cfgobj_editcode(objectptr);
}


void dEditDialog::updateMD()
{

    formdesigner->fileSaveAll();
	aCfg *md = item->md;
	aCfgItem obj = item->obj;
	QString ui;
	QFile f(eFormFile->text());
//if (cancelupdate) return;
	al->updateMD();
	item->setText( 0, eName->text().stripWhiteSpace() );
	md->setAttr( obj, mda_name, eName->text().stripWhiteSpace() );
	md->setAttr( obj, mda_type, cbFormMode->currentItem() );
	md->setAttr( obj, mda_readonly, cbReadOnly->isChecked() );
	md->setSText( obj, md_description, eDescription->text() );
	md->setSText( obj, md_sourcecode, eModule->text() );
//	ui.arg(cbDefault->currentItem());
//	md->setSText( obj, md_defaultmod, QString( "%1" ).arg( cbDefault->currentItem() ) );
	int i = (1<<md_form_new) * cbNew->isChecked() + \
		(1<<md_form_view) * cbView->isChecked() + \
		(1<<md_form_edit) * cbEdit->isChecked() +\
		(1<<md_form_select) * cbSelect->isChecked();
	md->setSText( obj, md_defaultmod, QString( "%1" ).arg( i ) );
	if (f.open(QIODevice::ReadOnly)){
		Q3TextStream ts(&f);
		ts.setEncoding(Q3TextStream::UnicodeUTF8);
		ui=ts.read();
		md->setSText( obj, md_formdesign, ui );
		f.close();
		f.remove();
	}

}



void dEditDialog::formPreview()
{
//    if ( !QFile::exists(eFormFile->text())) return;

	aCfg *md = item->md;
	aCfgItem obj = item->obj;
	QString ui, s;
	QFile f(eFormFile->text());

	if (!f.exists()){
		ui= md->sText( obj, md_formdesign );
		if (!ui.isEmpty()) {
			f.open(QIODevice::WriteOnly);
			f.writeBlock(ui, strlen(ui));
			f.close();
		} else {
		    return;
			QFile fi("inputform.ui.tpl");
			if ( fi.open( QIODevice::ReadOnly ) && f.open( QIODevice::WriteOnly ) ){
				Q3TextStream tsi( &fi ), tso( &f );
				tso << tsi.read();
				fi.close();
				f.close();
			}
		}
	}

	QIODevice *d;
	d= &f;
	d->open(QIODevice::ReadOnly);
	//--QWidget *form = QWidgetFactory::create(d);
    QFormBuilder fb;
    QWidget *form = fb.load(d);
	d->close();
	form->show();

}




int dEditDialog::getDocId()
{
    return docId;
}
