#include "perceptron.h"

//Constructor
perceptron::perceptron(){
}

//Destructor
perceptron::~perceptron(){
}

//Set the inputs
void perceptron::set_input(std::vector<std::vector<int>> v){
	this->input = v;
}

//set target
void perceptron::set_target(std::vector<int> v){
	this->target = v;
}

//set learning rate
void perceptron::set_learning_rate(double d){
	this->learning_rate = d;
}

//set the weights
void perceptron::set_weight(std::vector<int> v){
	this->weights = v;
}

//find the product sum for threshold
double perceptron::product_sum(){
	double product_sum;
	for(size_t i = 0; i < this->weights.size() ; i++){
		for(size_t j = 0; j < 4; j++){
			product_sum += this->weights[i] * this->input[j][i];
		}
	}
	return product_sum;
}

//activation function
void perceptron::activation_function(){
	double p = this->product_sum();
	if(0.0 <= p || p >= 2.0){
		this->output = 0;
	}
	else{
		this->output = 1;
	}
}
