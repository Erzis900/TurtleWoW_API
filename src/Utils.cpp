#include "Utils.h"
#include <array>

const std::array<std::string, 8> ObjectTypeStrings = {
    "None", "Item", "Container", "Unit", "Player", "GameObject", "DynamicObject", "Corpse"};

const std::array<std::string, 14> UnitTypeStrings = {
    "Unknown", "Beast", "Dragon", "Demon", "Elemental", "Giant",
    "Undead", "Humanoid", "Critter", "Mechanical", "NotSpecified",
    "Totem", "NonCombatPet", "GasCloud"};

namespace Utils
{
    std::string ObjectTypeToString(Types::ObjectType type)
    {
        return ObjectTypeStrings[type];
    }

    std::string UnitTypeToString(Types::UnitType type)
    {
        return UnitTypeStrings[type];
    }
}