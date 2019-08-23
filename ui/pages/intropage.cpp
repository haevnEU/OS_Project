#include "intropage.h"

IntroPage::IntroPage(QString text, pages_enum nextPage, QWidget* parent) : QWizardPage (parent){
    setTitle("Intro page");
    setSubTitle(text);
    nextPage_m  = nextPage;
}

int IntroPage::nextId() const{
    return nextPage_m;
}
