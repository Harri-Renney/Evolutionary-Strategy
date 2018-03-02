#include <iostream>
#include <iomanip>

#include "../QLearning.h"

void printGenome(std::vector<float> v)
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
	QLearning::QLearningApproxLinear ql(10, 0.2, 0.7, 10000, 0.7, 0.01);

	double reward = 0;
	int i = 0;
	while (1)
	{
		std::cout << "Genome Generation " << i << " : ";
		printGenome(ql.getFeatures());
		std::vector<float> nextAction = ql.maxAction();
		//reward = nextAction[8] - nextAction[13];
		//reward = nextAction[0] * nextAction[1] * nextAction[2] * nextAction[3] * nextAction[4] - nextAction[5] * nextAction[6] * nextAction[7] * nextAction[8] * nextAction[9];
		ql.transition(reward, nextAction);
		++i;
	}
	return 0;
}