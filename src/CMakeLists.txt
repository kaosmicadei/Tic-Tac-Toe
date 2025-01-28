# Create a libary to be tested.
add_library(tictactoe tictactoe.cpp)

# Optional since the header is in the same folder as the C++ file.
target_include_directories(tictactoe PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# If the TESTING macro is defined setup the private methods as public to allow tests.
if(TESTING)
    target_compile_definitions(tictactoe PRIVATE TESTING)
endif()

# Create the excecutable.
add_executable(main main.cpp)

# Link the executable to the core library.
target_link_libraries(main PRIVATE tictactoe)

# Optional since the header is in the same folder as the C++ file.
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
