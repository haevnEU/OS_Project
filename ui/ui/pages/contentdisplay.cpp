#include "contentdisplay.h"
#include "QHBoxLayout"

using namespace ui::window;

ContentDisplay::ContentDisplay(){

    layout = new QGridLayout();
    btBin = new QRadioButton("Bin");
    btHex = new QRadioButton("Hex");
    btTxt = new QRadioButton("Txt");

    btSave = new QPushButton(QIcon(QPixmap(":/images/theme/dark/res/dark/edit.svg")),"Save");
    btDelete = new QPushButton(QIcon(QPixmap(":/images/theme/dark/res/dark/trash-2.svg")),"Delete");
    btCancel = new QPushButton(QIcon(QPixmap(":/images/theme/dark/res/dark/log-out.svg")),"Cancel");
    content = new QListWidget();
    contentEditor = new QTextEdit();

    btSave->setFlat(true);
    btDelete->setFlat(true);
    btCancel->setFlat(true);

    contentEditor->setReadOnly(true);

    QHBoxLayout* radioButtonGroup = new QHBoxLayout();
    radioButtonGroup->addWidget(btBin);
    radioButtonGroup->addWidget(btHex);
    radioButtonGroup->addWidget(btTxt);

    QHBoxLayout* buttonGroup = new QHBoxLayout();
    buttonGroup->addWidget(btDelete);
    buttonGroup->addWidget(btSave);
    buttonGroup->addWidget(btCancel);

    content->setFixedWidth(150);


    layout->addWidget(content, 0, 0, 3, 1);
    layout->addLayout(radioButtonGroup, 0,1);
    layout->addLayout(buttonGroup, 1, 1);
    layout->addWidget(contentEditor, 2, 1);
    setLayout(layout);

    data = nullptr;


    connect(btHex, SIGNAL(clicked(bool)), this, SLOT(btHexClicked(bool)));
    connect(btBin, SIGNAL(clicked(bool)), this, SLOT(btBinClicked(bool)));
    connect(btTxt, SIGNAL(clicked(bool)), this, SLOT(btTxtClicked(bool)));

}

void ContentDisplay::enableDarkMode(){
    btSave->setIcon(QIcon(QPixmap(":/images/theme/dark/res/dark/edit.svg")));
    btDelete->setIcon(QIcon(QPixmap(":/images/theme/dark/res/dark/trash-2.svg")));
    btCancel->setIcon(QIcon(QPixmap(":/images/theme/dark/res/dark/log-out.svg")));
}

void ContentDisplay::enableLightMode(){
    btSave->setIcon(QIcon(QPixmap(":/images/theme/light/res/light/edit.svg")));
    btDelete->setIcon(QIcon(QPixmap(":/images/theme/light/res/light/trash-2.svg")));
    btCancel->setIcon(QIcon(QPixmap(":/images/theme/light/res/light/log-out.svg")));
}

void ContentDisplay::btHexClicked(bool checked){
    if(nullptr == data){
        return;
    }
    QString txt = "";
    for(int i = 0; data[i] > 0; i++){
        txt.append(QString("%1").arg((int)data[i],0,16).toUpper()).append(" ");
    }
    contentEditor->setText(txt);
}

void ContentDisplay::btBinClicked(bool checked){
    if(nullptr == data){
        return;
    }
    QString txt = "";
    for(int i = 0; data[i] > 0; i++){
        txt.append(QString("%1").arg((int)data[i],0,2)).append(" ");
    }
    contentEditor->setText(txt);
}

void ContentDisplay::btTxtClicked(bool checked){
    if(nullptr == data){
        return;
    }
    QString txt = "";
    for(int i = 0; data[i] > 0; i++){
        txt.append(QString(data[i]));
    }
    contentEditor->setText(txt);
}

void ContentDisplay::fileActivated(QListWidgetItem *item){

}
