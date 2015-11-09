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

    TYPED_TEST (MetresTest, AddSameType)
    {
        ASSERT_EQ
        (
            (
                Metres<TypeParam> (TypeParam (1)) +
                Metres<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (MetresTest, AddCentimetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Metres<TypeParam> (TypeParam (1)) +
                Centimetres<TypeParam> (TypeParam (200))
            ).getRawValue(),
            TypeParam (3)
        );
    }

    TYPED_TEST (MetresTest, AddMillimetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Metres<TypeParam> (TypeParam (1)) +
                Millimetres<TypeParam> (TypeParam (1000))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (MetresTest, SubtractSameType)
    {
        ASSERT_EQ
        (
            (
                Metres<TypeParam> (TypeParam (3)) -
                Metres<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    TYPED_TEST (CentimetresTest, AddSameType)
    {
        ASSERT_EQ
        (
            (
                Centimetres<TypeParam> (TypeParam (1)) +
                Centimetres<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (CentimetresTest, AddMetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Centimetres<TypeParam> (TypeParam (1)) +
                Metres<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (101)
        );
    }

    TYPED_TEST (CentimetresTest, AddMillimetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Centimetres<TypeParam> (TypeParam (1)) +
                Millimetres<TypeParam> (TypeParam (10))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (CentimetresTest, SubtractSameType)
    {
        ASSERT_EQ
        (
            (
                Centimetres<TypeParam> (TypeParam (2)) -
                Centimetres<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    TYPED_TEST (CentimetresTest, SubtractMillimetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Centimetres<TypeParam> (TypeParam (2)) -
                Millimetres<TypeParam> (TypeParam (10))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    TYPED_TEST (CentimetresTest, SubtractMetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Centimetres<TypeParam> (TypeParam (200)) -
                Metres<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (100)
        );
    }

    TYPED_TEST (MillimetresTest, AddSameType)
    {
        ASSERT_EQ
        (
            (
                Millimetres<TypeParam> (TypeParam (1)) +
                Millimetres<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (MillimetresTest, AddCentimetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Millimetres<TypeParam> (TypeParam (10)) +
                Centimetres<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (20)
        );
    }

    TYPED_TEST (MillimetresTest, AddMetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Millimetres<TypeParam> (TypeParam (10)) +
                Metres<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (1010)
        );
    }

    TYPED_TEST (MillimetresTest, SubtractSameType)
    {
        ASSERT_EQ
        (
            (
                Millimetres<TypeParam> (TypeParam (2)) -
                Millimetres<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    TYPED_TEST (MillimetresTest, SubtractCentimetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Millimetres<TypeParam> (TypeParam (1000)) -
                Centimetres<TypeParam> (TypeParam (99))
            ).getRawValue(),
            TypeParam (10)
        );
    }

    TYPED_TEST (MillimetresTest, SubtractMetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Millimetres<TypeParam> (TypeParam (100)) -
                Centimetres<TypeParam> (TypeParam (5))
            ).getRawValue(),
            TypeParam (50)
        );
    }
}
