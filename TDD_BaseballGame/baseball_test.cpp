#include <iostream>
#include "gmock/gmock.h"
#include "baseball.cpp"

using namespace std;

class BaseballFixture : public testing::Test {
public:
    Baseball game;
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

TEST_F(BaseballFixture, ThrowExceptionWhenInputLenghtIsUnmatched) {
    assertIllegalArgument("12");
}

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidChar) {
    assertIllegalArgument("12s");
}


