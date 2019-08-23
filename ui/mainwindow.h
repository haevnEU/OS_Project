#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <iostream>
#include <QMessageBox>
#include <QWizard>
#include <QWizardPage>

#include<QVBoxLayout>
#include<QLabel>
#include<QLineEdit>

#include<QGridLayout>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void click();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
