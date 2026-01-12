# TurtleWoW API (1.12 WoW Classic)
A lightweight internal C++ API for retrieving data from the game client. Its primary goal is to abstract low-level memory access into a simple, easy-to-use API layer for WoW game hacking.

# Features
- Access to common object data (position, name, health, rotation etc.)
- Object list enumeration
- Player setters (teleport, speed)
- Camera helpers

Any many more.

# Object Model

The API exposes all visible game objects through a GUID-based interface.
Each object has:
- A unique uint64_t GUID
- A base object pointer resolved internally
- A type defined by `Types::ObjectType`

You can query object-specific data only when it makes sense for that type.

Example:

```cpp
if (API::GetType(guid) == Types::Unit)
{
    int hp = API::GetHealth(guid);
}
```

# Examples
Speed hack is as simple as calling a single API function once:
```cpp
API::Player::SetSpeedModifier(20.f);
```
Full example:
```cpp
#include <Windows.h>
#include "API/API.h"

DWORD WINAPI MainThread(HINSTANCE hinstDLL)
{
    API::Player::SetSpeedModifier(20.f);
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

```

Teleport hack can be made with help of the following function:
```cpp
API::Player::SetPosition({...});
```

You can iterate over all the objects:
```cpp
// This function gets called for each object
bool __thiscall Callback(int filter, uint64_t guid)
{
    // Printing name
    std::cout << API::GetName(guid) << std::endl;
    return true;
}

DWORD WINAPI MainThread(HINSTANCE hinstDLL)
{
    Console::Init(); // Not part of API

    while (!(GetAsyncKeyState(VK_END) & 1))
    {
        // Iterating over objects
        API::ForEachObject(Callback);
        Sleep(50);
    }

    Console::Shutdown(); // Not part of API
    FreeLibraryAndExitThread(hinstDLL, 0);
    return 0;
}
```

There are certain properties which only make sense on certain types of objects. 
For example items and herbs don't have hp - but units do. That's why it's important to filter the objects. This can be  done simply:

```cpp
bool __thiscall Callback(int filter, uint64_t guid)
{
    // Check the object type and skip it if it's not a unit
    if (API::GetType(guid) != Types::Unit)
        return true;

    // Print unit position
    std::cout << API::GetPosition(guid).ToString() << std::endl;
    return true;
}
```

# Calling VTable Functions

The API exposes a generic virtual function caller:
```cpp
// Returns name of an object
std::string GetName(uint64_t guid)
{
    // Calling function at index 28 of a given object
    const char *name = CallVFunc<28, const char *>(GetObjectPtr(guid));
    return std::string(name);
}
```

# Building
This project can be treated as a base for your WoW cheat. It can be built using CMake.

```
mkdir build
cd build
cmake ..
cmake --build .
```

# Disclaimer

This project is provided for educational and research purposes only. You are fully responsible for how you use it.