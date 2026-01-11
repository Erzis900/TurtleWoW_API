#include "Player.h"
#include "Mem.h"

namespace API::Player
{
    bool IsLoggedIn()
    {
        return Functions::GetPlayerGUID() > 0;
    }

    uint64_t GetGUID()
    {
        return Functions::GetPlayerGUID();
    }

    uintptr_t GetPtr()
    {
        return Functions::GetObjectPtr(GetGUID());
    }

    Vec3 GetPosition()
    {
        return API::GetPosition(GetGUID());
    }

    void SetPosition(Vec3 position)
    {
        Mem::Write<Vec3>(GetPtr() + Offsets::Object::POSITION, position);
    }

    int GetHealth()
    {
        return API::GetHealth(GetGUID());
    }

    Types::ObjectType GetType()
    {
        return API::GetType(GetGUID());
    }

    std::string GetTypeString()
    {
        return API::GetTypeString(GetGUID());
    }

    void MoveTo(Vec3 position)
    {
        uint64_t guid = 0;
        Functions::MoveTo(GetPtr(), 4, &guid, &position, 2);
    }

    float GetRotation()
    {
        return API::GetRotation(GetGUID());
    }

    float GetSpeed()
    {
        return API::GetSpeed(GetGUID());
    }

    void SetSpeed(float speed)
    {
        Mem::Write<float>(GetPtr() + Offsets::Object::SPEED, speed);
    }

    float GetSpeedModifier()
    {
        return Mem::Read<float>(GetPtr() + Offsets::Object::SPEED_MOD);
    }

    void SetSpeedModifier(float speedModifier)
    {
        Mem::Write<float>(GetPtr() + Offsets::Object::SPEED_MOD, speedModifier);
    }
}