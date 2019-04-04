FLAGS=-std=c++14

output: IntArrayContainer.o main.o
	g++ ${FLAGS} IntArrayContainer.o main.o -o output

main.o: main.cpp IntArrayContainer.h
	g++ -c ${FLAGS} main.cpp

IntArrayContainer.o: IntArrayContainer.cpp IntArrayContainer.h
	g++ -c ${FLAGS} IntArrayContainer.cpp

execute:
	echo "Executing:"
	./output.exe

clean:
	rm *.o output