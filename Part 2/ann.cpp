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

//print to file
void ann::to_file(){
	std::ofstream outfile;
	outfile.open("part2_answers.txt");
	if(outfile.is_open()){
		outfile << "Question 3:" << std::endl;
		for(size_t g = 0 ; g < outputs.size(); g++){
			outfile << "neuron output" << g+1 << " : " << outputs[g] << std::endl;
		}
	}
}
