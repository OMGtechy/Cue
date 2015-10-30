#include <gtest/gtest.h>

#include <cue_Distance.hpp>

namespace cue_test
{
    using namespace ::cue;
    using Types = ::testing::Types
    <
        unsigned int,
        signed int,
        unsigned long,
        signed long,
        unsigned long long,
        signed long long,
        float,
        double
    >;

    template <typename StorageType> class MetresTest      : public ::testing::Test { };
    template <typename StorageType> class CentimetresTest : public ::testing::Test { };

    TYPED_TEST_CASE (MetresTest,      Types);
    TYPED_TEST_CASE (CentimetresTest, Types);

    TYPED_TEST (MetresTest, FromMetresCompiles)
    {
        Metres<TypeParam>::fromMetres (TypeParam());
    }

    TYPED_TEST (MetresTest, AddSameType)
    {
        ASSERT_EQ
        (
            (
                Metres<TypeParam>::fromMetres (1) +
                Metres<TypeParam>::fromMetres (1)
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (MetresTest, AddCentimetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Metres<TypeParam>::fromMetres (1) +
                Centimetres<TypeParam>::fromCentimetres (200)
            ).getRawValue(),
            TypeParam (3)
        );
    }

    TYPED_TEST (MetresTest, AddMillimetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Metres<TypeParam>::fromMetres (1) +
                Millimetres<TypeParam>::fromMillimetres (1000)
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (CentimetresTest, AddSameType)
    {
        ASSERT_EQ
        (
            (
                Centimetres<TypeParam>::fromCentimetres (1) +
                Centimetres<TypeParam>::fromCentimetres (1)
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (CentimetresTest, AddMetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Centimetres<TypeParam>::fromCentimetres (1) +
                Metres<TypeParam>::fromMetres (1)
            ).getRawValue(),
            TypeParam (101)
        );
    }
}
