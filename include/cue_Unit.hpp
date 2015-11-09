#pragma once

namespace cue
{
    template <typename StorageType, template <typename> class DerivedType>
    class Unit
    {
    public:
        explicit Unit (StorageType initialValue) noexcept : m_rawValue (initialValue) { };
        explicit Unit (DerivedType<StorageType> other) noexcept : Unit (other.getRawValue()) { };
        ~Unit() noexcept = default;

        StorageType getRawValue() const noexcept { return this->m_rawValue; }

        DerivedType<StorageType> operator= (DerivedType<StorageType> other)
        { return { other }; }

        template <typename OtherType>
        auto operator+ (OtherType other) const noexcept
        { return DerivedType<StorageType> (getRawValue() + DerivedType<StorageType> (other).getRawValue()); }

        template <typename OtherType>
        auto operator- (OtherType other) const noexcept
        { return DerivedType<StorageType> (getRawValue() - DerivedType<StorageType> (other).getRawValue()); }

        template <typename OtherType>
        auto operator* (OtherType other) const noexcept
        { return DerivedType<StorageType> (getRawValue() * DerivedType<StorageType> (other).getRawValue()); }

        template <typename OtherType>
        auto operator/ (OtherType other) const noexcept
        { return DerivedType<StorageType> (getRawValue() / DerivedType<StorageType> (other).getRawValue()); }

    protected:
        Unit() = default;

        void setRawValue (StorageType newValue) noexcept { m_rawValue = newValue; }

    private:
        StorageType m_rawValue;
    };
}

