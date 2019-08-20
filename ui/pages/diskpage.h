#ifndef DISKPAGE_H
#define DISKPAGE_H

#include <QWizardPage>
#include <QLabel>
#include <QSpinBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QComboBox>

#include "pages_enum.h"

/**
 * @brief The DiskPage class
 * @details This class is a custom implementation of a wizard page
 *          It request all required information for a disk creation
 * @author Nils Milewski (10010480)
 */
class DiskPage : public QWizardPage{

public:
    /**
     * @brief DiskPage This is a constructor
     * @details This constructor creates the layout of the page and set required attributes
     * @param parent Parent object which this object is associated with
     */
    DiskPage(QWidget* parent = nullptr);

    /**
     * @brief nextId This method returns the next id
     * @details This method overrides the default implementation to utilize different intro pages.
     *          It will return the enum of next_page to differenciate between disk and partition pages
     * @return Next id for the wizard
     */
    int nextId() const override;
};

#endif // DISKPAGE_H
