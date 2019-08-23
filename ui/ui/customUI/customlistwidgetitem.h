#ifndef CUSTOMLISTWIDGET_H
#define CUSTOMLISTWIDGET_H

#include <vector>
#include <QLabel>
#include <QPixmap>
#include <QVBoxLayout>
#include <QListWidgetItem>

//! This namespace contains all ui elements for this project
namespace ui{
    //! This namespace contains all custom implementation of UI elements
    namespace customUI{

    /**
     * @brief This class This class provides a custom impelemntation of a Listwidget
     * @details This class provides a custom implementation of the QListWidgetClass,
     *          it is a wrapper to enable different UI modes, such like dark and light
     * @author Nils Milewski(10010480)
     */
    class CustomListWidgetItem : public QListWidgetItem{


    private:
        /**
         * @brief dark This attributes detemrines if the darkmode is enabled
         */
        bool dark_m;

        /**
         * @brief darkMode This icon contains the image of the darkmode
         */
        QIcon* darkModeIcon_m;

        /**
         * @brief darkMode This icon contains the image of the lightmode
         */
        QIcon* lightModeIcon_m;

    public:
        /**
         * @brief CustomListWidgetItem This constructor creates a new instance of this class
         * @details This constructor will initalize all attributes and set the default to darkmode
         * @param text Text which the ListWidgetIte should display
         * @param res Name of the resource, note :/images/theme/<mode>/res/<mode>/ will be set, use the
         *            Icon name, e.g. add.svg
         */
        CustomListWidgetItem(QString text, QString res = nullptr);

        /**
         * @brief ~CustomListWidgetItem Destructor
         * @details This destructor will free up used resources
         */
        //virtual ~CustomListWidgetItem(void);

        /**
         * @brief enableLightMode This method enabled the light mode
         * @details This method sets the dark_m attribute to false
         *          and sets the icon to the lightModeIcon_m
         */
        void enableLightMode(void);

        /**
         * @brief enableLightMode This method enabled the dark mode
         * @details This method sets the dark_m attribute to true
         *          and sets the icon to the darkModeIcon_m
         */
        void enableDarkMode(void);
    };
    } // customUI
} // ui
#endif // CUSTOMLISTWIDGET_H
