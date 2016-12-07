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
    template <typename StorageType> class HoursTest : public ::testing::Test { };

    TYPED_TEST_CASE (HoursTest, TestTypes);

    // operator+

    TYPED_TEST (HoursTest, AddSameType)
    {
        ASSERT_EQ
        (
            (
                Hours<TypeParam> (TypeParam (1)) +
                Hours<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (HoursTest, AddSecondsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Hours<TypeParam> (TypeParam (1)) +
                Seconds<TypeParam> (TypeParam (3600))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (HoursTest, AddMinutesSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Hours<TypeParam> (TypeParam (2)) +
                Minutes<TypeParam> (TypeParam (60))
            ).getRawValue(),
            TypeParam (3)
        );
    }

    // operator-

    TYPED_TEST (HoursTest, SubtractSameType)
    {
        ASSERT_EQ
        (
            (
                Hours<TypeParam> (TypeParam (3)) -
                Hours<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (HoursTest, SubtractSecondsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Hours<TypeParam> (TypeParam (3)) -
                Seconds<TypeParam> (TypeParam (7200))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    TYPED_TEST (HoursTest, SubtractMinutesSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Hours<TypeParam> (TypeParam (2)) -
                Minutes<TypeParam> (TypeParam (60))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    // operator*

    TYPED_TEST (HoursTest, MultiplySameType)
    {
        ASSERT_EQ
        (
            (
                Hours<TypeParam> (TypeParam (2)) *
                Hours<TypeParam> (TypeParam (4))
            ).getRawValue(),
            TypeParam (8)
        );
    }

    TYPED_TEST (HoursTest, MultiplySecondsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Hours<TypeParam> (TypeParam (1)) *
                Seconds<TypeParam> (TypeParam (3600))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    TYPED_TEST (HoursTest, MultiplyMinutesSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Hours<TypeParam> (TypeParam (1)) *
                Minutes<TypeParam> (TypeParam (60))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    // operator/

    TYPED_TEST (HoursTest, DivideSameType)
    {
        ASSERT_EQ
        (
            (
                Hours<TypeParam> (TypeParam (10)) /
                Hours<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (5)
        );
    }

    TYPED_TEST (HoursTest, DivideSecondsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Hours<TypeParam> (TypeParam (4)) /
                Seconds<TypeParam> (TypeParam (7200))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (HoursTest, DivideMinutesSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Hours<TypeParam> (TypeParam (2)) /
                Minutes<TypeParam> (TypeParam (60))
            ).getRawValue(),
            TypeParam (2)
        );
    }
}

