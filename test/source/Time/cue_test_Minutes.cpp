#include <cue_test_Time.hpp>

namespace cue_test
{
    template <typename StorageType> class MinutesTest : public ::testing::Test { };

    TYPED_TEST_CASE (MinutesTest, TestTypes);

    // operator+

    TYPED_TEST (MinutesTest, AddSameType)
    {
        ASSERT_EQ
        (
            (
                Minutes<TypeParam> (TypeParam (1)) +
                Minutes<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (MinutesTest, AddSecondsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Minutes<TypeParam> (TypeParam (2)) +
                Seconds<TypeParam> (TypeParam (60))
            ).getRawValue(),
            TypeParam (3)
        );
    }

    TYPED_TEST (MinutesTest, AddHoursSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Minutes<TypeParam> (TypeParam (1)) +
                Hours<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (61)
        );
    }

    // operator-

    TYPED_TEST (MinutesTest, SubtractSameType)
    {
        ASSERT_EQ
        (
            (
                Minutes<TypeParam> (TypeParam (3)) -
                Minutes<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (MinutesTest, SubtractSecondsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Minutes<TypeParam> (TypeParam (2)) -
                Seconds<TypeParam> (TypeParam (60))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    TYPED_TEST (MinutesTest, SubtractHoursSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Minutes<TypeParam> (TypeParam (120)) -
                Hours<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (60)
        );
    }

    // operator*

    TYPED_TEST (MinutesTest, MultiplySameType)
    {
        ASSERT_EQ
        (
            (
                Minutes<TypeParam> (TypeParam (2)) *
                Minutes<TypeParam> (TypeParam (4))
            ).getRawValue(),
            TypeParam (8)
        );
    }

    TYPED_TEST (MinutesTest, MultiplySecondsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Minutes<TypeParam> (TypeParam (2)) *
                Seconds<TypeParam> (TypeParam (60))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (MinutesTest, MultiplyHoursSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Minutes<TypeParam> (TypeParam (2)) *
                Hours<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (120)
        );
    }

    // operator/

    TYPED_TEST (MinutesTest, DivideSameType)
    {
        ASSERT_EQ
        (
            (
                Minutes<TypeParam> (TypeParam (10)) /
                Minutes<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (5)
        );
    }

    TYPED_TEST (MinutesTest, DivideSecondsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Minutes<TypeParam> (TypeParam (2)) /
                Seconds<TypeParam> (TypeParam (120))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    TYPED_TEST (MinutesTest, DivideHoursSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Minutes<TypeParam> (TypeParam (120)) /
                Hours<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (1)
        );
    }
}

