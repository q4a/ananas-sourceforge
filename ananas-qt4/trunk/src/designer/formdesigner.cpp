/****************************************************************************
** $Id: formdesigner.cpp,v 1.10 2006/04/05 12:25:50 gr Exp $
**
** Code file of the Form designer of Ananas Designer applications
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

#include "formdesigner.h"

#include <QCloseEvent>

#include "../formdesigner/qdesigner_workbench.h"


//--aFormDesigner* aFormDesigner::m_designer = 0;

aFormDesigner::aFormDesigner()
{
    m_workbench = new QDesignerWorkbench();
    setCentralWidget(m_workbench->mainWindow());
}


aFormDesigner::~aFormDesigner()
{
}


/*aFormDesigner* aFormDesigner::designer()
{
    if (!m_designer)
        m_designer = new aFormDesigner();
    return m_designer;
}*/


/*QWidget* aFormDesigner::mainWindow()
{
    return m_workbench->mainWindow();
}*/


void aFormDesigner::fileOpen(const QString& fileName)
{
    //m_guibuilder->openFile(fileName);
    m_workbench->readInForm(fileName);
}


void aFormDesigner::closeEvent( QCloseEvent *e )
{
//CHECK_POINT
	e->accept();
//	deleteLater();
   // ( (MainForm*)this->topLevelWidget() )->removeTab(caption());
//	e->ignore();
}


void aFormDesigner::show()
{
    QMainWindow::show();
/*CHECK_POINT
	MainWindow::show();
CHECK_POINT
//	actioneditor()->hide();
	propertyeditor()->removePage( propertyeditor()->page( 1 ) ); //eventList()->hide();
	objectHierarchy()->parentWidget()->close();
	if(outputWindow() != NULL && outputWindow()->parentWidget()!=NULL)
	{

#ifndef _Windows
		outputWindow()->parentWidget()->close();
#endif
	}
	workspace()->parentWidget()->parentWidget()->close();*/
	//--mainWindow()->show();
}


void aFormDesigner::hide()
{
	QMainWindow::hide();
	//--fileSaveAll();
	//--fileClose();
  //  ( (MainForm*)this->topLevelWidget() )->removeTab(caption());
}


void aFormDesigner::mouseDoubleClickEvent ( QMouseEvent * e )
{
//CHECK_POINT

//	MainWindow::mouseDoubleClickEvent ( e );
}


/*GuiBuilderPart *aFormDesigner::guibuilder() const
{
  return m_guibuilder;
}*/
