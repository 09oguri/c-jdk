build: src/string.c test/test.c
	gcc -Wall -v -o bin/test.a -Iinclude -Ilib test/test.c src/string.c > build.log 2>&1

rebuild:	 clean build ;

clean:
	rm -f bin/*.a *.log

test: rebuild ;
	./bin/test.a