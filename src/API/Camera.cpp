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
}