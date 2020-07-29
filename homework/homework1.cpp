#include<windows.h>
#include<iostream>
const unsigned short SIZE_OF_BUFFER = 10;
unsigned short ProductID = 0;
unsigned short ConsumeID = 0;
unsigned short in = 0;
unsigned short out = 0;
int g_buffer[SIZE_OF_BUFFER];
bool g_continue = true;
HANDLE g_hMutex;
HANDLE g_hFullSemaphore;
HANDLE g_hEmptySemaphore;
DWORD WINAPI Producer(LPVOID);
DWORD WINAPI Consumer(LPVOID);


int main(){
    using namespace std;

    //g_hMutex = CreateMutex(); 
}