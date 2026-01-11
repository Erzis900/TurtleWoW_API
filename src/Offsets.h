#pragma once

namespace Offsets
{
    namespace Functions
    {
        constexpr uintptr_t GET_PLAYER_GUID = 0x00468550;
        constexpr uintptr_t GET_OBJECT_PTR = 0x00464870;
        constexpr uintptr_t ENUM_VISIBLE_OBJECTS = 0x00468380;
        constexpr uintptr_t GET_CAMERA = 0x004818F0;
        constexpr uintptr_t GET_SCREEN_COORDINATES = 0x00483EE0;
        constexpr uintptr_t MOVE_TO = 0x00611130;
        constexpr uintptr_t GET_CREATURE_TYPE = 0x00605570;
        constexpr uintptr_t GET_UNIT_REACTION = 0x006061E0;
        constexpr uintptr_t GET_UNIT_MODEL_NAME = 0x00600320;
        constexpr uintptr_t GET_MODEL_NAME = 0x005F8090;
    }

    namespace Object
    {
        constexpr uintptr_t TYPE = 0x14;
    }

    namespace Unit
    {
        constexpr uintptr_t DESCRIPTOR = 0x8;
        constexpr uintptr_t POSITION = 0x9B8;
        constexpr uintptr_t FACING = 0x09C4;
        constexpr uintptr_t HEALTH = 0x58;
        constexpr uintptr_t NAME = 0xB30;
        constexpr uintptr_t SPEED = 0xA2C;
    }

    namespace Camera
    {
        constexpr uintptr_t POSITION = 0x8;
    }
}