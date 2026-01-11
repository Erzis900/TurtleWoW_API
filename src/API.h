#pragma once
#include <cstdint>
#include "Types.h"
#include "Functions.h"
#include "Types.h"
#include <string>

namespace API
{
    namespace Player
    {
        bool IsLoggedIn();
        uint64_t GetGUID();
        uintptr_t GetPtr();
        Vec3 GetPosition();
        void SetPosition(Vec3 position);
        int GetHealth();
        Types::Object GetType();
        std::string GetTypeString();
        void MoveTo(Vec3 position);
        float GetRotation();
        float GetSpeed();
        void SetSpeed(float speed);
        void SetSpeedModifier(float speedModifier);
    }

    namespace Camera
    {
        uintptr_t GetPtr();
        Vec3 GetPosition();
    }

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