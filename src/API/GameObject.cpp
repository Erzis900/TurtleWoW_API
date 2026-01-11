#include "GameObject.h"

namespace API::GameObject
{
    std::string GetModelName(uint64_t guid)
    {
        const char *modelName = Functions::GetGameObjectModelName(GetObjectPtr(guid));
        if (!modelName)
            return "";

        return modelName;
    }
}