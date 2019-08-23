#include "partitionpage.h"
#include <QDebug>
#include <QSlider>

using namespace ui::wizard::pages;

PartitionPage::PartitionPage(unsigned long long diskSize, QWidget* parent) : PartitionPage(parent){
    this->diskSize = diskSize;
}

PartitionPage::PartitionPage(QWidget* parent) : QWizardPage(parent){
    // Set up UI
    // Instanziate UI elements
    slider = new QSlider();
    lbSliderValue = new QLabel();

    QGridLayout* layout = new QGridLayout();
    QComboBox* cbBlockSize = new QComboBox();
    QComboBox* cbFileSystem = new QComboBox();

    // Set basic information
    setTitle("Partition page");
    setSubTitle("");

    // Create combobox entries
    cbBlockSize->addItem("512");
    cbBlockSize->addItem("1024");
    cbBlockSize->addItem("2048");
    cbBlockSize->addItem("4096");
    cbBlockSize->addItem("8192");

    cbFileSystem->addItem("INode");
    cbFileSystem->addItem("FAT");
    cbFileSystem->addItem("CD-ROM");

    // Setup slider
    slider->setMaximum(INT_MAX);
    slider->setMinimum(1);
    slider->setOrientation(Qt::Orientation::Horizontal);

    // Setup layout
    layout->addWidget(new QLabel("Block size:"), 0, 0);
    layout->addWidget(cbBlockSize, 0, 1);
    layout->addWidget(new QLabel("Amount of Blocks:"), 1, 0);
    layout->addWidget(slider, 1, 1);
    layout->addWidget(lbSliderValue, 1, 2);
    layout->addWidget(new QLabel("Filesystem:"), 2, 0);
    layout->addWidget(cbFileSystem, 2, 1);
    layout->addWidget(slider, 3,1);

    // Register used fields
    registerField("partitionBlockSize", cbBlockSize);
    registerField("partitionBlockCount*", slider);
    registerField("partitionFileSystem", cbFileSystem);

    setLayout(layout);

    // Create singal slot connections
    connect(cbBlockSize, SIGNAL (currentIndexChanged(int)), this, SLOT (blockSizeChanged(int)));
    connect(slider, &QSlider::valueChanged, this, &PartitionPage::amountBlocksSliderValueChanged);
}

int PartitionPage::nextId() const{
    return pages_enum::summaryPage;
}

void PartitionPage::setVisible(bool visible){
    // Call base method
    QWizardPage::setVisible(visible);

    // Querry fields from previous pages
    int diskSize = field("DiskSize").toInt();
    int dimension = field("dimension").toInt();

    // Create subtitle text
    QString subTitle = "You can specify partition details. Available space is: ";

    if(diskSize > 0){
        subTitle.append(QString::number(diskSize));
    }else{
        subTitle.append(QString::number(this->diskSize));
    }

    unsigned long long dimSize = 1;
    // Switch between possible dimension size
    switch(dimension){
    case 0:
        subTitle.append("KB");
        dimSize = KB;
        break;
    case 1:
        subTitle.append("MB");
        dimSize = MB;
        break;
    case 2:
        subTitle.append("GB");
        dimSize = GB;
        break;
    case 3:
        subTitle.append("TB");
        dimSize = TB;
        break;
    }

    // Recalculate the disk size bsed on dimension,
    // 1 is added to ensure that never a zero multiplikation ocurres
    diskSize *= (dimSize + 1);
    // Set the disk size to calculated value
    if(diskSize != 0){
        this->diskSize = diskSize;
    }else{
        diskSize = this->diskSize;
    }
    // Set subtitle text
    setSubTitle(subTitle);
}

void PartitionPage::amountBlocksSliderValueChanged(int amount){
    lbSliderValue->setText(QString::number(amount));
}

void PartitionPage::blockSizeChanged(int index){
    // Convert combo box entry into a usable size
    unsigned long long maxBlocks = 1;
    switch(index){
    case 0:
        maxBlocks = diskSize / 512;
        break;
    case 1:
        maxBlocks = diskSize / 1024;
        break;
    case 2:
        maxBlocks = diskSize / 2048;
        break;
    case 3:
        maxBlocks = diskSize / 4096;
        break;
    case 4:
        maxBlocks = diskSize / 8192;
        break;
    }
    // Set the slider maximum to the max possible blocks.
    slider->setMaximum(static_cast<int>(maxBlocks));

}
