#include <Windows.h>

DWORD WINAPI MainThread(HINSTANCE hinstDLL)
{
    while (!(GetAsyncKeyState(VK_END) & 1))
    {
        Sleep(50);
    }

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
