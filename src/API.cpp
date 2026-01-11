#include "API.h"
#include "Mem.h"
#include "Offsets.h"
#include "Utils.h"
#include <iostream>

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

    Types::Object GetType(uint64_t guid)
    {
        return Mem::Read<Types::Object>(GetObjectPtr(guid) + Offsets::Object::TYPE);
    }

    Types::Object GetPlayerType()
    {
        return GetType(GetPlayerGUID());
    }

    std::string GetTypeString(uint64_t guid)
    {
        return Utils::ObjectTypeToString(GetType(guid));
    }

    std::string GetPlayerTypeString()
    {
        return GetTypeString(GetPlayerGUID());
    }

    std::string GetName(uint64_t guid)
    {
        uintptr_t ptr1 = Mem::Read<uintptr_t>(GetObjectPtr(guid) + Offsets::Unit::NAME);
        uintptr_t ptr2 = Mem::Read<uintptr_t>(ptr1);
        return Mem::ReadString(ptr2);
    }

    void ForEachObject(ObjectCallback function)
    {
        Functions::EnumVisibleObjects(function, 0);
    }

    uintptr_t GetCameraPtr()
    {
        return Functions::GetCamera();
    }

    Vec3 GetCameraPosition()
    {
        return Mem::Read<Vec3>(GetCameraPtr() + Offsets::Camera::POSITION);
    }

    void MoveTo(Vec3 position)
    {
        uint64_t guid = 0;
        Functions::MoveTo(GetPlayerPtr(), 4, &guid, &position, 2);
    }
}