#pragma once
#include <cstdint>
#include "Types.h"
#include "Functions.h"
#include "Types.h"
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

    Types::Object GetType(uint64_t guid);
    Types::Object GetPlayerType();

    std::string GetTypeString(uint64_t guid);
    std::string GetPlayerTypeString();

    std::string GetName(uint64_t guid);
    void ForEachObject(ObjectCallback function);

    uintptr_t GetCameraPtr();
    Vec3 GetCameraPosition();

    void MoveTo(Vec3 position);
    float GetRotation(uint64_t guid);
    float GetPlayerRotation();

    float GetSpeed(uint64_t guid);
    float GetPlayerSpeed();
}