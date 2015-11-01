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
    template <typename StorageType> class MillimetresTest : public ::testing::Test { };

    TYPED_TEST_CASE (MetresTest,      Types);
    TYPED_TEST_CASE (CentimetresTest, Types);
    TYPED_TEST_CASE (MillimetresTest, Types);

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

    TYPED_TEST (MetresTest, SubtractSameType)
    {
        ASSERT_EQ
        (
            (
                Metres<TypeParam>::fromMetres (3) -
                Metres<TypeParam>::fromMetres (2)
            ).getRawValue(),
            TypeParam (1)
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

    TYPED_TEST (CentimetresTest, AddMillimetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Centimetres<TypeParam>::fromCentimetres (1) +
                Millimetres<TypeParam>::fromMillimetres (10)
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (CentimetresTest, SubtractSameType)
    {
        ASSERT_EQ
        (
            (
                Centimetres<TypeParam>::fromCentimetres (2) -
                Centimetres<TypeParam>::fromCentimetres (1)
            ).getRawValue(),
            TypeParam (1)
        );
    }

    TYPED_TEST (CentimetresTest, SubtractMillimetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Centimetres<TypeParam>::fromCentimetres (2) -
                Millimetres<TypeParam>::fromMillimetres (10)
            ).getRawValue(),
            TypeParam (1)
        );
    }

    TYPED_TEST (CentimetresTest, SubtractMetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Centimetres<TypeParam>::fromCentimetres (200) -
                Metres<TypeParam>::fromMetres (1)
            ).getRawValue(),
            TypeParam (100)
        );
    }

    TYPED_TEST (MillimetresTest, AddSameType)
    {
        ASSERT_EQ
        (
            (
                Millimetres<TypeParam>::fromMillimetres (1) +
                Millimetres<TypeParam>::fromMillimetres (1)
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (MillimetresTest, AddCentimetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Millimetres<TypeParam>::fromMillimetres (10) +
                Centimetres<TypeParam>::fromCentimetres (1)
            ).getRawValue(),
            TypeParam (20)
        );
    }

    TYPED_TEST (MillimetresTest, AddMetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Millimetres<TypeParam>::fromMillimetres (10) +
                Metres<TypeParam>::fromMetres (1)
            ).getRawValue(),
            TypeParam (1010)
        );
    }

    TYPED_TEST (MillimetresTest, SubtractSameType)
    {
        ASSERT_EQ
        (
            (
                Millimetres<TypeParam>::fromMillimetres (2) -
                Millimetres<TypeParam>::fromMillimetres (1)
            ).getRawValue(),
            TypeParam (1)
        );
    }

    TYPED_TEST (MillimetresTest, SubtractCentimetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Millimetres<TypeParam>::fromMillimetres (1000) -
                Centimetres<TypeParam>::fromCentimetres (99)
            ).getRawValue(),
            TypeParam (10)
        );
    }

    TYPED_TEST (MillimetresTest, SubtractMetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Millimetres<TypeParam>::fromMillimetres (100) -
                Centimetres<TypeParam>::fromCentimetres (5)
            ).getRawValue(),
            TypeParam (50)
        );
    }
}
