#include <cue_test_Time.hpp>

namespace cue_test
{
    template <typename StorageType> class SecondsTest : public ::testing::Test { };

    TYPED_TEST_CASE (SecondsTest, TestTypes);

    // operator+

    TYPED_TEST (SecondsTest, AddSameType)
    {
        ASSERT_EQ
        (
            (
                Seconds<TypeParam> (TypeParam (1)) +
                Seconds<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (SecondsTest, AddMinutesSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Seconds<TypeParam> (TypeParam (2)) +
                Minutes<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (62)
        );
    }

    TYPED_TEST (SecondsTest, AddHoursSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Seconds<TypeParam> (TypeParam (1)) +
                Hours<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (3601)
        );
    }

    // operator-

    TYPED_TEST (SecondsTest, SubtractSameType)
    {
        ASSERT_EQ
        (
            (
                Seconds<TypeParam> (TypeParam (3)) -
                Seconds<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (SecondsTest, SubtractMinutesSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Seconds<TypeParam> (TypeParam (65)) -
                Minutes<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (5)
        );
    }

    TYPED_TEST (SecondsTest, SubtractHoursSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Seconds<TypeParam> (TypeParam (3601)) -
                Hours<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    // operator*

    TYPED_TEST (SecondsTest, MultiplySameType)
    {
        ASSERT_EQ
        (
            (
                Seconds<TypeParam> (TypeParam (2)) *
                Seconds<TypeParam> (TypeParam (4))
            ).getRawValue(),
            TypeParam (8)
        );
    }

    TYPED_TEST (SecondsTest, MultiplyMinutesSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Seconds<TypeParam> (TypeParam (2)) *
                Minutes<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (120)
        );
    }

    TYPED_TEST (SecondsTest, MultiplyHoursSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Seconds<TypeParam> (TypeParam (1)) *
                Hours<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (3600)
        );
    }

    // operator/

    TYPED_TEST (SecondsTest, DivideSameType)
    {
        ASSERT_EQ
        (
            (
                Seconds<TypeParam> (TypeParam (10)) /
                Seconds<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (5)
        );
    }

    TYPED_TEST (SecondsTest, DivideMinutesSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Seconds<TypeParam> (TypeParam (120)) /
                Minutes<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    TYPED_TEST (SecondsTest, DivideHoursSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Seconds<TypeParam> (TypeParam (7200)) /
                Hours<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (2)
        );
    }
}

