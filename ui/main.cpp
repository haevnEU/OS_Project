#include <QApplication>
#include "ui/pages/mainwindow.h"
#include "core/disk.h"
#include "core/FAT.h"
#include "core/File.h"
#include "core/FileSystem.h"
#include "core/api.h"
#include "core/block.h"
#include "core/masterbootrecord.h"
#include "core/partition.h"
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


    /*core::disk::Disk* disk = new core::disk::Disk(100000, "test");
    disk->MBR()->addPartition(512, 50, core::FileSystem::fileSystemType::FAT);
    core::FileData* data = new core::FileData(1024L);
    std::string* name = new std::string("test");
    std::string* ext = new std::string("out");
    core::File* file = new core::File(data, name, ext, 0,0,0,0,0,0);
    disk->MBR()->getPartition(0)->fileSystem()->createFile(file);
    core::FAT* fat = dynamic_cast<core::FAT*>(disk->MBR()->getPartition(0)->fileSystem());

    std::list<core::File*> files = fat->getDirectoryContent(std::string("/"));
    for(int i = 0; i < files.size(); i++){

        auto it1 = std::next(files.begin(), i);

        qDebug() << "File "<< i << ": " << (dynamic_cast<core::File*>(*it1)->getName());

    }*/

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
