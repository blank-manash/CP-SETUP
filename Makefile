test: prod_build
	@echo "Testing Against With script.sh: Make Sure it exists!"
	@chmod +x script.sh
	@./script.sh

run: build
	./gtest.o < in.in

build:
	@echo "Running Build With flags"
	g++ -std=c++17 -DLOCAL -DDEBUG  -Wall -Wextra -pedantic -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector gtest.cpp -o gtest.o

prod_build:
	@echo "Running Fast Build"
	g++ -std=c++17 -DLOCAL gtest.cpp -o gtest.o

debug:
	@echo "Compiling File and Starting Debugger"
	g++ -std=c++17 -DLOCAL -ggdb gtest.cpp -o gtest.debug.o
	gdb gtest.debug.o

clean:
	@echo "Cleaning Files"
	rm -f *.o *.in *.out *.ans *.sh

start:
	rm gtest.cpp && cp template.cpp gtest.cpp
	node server/index.js
	nvim gtest.cpp

add:
	@gum write --placeholder="Add Input (Ctrl-D to Finish)" --char-limit=0 > "input_${num}.in"
	@gum write --placeholder="Add Output" --char-limit=0 > "out_${num}.out"
	sed -e "s/^TEST_CASES.*/TEST_CASES=${num}/" script.sh > tmp_script
	rm script.sh && mv tmp_script script.sh


clone:
	node server/index.js

restart: clean start
