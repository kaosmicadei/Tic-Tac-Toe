#include <iostream>
#include "tictactoe.h"

void TicTacToe::printBoard() const {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif

  std::cout << "+---+---+---+" << std::endl;

  int cellmask = 1;
  for (int cell = 0; cell < 9; cell++) {
    if (cellmask & player1Board) {
      std::cout << "| X ";
    } else if (cellmask & player2Board) {
      std::cout << "| O ";
    } else {
      std::cout << std::format("| {} ", cell);
    }

    if (cell % 3 == 2) {
      std::cout << "|\n+---+---+---+" << std::endl;
    }

    cellmask <<= 1;
  }
}

bool TicTacToe::makeMove(int cell) {
  std::uint16_t move = 1 << cell;
  std::uint16_t& playerBoard = player1Turn ? player1Board : player2Board;

  if ((gameBoard & move) != 0) return false;

  gameBoard |= move;
  playerBoard |= move;
  player1Turn ^= true;

  return true;
}

void TicTacToe::updateGameState() {
  static std::uint16_t winmasks[] = {
    0b000000111, 0b000111000, 0b111000000,
    0b001001001, 0b010010010, 0b100100100,
    0b001010100, 0b100010001
  };

  for (std::uint16_t mask : winmasks) {
    if ((player1Board & mask) == mask) {
      gameState = GameState::Player1Win;
      return;
    }

    if ((player2Board & mask) == mask) {
      gameState = GameState::Player2Win;
      return;
    }
  }

  if (gameBoard == 0b111111111) gameState = GameState::Draw;
}

void TicTacToe::loop() {
  printBoard();

  while (gameState == GameState::Ongoing) {
    std::cout << (player1Turn ? "Player 1's turn (x) " : "Player 2's turn (o) ");

    int cell;
    while (true) {
      std::cin >> cell;

      if (std::cin.fail() || cell < 0 || cell > 8) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number between 0 and 8. ";
        continue;
      }

      if (!makeMove(cell)) {
        std::cout << "Cell already occupied ";
      } else {
        break;
      }
    }

    updateGameState();
    printBoard();
  }
}
