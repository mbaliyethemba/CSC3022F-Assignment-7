#include <vector>
#include <iostream>
#include <math.h>
#include <fstream>

#ifndef ANN_H
#define ANN_H

class ann{
	private:
		std::vector<double> nodes, bias;
		double y, b;
		std::vector<std::vector<double>> weights;
		std::vector<double> product_sum, outputs, hidden_weights;
		
	public:
		ann();
		~ann();
		void set_nodes(std::vector<double>);
		void set_target(double);
		void set_bias(std::vector<double>);
		void set_weights(std::vector<std::vector<double>>);
		void find_product_sum();
		double signoid(double);
		void get_output();
		void to_file();
		void set_hidden_weights(std::vector<double>);
		void set_hidden_bias(double);
};

#endif
