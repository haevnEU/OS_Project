#include "diskpage.h"

DiskPage::DiskPage(QWidget* parent) : QWizardPage (parent){

    setTitle("Disk details");
    setSubTitle("Please enter all required information about the disk.\n"
                "If you want to create a partition please check the box below, "
                "it is allways possible to create a partition form the menu");

    QGridLayout* layout = new QGridLayout;
    QSpinBox* sbSize = new QSpinBox();
    QComboBox* dimension = new QComboBox();
    QLineEdit* leName = new QLineEdit();
    QCheckBox* cbPartition = new QCheckBox("Create partition");

    registerField("DiskName*", leName);
    registerField("createPartition", cbPartition);

    sbSize->setMaximum(999);
    sbSize->setMinimum(0);
    registerField("DiskSize*", sbSize);

    dimension->addItem("MB");
    dimension->addItem("GB");
    dimension->addItem("TB");
    dimension->addItem("EB");
    registerField("dimension", dimension);


    layout->addWidget(new QLabel("Manufactor name"), 0, 0);
    layout->addWidget(leName, 0, 1);

    layout->addWidget(new QLabel("Block size"), 1, 0);
    layout->addWidget(sbSize, 1, 1);
    layout->addWidget(dimension, 1, 2);

    layout->addWidget(cbPartition, 2, 2);

    setLayout(layout);
}

int DiskPage::nextId() const{
    bool partition = field("createPartition").toBool();
    if(partition){
        return pages_enum::partitionPage;
    }else{
        return pages_enum::summaryPage;
    }
}
