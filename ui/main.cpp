#include <QApplication>
#include "ui/pages/mainwindow.h"
#include <QDebug>
/**
 * @brief main This is the main entry point
 * @param argc Argument count
 * @param argv Argument variable
 * @return execute code
 */

bool compare(const char* str1, const char* str2){
    for(int i = 0; i < 5; i++){
        if(str1[i] != str2[i]){
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]){
    bool consoleMode = false;
    int returnCode;
    for(int i = 0; i < argc; i++){ qDebug() << argv[i];}

    for(int i = 0; i < argc; i++){
        if(compare(argv[i], "-tui")){
            consoleMode = true;
        }
    }

    // UI Mode is active
    if(!consoleMode){
        QApplication a(argc, argv);
        ui::window::MainWindow mainWindow;
        mainWindow.show();
        returnCode = a.exec();
    }
    // TUI Mode is active
    else{
        returnCode = 0;
    }
    return returnCode;
}
