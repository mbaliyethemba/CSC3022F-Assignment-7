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
		for(size_t j = 0; j < this->weights.size(); j++){
			product_sum += this->weights[j] * this->input[i][j];
		}
		product.push_back(product_sum);
	}
}

//activation function
void perceptron::activation_function(){
	this->product_sum();
	int num;
	for(size_t i = 0; i < product.size() ; i++){
		if(0.0 <= product[i] || product[i] >= 2.0){
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
		this->weights[i] = this->weights[i] + this->learning_rate*(this->target[i] - this->output[i])*this->weights[i];
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
}
