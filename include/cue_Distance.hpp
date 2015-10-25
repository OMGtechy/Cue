#pragma once

#include "cue_Unit.hpp"

namespace cue
{
    template <typename StorageType>
    class Metres : protected Unit<StorageType>
    {
    public:
        static Metres fromMetres (StorageType metres) noexcept { return Metres (metres); }

    protected:
        using Unit<StorageType>::Unit;
    };
}
