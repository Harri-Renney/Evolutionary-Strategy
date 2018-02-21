#include "QLearning.h"

QLearningApprox::QLearningApprox() : EvolutionaryStrategy(100, 10, 0.1, 0.1)
{

}
QLearningApprox::QLearningApprox(int numberOfFeatures, float learningRate, float discountRate) : EvolutionaryStrategy(numberOfFeatures, 100, 0.1, 0.1)
{
	this->learningRate = learningRate;
	this->discountRate = discountRate;
	for (int i = 0; i != numberOfFeatures; ++i)
	{
		std::pair<float, float> placeHolder = std::make_pair(0.0, 1.0);
		state.push_back(placeHolder);
	}
}
float QLearningApprox::QFunction(std::vector<float> action)
{
	float qValueEstimate = 0.0;
	for (int i = 0; i != state.size(); ++i)		// weighted_sum = f(x_0) * w_0 + ... + f(x_n) * w_n
	{
		qValueEstimate += (state[i].first + action[i]) * state[i].second;
	}
	return qValueEstimate;
}
float QLearningApprox::currentQValue()
{
	float qValueEstimate = 0.0;
	for (int i = 0; i != state.size(); ++i)		// weighted_sum = f(x_0) * w_0 + ... + f(x_n) * w_n
	{
		qValueEstimate += state[i].first * state[i].second;
	}
	return qValueEstimate;
}
float QLearningApprox::maxQFunction()
{
	std::vector<float> bestAction;
	evolveParent();
	bestAction = getGenome();
	return QLearningApprox::QFunction(bestAction);
}
float QLearningApprox::maxQFunction(std::vector<float> &action)
{
	evolveParent();
	setAction(action);
	return QLearningApprox::QFunction(action);
}
void QLearningApprox::transitionNewState(float reward, std::vector<float> action)
{

	for (int i = 0; i != state.size(); ++i)
	{
		state[i].first += action[i];
	}
	updateWeights(reward, action);
}

//Error somewhere in here.
//Is this equation right because we only discover reward after making transition? I think so but having difficulty understanding maths.
void QLearningApprox::updateWeights(float reward, std::vector<float> action)
{
	for (int i = 0; i != state.size(); ++i)		//w = w + lr * (r + (dr * maxQ) - currentQ) * f(s)
	{
		float currentQ = currentQValue();
		float maxQ = maxQFunction();
		float temp = state[i].second + learningRate * ((reward + (discountRate * maxQFunction(action))) - currentQValue()) * state[i].first;
		if (temp > 10000)
			state[i].second = 10000;
		else if (temp < -10000)
			state[i].second = -10000;
		else
			state[i].second = temp;
		state[i].second;
	}
}

std::vector<float> QLearningApprox::getFeatures()
{
	std::vector<float> features;
	for (int i = 0; i != state.size(); ++i)
	{
		features.push_back(state[i].first);
	}
	return features;
}

std::vector<float> QLearningApprox::getWeights()
{
	std::vector<float> weights;
	for (int i = 0; i != state.size(); ++i)
	{
		weights.push_back(state[i].second);
	}
	return weights;
}

void QLearningApprox::setAction(std::vector<float>& a)
{
	a = getGenome();
}


//Pure virtual function for deciding fitness override.
float QLearningApprox::fitnessFunction(std::vector<float> genome)
{
	float qValueEstimate = 0.0;
	for (int i = 0; i != state.size(); ++i)		// weighted_sum = f(x_0) * w_0 + ... + f(x_n) * w_n
	{
		qValueEstimate += (state[i].first + genome[i]) * state[i].second;
	}
	return qValueEstimate;
}