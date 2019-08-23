#ifndef ADDFILEDIR_H
#define ADDFILEDIR_H

#include <QtWidgets>
#include "core/disk.h"
#include "core/FileSystem.h"
#include "core/File.h"
#include "core/FAT.h"

#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QSpinBox>
#include <QDateTimeEdit>
#include <QGroupBox>
#include <QCheckBox>
namespace ui {
    namespace window {
    class AddFileDir : public QWidget{

        Q_OBJECT

    private:
        QComboBox* fileDirCombBox;
        QLineEdit* name;
        QLineEdit* ext;
        QSpinBox* sbUID;
        QSpinBox* sbGID;
        QCheckBox* readUser;
        QCheckBox* writeUser;
        QCheckBox* executeUser;
        QCheckBox* readGroup;
        QCheckBox* writeGroup;
        QCheckBox* executeGroup;
        QCheckBox* hidden;

        QDateTimeEdit* accessPicker;
        QDateTimeEdit* createPicker;
        QDateTimeEdit* changePicker;

        QGridLayout* layout;
        QPushButton* btOk;
        QPushButton* btCancel;

        /**
         * @brief workingIndex This attributes is used as the partition index from workingDisk_m
         */
        int workingIndex;

    public:
        AddFileDir();

        /**
         * @brief setPartition This method sets the partition of the working disk
         * @param disk Partition of the working disk
         * @details This method sets the partition of the working disk of this windows
         */
        void setPartition(int idx);

        /**
         * @brief showEvent This event is called when the window is visible
         * @details This event occurres if the window enteres the state of visibility.
         *          All required field will be set to ensure a acurate functioanlity.
         * @param event QtInternal...
         */
        void showEvent(QShowEvent* event) override;

        /**
         * @brief enableDarkMode This methods enables the dark mode
         * @details This method will replace all icons with a dark styled icon model
         */
        void enableDarkMode();

        /**
         * @brief enableLightMode This methods enables the light mode
         * @details This method will replace all icons with a light styled icon model
         */
        void enableLightMode();

        /**
         * @brief diskChanged This method should be called if the disk changes
         * @details This method should be invoked if the disk changed to another one.
         *          This method will handle all requirements to refresh the UI
         */
        void diskChanged();

    public slots:
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
    }
}
#endif // ADDFILEDIR_H
