#include <cue_test_Distance.hpp>

namespace cue_test
{
    template <typename StorageType> class MillimetresTest : public ::testing::Test { };

    TYPED_TEST_CASE (MillimetresTest, TestTypes);

    // operator+

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

    // operator-

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

    // operator*

    TYPED_TEST (MillimetresTest, MultiplySameType)
    {
        ASSERT_EQ
        (
            (
                Millimetres<TypeParam> (TypeParam (2)) *
                Millimetres<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (4)
        );
    }

    TYPED_TEST (MillimetresTest, MultiplyCentimetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Millimetres<TypeParam> (TypeParam (1)) *
                Centimetres<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (20)
        );
    }

    TYPED_TEST (MillimetresTest, MultiplyMetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Millimetres<TypeParam> (TypeParam (1)) *
                Metres<TypeParam> (TypeParam (5))
            ).getRawValue(),
            TypeParam (5000)
        );
    }

    // operator/

    TYPED_TEST (MillimetresTest, DivideSameType)
    {
        ASSERT_EQ
        (
            (
                Millimetres<TypeParam> (TypeParam (4)) /
                Millimetres<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (MillimetresTest, DivideCentimetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Millimetres<TypeParam> (TypeParam (1000)) /
                Centimetres<TypeParam> (TypeParam (50))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (MillimetresTest, DivideMetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Millimetres<TypeParam> (TypeParam (10000)) /
                Metres<TypeParam> (TypeParam (5))
            ).getRawValue(),
            TypeParam (2)
        );
    }
}

