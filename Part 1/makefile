CFLAGS = -O
CC = g++

driver: driver.o
	$(CC) $(CFLAGS) -o driver driver.o perceptron.o --std=c++11

driver.o: perceptron.o driver.cpp
	$(CC) $(CFLAGS) -c driver.cpp --std=c++11

perceptron.o: perceptron.h perceptron.cpp
	$(CC) $(CFLAGS) -c perceptron.cpp --std=c++11

run:
	./driver

clean:
	rm -f core *.o
