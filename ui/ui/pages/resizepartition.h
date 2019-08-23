#ifndef RESIZEPARTITION_H
#define RESIZEPARTITION_H

#include <QLabel>
#include <QWidget>
#include <QSlider>
#include <QComboBox>
#include <QPushButton>
#include <QGridLayout>

#include "core/api.h"
#include "core/disk.h"

//! This namespace contains all ui elements for this project
namespace ui{
    //! This namespace contains all windows for this project
    namespace window {

    /**
     * @brief This class provides a partition resize window
     * @details This class is a window which display the possiblity to resize a partition
     *          It will provide a basic layout with the maximum size, minimum size, current size
     *          and a slider to adjust the size.
     * @author Nils Milewski (10010480)
     */
    class ResizePartition : public QWidget {

        Q_OBJECT

    private:

        /**
         * @brief maxLabel This UI element displays the maximum space
         */
        QLabel* lbMaxValue;

        /**
         * @brief lbPartitionInfo This UI element displays the partition info
         */
        QLabel* lbPartitionInfo;
        /**
         * @brief currentLabel This UI element displays the current value of the slider
         */
        QLabel* lbCurrentValue;

        /**
         * @brief slider This UI element provides the resize functionality
         */
        QSlider* sdPartitionSize;

        /**
         * @brief btOk This UI element represents an ok button
         */
        QPushButton* btOk;

        /**
         * @brief btOk This UI element represents a cancel button
         */
        QPushButton* btCancel;

        /**
         * @brief index This attributes is used to detemrine which partition should be resized.
         */
        int index_m;

        /**
         * @brief display Internal usage
         * @details This method refreshs the ui
         */
        void display();
    public:

        /**
         * @brief ResizePartition This Cosntructor creates the UI and initializes attributes.
         * @details This class requires a partition index corresponding to the partition inside
         *          the MBR of the disk.
         * @param partition Parititon index which should be resized, range 0 - 3.
         */
        ResizePartition(void);

        /**
         * @brief ~ResizePartition Destructor
         * @details This destructor will free up used resources
         */
        virtual ~ResizePartition(void) override;

        /**
         * @brief diskChanged This method should be called if the disk changes.
         * @details This method should be called if the disk changes, it will handle the UI refresh.
         */
        void diskChanged();

        /**
         * @brief setIndex This method sets the index of the partition
         * @details This method sets the index which should be used to operate on. Note the partition
         *          index must be inside the MBR (0 - 3)
         * @param index
         */
        void setIndex(int index);

        /**
         * @brief showEvent This event is called when the window is visible
         * @details This event occurres if the window enteres the state of visibility.
         *          All required field will be set to ensure a acurate functioanlity.
         * @param event QtInternal...
         */
        void showEvent(QShowEvent* event) override;

        /**
         * @brief setDisk This method sets the partition of the working disk
         * @details This method sets the the partition of the working disk which the resize
         *          operation should be operate on
         * @param idx New index of the partition
         */
        void setPartition(int idx);

    public slots:
        /**
         * @brief valueChanged This slot is invoked when a slider changes his value
         * @details When a slider changes hsi value this method will be invoked and refresh
         *          the UI
         * @param value New slider value
         */
        void valueChanged(int value);

        /**
         * @brief btOkPressed This slot is invoked when a ok button is pressed
         * @details This method ensures that all changes from the partition are saved.
         *          The partition will shrink or grow after this call
         */
        void btOkPressed();

        /**
         * @brief btCancelPressed This slot cancels the resize.
         * @details This method cancels the resize operation and discards all changes.
         */
        void btCancelPressed();
    };
    } // window
} // ui

#endif // RESIZEPARTITION_H
