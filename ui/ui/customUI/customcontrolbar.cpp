#include "customcontrolbar.h"
#include <QPushButton>
#include <QVBoxLayout>

using namespace ui::customUI;

CustomControlBar::CustomControlBar(QWidget *parent) : QPushButton (parent){
setStyleSheet("QPushButton {border-style: outset; border-width: 0px;}");
    darkModeRight = new QIcon(QPixmap(":/images/theme/dark/res/dark/arrow-right-circle.svg"));
    lightModeRight = new QIcon(QPixmap(":/images/theme/light/res/light/arrow-right-circle.svg"));
    darkModeLeft = new QIcon(QPixmap(":/images/theme/dark/res/dark/arrow-left-circle.svg"));
    lightModeLeft = new QIcon(QPixmap(":/images/theme/light/res/light/arrow-left-circle.svg"));

    dark = true;
    pointingIn = true;
    setFixedSize(50,50);
    setDarkMode();
}

void CustomControlBar::setDarkMode(){
    dark = true;
    if(pointingIn){
           setIcon(*darkModeLeft);
    }else{
        setIcon(*darkModeRight);
    }
}

void CustomControlBar::setLightMode(){
    dark = false;

    if(pointingIn){
        setIcon(*lightModeLeft);
    }else{
         setIcon(*lightModeRight);
    }
}

void CustomControlBar::toggleSide(){
    pointingIn = !pointingIn;
    if(dark){
        if(pointingIn){
               setIcon(*darkModeLeft);
        }else{
            setIcon(*darkModeRight);
        }
    }else{
        if(pointingIn){
            setIcon(*lightModeLeft);
        }else{
             setIcon(*lightModeRight);
        }
    }
}

bool CustomControlBar::pointingLeft(){
    return pointingIn;
}
