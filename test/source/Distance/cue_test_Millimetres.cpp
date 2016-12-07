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

#include <cue_test_Distance.hpp>

namespace cue_test
{
    template <typename StorageType> class MillimetresTest : public ::testing::Test { };

    TYPED_TEST_CASE (MillimetresTest, TestTypes);

    // operator+

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

    // operator-

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
                Millimetres<TypeParam> (TypeParam (6000)) -
                Metres<TypeParam> (TypeParam (5))
            ).getRawValue(),
            TypeParam (1000)
        );
    }

    // operator*

    TYPED_TEST (MillimetresTest, MultiplySameType)
    {
        ASSERT_EQ
        (
            (
                Millimetres<TypeParam> (TypeParam (2)) *
                Millimetres<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (4)
        );
    }

    TYPED_TEST (MillimetresTest, MultiplyCentimetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Millimetres<TypeParam> (TypeParam (1)) *
                Centimetres<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (20)
        );
    }

    TYPED_TEST (MillimetresTest, MultiplyMetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Millimetres<TypeParam> (TypeParam (1)) *
                Metres<TypeParam> (TypeParam (5))
            ).getRawValue(),
            TypeParam (5000)
        );
    }

    // operator/

    TYPED_TEST (MillimetresTest, DivideSameType)
    {
        ASSERT_EQ
        (
            (
                Millimetres<TypeParam> (TypeParam (4)) /
                Millimetres<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (MillimetresTest, DivideCentimetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Millimetres<TypeParam> (TypeParam (1000)) /
                Centimetres<TypeParam> (TypeParam (50))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (MillimetresTest, DivideMetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Millimetres<TypeParam> (TypeParam (10000)) /
                Metres<TypeParam> (TypeParam (5))
            ).getRawValue(),
            TypeParam (2)
        );
    }
}

