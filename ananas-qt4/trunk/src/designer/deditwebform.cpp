#include "deditwebform.h"

#include <qvariant.h>
#include <qimage.h>
#include <qpixmap.h>

/*
 *  Constructs a dEditWebForm as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 */
dEditWebForm::dEditWebForm(QWidget* parent, const char* name, Qt::WindowFlags fl)
    : Q3MainWindow(parent, name, fl)
{
    setupUi(this);

    (void)statusBar();
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
dEditWebForm::~dEditWebForm()
{
    destroy();
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void dEditWebForm::languageChange()
{
    retranslateUi(this);
}

#include "deditwebform.ui.h"
