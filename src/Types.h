#pragma once

struct Vec3
{
    float x, y, z;
};

enum ObjectType
{
    None,
    Item,
    Container,
    Unit,
    Player,
    GameObject,
    DynamicObject,
    Corpse
};