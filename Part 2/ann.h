#include <vector>
#include <iostream>
#include <stdlib.h>
#include <random>
#include <chrono>

#ifndef ANN_H
#define ANN_H

class ann{
	private:
		std::vector<double> nodes, bias;
		double y;
		std::vector<std::vector<double>> weights;
		
	public:
		ann();
		~ann();
		void set_nodes(std::vector<double>);
		void set_target(double);
		void set_bias(std::vector<double>);
		void set_weights(std::vector<std::vector<double>>);
		
};

#endif
