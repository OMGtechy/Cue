#include <cue_test_Weight.hpp>

namespace cue_test
{
    template <typename StorageType> class GramsTest : public ::testing::Test { };

    TYPED_TEST_CASE (GramsTest, TestTypes);

    // operator+

    TYPED_TEST (GramsTest, AddSameType)
    {
        ASSERT_EQ
        (
            (
                Grams<TypeParam> (TypeParam (1)) +
                Grams<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (GramsTest, AddKilogramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Grams<TypeParam> (TypeParam (1)) +
                Kilograms<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (1001)
        );
    }

    TYPED_TEST (GramsTest, AddMilligramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Grams<TypeParam> (TypeParam (1)) +
                Milligrams<TypeParam> (TypeParam (1000))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    // operator-

    TYPED_TEST (GramsTest, SubtractSameType)
    {
        ASSERT_EQ
        (
            (
                Grams<TypeParam> (TypeParam (2)) -
                Grams<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    TYPED_TEST (GramsTest, SubtractMilligramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Grams<TypeParam> (TypeParam (2)) -
                Milligrams<TypeParam> (TypeParam (1000))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    TYPED_TEST (GramsTest, SubtractKilogramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Grams<TypeParam> (TypeParam (2000)) -
                Kilograms<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (1000)
        );
    }

    // operator*

    TYPED_TEST (GramsTest, MultiplySameType)
    {
        ASSERT_EQ
        (
            (
                Grams<TypeParam> (TypeParam (2)) *
                Grams<TypeParam> (TypeParam (3))
            ).getRawValue(),
            TypeParam (6)
        );
    }

    TYPED_TEST (GramsTest, MultiplyMilligramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Grams<TypeParam> (TypeParam (2)) *
                Milligrams<TypeParam> (TypeParam (2000))
            ).getRawValue(),
            TypeParam (4)
        );
    }

    TYPED_TEST (GramsTest, MultiplyKilogramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Grams<TypeParam> (TypeParam (2)) *
                Kilograms<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (2000)
        );
    }

    // operator/

    TYPED_TEST (GramsTest, DivideSameType)
    {
        ASSERT_EQ
        (
            (
                Grams<TypeParam> (TypeParam (6)) /
                Grams<TypeParam> (TypeParam (3))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (GramsTest, DivideMilligramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Grams<TypeParam> (TypeParam (2)) /
                Milligrams<TypeParam> (TypeParam (1000))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (GramsTest, DivideKilogramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Grams<TypeParam> (TypeParam (4000)) /
                Kilograms<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (2)
        );
    }
}

