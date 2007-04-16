#include "addfdialog.h"

#include <qvariant.h>
#include "wdbfield.h"
/*
 *  Constructs a addfdialog as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  true to construct a modal dialog.
 */
addfdialog::addfdialog(QWidget* parent, const char* name, bool modal, Qt::WindowFlags fl)
    : QDialog(parent, name, modal, fl)
{
    setupUi(this);

    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
addfdialog::~addfdialog()
{
    destroy();
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void addfdialog::languageChange()
{
    retranslateUi(this);
}

#include "addfdialog.ui.h"
