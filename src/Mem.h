#pragma once
#include <cstdint>
#include <vector>
#include <string>

namespace Mem
{
    template <typename T>
    T Read(uintptr_t address)
    {
        return *reinterpret_cast<T *>(address);
    }

    std::string ReadString(uintptr_t address)
    {
        return std::string(reinterpret_cast<char *>(address));
    }
}