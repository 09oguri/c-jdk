init:
	if [ ! -d bin ] ; then mkdir bin ; fi

build: src/lang.String.c test/lang.StringTest.c
	gcc -Wall -v -o bin/lang.StringTest.a -Iinclude -Ilib test/lang.StringTest.c src/lang.String.c > build.log 2>&1

rebuild:	 clean build ;

clean:
	rm -f bin/*.a *.log

test:	init rebuild ;
	./bin/lang.StringTest.a