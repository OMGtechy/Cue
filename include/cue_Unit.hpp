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

