output: main.o message.o 
	g++ message.o main.o -o output.out
message.o: message.cpp
	g++ -c message.cpp
main.o: main.cpp 
	g++ -c main.cpp
clean:
	rm *.o output
