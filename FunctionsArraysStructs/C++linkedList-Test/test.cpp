#include "pch.h"
#include "catch2.hpp"


TEST(TestEmptyListAddOneSizeOne, TestAddOne)
{
	GIVEN("An empty linked list")
	{
		auto lL = new LinkedList<int>();

		_When_("I add an item")
		{
			iL->Add(0);

			REQUIRE(lL->size == 0);

			Then("Size is 1")
			{
				REQUIRE(iL -> size == 1);
			}
		}
	}
	
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

// Setup
// TestGetValueFromCorrectIndex()
// TestSetIteminCorrectIndex()
// TestCountIsZeroAfterClear()
// TestRemoveIndexAt()
// TestContainsValueAtCorrectIndex()
// TestIndexOf()
// TestRemove()
