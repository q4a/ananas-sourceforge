#include "deditcommand.h"

#include <qvariant.h>
#include <qimage.h>
#include <qpixmap.h>

/*
 *  Constructs a dEditCommand as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 */
dEditCommand::dEditCommand(QWidget* parent, const char* name, Qt::WindowFlags fl)
    : Q3MainWindow(parent, name, fl)
{
    setupUi(this);

    (void)statusBar();
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
dEditCommand::~dEditCommand()
{
    destroy();
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void dEditCommand::languageChange()
{
    retranslateUi(this);
}

#include "deditcommand.ui.h"
