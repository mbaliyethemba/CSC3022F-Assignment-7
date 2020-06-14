#include "ann.h"

//constructor
ann::ann(){
}

//destructor
ann::~ann(){
}

//set ann nodes
void ann::set_nodes(std::vector<double> x){
	this->nodes = x;
}

//set expected output
void ann::set_target(double y){
	this->y = y;
}

//set the bias
void ann::set_bias(std::vector<double> v){
	this->bias = v;
}

//set the weights connecting input to hidden layer nodes
void ann::set_weights(std::vector<std::vector<double>> v){
	this->weights = v;
}

//find the product sum
void ann::find_product_sum(){
	double p_sum = 0.0;
	for(size_t b = 0; b < 2; b++){
		for(size_t c = 0; c < 3; c++){
			p_sum += this->weights[b][c] * this->nodes[c];
		}
		product_sum.push_back(p_sum);
		p_sum = 0.0;
	}
	
	for(size_t d = 0; d < 2; d++){
		product_sum[d] = product_sum[d] + bias[d];
	}
}

//signoid function
double ann::signoid(double d){
	return (1/(1+exp(d*(-1))));
}
