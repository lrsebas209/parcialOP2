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
    SimpleSemaphore semBuffer("/semBuff");
	SharedMemory<int> sm("/sm");
	int &i = sm();

    for (int cont=0; cont < 10; cont++){
        cout << "Productor: esperando el buffer "<< endl;
        semCP.Wait();
        semBuffer.Wait();
        i = getpid();
        sleep(3);
        cout << "Productor: mi identificacion es: " << i << endl;
        semBuffer.Signal();
        semPC.Signal();
    }
}