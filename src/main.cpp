#include "tictactoe.h"
#include <iostream>

void announceResult(GameState);

int main(void) {
  TicTacToe game;
  game.loop();
  announceResult(game.getGameState());
}

void announceResult(GameState state) {
  switch (state) {
    case GameState::Draw:
      std::cout << "It's a draw!" << std::endl;
      break;
    case GameState::Player1Win:
      std::cout << "Player 1 wins!" << std::endl;
      break;
    case GameState::Player2Win:
      std::cout << "Player 2 wins!" << std::endl;
      break;
    default:
      std::cout << "Sorry, something went wrong...";
      break;
    }
}