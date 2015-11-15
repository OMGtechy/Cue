#include <gtest/gtest.h>

#include <cue_Distance.hpp>

namespace cue_test
{
    using namespace ::cue;
    using TestTypes = ::testing::Types
    <
        unsigned int,
        signed int,
        unsigned long,
        signed long,
        unsigned long long,
        signed long long,
        float,
        double
    >;
}
