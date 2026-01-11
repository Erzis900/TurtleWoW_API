#include <Windows.h>
#include "Console.h"
#include "API.h"
#include <iostream>

DWORD WINAPI MainThread(HINSTANCE hinstDLL)
{
    Console::Init();

    while (!(GetAsyncKeyState(VK_END) & 1))
    {
        std::cout << API::GetPlayerTypeString() << std::endl;
        Sleep(50);
    }

    Console::Shutdown();
    FreeLibraryAndExitThread(hinstDLL, 0);
    return 0;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    if (fdwReason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(hinstDLL);
        CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)MainThread, hinstDLL, 0, nullptr);
    }

    return TRUE;
}
