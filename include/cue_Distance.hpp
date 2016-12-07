/*
    This file is part of Cue.

    Cue is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Cue is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

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
    constexpr Metres<StorageType>::Metres (const Millimetres<StorageType>& other) noexcept
    { this->setRawValue (other.getRawValue() / StorageType (1000)); }

    template <typename StorageType>
    constexpr Metres<StorageType>::Metres (const Centimetres<StorageType>& other) noexcept
    { this->setRawValue (other.getRawValue() / StorageType (100)); }

    template <typename StorageType>
    constexpr Centimetres<StorageType>::Centimetres (const Millimetres<StorageType>& other) noexcept
    { this->setRawValue (other.getRawValue() / StorageType (10)); }

    template <typename StorageType>
    constexpr Centimetres<StorageType>::Centimetres (const Metres<StorageType>& other) noexcept
    { this->setRawValue (other.getRawValue() * StorageType (100)); }

    template <typename StorageType>
    constexpr Millimetres<StorageType>::Millimetres (const Centimetres<StorageType>& other) noexcept
    { this->setRawValue (other.getRawValue() * StorageType (10)); }

    template <typename StorageType>
    constexpr Millimetres<StorageType>::Millimetres (const Metres<StorageType>& other) noexcept
    { this->setRawValue (other.getRawValue() * StorageType (1000)); }
}

