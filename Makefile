GREEN=\e[1;33m
RESET=\e[0m

all: build
	@echo -e "${GREEN} This is target for all Files ${RESET}"
	./gtest.o

test: build
	@echo "Testing Against With script.sh: Make Sure it exists!"
	@chmod +x script.sh
	@./script.sh

build:
	@echo "Building File"
	g++ -std=c++17 -DDEBUG gtest.cpp -o gtest.o
	@echo "Done"

debug:
	@echo "Compiling File and Starting Debugger"
	g++ -std=c++17 -DLOCAL -ggdb gtest.cpp -o gtest.debug.o
	gdb --tui gtest.debug.o

clean:
	@echo "Cleaning Files"
	rm -f *.o *.in *.out *.ans *.sh

clone:
	@chmod +x clone
	./clone
