#pragma once

#include <cstdint>

enum class GameState {
  Ongoing,
  Draw,
  Player1Win,
  Player2Win,
};

class TicTacToe {
private:
  std::uint16_t gameBoard;
  std::uint16_t player1Board;
  std::uint16_t player2Board;
  bool player1Turn;
  GameState gameState;

public:
  TicTacToe() :
    gameBoard(0),
    player1Board(0),
    player2Board(0),
    player1Turn(true),
    gameState(GameState::Ongoing) {}

  void loop();

private:
  bool makeMove(int cell);
  void updateGameState();
  void printBoard() const;
};
