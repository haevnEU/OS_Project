#ifndef CONTENTDISPLAY_H
#define CONTENTDISPLAY_H

#include <QWidget>

#include <QTextEdit>
#include <QRadioButton>
#include <QGridLayout>
#include <QListWidget>
#include "ui/customUI/customlistwidgetitem.h"
#include <QHBoxLayout>
#include "core/File.h"
#include "core/api.h"
#include <QPushButton>

namespace ui{
     namespace window{
     class ContentDisplay : public QWidget{

         Q_OBJECT

     private:
         QGridLayout* layout;
         QRadioButton* btBin;
         QRadioButton* btHex;
         QRadioButton* btTxt;

         QPushButton* btSave;
         QPushButton* btDelete;
         QPushButton* btCancel;

         QListWidget* content;
         QTextEdit* contentEditor;

         char* data;
     public:
         ContentDisplay();

         void enableDarkMode(void);
         void enableLightMode(void);
     private slots:
         void btHexClicked(bool checked);
         void btBinClicked(bool checked);
         void btTxtClicked(bool checked);
         void fileActivated(QListWidgetItem *item);
     };
     }
}
#endif // CONTENTDISPLAY_H
