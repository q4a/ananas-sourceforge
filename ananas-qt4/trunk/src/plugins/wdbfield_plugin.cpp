/****************************************************************************
**
** Code file
**
** Copyright (C) 2006 Dmitriy Pavlyuk <dm-p@rambler.ru>
**
** This file is part of the Ananas Plugins of the Ananas
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
**********************************************************************/

#include "wdbfield_plugin.h"

#include <QtPlugin>

#include "wdbfield.h"


wDBFieldPlugin::wDBFieldPlugin(QObject *parent)
    : QObject(parent), m_initialized(false)
{
    m_initialized = false;
}

bool wDBFieldPlugin::isContainer() const
{
    return false;
}

bool wDBFieldPlugin::isInitialized() const
{
    return m_initialized;
}

void wDBFieldPlugin::initialize(QDesignerFormEditorInterface *core)
{
    if (m_initialized)
        return;
    Q_UNUSED(core);
    m_initialized = true;
}

QWidget *wDBFieldPlugin::createWidget(QWidget *parent)
{
    wDBField *w = new wDBField(parent, 0);
    return w;
}

QString wDBFieldPlugin::name() const
{
    return QLatin1String("wDBField");
}

QString wDBFieldPlugin::group() const
{
    return QLatin1String("Ananas");
}

QString wDBFieldPlugin::toolTip() const
{
    return QString("Ananas for QT Database Field Edit Widget");
}

QString wDBFieldPlugin::whatsThis() const
{
    return QString("Entry to modify field value of Ananas's object");
}

QString wDBFieldPlugin::includeFile() const
{
    return QLatin1String("wdbfield.h");
}

QIcon wDBFieldPlugin::icon() const
{
    //return QIcon();
    return QIcon(":/images/wdbfield.png");
}

QString wDBFieldPlugin::domXml() const
{
    return "<widget class=\"wDBField\" name=\"wDBField_1\">\n</widget>\n";
}
