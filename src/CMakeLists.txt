add_executable(TicTacToe
    main.cpp
    tictactoe.cpp
)

# To include headers
target_include_directories(TicTacToe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
