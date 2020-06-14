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
