#pragma once
#include <cstdint>
#include "Offsets.h"

using fpGetPlayerGUID = uint64_t(__cdecl *)();
using fpGetObjectPtr = uintptr_t(__stdcall *)(uint64_t guid);
using EnumVisibleObjectsCallback = bool(__thiscall *)(int filter, uint64_t guid);
using fpEnumVisibleObjects = bool(__fastcall *)(EnumVisibleObjectsCallback proc, unsigned int filter);
// using GetActiveCamera = uintptr_t(__cdecl *)();
// using GetScreenCoordinates = bool(__thiscall *)(uintptr_t frame, Vec3 *worldPos, ImVec2 *screenOut);
// using ClickToMove = bool(__thiscall *)(uintptr_t playerPtr, int clickType, uint64_t *interactGuidPtr, Vec3 *clickPos, float precision);
// using GetCreatureType = int(__thiscall *)(uintptr_t unitPtr);
// using GetUnitReaction = int(__thiscall *)(uintptr_t unitPtr1, uintptr_t unitPtr2);
// using GetUnitModelName = char *(__fastcall *)(uintptr_t ptr);
// using GetModelName = const char *(__fastcall *)(uintptr_t objectPtr);

namespace Functions
{
    inline fpGetPlayerGUID GetPlayerGUID = reinterpret_cast<fpGetPlayerGUID>(Offsets::Functions::GET_PLAYER_GUID);
    inline fpGetObjectPtr GetObjectPtr = reinterpret_cast<fpGetObjectPtr>(Offsets::Functions::GET_OBJECT_PTR);
    inline fpEnumVisibleObjects EnumVisibleObjects = reinterpret_cast<fpEnumVisibleObjects>(Offsets::Functions::ENUM_VISIBLE_OBJECTS);
}