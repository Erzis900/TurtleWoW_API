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
        return Functions::GetObjectPtr(Functions::GetPlayerGUID());
    }

    Vec3 GetPosition()
    {
        return API::GetPosition(GetGUID());
    }

    void SetPosition(Vec3 position)
    {
        Mem::Write<Vec3>(GetPtr() + Offsets::Unit::POSITION, position);
    }

    int GetHealth()
    {
        return API::GetHealth(GetGUID());
    }

    Types::Object GetType()
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

    float GetPlayerRotation()
    {
        return API::GetRotation(GetGUID());
    }

    float GetPlayerSpeed()
    {
        return API::GetSpeed(GetGUID());
    }

    void SetPlayerSpeed(float speed)
    {
        Mem::Write<float>(GetPtr() + Offsets::Unit::SPEED, speed);
    }

    float GetSpeedModifier(uint64_t guid)
    {
        return Mem::Read<float>(GetPtr() + Offsets::Unit::SPEED_MOD);
    }

    void SetPlayerSpeedModifier(float speedModifier)
    {
        Mem::Write<float>(GetPtr() + Offsets::Unit::SPEED_MOD, speedModifier);
    }
}