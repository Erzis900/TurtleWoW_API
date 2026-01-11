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
        return Mem::Read<Vec3>(GetObjectPtr(guid) + Offsets::Object::POSITION);
    }

    uintptr_t GetDescriptor(uint64_t guid)
    {
        return Mem::Read<uintptr_t>(GetObjectPtr(guid) + Offsets::Object::DESCRIPTOR);
    }

    int GetHealth(uint64_t guid)
    {
        return Mem::Read<int>(GetDescriptor(guid) + Offsets::Object::HEALTH);
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
        const char *name = CallVFunc<28, const char *>(GetObjectPtr(guid));
        return std::string(name);
    }

    void ForEachObject(ObjectCallback function)
    {
        Functions::EnumVisibleObjects(function, 0);
    }

    float GetRotation(uint64_t guid)
    {
        return Mem::Read<float>(Functions::GetObjectPtr(guid) + Offsets::Object::ROTATION);
    }

    float GetSpeed(uint64_t guid)
    {
        return Mem::Read<float>(Functions::GetObjectPtr(guid) + Offsets::Object::SPEED);
    }

    float GetSpeedModifier(uint64_t guid)
    {
        return Mem::Read<float>(Functions::GetObjectPtr(guid) + Offsets::Object::SPEED_MOD);
    }

    int GetID(uint64_t guid)
    {
        return Mem::Read<int>(GetDescriptor(guid) + Offsets::Object::ID);
    }
}