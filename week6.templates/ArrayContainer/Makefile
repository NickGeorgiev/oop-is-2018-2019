FLAGS=-std=c++14

output: ArrayContainer.o main.o
	g++ ${FLAGS} ArrayContainer.o main.o -o output

main.o: main.cpp ArrayContainer.h
	g++ -c ${FLAGS} main.cpp

ArrayContainer.o: ArrayContainer.cpp ArrayContainer.h
	g++ -c ${FLAGS} ArrayContainer.cpp

execute:
	echo "Executing:"
	./output.exe

clean:
	rm *.o output