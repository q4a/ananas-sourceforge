#include "deditdialog.h"

#include <qvariant.h>
#include <qimage.h>
#include <qpixmap.h>

#include "qtextcodec.h"
/*
 *  Constructs a dEditDialog as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 */
dEditDialog::dEditDialog(QWidget* parent, const char* name, Qt::WindowFlags fl)
    : Q3MainWindow(parent, name, fl)
{
    setupUi(this);

    (void)statusBar();
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
dEditDialog::~dEditDialog()
{
    destroy();
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void dEditDialog::languageChange()
{
    retranslateUi(this);
}

#include "deditdialog.ui.h"
