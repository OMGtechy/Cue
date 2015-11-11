#pragma once

#include "cue_Unit.hpp"

namespace cue
{
    template <typename StorageType> class Millimetres;
    template <typename StorageType> class Centimetres;
    template <typename StorageType> class Metres;

    template <typename StorageType>
    class Metres : public Unit<StorageType, Metres>
    {
    public:
        using Unit<StorageType, ::cue::Metres>::Unit;

        explicit constexpr Metres (const Millimetres<StorageType>&) noexcept;
        explicit constexpr Metres (const Centimetres<StorageType>&) noexcept;
    };

    template <typename StorageType>
    class Centimetres : public Unit<StorageType, Centimetres>
    {
    public:
        using Unit<StorageType, ::cue::Centimetres>::Unit;

        explicit constexpr Centimetres (const Millimetres<StorageType>&) noexcept;
        explicit constexpr Centimetres (const Metres<StorageType>&)      noexcept;
    };

    template <typename StorageType>
    class Millimetres : public Unit<StorageType, Millimetres>
    {
    public:
        using Unit<StorageType, ::cue::Millimetres>::Unit;

        explicit constexpr Millimetres (const Centimetres<StorageType>&) noexcept;
        explicit constexpr Millimetres (const Metres<StorageType>&)      noexcept;
    };

    template <typename StorageType>
    constexpr Metres<StorageType>::Metres (const Millimetres<StorageType>& other) noexcept { this->setRawValue (other.getRawValue() / StorageType (1000)); }

    template <typename StorageType>
    constexpr Metres<StorageType>::Metres (const Centimetres<StorageType>& other) noexcept { this->setRawValue (other.getRawValue() / StorageType (100)); }

    template <typename StorageType>
    constexpr Centimetres<StorageType>::Centimetres (const Millimetres<StorageType>& other) noexcept { this->setRawValue (other.getRawValue() / StorageType (10)); }

    template <typename StorageType>
    constexpr Centimetres<StorageType>::Centimetres (const Metres<StorageType>& other) noexcept { this->setRawValue (other.getRawValue() * StorageType (100)); }

    template <typename StorageType>
    constexpr Millimetres<StorageType>::Millimetres (const Centimetres<StorageType>& other) noexcept { this->setRawValue (other.getRawValue() * StorageType (10)); }

    template <typename StorageType>
    constexpr Millimetres<StorageType>::Millimetres (const Metres<StorageType>& other) noexcept { this->setRawValue (other.getRawValue() * StorageType (1000)); }
}

