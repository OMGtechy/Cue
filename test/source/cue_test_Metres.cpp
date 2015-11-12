#include <cue_test_Distance.hpp>

namespace cue_test
{
    template <typename StorageType> class MetresTest : public ::testing::Test { };

    TYPED_TEST_CASE (MetresTest, TestTypes);

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
}

