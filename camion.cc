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
    SimpleSemaphore smpesa1("/smPesa1",0);
    SimpleSemaphore smpesa2("/smPesa2",0);
    SimpleSemaphore smpesa3("/smPesa3",0);

    SimpleSemaphore smCarril("/smCarril",0); 

    int &dp3 = dpesa3();
    int &dp2 = dpesa2();
    int &dp1 = dpesa1();
    int &pesa = smPesa();
    int &dpesa1 = smpesa1();
    int &dpesa2 = smpesa2();
    int &dpesa3 = smpesa3();
    
    for(int cont=0; cont < 10; cont++){

        pesa.Wait();

        if(dp1 == 1){ 
          dp1 = 0;
          dpesa1.Wait();    
        }
        if(dp2 == 1){ 
          dp2 = 0;
          dpesa2.Wait();    
        }
        if(dp3 == 1){ 
          dp3 = 0;
          dpesa3.Wait();    
        }

        sleep(3);

        carril.wait();

        sleep(3);  

    }
    
}