/****************************************************************************
** $Id: deditireg.ui.h,v 1.9 2006/08/09 07:37:23 gr Exp $
**
** Code file of the Edit Information Register window
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


#include <qstatusbar.h>
#include "acfg.h"


void dEditIReg::init()
{
    delete statusBar();
}

void dEditIReg::destroy()
{
    updateMD();
    ( (MainForm*)this->topLevelWidget() )->wl->remove( this );
    ( (MainForm*)this->topLevelWidget() )->removeTab(name());
}

void dEditIReg::setData( aListViewItem *o )
{
	item = o;
	aCfg *md = o->md;
	aCfgItem obj = o->obj;
            aAliasEditor *a = new aAliasEditor( md, obj, tAliases );
	al = a;
	al->setData();
	setCaption( tr("Information register:") + md->attr( obj, mda_name ) );
	eName->setText( md->attr( obj, mda_name ) );
	if(md->attr(obj, mda_no_unconduct)=="1")
	{
	   	checkBox1->setChecked(true);
	}
	else
	{
	   	checkBox1->setChecked(false);
	}
	eDescription->setText( md->sText( obj, md_description ) );
}

void dEditIReg::updateMD()
{
	aCfg *md = item->md;
	aCfgItem obj = item->obj;

	al->updateMD();
	item->setText( 0, eName->text().stripWhiteSpace() );
	md->setAttr( obj, mda_name, eName->text().stripWhiteSpace() );
	md->setAttr( obj, mda_no_unconduct, checkBox1->isChecked()?"1":"0");
	md->setSText( obj, md_description, eDescription->text() );
}
