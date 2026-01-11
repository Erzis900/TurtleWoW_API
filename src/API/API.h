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

    // C++ magic, don't ask me about it
    template <std::size_t index, typename Ret, typename... Args>
    Ret CallVFunc(uintptr_t objectPtr, Args... args)
    {
        using Fn = Ret(__thiscall *)(void *, Args...);

        auto function = (*reinterpret_cast<Fn **>(objectPtr))[index];
        return function(reinterpret_cast<void *>(objectPtr), args...);
    }
}