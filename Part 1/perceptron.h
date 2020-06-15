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
		std::vector<int> target, x_inputs;
		std::vector<double> weights;
		std::vector<double> product;
		double learning_rate;
		std::vector<int> output, or_output, nand_output;
		
	public:
		perceptron();
		~perceptron();
		void set_input(std::vector<std::vector<int>>);
		void set_x_inputs(std::vector<int>);
		void set_target(std::vector<int>);
		void set_learning_rate(double);
		void set_weight(std::vector<double>);
		void product_sum();
		void activation_function();
		void perceptron_rule();
		void to_string();
		void find_error();
		void or_activation_func();
		void or_perceptron_rule();
		void nand_activation_func();
};
#endif
