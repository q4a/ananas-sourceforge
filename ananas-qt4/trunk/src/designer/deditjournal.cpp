#include "deditjournal.h"

#include <qvariant.h>
#include <qimage.h>
#include <qpixmap.h>

/*
 *  Constructs a dEditJournal as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 */
dEditJournal::dEditJournal(QWidget* parent, const char* name, Qt::WindowFlags fl)
    : Q3MainWindow(parent, name, fl)
{
    setupUi(this);

    (void)statusBar();
    init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
dEditJournal::~dEditJournal()
{
    destroy();
    // no need to delete child widgets, Qt does it all for us
}

/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void dEditJournal::languageChange()
{
    retranslateUi(this);
}

#include "deditjournal.ui.h"
