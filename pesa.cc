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
    SimpleSemaphore smPesa1("/smPesa1",0);
    SimpleSemaphore smPesa2("/smPesa2",0);
    SimpleSemaphore smPesa3("/smPesa3",0);

    int &dp3 = dpesa3();
    int &dp2 = dpesa2();
    int &dp1 = dpesa1();
    
    int &dsmpesa1 = smpesa1();
    int &dsmpesa2 = smpesa2();
    int &dsmpesa3 = smpesa3();
    
    while(true){
       
       if(dp1 == 0 ){
           sleep(3);
           dsmpesa1.signal();
           
       }



    }  
}