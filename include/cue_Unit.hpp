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
    along with Cue.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

namespace cue
{
    template <typename StorageType, template <typename> class DerivedType>
    class Unit
    {
    public:
        explicit constexpr Unit (StorageType initialValue) noexcept : m_rawValue (initialValue) { };
        explicit constexpr Unit (const DerivedType<StorageType>& other) noexcept : Unit (other.getRawValue()) { };
        ~Unit() noexcept = default;

        constexpr StorageType getRawValue() const noexcept { return this->m_rawValue; }

        constexpr DerivedType<StorageType> operator= (const DerivedType<StorageType>& other)
        { return { other }; }

        template <typename OtherType>
        constexpr auto operator+ (OtherType other) const noexcept
        { return DerivedType<StorageType> (getRawValue() + DerivedType<StorageType> (other).getRawValue()); }

        template <typename OtherType>
        constexpr auto operator- (OtherType other) const noexcept
        { return DerivedType<StorageType> (getRawValue() - DerivedType<StorageType> (other).getRawValue()); }

        template <typename OtherType>
        constexpr auto operator* (OtherType other) const noexcept
        { return DerivedType<StorageType> (getRawValue() * DerivedType<StorageType> (other).getRawValue()); }

        template <typename OtherType>
        constexpr auto operator/ (OtherType other) const noexcept
        { return DerivedType<StorageType> (getRawValue() / DerivedType<StorageType> (other).getRawValue()); }

    protected:
        constexpr Unit() = default;

        constexpr void setRawValue (StorageType newValue) noexcept { m_rawValue = newValue; }

    private:
        StorageType m_rawValue;
    };
}

