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

    template <typename StorageType>
    class Centimetres : public Unit<StorageType>
    {
    public:
        static Centimetres fromCentimetres (StorageType centimetres) noexcept
        { return Centimetres (centimetres); }

        Centimetres operator+ (Centimetres rhs) noexcept
        { return Centimetres (this->getRawValue() + rhs.getRawValue()); }

        Centimetres operator+ (Metres<StorageType> rhs) noexcept
        { return Centimetres (this->getRawValue() + rhs.getRawValue() * 100); }

    protected:
        using Unit<StorageType>::Unit;
    };
}
