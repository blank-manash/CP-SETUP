test: prod_build
	@echo "Testing Against With script.sh: Make Sure it exists!"
	@chmod +x script.sh
	@./script.sh

run: build
	./gtest.o

build:
	@echo "Running Build With flags"
	g++ -std=c++17 -DLOCAL -DDEBUG  -Wall -Wextra -pedantic -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector gtest.cpp -o gtest.o

prod_build:
	@echo "Running Fast Build"
	g++ -std=c++17 -DLOCAL gtest.cpp -o gtest.o

debug:
	@echo "Compiling File and Starting Debugger"
	clang++ -std=c++17 -DLOCAL -g gtest.cpp -o gtest.debug.o

clean:
	@echo "Cleaning Files"
	rm -rf *.o *.in *.out *.ans *.sh gtest.dYSM/

start:
	rm gtest.cpp && cp template.cpp gtest.cpp

clone:
	node server/index.js

restart: clean start clone
	nvim gtest.cpp

copy:
	cat gtest.cpp | pbcopy
