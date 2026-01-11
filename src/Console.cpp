#include "Console.h"
#include <Windows.h>
#include <cstdio>
#include <iostream>

namespace Console
{
    void Init()
    {
        AllocConsole();
        freopen("CONOUT$", "w", stdout);

        SetConsoleTitleA("TurtleWoW API by Einhar");
        std::cout << "Console initialized\n";
    }

    void Shutdown()
    {
        fclose(stdout);
        FreeConsole();
    }
}
