#pragma once
#include <string>

struct Vec3
{
    float x, y, z;

    std::string ToString()
    {
        return "(" + std::to_string(x) + ", " +
               std::to_string(y) + ", " +
               std::to_string(z) + ")";
    }
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