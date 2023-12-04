OBJS = main.o hamming.o 
unitTestCPP = unitTests.cpp

demo: $(OBJS)
	g++ $(OBJS) -o demo
test:
	g++ hamming.o unitTests.o -o test
	./test
	clean 
main.o: main.cpp
	g++ main.cpp -c main.o
hamming.o: hamming.cpp hamming.h
	g++ hamming.cpp -c hamming.o
unitTest.o: $(unitTestCPP) hamming.h
	g++ $(unitTestCPP) -c unitTest.o


clean:
	rm -f *.o demo test