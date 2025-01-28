#include <gtest/gtest.h>
#include "../src/tictactoe.h"

TEST(Game, MakeMove) {
    TicTacToe game;
    ASSERT_TRUE(game.makeMove(0));
    ASSERT_FALSE(game.makeMove(0));
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); 
}