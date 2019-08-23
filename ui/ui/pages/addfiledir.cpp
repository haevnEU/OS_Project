#include "addfiledir.h"
#include "core/FAT.h"
#include "core/api.h"
#include <QDebug>
using namespace ui::window;

AddFileDir::AddFileDir(){

    name = new QLineEdit;
    ext = new QLineEdit;
    sbUID = new QSpinBox;
    sbGID = new QSpinBox;
    readUser = new QCheckBox("Read");
    writeUser = new QCheckBox("Write");
    executeUser = new QCheckBox("Execute");
    readGroup = new QCheckBox("Read");
    writeGroup = new QCheckBox("Write");
    executeGroup = new QCheckBox("Execute");
    hidden = new QCheckBox("Hidden");

    createPicker = new QDateTimeEdit(QDateTime::currentDateTime());
    accessPicker = new QDateTimeEdit(QDateTime::currentDateTime());
    changePicker = new QDateTimeEdit(QDateTime::currentDateTime());

    fileDirCombBox = new QComboBox;
    layout = new QGridLayout;
    btOk = new QPushButton("Ok");
    btCancel = new QPushButton("Cancel");

    QGroupBox* userBox = new QGroupBox;
    QGridLayout* userLayout = new QGridLayout;
    userBox->setTitle("User");
    userLayout->addWidget(readUser, 0,0);
    userLayout->addWidget(writeUser, 0,1);
    userLayout->addWidget(executeUser, 0,2);
    userBox->setLayout(userLayout);

    QGroupBox* groupBox = new QGroupBox;
    QGridLayout* groupLayout = new QGridLayout;
    groupBox->setTitle("Group");
    groupLayout->addWidget(readGroup, 0,0);
    groupLayout->addWidget(writeGroup, 0,1);
    groupLayout->addWidget(executeGroup, 0,2);

    groupBox->setLayout(groupLayout);

    enableDarkMode();

    layout->addWidget(new QLabel("Name"), 0, 0);
    layout->addWidget(name, 0, 1);
    layout->addWidget(new QLabel("Extension"), 1, 0);
    layout->addWidget(ext, 1, 1);

    layout->addWidget(new QLabel("Type"), 2, 0);
    layout->addWidget(fileDirCombBox, 2, 1);

    layout->addWidget(hidden, 3, 0);

    layout->addWidget(userBox, 4, 0, 1, 2);
    layout->addWidget(groupBox, 5, 0, 1, 2);

    layout->addWidget(new QLabel("Create Time"), 6, 0);
    layout->addWidget(createPicker, 6, 1);

    layout->addWidget(new QLabel("Access Time"), 7, 0);
    layout->addWidget(accessPicker, 7, 1);

    layout->addWidget(new QLabel("Change Time"), 8, 0);
    layout->addWidget(changePicker, 8, 1);

    layout->addWidget(btOk, 9, 1);
    layout->addWidget(btCancel, 9, 0);

    setLayout(layout);

    connect(btOk, SIGNAL(pressed()), this, SLOT(btOkPressed()));
    connect(btCancel, SIGNAL(pressed()), this, SLOT(btCancelPressed()));
}

void AddFileDir::enableDarkMode(void){
    fileDirCombBox->clear();
    fileDirCombBox->addItem(QIcon(QPixmap(":/images/theme/dark/res/dark/file.svg")), "File");
    fileDirCombBox->addItem(QIcon(QPixmap(":/images/theme/dark/res/dark/folder.svg")), "Directory");

}
void AddFileDir::enableLightMode(void){
    fileDirCombBox->clear();
    fileDirCombBox->addItem(QIcon(QPixmap(":/images/themes/light/res/light/file.svg")), "File");
    fileDirCombBox->addItem(QIcon(QPixmap(":/images/themes/light/res/light/folder.svg")), "Directory");
}

void AddFileDir::diskChanged(){
    // TODO implement if used
}

void AddFileDir::setPartition(int idx){
    this->workingIndex = idx;
}

void AddFileDir::showEvent(QShowEvent *event){
    QWidget::showEvent(event);
    if(nullptr == API::GetInstance()->currentDisk()){
        return;
    }
}

void AddFileDir::btOkPressed(){
    QString name = this->name->text();
    QString ext = this->ext->text();
    long uid = sbUID->value();
    long gid = sbGID->value();

    bool readUser = this->readUser->isChecked();
    bool writeUser = this->writeUser->isChecked();
    bool executeUser = this->executeUser->isChecked();
    bool readGroup = this->readGroup->isChecked();
    bool writeGroup = this->writeGroup->isChecked();
    bool executeGroup = this->executeGroup->isChecked();
    bool hidden = this->hidden->isChecked();
    bool dir = false;

    long long create = createPicker->dateTime().toUTC().toSecsSinceEpoch();
    long long  access = accessPicker->dateTime().toUTC().toSecsSinceEpoch();
    long long  change = changePicker->dateTime().toUTC().toSecsSinceEpoch();

    char permision;
    /*

permission: short // 7 6 5 4 3 2 1 0
                  // d h x w r x w r
                  //     g g g o o o
                  set: number |= 1UL << n;
                  clear: umber &= ~(1UL << n);
     */
    if(readUser){
        permision |= 1 << 0;
    }else{
        permision &= ~(1 << 0);
    }
    if(writeUser){
        permision |= 1 << 1;
    }else{
        permision &= ~(1 << 1);
    }
    if(executeUser){
        permision |= 1 << 2;
    }else{
        permision &= ~(1 << 2);
    }

    if(readGroup){
        permision |= 1 << 3;
    }else{
        permision &= ~(1 << 3);
    }
    if(writeGroup){
        permision |= 1 << 4;
    }else{
        permision &= ~(1 << 4);
    }
    if(executeGroup){
        permision |= 1 << 5;
    }else{
        permision &= ~(1 << 5);
    }

    if(hidden){
        permision |= 1 << 6;
    }else{
        permision &= ~(1 << 6);
    }
    if(dir){
        permision |= 1 << 7;
    }else{
        permision &= ~(1 << 7);
    }

    qDebug() << "Name: " << name << "." << ext;
    qDebug() << "UID/GID: " << uid << "/" << gid;
    qDebug() << "Read (User/Group): " << readUser << "/"<< readGroup;
    qDebug() << "Write (User/Group): " << writeUser << "/"<< writeGroup;
    qDebug() << "Execute (User/Group): " << executeUser << "/"<< executeGroup;
    qDebug() << "Hidden: " << (hidden ? "true" : "false");
    qDebug() << "Permission: " << QString::number((int)permision);
    qDebug() << "Create: " << create;
    qDebug() << "access: " << access;
    qDebug() << "change: " << change;

    API::GetInstance()->createFile(workingIndex, name.toStdString(), ext.toStdString(),uid, gid, permision, create, access, change);

    this->hide();

}

void AddFileDir::btCancelPressed(){
    this->hide();
}
