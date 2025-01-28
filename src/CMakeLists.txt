# Create a libary to be tested.
add_library(tictactoe tictactoe.cpp)

# If the TESTING macro is defined setup the private methods a public to allow tests.
if(TESTING)
    target_compile_definitions(tictactoe PRIVATE TESTING)
endif()

# Create the excecutable.
add_executable(main main.cpp)

# Link the executable to the core library.
target_link_libraries(main PRIVATE tictactoe)
