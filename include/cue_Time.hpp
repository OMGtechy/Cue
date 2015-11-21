#pragma once

#include "cue_Unit.hpp"

namespace cue
{
    template <typename StorageType> class Seconds;
    template <typename StorageType> class Minutes;
    template <typename StorageType> class Hours;

    template <typename StorageType>
    class Seconds : public Unit<StorageType, Seconds>
    {
    public:
        using Unit<StorageType, ::cue::Seconds>::Unit;

        explicit constexpr Seconds (const Minutes<StorageType>&) noexcept;
        explicit constexpr Seconds (const Hours<StorageType>&) noexcept;
    };

    template <typename StorageType>
    class Minutes : public Unit<StorageType, Minutes>
    {
    public:
        using Unit<StorageType, ::cue::Minutes>::Unit;

        explicit constexpr Minutes (const Seconds<StorageType>&) noexcept;
        explicit constexpr Minutes (const Hours<StorageType>&) noexcept;
    };

    template <typename StorageType>
    class Hours : public Unit<StorageType, Hours>
    {
    public:
        using Unit<StorageType, ::cue::Hours>::Unit;

        explicit constexpr Hours (const Seconds<StorageType>&) noexcept;
        explicit constexpr Hours (const Minutes<StorageType>&) noexcept;
    };

    template <typename StorageType>
    constexpr Seconds<StorageType>::Seconds (const Minutes<StorageType>& other) noexcept
    { this->setRawValue (other.getRawValue() * StorageType (60)); }

    template <typename StorageType>
    constexpr Seconds<StorageType>::Seconds (const Hours<StorageType>& other) noexcept
    { this->setRawValue (other.getRawValue() * StorageType (3600)); }

    template <typename StorageType>
    constexpr Minutes<StorageType>::Minutes (const Seconds<StorageType>& other) noexcept
    { this->setRawValue (other.getRawValue() / StorageType (60)); }

    template <typename StorageType>
    constexpr Minutes<StorageType>::Minutes (const Hours<StorageType>& other) noexcept
    { this->setRawValue (other.getRawValue() * StorageType (60)); }

    template <typename StorageType>
    constexpr Hours<StorageType>::Hours (const Seconds<StorageType>& other) noexcept
    { this->setRawValue (other.getRawValue() / StorageType (3600)); }

    template <typename StorageType>
    constexpr Hours<StorageType>::Hours (const Minutes<StorageType>& other) noexcept
    { this->setRawValue (other.getRawValue() / StorageType (60)); }
}

