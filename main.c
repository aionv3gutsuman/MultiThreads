#include <stdio.h>
#include <Windows.h>
#include <process.h>

#define CLIENTNUM 2


unsigned __stdcall MultiThreadFunc(void* pArguments);

int main()
{

	HANDLE handles[CLIENTNUM] = { NULL,NULL };
	unsigned threadID[CLIENTNUM] = { 0,0 };

	for (int i = 0; i < CLIENTNUM; ++i)
	{
		handles[i] = (HANDLE)_beginthreadex(NULL, 0, &MultiThreadFunc, (void*)i, 0, &threadID);
		Sleep(1);
	}

	for (int i = 0; i < CLIENTNUM; ++i)
	{

		if (handles[i] != 0)
		{
			WaitForSingleObject(handles[i], INFINITE);
		}

	}

	for (int i = 0; i < CLIENTNUM; ++i)
	{

		if (handles[i] != 0)
		{
			CloseHandle(handles[i]);
		}

	}


	return 0;
}




unsigned __stdcall MultiThreadFunc(void* pArguments)
{
	printf("ThreadNo.%d\n", (int)pArguments);

	return 0;

}
