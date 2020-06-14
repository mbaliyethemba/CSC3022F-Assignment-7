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
		std::vector<double> product;
		double learning_rate;
		std::vector<int> output;
		
	public:
		perceptron();
		~perceptron();
		void set_input(std::vector<std::vector<int>>);
		void set_target(std::vector<int>);
		void set_learning_rate(double);
		void set_weight(std::vector<int>);
		void product_sum();
		void activation_function();
		void perceptron_rule();
		void to_string();
		void find_error();
};
#endif
