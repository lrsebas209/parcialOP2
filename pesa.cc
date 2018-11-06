#ifndef __SIMPLESEMAPHORE_H_
#include <SimpleSemaphore.h>
#define __SIMPLESEMAPHORE_H_
#endif

#ifndef __SHAREDMEMORY_H_
#include <SharedMemory.h>
#define __SHAREDMEMORY_H_
#endif

#ifndef __IOSTREAM__
#include <iostream>
#define __IOSTREAM__
#endif

using std::cout;

int main() {
    SharedMemory<int> dpesa1("/dpesa1");
    SharedMemory<int> dpesa2("/dpesa2");
    SharedMemory<int> dpesa3("/dpesa3");

    SimpleSemaphore smPesa("/smPesa",0);
   

    int &dp3 = dpesa3();
    int &dp2 = dpesa2();
    int &dp1 = dpesa1();
    
    while(true){
       
       


    }  
}