CC = g++
CPATH = include/
CFLAGS = -Wall -Werror

SRC = src/*.cpp

OBJ = $(patsubst src/%.cpp,bin/%.o, $(wildcard $(SRC)))

app.exe: $(OBJ)
	$(CC) $^ -o $@ 

bin/%.o: src/%.cpp
	mkdir -p bin
	$(CC) -c -o $@ $(CFLAGS) $^ -I$(CPATH)

run_app:
	./app.exe

run_app_valgrind:
	valgrind --leak-check=yes --track-origins=yes ./app.exe

clean:
	rm -rf bin/ *.exe vgcore*
