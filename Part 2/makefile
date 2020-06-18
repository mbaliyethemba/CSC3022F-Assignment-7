CFLAGS = -O
CC = g++

driver: driver.o
	$(CC) $(CFLAGS) -o driver driver.o ann.o --std=c++11

driver.o: ann.o driver.cpp
	$(CC) $(CFLAGS) -c driver.cpp --std=c++11

perceptron.o: ann.h ann.cpp
	$(CC) $(CFLAGS) -c ann.cpp --std=c++11

run:
	./driver

clean:
	rm -f core *.o
