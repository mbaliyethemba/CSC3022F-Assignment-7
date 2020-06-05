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
