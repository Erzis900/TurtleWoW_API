#include "API.h"
#include "Mem.h"
#include "Offsets.h"
#include "Utils.h"
#include <iostream>

namespace API
{
    namespace Player
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

    namespace Camera
    {
        uintptr_t GetPtr()
        {
            return Functions::GetCamera();
        }

        Vec3 GetPosition()
        {
            return Mem::Read<Vec3>(GetPtr() + Offsets::Camera::POSITION);
        }
    }

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