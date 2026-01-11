#pragma once
#include <cstdint>
#include "Types.h"
#include "Functions.h"
#include <string>

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

    ObjectType GetType(uint64_t guid);
    ObjectType GetPlayerType();

    std::string GetTypeString(uint64_t guid);
    std::string GetPlayerTypeString();

    std::string GetName(uint64_t guid);
    void ForEachObject(ObjectCallback function);
}