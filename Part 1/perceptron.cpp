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

//set x inputs
void perceptron::set_x_inputs(std::vector<int> v){
	this->x_inputs = v;
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
void perceptron::set_weight(std::vector<double> v){
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
}

//find the product sum for threshold
void perceptron::a_product_sum(){
	double product_sum;
	for(size_t i = 0; i < 4 ; i++){
		product_sum = this->weights[0] * this->or_output[i] + this->weights[1] * this->nand_output[i];
		a_prod.push_back(product_sum);
		product_sum = 0.0;
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

//or activation function
void perceptron::or_activation_func(){
	this->product_sum();
	int num;
	for(size_t i = 0; i < product.size() ; i++){
		if(product[i] < 1){
			num = 0;
			this->or_output.push_back(num);
			
		}
		else{
			num = 1;
			this->or_output.push_back(num);
		}
	}
}

//nand activation function
void perceptron::nand_activation_func(){
	this->product_sum();
	int num;
	for(size_t i = 0; i < product.size() ; i++){
		if(product[i] > 1){
			num = 0;
			this->nand_output.push_back(num);
			
		}
		else{
			num = 1;
			this->nand_output.push_back(num);
		}
	}
}

//and activation function
void perceptron::and_activation_func(){
	this->product_sum();
	int num;
	for(size_t i = 0; i < product.size() ; i++){
		if(product[i] < 2){
			num = 0;
			this->and_output.push_back(num);
			
		}
		else{
			num = 1;
			this->and_output.push_back(num);
		}
	}
}

void perceptron::or_perceptron_rule(){
	this->or_activation_func();
	for(size_t i = 0; i < this->weights.size(); i++){
		for(size_t j = 0; j < 4; j++){
			this->weights[i] += this->learning_rate*(this->target[j] - this->or_output[j])* this->input[i][j];
			}
	}
}

void perceptron::nand_perceptron_rule(){
	this->nand_activation_func();
	for(size_t i = 0; i < this->weights.size(); i++){
		for(size_t j = 0; j < 4; j++){
			this->weights[i] += this->learning_rate*(this->target[j] - this->nand_output[j])* this->input[i][j];
			}
	}
}

void perceptron::and_perceptron_rule(){
	this->and_activation_func();
	for(size_t i = 0; i < this->weights.size(); i++){
		for(size_t j = 0; j < 4; j++){
			this->weights[i] += this->learning_rate*(this->target[j] - this->and_output[j])* this->input[i][j];
			}
	}
}

void perceptron::perceptron_rule(){
	this->or_perceptron_rule();
	this->nand_perceptron_rule();
	this->and_perceptron_rule();
}

//Printing the or gate
void perceptron::or_to_string(){
	std::cout << "Training the OR perceptron" << std::endl;
	std::cout << "Input1 " << "Input2 " << "Output" << std::endl;
	std::cout << this->input[0][0] << "       " << this->input[1][0] << "       "<< or_output[0] << std::endl;
	std::cout << this->input[0][1] << "       " << this->input[1][1] << "       "<< or_output[1] << std::endl;
	std::cout << this->input[0][2] << "       " << this->input[1][2] << "       "<< or_output[2] << std::endl;
	std::cout << this->input[0][3] << "       " << this->input[1][3] << "       "<< or_output[3] << std::endl;
}

//printing nand gate
void perceptron::nand_to_string(){
	std::cout << "Training the OR perceptron" << std::endl;
	std::cout << "Input1 " << "Input2 " << "Output" << std::endl;
	std::cout << this->input[0][0] << "       " << this->input[1][0] << "       "<< nand_output[0] << std::endl;
	std::cout << this->input[0][1] << "       " << this->input[1][1] << "       "<< nand_output[1] << std::endl;
	std::cout << this->input[0][2] << "       " << this->input[1][2] << "       "<< nand_output[2] << std::endl;
	std::cout << this->input[0][3] << "       " << this->input[1][3] << "       "<< nand_output[3] << std::endl;
}

void perceptron::to_string(){
	std::cout << "solving the XOR problem" << std::endl;
	std::cout << "Training the OR perceptron" << std::endl;
	std::cout << "Target :" << std::endl;
	for(size_t i = 0; i < 3; i++){
		std::cout << this->target[i] << " ";
	}
	std::cout << this->target[3] << std::endl;
	
	std::cout << "Output :" << std::endl;
	for(size_t i = 0; i < 3; i++){
		std::cout << this->or_output[i] << " ";
	}
	std::cout << this->or_output[3] << std::endl;
	
	std::cout << "Weights :" << std::endl;
	std::cout << this->weights[0] << " " << this->weights[1] << std::endl;
	
	std::cout << "Training the NAND perceptron" << std::endl;
	std::cout << "Target :" << std::endl;
	for(size_t i = 0; i < 3; i++){
		std::cout << this->target[i] << " ";
	}
	std::cout << this->target[3] << std::endl;
	
	std::cout << "Output :" << std::endl;
	for(size_t i = 0; i < 3; i++){
		std::cout << this->nand_output[i] << " ";
	}
	std::cout << this->nand_output[3] << std::endl;
	
	std::cout << "Weights :" << std::endl;
	std::cout << this->weights[0] << " " << this->weights[1] << std::endl;
	
	std::cout << "Training the AND perceptron" << std::endl;
	std::cout << "Target :" << std::endl;
	for(size_t i = 0; i < 3; i++){
		std::cout << this->target[i] << " ";
	}
	std::cout << this->target[3] << std::endl;
	
	std::cout << "Output :" << std::endl;
	for(size_t i = 0; i < 3; i++){
		std::cout << this->and_output[i] << " ";
	}
	std::cout << this->and_output[3] << std::endl;
	
	std::cout << "Weights :" << std::endl;
	std::cout << this->weights[0] << " " << this->weights[1] << std::endl;
}

//function to find the error
void perceptron::find_error(){
	if(this->target == this->and_output){
		this->to_string();
	}
	else{
		this->perceptron_rule();
		this->find_error();
	}
}
