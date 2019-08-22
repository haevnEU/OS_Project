#include "intropage.h"

using namespace ui::wizard::pages;

IntroPage::IntroPage(QString text, pages_enum nextPage, QWidget* parent) : QWizardPage (parent){
    setTitle("Intro page");
    setSubTitle(text);
    nextPage_m  = nextPage;
}

IntroPage::~IntroPage(){
    QWizardPage::~QWizardPage();
}

int IntroPage::nextId() const{
    return nextPage_m;
}
