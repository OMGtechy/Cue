#pragma once

#include "cue_Unit.hpp"

namespace cue
{
    template <typename StorageType>
    class Metres : public Unit<StorageType>
    {
    public:
        static Metres fromMetres (StorageType metres) noexcept
        { return Metres (metres); }

        Metres operator+ (Metres rhs) noexcept
        { return Metres (this->getRawValue() + rhs.getRawValue()); }

    protected:
        using Unit<StorageType>::Unit;
    };
}
