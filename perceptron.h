#include <vector>
#include <iostream>
#include <stdlib.h>
#include <random>
#include <chrono>

#ifndef PERCEPTRON_H
#define PERCEPTRON_H
class perceptron{
	private:
		std::vector<std::vector<int>> input;
		std::vector<int> target;
		
	public:
		perceptron();
		~perceptron();
		void set_input(std::vector<std::vector<int>>);
};
#endif
