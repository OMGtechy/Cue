#pragma once

namespace cue
{
    template <typename StorageType>
    class Unit
    {
    public:
        StorageType getRawValue() const noexcept { return m_rawValue; }

    protected:
        Unit (StorageType initialValue) noexcept : m_rawValue (initialValue) { };
        ~Unit() noexcept = default;

        void setRawValue (StorageType newValue) noexcept { m_rawValue = newValue; }

    private:
        StorageType m_rawValue;
    };
}
