#include "perceptron.h"

int main(int argc, char const *argv[]){
	perceptron p;
	p.set_input({{0,0},{0,1},{1,0},{1,1}});
	p.set_target({0,1,1,0});
	p.set_learning_rate(0.5);
	p.set_weight({1,1});
	p.perceptron_rule();
	p.to_string();
}
