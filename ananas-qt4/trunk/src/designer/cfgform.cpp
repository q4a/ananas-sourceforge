#include "cfgform.h"

#include <qvariant.h>
#include <qimage.h>
#include <qpixmap.h>

/*
 *  Constructs a CfgForm as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 */
CfgForm::CfgForm(QWidget* parent, const char* name, Qt::WindowFlags fl)
    : Q3MainWindow(parent, name, fl)
{
    setupUi(this);

    (void)statusBar();
}

/*
 *  Destroys the object and frees any allocated resources
 */
CfgForm::~CfgForm()
{
    destroy();
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CfgForm::languageChange()
{
    retranslateUi(this);
}

#include "cfgform.ui.h"
