#pragma once
#include <cstdint>

namespace Mem
{
    template <typename T>
    T Read(uintptr_t address)
    {
        return *reinterpret_cast<T *>(address);
    }
}