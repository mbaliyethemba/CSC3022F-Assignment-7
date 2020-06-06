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
