/****************************************************************************
** $Id: deditcat.ui.h,v 1.20 2004/12/23 14:37:55 gr Exp $
**
** Code file of the Edit Catalog window
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
#include <qsinterpreter.h>
#include <qseditor.h>
#include "acfg.h"

void dEditCat::setData( aListViewItem *o )
{
    long int i;
    int fid, fcount, fieldid, stdf;
    item = o;
    aCfg *md = o->md;
    aCfgItem obj = o->obj, sv, g, e, field;

    aAliasEditor *a = new aAliasEditor( md, obj, tAliases );
    al = a;
    al->setData();
    aRoleEditor *r = new aRoleEditor( md, obj, tRoles, md_catalogue );
    re = r;
    re->setData();
    setCaption( tr("Catalogue:") + md->attr( obj, mda_name ) );
    eName->setText( md->attr( obj, mda_name ) );
    eDescription->setText( md->sText( obj, md_description ) );
    g = md->find( obj, md_group ); // Find group context
    e = md->find( obj, md_element ); // Find Element context
    sv = md->find( g, md_string_view ); // Group string view
//====================================
    eStrViewFG->setText( md->sText( sv, md_svfunction ) );
    eSvG->insertItem( "[ standart function ]" );
    eSvG->insertItem( "[ user function ]" );
    fid = md->sText( sv, md_fieldid ).toInt();
    stdf = md->attr( sv, mda_stdf ).toInt();
    eSvG->setCurrentItem( 0 );
    for ( i = 0; i < md->count( g, md_field ); i++ ) {
	field = md->find( g, md_field, i );
	eSvG->insertItem( QString("%1").arg( md->attr( field, mda_name ) ) );
	fieldid = md->id( field );
	fieldsg.insert( i, new int( fieldid ) );
	if ( fid == fieldid && !stdf ) {
	    eSvG->setCurrentItem( i + 2 );
	    eStrViewFG->setEnabled( FALSE );
	}
    }
    if ( !fid && !stdf ) {
	eStrViewFG->setEnabled( TRUE );
	eSvG->setCurrentItem( 1 );
    }

//====================================
    sv = md->find( e, md_string_view );
    eStrViewF->setText( md->sText( sv, md_svfunction ) );
    eSv->insertItem( "[ standart function ]" );
    eSv->insertItem( "[ user function ]" );
    fid = md->sText( sv, md_fieldid ).toInt();
    stdf = md->attr( sv, mda_stdf ).toInt();
    eSv->setCurrentItem( 0 );
    for ( i = 0; i < md->count( e, md_field ); i++ ) {
	field = md->find( e, md_field, i );
	eSv->insertItem( QString("%1").arg( md->attr( field, mda_name ) ) );
	fieldid = md->id( field );
	fields.insert( i, new int( fieldid ) );
	if ( fid == fieldid && !stdf ) {
	    eSv->setCurrentItem( i + 2 );
	    eStrViewF->setEnabled( FALSE );
	}
    }
    if ( !fid && !stdf ) {
	eStrViewF->setEnabled( TRUE );
	eSv->setCurrentItem( 1 );
    }
}


void dEditCat::init()
{
	delete statusBar();
	eStrViewF->setInterpreter( new QSInterpreter() );
	eStrViewF->setEnabled( FALSE );
}


void dEditCat::updateMD()
{
    	aCfg *md = item->md;
	aCfgItem obj = item->obj, sv, g, e;

	al->updateMD();
	re->updateMD();
	item->setText( 0, eName->text().stripWhiteSpace() );
	md->setAttr( obj, mda_name, eName->text().stripWhiteSpace() );
	md->setSText( obj, md_description, eDescription->text() );
	g = md->find( obj, md_group ); // Find group context
	e= md->find( obj, md_element ); // Find Element context
	//======== Element view save
	sv = md->find( e, md_string_view );
	if ( sv.isNull() ) sv = md->insert( e, md_string_view );
	md->setSText( sv, md_svfunction, eStrViewF->text() );
	if ( eSv->currentItem() == 0 ) md->setAttr( sv, mda_stdf, "1" );
	else {
	    md->setAttr( sv, mda_stdf, "0" );
	    if ( eSv->currentItem() == 1 ) md->setSText( sv, md_fieldid, "0" );
	    else md->setSText( sv, md_fieldid, QString("%1").arg( *(fields.find( eSv->currentItem() - 2 ) ) ) );
	}
	//======== Group view save
	sv = md->find( g, md_string_view );
	if ( sv.isNull() ) sv = md->insert( g, md_string_view );
	md->setSText( sv, md_svfunction, eStrViewFG->text() );
	if ( eSvG->currentItem() == 0 ) md->setAttr( sv, mda_stdf, "1" );
	else {
	    md->setAttr( sv, mda_stdf, "0" );
	    if ( eSvG->currentItem() == 1 ) md->setSText( sv, md_fieldid, "0" );
	    else md->setSText( sv, md_fieldid, QString("%1").arg( *(fieldsg.find( eSvG->currentItem() - 2 ) ) ) );
	}

}

void dEditCat::destroy()
{
    updateMD();
    ( (MainForm*)this->topLevelWidget() )->wl->remove( this );
    ( (MainForm*)this->topLevelWidget() )->removeTab(name());
}




void dEditCat::eSv_activated( int index )
{
    if ( index == 1 ) eStrViewF->setEnabled( TRUE );
    else eStrViewF->setEnabled( FALSE );
}

void dEditCat::eSvG_activated( int index )
{
    if ( index == 1 ) eStrViewFG->setEnabled( TRUE );
    else eStrViewFG->setEnabled( FALSE );
}
