CC	 := g++
CFLAGS 	:= -Wall -Wextra -O3 --std=c++17
IFLAGS  := -I/usr/local/include/boost
LDFLAGS := -lm -L/usr/local/lib -lgsl -lgslcblas
EXE 	:= monte_carlo_pi
CFILES	:= coord.cc
OBJECTS := monte_carlo_pi.o coord.o
all: ${EXE}

# $@ = PROGS (name of target)

${EXE}: $(OBJECTS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJECTS) $(LDFLAGS)

coord.o: coord.cc
	$(CC) $(CFLAGS) -c coord.cc $(IFLAGS)

monte_carlo_pi.o: monte_carlo_pi.cc
	$(CC) $(CFLAGS) -c monte_carlo_pi.cc $(IFLAGS)

.PHONY: clean
clean:
	rm -f $(EXE) $(OBJECTS) *.txt