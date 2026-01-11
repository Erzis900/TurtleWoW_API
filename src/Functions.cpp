#include "Functions.h"
#include "Offsets.h"

namespace Functions
{
    fpGetPlayerGUID GetPlayerGUID = reinterpret_cast<fpGetPlayerGUID>(Offsets::Functions::GET_PLAYER_GUID);
    fpGetObjectPtr GetObjectPtr = reinterpret_cast<fpGetObjectPtr>(Offsets::Functions::GET_OBJECT_PTR);
}