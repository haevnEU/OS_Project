#ifndef DISKPAGE_H
#define DISKPAGE_H

#include <QLabel>
#include <QSpinBox>
#include <QCheckBox>
#include <QLineEdit>
#include <QComboBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QWizardPage>

#include "pages_enum.h"

//! This namespace contains all ui elements for this project
namespace ui{
    //! This namespace contains all wizards for this project
    namespace wizard{
        //! This namespace contains all wizard pages for this project
        namespace pages{

        /**
         * @brief This class provides a custom implementation of a wizard page
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
             * @brief ~DiskPage Destructor
             * @details This destructor will free up used resources
             */
            //virtual ~DiskPage(void) override;

            /**
             * @brief nextId This method returns the next id
             * @details This method overrides the default implementation to utilize different intro pages.
             *          It will return the enum of next_page to differenciate between disk and partition pages
             * @return Next id for the wizard
             */
            int nextId() const override;
        };
        } // pages
    } // wizard
} // ui
#endif // DISKPAGE_H
