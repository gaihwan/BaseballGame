#include <iostream>
#include "gmock/gmock.h"
#include "baseball.cpp"

using namespace std;

class BaseballFixture : public testing::Test {
public:
    Baseball game{ "123" };
    void assertIllegalArgument(string guessNumber) {
        try {
            game.guess(guessNumber);
            FAIL();
        }
        catch (exception e) {
            // PASS
        }
    }
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCases0) {
    assertIllegalArgument("12");
    assertIllegalArgument("12s");
    assertIllegalArgument("12t");
    assertIllegalArgument("121");
}

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCases1) {
    assertIllegalArgument("12t");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
    Baseball game{ "123" };
    GuessResult result = game.guess("123");

    EXPECT_TRUE(result.solved);
    EXPECT_EQ(3, result.strikes);
    EXPECT_EQ(0, result.balls);

}


