CXX = clang++
CXXFLAGS = --std=c++20
OBJS = main.o tictactoe.o
TARGET = game

.PHONY: app clean run

run: app
	./$(TARGET)

app: $(OBJS)
	$(CXX) -o $(TARGET) $^

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

clean: *.o
	rm $^