#include "catalogform.h"

#include <qvariant.h>
#include <qimage.h>
#include "alog.h"
// TODO Remove!!!
#include "../ananas/mainform.h"
#include "aform.h"
#include "aservice.h"
/*
 *  Constructs a CatalogForm as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 */
CatalogForm::CatalogForm(QWidget* parent, const char* name, Qt::WindowFlags fl)
    : Q3MainWindow(parent, name, fl)
{
    setupUi(this);

    (void)statusBar();
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
CatalogForm::~CatalogForm()
{
    destroy();
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void CatalogForm::languageChange()
{
    retranslateUi(this);
}

#include "catalogform.ui.h"
