test: build
	@echo "Testing Against With script.sh: Make Sure it exists!"
	@chmod +x script.sh
	@./script.sh

run: build
	./gtest.o < in.in

build:
	@echo "Building File"
	g++ -std=c++17 -DLOCAL -DDEBUG gtest.cpp -o gtest.o

debug:
	@echo "Compiling File and Starting Debugger"
	g++ -std=c++17 -DLOCAL -ggdb gtest.cpp -o gtest.debug.o
	gdb --tui gtest.debug.o

clean:
	@echo "Cleaning Files"
	rm -f *.o *.in *.out *.ans *.sh

start:
	rm gtest.cpp && cp template.cpp gtest.cpp

clone:
	./parser

restart: clean start clone
