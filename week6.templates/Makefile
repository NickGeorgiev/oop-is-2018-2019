FLAGS=-std=c++14

output: ArrayContainer.o sem.o
	g++ ${FLAGS} ArrayContainer.o sem.o -o output

sem.o: sem.cpp ./ArrayContainer/ArrayContainer.cpp
	g++ -c ${FLAGS} sem.cpp

ArrayContainer.o: ./ArrayContainer/ArrayContainer.cpp ./ArrayContainer/ArrayContainer.h
	g++ -c ${FLAGS} ./ArrayContainer/ArrayContainer.cpp

execute:
	echo "Executing:"
	./output.exe

clean:
	rm *.o output