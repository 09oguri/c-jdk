init:
	if [ ! -d bin ] ; then mkdir bin ; fi

build: src/lang.String.c test/lang.StringTest.c src/util.ArrayList.c test/util.ArrayListTest.c
	gcc -Wall -v -o bin/lang.StringTest.a -Iinclude -Ilib test/lang.StringTest.c src/lang.String.c > build.log 2>&1
	gcc -Wall -v -o bin/util.ArrayListTest.a -Iinclude -Ilib test/util.ArrayListTest.c src/util.ArrayList.c >> build.log 2>&1

rebuild:	 clean build ;

clean:
	rm -f bin/*.a *.log

test:	init rebuild ;
	./bin/lang.StringTest.a
	./bin/util.ArrayListTest.a

examples: src/lang.String.c src/util.ArrayList.c src-examples/arraylist_string.c
	gcc -Wall -v -o bin/arraylist_string.a -Iinclude -Ilib src/lang.String.c src/util.ArrayList.c src-examples/arraylist_string.c
	./bin/arraylist_string.a