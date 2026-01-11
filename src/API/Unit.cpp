#include "Unit.h"
#include "Utils.h"

namespace API::Unit
{
    Types::UnitType GetType(uint64_t guid)
    {
        return static_cast<Types::UnitType>(Functions::GetUnitType(GetObjectPtr(guid)));
    }

    std::string GetTypeString(uint64_t guid)
    {
        return Utils::UnitTypeToString(GetType(guid));
    }

    Types::ReactionType GetReactionType(uint64_t guid1, uint64_t guid2)
    {
        return static_cast<Types::ReactionType>(Functions::GetUnitReaction(GetObjectPtr(guid1), GetObjectPtr(guid2)));
    }

    std::string GetReactionTypeString(uint64_t guid1, uint64_t guid2)
    {
        return Utils::ReactionTypeToString(GetReactionType(guid1, guid2));
    }

    // 17379391011599442302 17379391015927964314
    // 6452165
    // 17379391011515556093
    // 17379391011599442413
}