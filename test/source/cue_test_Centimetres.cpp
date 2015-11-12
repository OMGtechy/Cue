#include <cue_test_Distance.hpp>

namespace cue_test
{
    template <typename StorageType> class CentimetresTest : public ::testing::Test { };

    TYPED_TEST_CASE (CentimetresTest, TestTypes);

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
}

