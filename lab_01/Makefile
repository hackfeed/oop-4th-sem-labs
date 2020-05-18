CC = g++
CPATH = include/
CFLAGS = -Wall -Werror
GTKFLAGS = `pkg-config --libs --cflags gtkmm-3.0`

SRC = src/*.cpp

OBJ = $(patsubst src/%.cpp,bin/%.o, $(wildcard $(SRC)))

app.exe: $(OBJ)
	$(CC) $^ -o $@ $(GTKFLAGS) 

bin/%.o: src/%.cpp
	mkdir -p bin
	$(CC) -c -o $@ $(GTKFLAGS) $(CFLAGS) $^ -I$(CPATH)

run_app:
	./app.exe

run_app_valgrind:
	valgrind --leak-check=yes --track-origins=yes ./app.exe

clean:
	rm -rf bin/ *.exe vgcore*
