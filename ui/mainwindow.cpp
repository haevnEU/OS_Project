#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "pages/diskpage.h"
#include "pages/intropage.h"
#include "pages/pages_enum.h"
#include "pages/partitionpage.h"
#include "pages/summarypage.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL (pressed()), this, SLOT (click()));}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::click(){
QWizard wizard;
wizard.setPage(pages_enum::introPage, new IntroPage("This wizard guides you through a creation of a disk", pages_enum::diskPage));
wizard.setPage(pages_enum::diskPage, new DiskPage());
wizard.setPage(pages_enum::partitionPage, new PartitionPage());
wizard.setPage(pages_enum::summaryPage, new SummaryPage());

wizard.setStartId(pages_enum::introPage);
wizard.exec();

QWizard wizard2;
wizard2.setPage(pages_enum::introPage, new IntroPage("TEST", pages_enum::partitionPage));
wizard2.setPage(pages_enum::partitionPage, new PartitionPage());
wizard2.setPage(pages_enum::summaryPage, new SummaryPage());

wizard2.exec();
}

