#include <cue_test_Weight.hpp>

namespace cue_test
{
    template <typename StorageType> class MilligramsTest : public ::testing::Test { };

    TYPED_TEST_CASE (MilligramsTest, TestTypes);

    // operator+

    TYPED_TEST (MilligramsTest, AddSameType)
    {
        ASSERT_EQ
        (
            (
                Milligrams<TypeParam> (TypeParam (1)) +
                Milligrams<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (MilligramsTest, AddGramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Milligrams<TypeParam> (TypeParam (1)) +
                Grams<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (1001)
        );
    }

    TYPED_TEST (MilligramsTest, AddKilogramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Milligrams<TypeParam> (TypeParam (10)) +
                Kilograms<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (1000010)
        );
    }

    // operator-

    TYPED_TEST (MilligramsTest, SubtractSameType)
    {
        ASSERT_EQ
        (
            (
                Milligrams<TypeParam> (TypeParam (2)) -
                Milligrams<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    TYPED_TEST (MilligramsTest, SubtractGramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Milligrams<TypeParam> (TypeParam (2000)) -
                Grams<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (1000)
        );
    }

    TYPED_TEST (MilligramsTest, SubtractKilogramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Milligrams<TypeParam> (TypeParam (6000000)) -
                Kilograms<TypeParam> (TypeParam (5))
            ).getRawValue(),
            TypeParam (1000000)
        );
    }

    // operator*

    TYPED_TEST (MilligramsTest, MultiplySameType)
    {
        ASSERT_EQ
        (
            (
                Milligrams<TypeParam> (TypeParam (2)) *
                Milligrams<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (4)
        );
    }

    TYPED_TEST (MilligramsTest, MultiplyGramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Milligrams<TypeParam> (TypeParam (1)) *
                Grams<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (2000)
        );
    }

    TYPED_TEST (MilligramsTest, MultiplyKilogramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Milligrams<TypeParam> (TypeParam (1)) *
                Kilograms<TypeParam> (TypeParam (5))
            ).getRawValue(),
            TypeParam (5000000)
        );
    }

    // operator/

    TYPED_TEST (MilligramsTest, DivideSameType)
    {
        ASSERT_EQ
        (
            (
                Milligrams<TypeParam> (TypeParam (4)) /
                Milligrams<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (MilligramsTest, DivideGramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Milligrams<TypeParam> (TypeParam (10000)) /
                Grams<TypeParam> (TypeParam (5))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (MilligramsTest, DivideKilogramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Milligrams<TypeParam> (TypeParam (1000000)) /
                Kilograms<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (1)
        );
    }
}

