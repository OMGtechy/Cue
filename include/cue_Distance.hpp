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

        explicit Metres (const Millimetres<StorageType>&) noexcept;
        explicit Metres (const Centimetres<StorageType>&) noexcept;
    };

    template <typename StorageType>
    class Centimetres : public Unit<StorageType, Centimetres>
    {
    public:
        using Unit<StorageType, ::cue::Centimetres>::Unit;

        explicit Centimetres (const Millimetres<StorageType>&) noexcept;
        explicit Centimetres (const Metres<StorageType>&)      noexcept;
    };

    template <typename StorageType>
    class Millimetres : public Unit<StorageType, Millimetres>
    {
    public:
        using Unit<StorageType, ::cue::Millimetres>::Unit;

        explicit Millimetres (const Centimetres<StorageType>&) noexcept;
        explicit Millimetres (const Metres<StorageType>&)      noexcept;
    };

    template <typename StorageType>
    Metres<StorageType>::Metres (const Millimetres<StorageType>& other) noexcept { this->setRawValue (other.getRawValue() / StorageType (1000)); }

    template <typename StorageType>
    Metres<StorageType>::Metres (const Centimetres<StorageType>& other) noexcept { this->setRawValue (other.getRawValue() / StorageType (100)); }

    template <typename StorageType>
    Centimetres<StorageType>::Centimetres (const Millimetres<StorageType>& other) noexcept { this->setRawValue (other.getRawValue() / StorageType (10)); }

    template <typename StorageType>
    Centimetres<StorageType>::Centimetres (const Metres<StorageType>& other) noexcept { this->setRawValue (other.getRawValue() * StorageType (100)); }

    template <typename StorageType>
    Millimetres<StorageType>::Millimetres (const Centimetres<StorageType>& other) noexcept { this->setRawValue (other.getRawValue() * StorageType (10)); }

    template <typename StorageType>
    Millimetres<StorageType>::Millimetres (const Metres<StorageType>& other) noexcept { this->setRawValue (other.getRawValue() * StorageType (1000)); }
}

