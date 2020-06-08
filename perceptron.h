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
		std::vector<int> weights;
		double learning_rate;
		
	public:
		perceptron();
		~perceptron();
		void set_input(std::vector<std::vector<int>>);
		void set_target(std::vector<int>);
		void set_learning_rate(double);
		void set_weight(std::vector<int>);
		double product_sum();
		void activation_function();
};
#endif
