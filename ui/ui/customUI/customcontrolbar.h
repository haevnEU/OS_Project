#ifndef CUSTOMCOMBOBOXLISTWIDGETITEM_H
#define CUSTOMCOMBOBOXLISTWIDGETITEM_H

#include <QLabel>
#include <vector>
#include <QPixmap>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QListWidgetItem>

//! This namespace contains all ui elements for this project
namespace ui{
//! This namespace contains all custom implementation of UI elements
namespace customUI {
/**
 * @brief This class will be removed
 */
class CustomControlBar : public QPushButton{
public:

    bool dark;
    bool pointingIn;
    QIcon* darkModeRight;
    QIcon* lightModeRight;
    QIcon* darkModeLeft;
    QIcon* lightModeLeft;
    CustomControlBar(QWidget* parent = nullptr);

    void setDarkMode(void);

    void setLightMode(void);

    void toggleSide(void);

    bool pointingLeft(void);
};

}
}

#endif // CUSTOMCOMBOBOXLISTWIDGETITEM_H
