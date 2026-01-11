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
    enum ObjectType
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

    enum UnitType
    {
        Unknown,
        Beast,
        Dragon,
        Demon,
        Elemental,
        Giant,
        Undead,
        Humanoid,
        Critter,
        Mechanical,
        NotSpecified,
        Totem,
        NonCombatPet,
        GasCloud
    };
}