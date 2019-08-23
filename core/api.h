#ifndef API_H
#define API_H

#include <string>
#include "block.h"
#include "disk.h"
#include "masterbootrecord.h"
#include "partition.h"

class API
{
public:
   static API* GetInstance();

   void setDisk(disk::Disk* disk);
   void clearDisk();




private:
   disk::Disk* curentDisk = nullptr;

   API();
   static API* instance;

};

#endif // API_H
