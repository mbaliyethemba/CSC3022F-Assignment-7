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

//find the output
void ann::get_output(){
	for(size_t f = 0; f < 2; f++){
		outputs.push_back(this->signoid(product_sum[f]));
	}
	std::cout << "Question 1" << std::endl;
	std::cout << outputs[0] << std::endl;
	std::cout << outputs[1] << std::endl;
}

//set hidden weights
void ann::set_hidden_weights(std::vector<double> v){
	this->hidden_weights = v;
}

//set hidden bias
void ann::set_hidden_bias(double d){
	this->b = d;
}

//find hidden product sum
double ann::hidden_product_sum(){
	double hps = 0.0;
	for(size_t h = 0; h < 2; h++){
		hps += this->outputs[h] * this->hidden_weights[h];
	}
	hps = hps + b;
	this->hidden_sum = hps;
	return hps;
}

//find the output
void ann::get_hidden_output(){
	hidden_output = this->signoid(this->hidden_product_sum());
	std::cout << "Question 2" << std::endl;
	std::cout << hidden_output << std::endl;
}

//mean squared error
void ann::get_mean_sqrd_err(){
	this->mean_sqrd_err = ((y-hidden_output)*(y-hidden_output))/2.0;
}

//print to file
void ann::to_file(){
	std::ofstream outfile;
	outfile.open("part2_answers.txt");
	if(outfile.is_open()){
		outfile << "Question 3:" << std::endl;
		for(size_t g = 0 ; g < this->outputs.size(); g++){
			outfile << "neuron output " << g+1 << " : " << this->outputs[g] << std::endl;
		}
		outfile << "**************************" << std::endl;
		outfile << "Question 4:" << std::endl;
		outfile << "output neuron : " << hidden_output << std::endl;
		outfile << "**************************" << std::endl;
	}
}
