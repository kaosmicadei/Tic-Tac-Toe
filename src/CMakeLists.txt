add_executable(TicTacToe
    main.cpp
    tictactoe.cpp
)

# To include header
target_include_directories(TicTacToe PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# set_target_properties(TicTacToe PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)