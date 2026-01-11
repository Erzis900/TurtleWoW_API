#include <Windows.h>
#include "Console.h"
#include "API.h"
#include <iostream>

bool __thiscall Callback(int filter, uint64_t guid)
{
    // std::cout << API::GetTypeString(guid) << std::endl;
    // if (API::GetType(guid) != Types::Object::Player)
    // {
    //     std::cout << API::GetName(guid) << std::endl;
    // }

    // std::cout << API::GetCameraPosition().ToString() << std::endl;
    std::cout << API::GetPlayerSpeed() << std::endl;

    return true;
}

DWORD WINAPI MainThread(HINSTANCE hinstDLL)
{
    Console::Init();

    while (!(GetAsyncKeyState(VK_END) & 1))
    {
        API::ForEachObject(Callback);
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
