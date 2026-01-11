#include "API.h"
#include "Mem.h"
#include "Offsets.h"
#include "Utils.h"
#include <iostream>

namespace API
{
    uintptr_t GetObjectPtr(uint64_t guid)
    {
        return Functions::GetObjectPtr(guid);
    }

    Vec3 GetPosition(uint64_t guid)
    {
        return Mem::Read<Vec3>(GetObjectPtr(guid) + Offsets::Unit::POSITION);
    }

    uintptr_t GetDescriptor(uint64_t guid)
    {
        return Mem::Read<uintptr_t>(GetObjectPtr(guid) + Offsets::Unit::DESCRIPTOR);
    }

    int GetHealth(uint64_t guid)
    {
        return Mem::Read<int>(GetDescriptor(guid) + Offsets::Unit::HEALTH);
    }

    Types::Object GetType(uint64_t guid)
    {
        return Mem::Read<Types::Object>(GetObjectPtr(guid) + Offsets::Object::TYPE);
    }

    std::string GetTypeString(uint64_t guid)
    {
        return Utils::ObjectTypeToString(GetType(guid));
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

    float GetRotation(uint64_t guid)
    {
        return Mem::Read<float>(Functions::GetObjectPtr(guid) + Offsets::Unit::FACING);
    }

    float GetSpeed(uint64_t guid)
    {
        return Mem::Read<float>(Functions::GetObjectPtr(guid) + Offsets::Unit::SPEED);
    }
}