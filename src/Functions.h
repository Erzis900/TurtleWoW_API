#pragma once
#include <cstdint>
#include "Offsets.h"

using fpGetPlayerGUID = uint64_t(__cdecl *)();
using fpGetObjectPtr = uintptr_t(__stdcall *)(uint64_t guid);
using ObjectCallback = bool(__thiscall *)(int filter, uint64_t guid);
using fpEnumVisibleObjects = bool(__fastcall *)(ObjectCallback proc, unsigned int filter);
using fpGetCamera = uintptr_t(__cdecl *)();
using fpMoveTo = bool(__thiscall *)(uintptr_t playerPtr, int clickType, uint64_t *interactGuidPtr, Vec3 *clickPos, float precision);
using fpGetUnitType = int(__thiscall *)(uintptr_t unitPtr);
using fpGetUnitReaction = int(__thiscall *)(uintptr_t unitPtr1, uintptr_t unitPtr2);
using fpGetGameObjectModelName = const char *(__fastcall *)(uintptr_t gameObjectPtr);

namespace Functions
{
    inline fpGetPlayerGUID GetPlayerGUID = reinterpret_cast<fpGetPlayerGUID>(Offsets::Functions::GET_PLAYER_GUID);
    inline fpGetObjectPtr GetObjectPtr = reinterpret_cast<fpGetObjectPtr>(Offsets::Functions::GET_OBJECT_PTR);
    inline fpEnumVisibleObjects EnumVisibleObjects = reinterpret_cast<fpEnumVisibleObjects>(Offsets::Functions::ENUM_VISIBLE_OBJECTS);
    inline fpGetCamera GetCamera = reinterpret_cast<fpGetCamera>(Offsets::Functions::GET_CAMERA);
    inline fpMoveTo MoveTo = reinterpret_cast<fpMoveTo>(Offsets::Functions::MOVE_TO);
    inline fpGetUnitType GetUnitType = reinterpret_cast<fpGetUnitType>(Offsets::Functions::GET_UNIT_TYPE);
    inline fpGetUnitReaction GetUnitReaction = reinterpret_cast<fpGetUnitReaction>(Offsets::Functions::GET_UNIT_REACTION);
    inline fpGetGameObjectModelName GetGameObjectModelName = reinterpret_cast<fpGetGameObjectModelName>(Offsets::Functions::GET_GAMEOBJECT_MODEL_NAME);
}