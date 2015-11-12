#include <cue_test_Distance.hpp>

namespace cue_test
{
    template <typename StorageType> class MillimetresTest : public ::testing::Test { };

    TYPED_TEST_CASE (MillimetresTest, TestTypes);

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

