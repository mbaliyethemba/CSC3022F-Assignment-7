#include <vector>
#include <iostream>
#include <math.h>

#ifndef ANN_H
#define ANN_H

class ann{
	private:
		std::vector<double> nodes, bias;
		double y;
		std::vector<std::vector<double>> weights;
		std::vector<double> product_sum, outputs;
		
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
};

#endif
