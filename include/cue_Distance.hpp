#pragma once

#include "cue_Unit.hpp"

namespace cue
{
    template <typename StorageType> class Centimetres;

    template <typename StorageType>
    class Metres : public Unit<StorageType>
    {
    public:
        static Metres fromMetres (StorageType metres) noexcept;

        Metres operator+ (Metres rhs) const noexcept;
        Metres operator+ (Centimetres<StorageType> rhs) const noexcept;

    protected:
        using Unit<StorageType>::Unit;
    };

    template <typename StorageType>
    class Centimetres : public Unit<StorageType>
    {
    public:
        static Centimetres fromCentimetres (StorageType centimetres) noexcept;

        Centimetres operator+ (Centimetres rhs) const noexcept;
        Centimetres operator+ (Metres<StorageType> rhs) const noexcept;

    protected:
        using Unit<StorageType>::Unit;
    };

    template <typename StorageType>
    Metres<StorageType> Metres<StorageType>::fromMetres (StorageType metres) noexcept
    { return { metres }; }

    template <typename StorageType>
    Metres<StorageType> Metres<StorageType>::operator+ (Metres<StorageType> rhs) const noexcept
    { return { this->getRawValue() + rhs.getRawValue() }; }

    template <typename StorageType>
    Metres<StorageType> Metres<StorageType>::operator+ (Centimetres<StorageType> rhs) const noexcept
    { return { this->getRawValue() + rhs.getRawValue() / StorageType (100) }; }

    template <typename StorageType>
    Centimetres<StorageType> Centimetres<StorageType>::fromCentimetres (StorageType centimetres) noexcept
    { return { centimetres }; }

    template <typename StorageType>
    Centimetres<StorageType> Centimetres<StorageType>::operator+ (Centimetres<StorageType> rhs) const noexcept
    { return { this->getRawValue() + rhs.getRawValue() }; }

    template <typename StorageType>
    Centimetres<StorageType> Centimetres<StorageType>::operator+ (Metres<StorageType> rhs) const noexcept
    { return { this->getRawValue() + rhs.getRawValue() * 100 }; }
}
