#ifndef SUMMARYPAGE_H
#define SUMMARYPAGE_H

#include <QTextEdit>
#include <QWizardPage>
#include <QGridLayout>

#include "pages_enum.h"

//! This namespace contains all ui elements for this project
namespace ui{
    //! This namespace contains all wizards for this project
    namespace wizard{
        //! This namespace contains all wizard pages for this project
        namespace pages {

        /**
         * @brief This class provides a custom implementation of a wizard page
         * @details This class is a custom implementation of a wizard page
         *          It displays all information which where previous entered.
         * @author Nils Milewski (10010480)
         */
        class SummaryPage : public QWizardPage{

        private:
            /**
             * @brief usedPages This variable defines which pages was shown to the user
             * @details This variable is used to determine which information will be displayed to the user
             */
            int usedPages_m;

            /**
             * @brief getDiskText This method returns a text representing a disk
             * @details This method querries all attributes of a disk and creates a human readable
             *          string which can be used to display disk inormation
             * @return Summary of disk in string format
             */
            QString getDiskText();

            /**
             * @brief getPartitioNText This method returns a text representing a partition
             * @details This method querries all attributes of a partition and creates a human readable
             *          string which can be used to display disk inormation
             * @return Summary of partition in string format
             */
            QString getPartitioNText();

        public:

            /**
             * @brief PartitionPage This is a constructor
             * @details This constructor creates the layout of the page
             * @param parent Parent object which this object is associated with
             */
            SummaryPage(int usedPages, QWidget* parent = nullptr);

            /**
             * @brief ~SummaryPage Destructor
             * @details This destructor will free up used resources
             */
            //virtual ~SummaryPage(void) override;

        protected:
            /**
             * @brief initializePage This method initializes the page
             * @details This method overrides the base initializePage method to ensure that
             *          Custom behaivour can be implemented. This method sets the subtitle with all previous entered information
             */
            void initializePage() override;

            /**
             * @brief nextId This method returns the next id for the wizard
             * @details This method overrides the default implementation to ensure a dynamic wizard.
             *          This page will allways return -1 to signal a final page.
             * @return next wizard ID
             */
            int nextId() const override;
        };
        } // pages
    } // wizard
} // ui

#endif // SUMMARYPAGE_H
