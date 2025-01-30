#include "../src/tictactoe.h"
#include <gtest/gtest.h>
#include <ranges>
#include <vector>

TEST(Game, MakeMove) {
  TicTacToe game;
  ASSERT_TRUE(game.makeMove(0));
  ASSERT_FALSE(game.makeMove(0));
}

TEST(Game, Player1Win) {
  TicTacToe game;
  for (int move : std::views::iota(0, 7)) game.makeMove(move);
  game.updateGameState();
  EXPECT_EQ(game.getGameState(), GameState::Player1Win);
}

TEST(Game, Payler2Win) {
  TicTacToe game;
  std::vector<int> moves = {0,4,6,3,1,5};
  for (int move : moves) game.makeMove(move);
  game.updateGameState();
  EXPECT_EQ(game.getGameState(), GameState::Player2Win);
}

TEST(Game, Draw) {
  TicTacToe game;
  std::vector<int> moves = {0,4,6,3,5,1,7,8,2};
  for (int move : moves) game.makeMove(move);
  game.updateGameState();
  EXPECT_EQ(game.getGameState(), GameState::Draw);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
