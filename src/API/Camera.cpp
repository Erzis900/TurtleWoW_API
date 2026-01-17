#include "Camera.h"
#include "Mem.h"

namespace API::Camera
{
    uintptr_t GetPtr()
    {
        return Functions::GetCamera();
    }

    Vec3 GetPosition()
    {
        return Mem::Read<Vec3>(GetPtr() + Offsets::Camera::POSITION);
    }

    Vec2 GetScreenCoordinates(Vec3 worldPosition)
    {
        Vec2 screenCoordinates;
        Functions::GetScreenCoordinates(GetWorldFrame(), &worldPosition, &screenCoordinates);
        return screenCoordinates;
    }

    uintptr_t GetWorldFrame()
    {
        return Mem::Read<uintptr_t>(Offsets::Camera::WORLD_FRAME_PTR);
    }
}