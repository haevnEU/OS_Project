#ifndef PARTITIONWIZARD_H
#define PARTITIONWIZARD_H

#include <QWizard>
#include <QMessageBox>

#include "pages/diskpage.h"
#include "pages/intropage.h"
#include "pages/pages_enum.h"
#include "pages/summarypage.h"
#include "pages/partitionpage.h"
#include "core/partition.h"

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
    class PartitionWizard : public QWizard{
    public:

        /**
         * @brief PartitionWizard Constructor
         * @details This constructor construct a wizard and assign the page order.
         * @param diskSize Size of the disk where the partition should be created
         * @param parent
         */
        PartitionWizard(unsigned long long diskSize, QWidget* parent = nullptr);

        /**
         * @brief ~PartitionWizard Destructor
         * @details This destructor will free up used resources
         */

        //virtual ~PartitionWizard(void) override;
        /**
         * @brief getResultedPartition This method returns the partition which where created.
         * @details This method creates a new partition based on prviouus entered information
         * @return partition based on previous information
         */
        core::logic::Partition* getResultedPartition(void);

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

#endif // PARTITIONWIZARD_H
