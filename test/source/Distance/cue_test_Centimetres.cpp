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
    template <typename StorageType> class CentimetresTest : public ::testing::Test { };

    TYPED_TEST_CASE (CentimetresTest, TestTypes);

    // operator+

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

    // operator-

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

    // operator*

    TYPED_TEST (CentimetresTest, MultiplySameType)
    {
        ASSERT_EQ
        (
            (
                Centimetres<TypeParam> (TypeParam (2)) *
                Centimetres<TypeParam> (TypeParam (3))
            ).getRawValue(),
            TypeParam (6)
        );
    }

    TYPED_TEST (CentimetresTest, MultiplyMillimetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Centimetres<TypeParam> (TypeParam (2)) *
                Millimetres<TypeParam> (TypeParam (20))
            ).getRawValue(),
            TypeParam (4)
        );
    }

    TYPED_TEST (CentimetresTest, MultiplyMetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Centimetres<TypeParam> (TypeParam (2)) *
                Metres<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (200)
        );
    }

    // operator/

    TYPED_TEST (CentimetresTest, DivideSameType)
    {
        ASSERT_EQ
        (
            (
                Centimetres<TypeParam> (TypeParam (6)) /
                Centimetres<TypeParam> (TypeParam (3))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (CentimetresTest, DivideMillimetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Centimetres<TypeParam> (TypeParam (2)) /
                Millimetres<TypeParam> (TypeParam (10))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (CentimetresTest, DivideMetresSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Centimetres<TypeParam> (TypeParam (400)) /
                Metres<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (2)
        );
    }
}

