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
		std::vector<int> target, input1, input2;
		std::vector<double> weights;
		std::vector<double> product, a_prod;
		double learning_rate;
		std::vector<int> output, or_output, nand_output, and_output;
		
	public:
		perceptron(std::vector<int>,std::vector<int>,std::vector<int>,double,std::vector<double>);
		~perceptron();
		void set_input(std::vector<std::vector<int>>);
		void set_x_inputs(std::vector<int>);
		void set_target(std::vector<int>);
		void set_learning_rate(double);
		void set_weight(std::vector<double>);
		void product_sum();
		void a_product_sum();
		void activation_function();
		void perceptron_rule();
		void to_string();
		void find_error();
		void or_activation_func();
		void or_perceptron_rule();
		void nand_activation_func();
		void nand_perceptron_rule();
		void and_activation_func();
		void and_perceptron_rule();
};
#endif
