//
// Created by Leon on 15.07.2019.
//
#include <iostream>
#include <diskSimulation/Disk.h>

using namespace std;
int main() {

    Disk* test1 =new Disk(160,16);

    for(int i=0;i < 10; i++){
        cout <<endl << "Block " << i <<": "<< endl;
        for(int n =0; n < 16;n++){
            cout << test1->getBit(i,n) ;
        }

    }
    test1->setBit(0,1,1);
    for(int i=0;i < 10; i++){
        cout <<endl << "Block " << i <<": "<< endl;
        for(int n =0; n < 16;n++){
            cout << test1->getBit(i,n) ;
        }

    }
    test1->coppyBlockContent(0,1);
    for(int i=0;i < 10; i++){
        cout <<endl << "Block " << i <<": "<< endl;
        for(int n =0; n < 16;n++){
            cout << test1->getBit(i,n) ;
        }

    }

    return 0;

}
