#include <cue_test_Distance.hpp>

namespace cue_test
{
    template <typename StorageType> class MetresTest : public ::testing::Test { };

    TYPED_TEST_CASE (MetresTest, TestTypes);

    // operator+

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

    // operator-

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

    TYPED_TEST (MetresTest, SubtractCentimetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Metres<TypeParam> (TypeParam (3)) -
                Centimetres<TypeParam> (TypeParam (200))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    TYPED_TEST (MetresTest, SubtractMillimetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Metres<TypeParam> (TypeParam (3)) -
                Millimetres<TypeParam> (TypeParam (2000))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    // operator*

    TYPED_TEST (MetresTest, MultiplySameType)
    {
        ASSERT_EQ
        (
            (
                Metres<TypeParam> (TypeParam (3)) *
                Metres<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (6)
        );
    }

    TYPED_TEST (MetresTest, MultiplyCentimetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Metres<TypeParam> (TypeParam (3)) *
                Centimetres<TypeParam> (TypeParam (200))
            ).getRawValue(),
            TypeParam (6)
        );
    }

    TYPED_TEST (MetresTest, MultiplyMillimetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Metres<TypeParam> (TypeParam (3)) *
                Millimetres<TypeParam> (TypeParam (2000))
            ).getRawValue(),
            TypeParam (6)
        );
    }

    // operator/

    TYPED_TEST (MetresTest, DivideSameType)
    {
        ASSERT_EQ
        (
            (
                Metres<TypeParam> (TypeParam (4)) /
                Metres<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (MetresTest, DivideCentimetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Metres<TypeParam> (TypeParam (4)) /
                Centimetres<TypeParam> (TypeParam (200))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (MetresTest, DivideMillimetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Metres<TypeParam> (TypeParam (4)) /
                Millimetres<TypeParam> (TypeParam (2000))
            ).getRawValue(),
            TypeParam (2)
        );
    }
}

