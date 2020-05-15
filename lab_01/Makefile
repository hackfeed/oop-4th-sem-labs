CC = g++ -Iinclude/
BINARIES = $(patsubst src/%.cpp,bin/%.o, $(wildcard src/*.cpp))
GTK_FLAGS = `pkg-config --libs --cflags gtkmm-3.0`
COMPILE_FLAGS = -Wall -Werror

.PHONY: all test clean
all: app.exe

app.exe: $(BINARIES)
	$(CC) $^ -o $@ $(GTK_FLAGS) 

bin/%.o: src/%.cpp
	mkdir -p bin
	$(CC) -c -o $@ $(GTK_FLAGS) $(COMPILE_FLAGS) $^

clean:
	rm -rf bin/ app.exe
