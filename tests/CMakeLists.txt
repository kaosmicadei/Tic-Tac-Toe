# Add Google Test
find_package(GTest REQUIRED)

# Add tess and link it to Google Test and the lib to be tested.
add_executable(tests test_tictactoe.cpp)
target_link_libraries(tests PRIVATE tictactoe GTest::gtest_main GTest::gtest)

# Set TESTING macro to compile the tests
target_compile_definitions(tests PRIVATE TESTING)
set(TESTING ON CACHE INTERNAL "")

# Add test to CTest.
add_test(NAME TicTacToe COMMAND tests)
