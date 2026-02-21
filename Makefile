test: prod_build
	@echo "Testing Against With script.sh: Make Sure it exists!"
	@chmod +x script.sh
	@./script.sh

run: build
	java gtest < in.in

build:
	@echo "Running Build With flags"
	javac Debug.java gtest.java

prod_build:
	@echo "Running Fast Build"
	javac Debug.java gtest.java

debug:
	@echo "Compiling File and Starting Debugger"
	javac -g Debug.java gtest.java
	jdb gtest

clean:
	@echo "Cleaning Files"
	rm -f *.class *.in *.out *.ans *.sh

start:
	rm -f gtest.java && cp template.java gtest.java

clone:
	./parser

restart: clean start clone
