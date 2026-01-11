#pragma once
#include "API.h"

namespace API::Player
{
    bool IsLoggedIn();
    uint64_t GetGUID();
    uintptr_t GetPtr();
    Vec3 GetPosition();
    void SetPosition(Vec3 position);
    int GetHealth();
    Types::ObjectType GetType();
    std::string GetTypeString();
    void MoveTo(Vec3 position);
    float GetRotation();
    float GetSpeed();
    void SetSpeed(float speed);
    void SetSpeedModifier(float speedModifier);
}