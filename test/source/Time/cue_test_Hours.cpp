#include <cue_test_Time.hpp>

namespace cue_test
{
    template <typename StorageType> class HoursTest : public ::testing::Test { };

    TYPED_TEST_CASE (HoursTest, TestTypes);

    // operator+

    TYPED_TEST (HoursTest, AddSameType)
    {
        ASSERT_EQ
        (
            (
                Hours<TypeParam> (TypeParam (1)) +
                Hours<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (HoursTest, AddSecondsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Hours<TypeParam> (TypeParam (1)) +
                Seconds<TypeParam> (TypeParam (3600))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (HoursTest, AddMinutesSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Hours<TypeParam> (TypeParam (2)) +
                Minutes<TypeParam> (TypeParam (60))
            ).getRawValue(),
            TypeParam (3)
        );
    }

    // operator-

    TYPED_TEST (HoursTest, SubtractSameType)
    {
        ASSERT_EQ
        (
            (
                Hours<TypeParam> (TypeParam (3)) -
                Hours<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (HoursTest, SubtractSecondsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Hours<TypeParam> (TypeParam (3)) -
                Seconds<TypeParam> (TypeParam (7200))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    TYPED_TEST (HoursTest, SubtractMinutesSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Hours<TypeParam> (TypeParam (2)) -
                Minutes<TypeParam> (TypeParam (60))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    // operator*

    TYPED_TEST (HoursTest, MultiplySameType)
    {
        ASSERT_EQ
        (
            (
                Hours<TypeParam> (TypeParam (2)) *
                Hours<TypeParam> (TypeParam (4))
            ).getRawValue(),
            TypeParam (8)
        );
    }

    TYPED_TEST (HoursTest, MultiplySecondsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Hours<TypeParam> (TypeParam (1)) *
                Seconds<TypeParam> (TypeParam (3600))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    TYPED_TEST (HoursTest, MultiplyMinutesSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Hours<TypeParam> (TypeParam (1)) *
                Minutes<TypeParam> (TypeParam (60))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    // operator/

    TYPED_TEST (HoursTest, DivideSameType)
    {
        ASSERT_EQ
        (
            (
                Hours<TypeParam> (TypeParam (10)) /
                Hours<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (5)
        );
    }

    TYPED_TEST (HoursTest, DivideSecondsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Hours<TypeParam> (TypeParam (4)) /
                Seconds<TypeParam> (TypeParam (7200))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (HoursTest, DivideMinutesSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Hours<TypeParam> (TypeParam (2)) /
                Minutes<TypeParam> (TypeParam (60))
            ).getRawValue(),
            TypeParam (2)
        );
    }
}

