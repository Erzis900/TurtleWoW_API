#pragma once

struct Vec3
{
    float x, y, z;
};

namespace Types
{
    enum Object
    {
        None,
        Item,
        Container,
        Unit,
        Player,
        GameObject,
        DynamicObject,
        Corpse
    };
}