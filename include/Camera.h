#pragma once
#include "API.h"

namespace API::Camera
{
    uintptr_t GetPtr();
    Vec3 GetPosition();
    Vec2 GetScreenCoordinates(Vec3 worldPosition);
    uintptr_t GetWorldFrame();
}