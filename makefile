OBJS = main.o hamming.o 
unitTestOBJ = unitTest.o

demo: $(OBJS)
	g++ $(OBJS) -o demo

main.o: main.cpp
	g++ main.cpp -c main.o
hamming.o: hamming.cpp hamming.h
	g++ hamming.cpp -c hamming.o

test:
	g++ hamming.o unitTest.o -o test
	./test

clean:
	rm -f *.o demo test