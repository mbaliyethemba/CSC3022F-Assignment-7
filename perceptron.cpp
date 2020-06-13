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
void perceptron::product_sum(){
	double product_sum;
	for(size_t i = 0; i < 4 ; i++){
		product_sum = this->weights[0] * this->input[i][0] + this->weights[1] * this->input[i][1];
		product.push_back(product_sum);
		product_sum = 0.0;
	}
	for(size_t q = 0; q < this->product.size(); q++){
		std::cout << product[q] << std::endl;
	}
}

//activation function
void perceptron::activation_function(){
	this->product_sum();
	int num;
	for(size_t i = 0; i < product.size() ; i++){
		if(product[i] <= 0 || product[i] >= 2.0){
			num = 0;
			this->output.push_back(num);
			
		}
		else{
			num = 1;
			this->output.push_back(num);
		}
	}
}

void perceptron::perceptron_rule(){
	this->activation_function();
	for(size_t i = 0; i < this->weights.size(); i++){
		for(size_t j = 0; j < 4; j++){
			this->weights[i] = this->weights[i] + this->learning_rate*(this->target[j] - this->output[j]) * this->input[i][j];
			}
	}
}

void perceptron::to_string(){
	std::cout << "Target :" << std::endl;
	for(size_t i = 0; i < 3; i++){
		std::cout << this->target[i] << " ";
	}
	std::cout << this->target[3] << std::endl;
	
	std::cout << "Output :" << std::endl;
	for(size_t i = 0; i < 3; i++){
		std::cout << this->output[i] << " ";
	}
	std::cout << this->output[3] << std::endl;
	
	std::cout << "Weights :" << std::endl;
	std::cout << this->weights[0] << " " << this->weights[1] << std::endl;
}

//function to find the error
void perceptron::find_error(){
	if(this->target == this->output){
		this->to_string();
	}
	else{
		this->perceptron_rule();
		this->find_error();
	}
}
