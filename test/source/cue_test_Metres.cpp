#include <gtest/gtest.h>

#include <cue_Distance.hpp>

namespace cue_test
{
    using ::cue::Metres;
    using Types = ::testing::Types
    <
        char,
        short,
        int,
        long,
        long long,
        float,
        double
    >;

    template <typename StorageType>
    class MetresTest : public ::testing::Test { };

    TYPED_TEST_CASE (MetresTest, Types);

    TYPED_TEST (MetresTest, FromMetresCompiles)
    {
        Metres<TypeParam>::fromMetres (TypeParam());
    }

    TYPED_TEST (MetresTest, AddSameType)
    {
        ASSERT_EQ
        (
            (
                Metres<TypeParam>::fromMetres (TypeParam (1)) +
                Metres<TypeParam>::fromMetres (TypeParam (1))
            ).getRawValue(),
            2
        );
    }
}
