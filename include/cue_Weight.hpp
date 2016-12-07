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
    template <typename StorageType> class Milligrams;
    template <typename StorageType> class Grams;
    template <typename StorageType> class Kilograms;

    template <typename StorageType>
    class Kilograms : public Unit<StorageType, Kilograms>
    {
    public:
        using Unit<StorageType, ::cue::Kilograms>::Unit;

        explicit constexpr Kilograms (const Milligrams<StorageType>&) noexcept;
        explicit constexpr Kilograms (const Grams<StorageType>&) noexcept;
    };

    template <typename StorageType>
    class Grams : public Unit<StorageType, Grams>
    {
    public:
        using Unit<StorageType, ::cue::Grams>::Unit;

        explicit constexpr Grams (const Milligrams<StorageType>&) noexcept;
        explicit constexpr Grams (const Kilograms<StorageType>&)      noexcept;
    };

    template <typename StorageType>
    class Milligrams : public Unit<StorageType, Milligrams>
    {
    public:
        using Unit<StorageType, ::cue::Milligrams>::Unit;

        explicit constexpr Milligrams (const Grams<StorageType>&) noexcept;
        explicit constexpr Milligrams (const Kilograms<StorageType>&)      noexcept;
    };

    template <typename StorageType>
    constexpr Kilograms<StorageType>::Kilograms (const Milligrams<StorageType>& other) noexcept
    { this->setRawValue (other.getRawValue() / StorageType (1000000)); }

    template <typename StorageType>
    constexpr Kilograms<StorageType>::Kilograms (const Grams<StorageType>& other) noexcept
    { this->setRawValue (other.getRawValue() / StorageType (1000)); }

    template <typename StorageType>
    constexpr Grams<StorageType>::Grams (const Milligrams<StorageType>& other) noexcept
    { this->setRawValue (other.getRawValue() / StorageType (1000)); }

    template <typename StorageType>
    constexpr Grams<StorageType>::Grams (const Kilograms<StorageType>& other) noexcept
    { this->setRawValue (other.getRawValue() * StorageType (1000)); }

    template <typename StorageType>
    constexpr Milligrams<StorageType>::Milligrams (const Grams<StorageType>& other) noexcept
    { this->setRawValue (other.getRawValue() * StorageType (1000)); }

    template <typename StorageType>
    constexpr Milligrams<StorageType>::Milligrams (const Kilograms<StorageType>& other) noexcept
    { this->setRawValue (other.getRawValue() * StorageType (1000000)); }
}

