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
	SimpleSemaphore semPC("/sem",0);
	SimpleSemaphore semCP("/sem2");
    SimpleSemaphore semB("/semBuff");
	SharedMemory<int> mc("/sm");
	int &i = mc();

    for (int cont=0; cont < 10; cont++){
        sleep(3);
        cout << "productor: estoy esperando el buffer "<< endl;
        semCP.Wait();
        semB.Wait();
        i = getpid();
        cout << "productor: mi id es: " << i << endl;
        semB.Signal();
        semPC.Signal();
    }
}