/*
    This file is part of Cue.

    Cue is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Cue is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Foobar.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <cue_test_Time.hpp>

namespace cue_test
{
    template <typename StorageType> class MinutesTest : public ::testing::Test { };

    TYPED_TEST_CASE (MinutesTest, TestTypes);

    // operator+

    TYPED_TEST (MinutesTest, AddSameType)
    {
        ASSERT_EQ
        (
            (
                Minutes<TypeParam> (TypeParam (1)) +
                Minutes<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (MinutesTest, AddSecondsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Minutes<TypeParam> (TypeParam (2)) +
                Seconds<TypeParam> (TypeParam (60))
            ).getRawValue(),
            TypeParam (3)
        );
    }

    TYPED_TEST (MinutesTest, AddHoursSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Minutes<TypeParam> (TypeParam (1)) +
                Hours<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (61)
        );
    }

    // operator-

    TYPED_TEST (MinutesTest, SubtractSameType)
    {
        ASSERT_EQ
        (
            (
                Minutes<TypeParam> (TypeParam (3)) -
                Minutes<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (MinutesTest, SubtractSecondsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Minutes<TypeParam> (TypeParam (2)) -
                Seconds<TypeParam> (TypeParam (60))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    TYPED_TEST (MinutesTest, SubtractHoursSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Minutes<TypeParam> (TypeParam (120)) -
                Hours<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (60)
        );
    }

    // operator*

    TYPED_TEST (MinutesTest, MultiplySameType)
    {
        ASSERT_EQ
        (
            (
                Minutes<TypeParam> (TypeParam (2)) *
                Minutes<TypeParam> (TypeParam (4))
            ).getRawValue(),
            TypeParam (8)
        );
    }

    TYPED_TEST (MinutesTest, MultiplySecondsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Minutes<TypeParam> (TypeParam (2)) *
                Seconds<TypeParam> (TypeParam (60))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (MinutesTest, MultiplyHoursSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Minutes<TypeParam> (TypeParam (2)) *
                Hours<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (120)
        );
    }

    // operator/

    TYPED_TEST (MinutesTest, DivideSameType)
    {
        ASSERT_EQ
        (
            (
                Minutes<TypeParam> (TypeParam (10)) /
                Minutes<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (5)
        );
    }

    TYPED_TEST (MinutesTest, DivideSecondsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Minutes<TypeParam> (TypeParam (2)) /
                Seconds<TypeParam> (TypeParam (120))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    TYPED_TEST (MinutesTest, DivideHoursSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Minutes<TypeParam> (TypeParam (120)) /
                Hours<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (1)
        );
    }
}

