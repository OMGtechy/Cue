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

#include <cue_test_Weight.hpp>

namespace cue_test
{
    template <typename StorageType> class KilogramsTest : public ::testing::Test { };

    TYPED_TEST_CASE (KilogramsTest, TestTypes);

    // operator+

    TYPED_TEST (KilogramsTest, AddSameType)
    {
        ASSERT_EQ
        (
            (
                Kilograms<TypeParam> (TypeParam (1)) +
                Kilograms<TypeParam> (TypeParam (1))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (KilogramsTest, AddGramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Kilograms<TypeParam> (TypeParam (1)) +
                Grams<TypeParam> (TypeParam (2000))
            ).getRawValue(),
            TypeParam (3)
        );
    }

    TYPED_TEST (KilogramsTest, AddMilligramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Kilograms<TypeParam> (TypeParam (1)) +
                Milligrams<TypeParam> (TypeParam (1000000))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    // operator-

    TYPED_TEST (KilogramsTest, SubtractSameType)
    {
        ASSERT_EQ
        (
            (
                Kilograms<TypeParam> (TypeParam (3)) -
                Kilograms<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    TYPED_TEST (KilogramsTest, SubtractGramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Kilograms<TypeParam> (TypeParam (3)) -
                Grams<TypeParam> (TypeParam (2000))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    TYPED_TEST (KilogramsTest, SubtractMilligramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Kilograms<TypeParam> (TypeParam (3)) -
                Milligrams<TypeParam> (TypeParam (2000000))
            ).getRawValue(),
            TypeParam (1)
        );
    }

    // operator*

    TYPED_TEST (KilogramsTest, MultiplySameType)
    {
        ASSERT_EQ
        (
            (
                Kilograms<TypeParam> (TypeParam (3)) *
                Kilograms<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (6)
        );
    }

    TYPED_TEST (KilogramsTest, MultiplyGramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Kilograms<TypeParam> (TypeParam (3)) *
                Grams<TypeParam> (TypeParam (2000))
            ).getRawValue(),
            TypeParam (6)
        );
    }

    TYPED_TEST (KilogramsTest, MultiplyMilligramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Kilograms<TypeParam> (TypeParam (3)) *
                Milligrams<TypeParam> (TypeParam (2000000))
            ).getRawValue(),
            TypeParam (6)
        );
    }

    // operator/

    TYPED_TEST (KilogramsTest, DivideSameType)
    {
        ASSERT_EQ
        (
            (
                Kilograms<TypeParam> (TypeParam (4)) /
                Kilograms<TypeParam> (TypeParam (2))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (KilogramsTest, DivideGramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Kilograms<TypeParam> (TypeParam (4)) /
                Grams<TypeParam> (TypeParam (2000))
            ).getRawValue(),
            TypeParam (2)
        );
    }

    TYPED_TEST (KilogramsTest, DivideMilligramsSameStorageType)
    {
        ASSERT_EQ
        (
            (
                Kilograms<TypeParam> (TypeParam (4)) /
                Milligrams<TypeParam> (TypeParam (2000000))
            ).getRawValue(),
            TypeParam (2)
        );
    }
}

