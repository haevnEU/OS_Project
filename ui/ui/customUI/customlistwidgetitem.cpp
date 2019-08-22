#include "customlistwidgetitem.h"

using namespace ui::customUI;

CustomListWidgetItem::CustomListWidgetItem(QString text, QString res) : QListWidgetItem(){
        darkModeIcon_m = new QIcon(QPixmap(QString(":/images/theme/dark/res/dark/").append(res)));
        lightModeIcon_m = new QIcon(QPixmap(QString(":/images/theme/light/res/light/").append(res)));
       enableDarkMode();

       setText(text);
}

CustomListWidgetItem::~CustomListWidgetItem(){
    QListWidgetItem::~QListWidgetItem();
}

void CustomListWidgetItem::enableLightMode(void){
    if(nullptr != darkModeIcon_m){
        setIcon(*lightModeIcon_m);
        dark_m = false;
    }
}

void CustomListWidgetItem::enableDarkMode(void){
    if(nullptr != darkModeIcon_m){
        setIcon(*darkModeIcon_m);
        dark_m = true;
    }
}
