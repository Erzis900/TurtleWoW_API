#pragma once
#include <cstdint>
#include <string>
#include "Types.h"
#include "Functions.h"

#include "Player.h"
#include "Camera.h"

namespace API
{
    uintptr_t GetObjectPtr(uint64_t guid);
    Vec3 GetPosition(uint64_t guid);
    uintptr_t GetDescriptor(uint64_t guid);
    int GetHealth(uint64_t guid);
    Types::Object GetType(uint64_t guid);
    std::string GetTypeString(uint64_t guid);
    std::string GetName(uint64_t guid);
    void ForEachObject(ObjectCallback function);
    float GetRotation(uint64_t guid);
    float GetSpeed(uint64_t guid);
    float GetSpeedModifier(uint64_t guid);
}