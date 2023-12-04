OBJS = main.o hamming.o 

unitTestCPP = unitTests.cpp

demo: $(OBJS)
	g++ $(OBJS) -o demo
test: unitTests.o hamming.o
	g++ hamming.o unitTests.o -o test
	./test
	make clean
main.o: main.cpp
	g++ main.cpp -c main.o
hamming.o: hamming.cpp hamming.h
	g++ hamming.cpp -c hamming.o
unitTests.o: $(unitTestCPP) hamming.h
	g++ -c $(unitTestCPP)


clean:
	rm -f *.o demo test