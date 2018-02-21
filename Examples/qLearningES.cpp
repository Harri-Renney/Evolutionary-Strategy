#include <iostream>
#include <iomanip>

#include "../QLearning.h"

void printSimpleGenome(std::vector<float> v)
{
	for (float print: v)
	{
		std::cout << print << ", ";
	}
	std::cout << std::endl;
}

int main()
{
	std::cout << "This is a simple example of the Evolutionary Strategy API being used in Q Learning class to solve a simple problem where the reward mjust exceed 10" << std::endl << std::endl;
	std::cout << std::setprecision(2) << std::fixed;
	QLearningApprox ql(3, 0.2, 0.7);

	double reward = 0;
	int i = 0;
	while (1)
	{
		std::cout << "Genome Generation " << i << " : ";
		printSimpleGenome(ql.getFeatures());
		std::vector<float> action;
		ql.maxQFunction(action);
		reward = action[2]*3 - action[1]*3;
		ql.transitionNewState(reward, action);
		++i;
	}
	return 0;
}