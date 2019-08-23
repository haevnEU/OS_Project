#ifndef DISKWIZARD_H
#define DISKWIZARD_H

#include <QWizard>
#include <QMessageBox>

#include "pages/diskpage.h"
#include "pages/intropage.h"
#include "pages/pages_enum.h"
#include "pages/summarypage.h"
#include "pages/partitionpage.h"

#include "core/disk.h"
#include "core/partition.h"
#include "core/FileSystem.h"

//! This namespace contains all ui elements for this project
namespace ui{
    //! This namespace contains all wizards for this project
    namespace wizard{
    /**
     * @brief This class this class implements a wizard
     * @details This class is a custom implementation of a wizard.
     *          It handles all pages and serves as an interaction
     *          with the calling object
     * @author Nils Milewski (10010480)
     */
    class DiskWizard : public QWizard{

    public:
        /**
         * @brief DiskWizard Constructor
         * @details This constructor construct a wizard and assign the page order.
         * @param parent
         */
        DiskWizard(QWidget* parent = nullptr);

        /**
         * @brief ~DiskWizard Destrucotr
         */
      //  virtual ~DiskWizard(void) override;

        /**
         * @brief getResultedDisk This method returns the disk which where created.
         * @details This method creates a new Disk based on prviuous entered information
         * @return Disk based on previous information
         */
        core::disk::Disk* getResultedDisk(void);

    protected:
        /**
         * @brief done This is a custom implementation of the done event
         * @details This event will ensure that the wizard only closes after the user
         *          aproved it with an anwser of a close question.
         * @param result Qt internal
         */
        virtual void done(int result) override;

    };
    } // wizard
} // ui

#endif // DISKWIZARD_H
