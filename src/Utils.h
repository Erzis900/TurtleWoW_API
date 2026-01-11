#pragma once
#include <string>
#include "Types.h"

namespace Utils
{
    std::string ObjectTypeToString(Types::ObjectType type);
    std::string UnitTypeToString(Types::UnitType type);
    std::string ReactionTypeToString(Types::ReactionType type);
}