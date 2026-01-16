#pragma once
#include "API.h"

namespace API::Unit
{
    Types::UnitType GetType(uint64_t guid);
    std::string GetTypeString(uint64_t guid);
    Types::ReactionType GetReactionType(uint64_t guid1, uint64_t guid2);
    std::string GetReactionTypeString(uint64_t guid1, uint64_t guid2);
}