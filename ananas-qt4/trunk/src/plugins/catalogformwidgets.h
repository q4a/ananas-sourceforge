/****************************************************************************
** $Id: catalogformwidgets.h,v 1.12 2005/12/19 12:41:27 gr Exp $
**
** Catalogue metadata object implementation file of
** Ananas application library
**
** Created : 20031201
**
** Copyright (C) 2003-2004 Grigory Panov, Yoshkar-Ola.
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
#ifndef CATALOGFORMWIDGET_H
#define CATALOGFORMWIDGET_H

#include <stdlib.h>
#include <qwidget.h>
#include <qtimer.h>
#include <qlistbox.h>
#include <qlineedit.h>
#include <qlistview.h>
#include <qlayout.h> 
#include <qlabel.h>
#include <qevent.h> 
#include <qpopupmenu.h>
//class QVBoxLayout;

class aListBox:public QListBox
{
	Q_OBJECT
public:
	aListBox(QWidget *parent = 0, const char* name = 0, WFlags f = 0);
	~aListBox();
	void insertItem(const QString &s, long idx, int index = -1);
	void show(QWidget *w, QFrame *fr);//, QLabel *lb);
		
	long getId(int ind) { return atol(listPrivate->text(ind).ascii()); };
	
	void clear();
	//void setId(long idx) {id = idx;};
public slots:
	virtual void setFocus();

protected:
	
	virtual void keyPressEvent ( QKeyEvent *e );	
	void focusOutEvent ( QFocusEvent *e ); 
protected slots:
	void doubleClickHandler(QListBoxItem *i);
	//	QVBoxLayout* layout1;
//	QLabel * statusBar;	
signals:
	void keyArrowLRPressed();
	void keyArrowLRPressed(const QString&);
	void keyEnterPressed();
	void lostFocus();
	void sendMessage(const QString &);
private:
	QListBox* listPrivate;
};


class aLineEdit:public QLineEdit
{
	Q_OBJECT
public:
	aLineEdit( QWidget* parent, const char* name = 0 );
	~aLineEdit();
	
protected:
	virtual void keyPressEvent ( QKeyEvent *e );	
	
private:
	QTimer *timer;
	
public slots:
	void	stopTimer();
	virtual void 	setFocus();
protected slots:
	void	timerDone();
	void	timerRestart(const QString & s);
		
signals:
	void 	keyArrowPressed();
	void 	delayTextChanged(const QString &);
	void 	keyEnterPressed();
	void	sendMessage(const QString &);
};

class aListView : public QListView
{
	Q_OBJECT
public:
	aListView(QWidget* parent = 0, const char* name = 0, WFlags f = 0);
	~aListView();
	
	QPopupMenu *menu;
	void setDestination(const bool dest);
	bool getDestination();
protected:
	virtual void keyPressEvent ( QKeyEvent *e );	
	
public slots:
	
	void 	showMenu( QListViewItem* item, const QPoint& p, int);
	void 	newItem();
	void 	newGroup();
	void	delItem();
	void	markDeleted();
	void 	undoMarkDeleted();
	void	edit();
	void	select();
	virtual void 	setFocus();
	
protected slots:
	void 	doubleClickHandler( QListViewItem *, const QPoint&, int col);	
	
signals:
	
	void	sendMessage(const QString &);
 	void	newItemRequest(QListViewItem* parentItem);
	void	newGroupRequest(QListViewItem* parentItem);
	void	delItemRequest(QListViewItem* item);
	void	markDeletedRequest(QListViewItem* item);
	void 	undoMarkDeletedRequest(QListViewItem* item);
	void	editRequest(QListViewItem* item, int columnClicked);
	void	selectRequest(QListViewItem* item);
private:
	QListViewItem* parentItem;
	int columnClicked;
	bool toSelect;
};
#endif 

