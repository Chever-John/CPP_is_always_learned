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
using namespace std;
 
int main(void)
{
	g_hMutex = CreateMutex(NULL, FALSE, NULL);
	g_hFullSemaphore = CreateSemaphore(NULL, 0, SIZE_OF_BUFFER - 1, NULL);
	g_hEmptySemaphore = CreateSemaphore(NULL, SIZE_OF_BUFFER - 1, SIZE_OF_BUFFER - 1, NULL);
	const unsigned short PRODUCERS_COUNT = 3;
	const unsigned short CONSUMERS_COUNT = 1;
	const unsigned short THREADS_COUNT = PRODUCERS_COUNT + CONSUMERS_COUNT;
	HANDLE hThreads[THREADS_COUNT];
	DWORD producerID[PRODUCERS_COUNT];
	DWORD consumerID[CONSUMERS_COUNT];
 
	for (int i = 0; i < PRODUCERS_COUNT; ++i)
	{
		hThreads[i] = CreateThread(NULL, 0, Producer, NULL, 0, &producerID[i]);
		if (hThreads[i] == NULL)
			return -1;
	}
 
	for (int i = 0; i < CONSUMERS_COUNT; ++i)
	{
		hThreads[PRODUCERS_COUNT + i] = CreateThread(NULL, 0, Consumer, NULL, 0, &consumerID[i]);
		if (hThreads[i] == NULL)
			return -1;
	}
 
	while (g_continue)
	{
		if (getchar())g_continue = false;
	}
	return 0;
}
 
void Produce()
{
	cerr << "Producing" << ++ProductID << "...";
	cerr << "Succeed" << endl;
}
 
void Append()
{
	cerr << "Appending a product...";
	g_buffer[in] = ProductID;
	in = (in + 1) % SIZE_OF_BUFFER;
	cerr << "Succeed" << endl;
	for (int i = 0; i < SIZE_OF_BUFFER; ++i)
	{
		cout << i << ":" << g_buffer[i];
		if (i == in)cout << "<--     生产";
		if (i == out)cout << "<--    消费";
		cout << endl;
	}
}
 
void Take()
{
	cerr << "Taking a product ...";
	ConsumeID = g_buffer[out];
	out = (out + 1) % SIZE_OF_BUFFER;
	cerr << "Succeed" << endl;
	for (int i = 0; i < SIZE_OF_BUFFER; i++)
	{
		cout << i << ":" << g_buffer[i];
		if (i == in)cout << "<--     生产";
		if (i == out)cout << "<--    消费";
		cout << endl;
	}
}
 
void Consume()
{
	cerr << "Consuming" << ConsumeID << "...";
	cerr << "Succeed" << endl;
}
 
DWORD WINAPI Producer(LPVOID lpPara)
{
	while (g_continue)
	{
		WaitForSingleObject(g_hEmptySemaphore, INFINITE);
		WaitForSingleObject(g_hMutex, INFINITE);
		Produce();
		Append();
		Sleep(1500);
		ReleaseMutex(g_hMutex);
		ReleaseSemaphore(g_hFullSemaphore, 1, NULL);
	}
	return 0;
}
 
DWORD WINAPI Consumer(LPVOID lpPara)
{
	while (g_continue)
	{
		WaitForSingleObject(g_hFullSemaphore, INFINITE);
		WaitForSingleObject(g_hMutex, INFINITE);
		Take();
		Consume();
		Sleep(1500);
		ReleaseMutex(g_hMutex);
		ReleaseSemaphore(g_hEmptySemaphore, 1, NULL);
	}
	return 0;
}
