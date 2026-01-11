#pragma once
#include <cstdint>
#include "Types.h"

namespace API
{
    bool IsLoggedIn();
    uint64_t GetPlayerGUID();
    uintptr_t GetObjectPtr(uint64_t guid);
    uintptr_t GetPlayerPtr();
    Vec3 GetPosition(uint64_t guid);
    Vec3 GetPlayerPosition();
    uintptr_t GetDescriptor(uint64_t guid);
    int GetHealth(uint64_t guid);
    int GetPlayerHealth();

    int GetType(uint64_t guid);
    int GetPlayerType();
}