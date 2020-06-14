#include <vector>
#include <iostream>
#include <stdlib.h>
#include <random>
#include <chrono>

#ifndef ANN_H
#define ANN_H

class ann{
	private:
		std::vector<double> nodes;
		double y;
		
	public:
		ann();
		~ann();
		void set_nodes(std::vector<double>);
		void set_target(double);
		void set_bias(std::vector<double>);
};

#endif
