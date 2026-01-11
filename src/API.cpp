#include "API.h"
#include "Functions.h"
#include "Mem.h"
#include "Offsets.h"

namespace API
{
    bool IsLoggedIn()
    {
        return Functions::GetPlayerGUID() > 0;
    }

    uint64_t GetPlayerGUID()
    {
        return Functions::GetPlayerGUID();
    }

    uintptr_t GetObjectPtr(uint64_t guid)
    {
        return Functions::GetObjectPtr(guid);
    }

    uintptr_t GetPlayerPtr()
    {
        return Functions::GetObjectPtr(Functions::GetPlayerGUID());
    }

    Vec3 GetPosition(uint64_t guid)
    {
        return Mem::Read<Vec3>(GetObjectPtr(guid) + Offsets::Unit::POSITION);
    }

    Vec3 GetPlayerPosition()
    {
        return GetPosition(GetPlayerGUID());
    }

    uintptr_t GetDescriptor(uint64_t guid)
    {
        return Mem::Read<uintptr_t>(GetObjectPtr(guid) + Offsets::Unit::DESCRIPTOR);
    }

    int GetHealth(uint64_t guid)
    {
        return Mem::Read<int>(GetDescriptor(guid) + Offsets::Unit::HEALTH);
    }

    int GetPlayerHealth()
    {
        return GetHealth(GetPlayerGUID());
    }

    int GetType(uint64_t guid)
    {
        return Mem::Read<ObjectType>(GetObjectPtr(guid) + Offsets::Object::TYPE);
    }

    int GetPlayerType()
    {
        return GetType(GetPlayerGUID());
    }
}