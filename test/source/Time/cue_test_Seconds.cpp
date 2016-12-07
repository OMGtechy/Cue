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
    along with Cue.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <cue_test_Time.hpp>

namespace cue_test
{
    template <typename StorageType> class SecondsTest : public ::testing::Test { };

    TYPED_TEST_CASE (SecondsTest, TestTypes);

    // operator+

    TYPED_TEST (SecondsTest, AddSameType)
    {
        ASSERT_EQ
        (
            (
                Seconds<TypeParam> (TypeParam (1)) +
                Seconds<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (SecondsTest, AddMinutesSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Seconds<TypeParam> (TypeParam (2)) +
                Minutes<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (62)
        );
    }

    TYPED_TEST (SecondsTest, AddHoursSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Seconds<TypeParam> (TypeParam (1)) +
                Hours<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (3601)
        );
    }

    // operator-

    TYPED_TEST (SecondsTest, SubtractSameType)
    {
        ASSERT_EQ
        (
            (
                Seconds<TypeParam> (TypeParam (3)) -
                Seconds<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (SecondsTest, SubtractMinutesSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Seconds<TypeParam> (TypeParam (65)) -
                Minutes<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (5)
        );
    }

    TYPED_TEST (SecondsTest, SubtractHoursSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Seconds<TypeParam> (TypeParam (3601)) -
                Hours<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    // operator*

    TYPED_TEST (SecondsTest, MultiplySameType)
    {
        ASSERT_EQ
        (
            (
                Seconds<TypeParam> (TypeParam (2)) *
                Seconds<TypeParam> (TypeParam (4))
            ).getRawValue(),
            TypeParam (8)
        );
    }

    TYPED_TEST (SecondsTest, MultiplyMinutesSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Seconds<TypeParam> (TypeParam (2)) *
                Minutes<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (120)
        );
    }

    TYPED_TEST (SecondsTest, MultiplyHoursSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Seconds<TypeParam> (TypeParam (1)) *
                Hours<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (3600)
        );
    }

    // operator/

    TYPED_TEST (SecondsTest, DivideSameType)
    {
        ASSERT_EQ
        (
            (
                Seconds<TypeParam> (TypeParam (10)) /
                Seconds<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (5)
        );
    }

    TYPED_TEST (SecondsTest, DivideMinutesSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Seconds<TypeParam> (TypeParam (120)) /
                Minutes<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    TYPED_TEST (SecondsTest, DivideHoursSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Seconds<TypeParam> (TypeParam (7200)) /
                Hours<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (2)
        );
    }
}

