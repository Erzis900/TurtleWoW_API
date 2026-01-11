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

    std::vector<uint8_t> ReadBytes(uintptr_t address, int count)
    {
        std::vector<uint8_t> bytes;
        bytes.resize(count);

        uint8_t *ptr = reinterpret_cast<uint8_t *>(address);

        for (int i = 0; i < count; i++)
            bytes[i] = ptr[i];

        return bytes;
    }

    std::string ReadString(uintptr_t address)
    {
        auto buffer = ReadBytes(address, 512);

        std::string ret(buffer.begin(), buffer.end());

        size_t nullPos = ret.find('\0');
        if (nullPos != std::string::npos)
            ret.erase(nullPos);

        return ret;
    }
}