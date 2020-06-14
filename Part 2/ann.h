#include <vector>
#include <iostream>
#include <stdlib.h>
#include <random>
#include <chrono>

#ifndef ANN_H
#define ANN_H

class ann{
	private:
		std::vector<double> inputs;
		
	public:
		ann();
		~ann();
};

#endif
