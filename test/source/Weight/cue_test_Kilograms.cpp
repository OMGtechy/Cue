#include <cue_test_Weight.hpp>

namespace cue_test
{
    template <typename StorageType> class KilogramsTest : public ::testing::Test { };

    TYPED_TEST_CASE (KilogramsTest, TestTypes);

    // operator+

    TYPED_TEST (KilogramsTest, AddSameType)
    {
        ASSERT_EQ
        (
            (
                Kilograms<TypeParam> (TypeParam (1)) +
                Kilograms<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (KilogramsTest, AddGramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Kilograms<TypeParam> (TypeParam (1)) +
                Grams<TypeParam> (TypeParam (2000))
            ).getRawValue(),
            TypeParam (3)
        );
    }

    TYPED_TEST (KilogramsTest, AddMilligramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Kilograms<TypeParam> (TypeParam (1)) +
                Milligrams<TypeParam> (TypeParam (1000000))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    // operator-

    TYPED_TEST (KilogramsTest, SubtractSameType)
    {
        ASSERT_EQ
        (
            (
                Kilograms<TypeParam> (TypeParam (3)) -
                Kilograms<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    TYPED_TEST (KilogramsTest, SubtractGramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Kilograms<TypeParam> (TypeParam (3)) -
                Grams<TypeParam> (TypeParam (2000))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    TYPED_TEST (KilogramsTest, SubtractMilligramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Kilograms<TypeParam> (TypeParam (3)) -
                Milligrams<TypeParam> (TypeParam (2000000))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    // operator*

    TYPED_TEST (KilogramsTest, MultiplySameType)
    {
        ASSERT_EQ
        (
            (
                Kilograms<TypeParam> (TypeParam (3)) *
                Kilograms<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (6)
        );
    }

    TYPED_TEST (KilogramsTest, MultiplyGramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Kilograms<TypeParam> (TypeParam (3)) *
                Grams<TypeParam> (TypeParam (2000))
            ).getRawValue(),
            TypeParam (6)
        );
    }

    TYPED_TEST (KilogramsTest, MultiplyMilligramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Kilograms<TypeParam> (TypeParam (3)) *
                Milligrams<TypeParam> (TypeParam (2000000))
            ).getRawValue(),
            TypeParam (6)
        );
    }

    // operator/

    TYPED_TEST (KilogramsTest, DivideSameType)
    {
        ASSERT_EQ
        (
            (
                Kilograms<TypeParam> (TypeParam (4)) /
                Kilograms<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (KilogramsTest, DivideGramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Kilograms<TypeParam> (TypeParam (4)) /
                Grams<TypeParam> (TypeParam (2000))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (KilogramsTest, DivideMilligramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Kilograms<TypeParam> (TypeParam (4)) /
                Milligrams<TypeParam> (TypeParam (2000000))
            ).getRawValue(),
            TypeParam (2)
        );
    }
}

