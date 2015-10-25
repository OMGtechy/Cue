#pragma once

namespace cue
{
    template <typename StorageType>
    class Unit
    {
    protected:
        Unit (StorageType initialValue) noexcept : m_rawValue (initialValue) { };
        ~Unit () noexcept = default;

        StorageType getRawValue () const noexcept { return m_rawValue; }
        void setRawValue (StorageType newValue) noexcept { m_rawValue = newValue; }

    private:
        StorageType m_rawValue;
    };
}
