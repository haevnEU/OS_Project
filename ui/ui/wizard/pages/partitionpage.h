#ifndef PARTITIONPAGE_H
#define PARTITIONPAGE_H

#include <QLabel>
#include <QSpinBox>
#include <QComboBox>
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
         *          It request all required information for a partition creation
         * @author Nils Milewski (10010480)
         */
        class PartitionPage : public QWizardPage{

            Q_OBJECT
        private:

            /**
             * @brief diskSize This attribute state the total usable disk size
             */
            unsigned long long diskSize;

            /**
             * @brief lbSliderValue This UI element shows the current value of the slider
             */
            QLabel* lbSliderValue;

            /**
             * @brief slider This UI element changes the partition size
             */
            QSlider* slider;

        public:
            /**
             * @brief PartitionPage This is a constructor
             * @details This constructor creates the layout of the page and set required attributes
             *          Note only call iff this page is used during a disk creation process
             * @param parent Parent object which this object is associated with
             */
            PartitionPage(QWidget* parent = nullptr);

            /**
             * @brief ~PartitionPage Destructor
             * @details This destructor will free up used resources
             */
            virtual ~PartitionPage(void) override;

            /**
             * @brief PartitionPage This is a constructor
             * @details This constructor creates the layout of the page and set required attributes,
             * @param diskSize Size of the disk
             * @param parent Parent object which this object is associated with
             */
            PartitionPage(unsigned long long diskSize, QWidget* parent = nullptr);

            /**
             * @brief nextId This method returns the next id
             * @details This method overrides the default implementation to utilize different intro pages.
             *          It will return the enum of next_page to differenciate between disk and partition pages
             * @return Next id for the wizard
             */
            int nextId() const override;

            /**
             * @brief setVisible This method toggles the visiblity state of the pages
             * @details This method sets the page visible or unset it. It is used to set specific information
             *          The page require to operate based on previous information.
             * @param visible Visibility state of the page
             */
            void setVisible(bool visible) override;

        public slots:
            /**
             * @brief amountBlocksSliderValueChanged This slot is used to change the value of the partition
             * @details This method is invoked if the slider changes his value, inside the method the new partition
             *          size will be set
             * @param amount Amount of the change
             */
            void amountBlocksSliderValueChanged(int amount);

            /**
             * @brief blockSizeChanged This slot is used to change the block size of the partition
             * @details This method is invoked if the user changes the content of the blocksize
             *          combo box, it will set the new block size and adjust the slider max value.
             * @param index Index corresponding to block size. 0 = 512, 1 = 1024, 2 = 2048, 3 = 4096, 4 = 8192
             */
            void blockSizeChanged(int index);
        };

        } // pages
    } // wizard
} // ui
#endif // PARTITIONPAGE_H
