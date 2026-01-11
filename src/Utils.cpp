#include "Utils.h"
#include <array>

const std::array<std::string, 8> ObjectTypeStrings = {
    "None", "Item", "Container", "Unit", "Player", "GameObject", "DynamicObject", "Corpse"};

namespace Utils
{
    std::string ObjectTypeToString(ObjectType type)
    {
        return ObjectTypeStrings[type];
    }
}