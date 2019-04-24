FLAGS=-std=c++14

output: main.o
	g++ ${FLAGS} main.o -o output

main.o: main.cpp ArrayContainer.h
	g++ -c ${FLAGS} main.cpp

execute:
	echo "Executing:"
	./output

clean:
	rm *.o output