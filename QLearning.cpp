#include "QLearning.h"

using namespace QLearning;

//QLearningApprox::QLearningApprox() : EvolutionaryStrategy(100, 10, 0.1, 0.1)
//{
//
//}
//QLearningApprox::QLearningApprox(int numberOfFeatures, float learningRate, float discountRate) : EvolutionaryStrategy(numberOfFeatures, 10, 0.3, 0.001)
//{
//	this->learningRate = learningRate;
//	this->discountRate = discountRate;
//	for (int i = 0; i != numberOfFeatures; ++i)
//	{
//		std::pair<float, float> placeHolder = std::make_pair(0.01, 0.0);
//		state.push_back(placeHolder);
//	}
//}
//float QLearningApprox::QFunction(std::vector<float> action)
//{
//	float qValueEstimate = 0.0;
//	for (int i = 0; i != state.size(); ++i)		// weighted_sum = f(x_0) * w_0 + ... + f(x_n) * w_n
//	{
//		qValueEstimate += (state[i].first + action[i]) * state[i].second;
//	}
//	return qValueEstimate;
//}
//float QLearningApprox::currentQValue()
//{
//	float qValueEstimate = 0.0;
//	for (int i = 0; i != state.size(); ++i)		// weighted_sum = f(x_0) * w_0 + ... + f(x_n) * w_n
//	{
//		qValueEstimate += state[i].first * state[i].second;
//	}
//	return qValueEstimate;
//}
//float QLearningApprox::maxQFunction()
//{
//	std::vector<float> bestAction;
//	evolveParent();
//	bestAction = getGenome();
//	return QLearningApprox::QFunction(bestAction);
//}
//float QLearningApprox::maxQFunction(std::vector<float> &action)
//{
//	evolveParent();
//	action = getGenome();
//	return QLearningApprox::QFunction(action);
//}
//std::vector<float> QLearningApprox::transitionNewState(float reward, std::vector<float> action)
//{
//
//	for (int i = 0; i != state.size(); ++i)
//	{
//		state[i].first += action[i];
//	}
//	return updateWeights(reward, action);
//}
//
////Error somewhere in here.
////Is this equation right because we only discover reward after making transition? I think so but having difficulty understanding maths.
//std::vector<float> QLearningApprox::updateWeights(float reward, std::vector<float> action)
//{
//	std::vector<float> newAction;
//	float currentQ = currentQValue();
//	float maxQ = maxQFunction(newAction);
//	for (int i = 0; i != state.size(); ++i)		//w = w + lr * (r + (dr * maxQ) - currentQ) * f(s)
//	{
//		float temp = state[i].second + (learningRate * ((reward + (discountRate * maxQ)) - currentQValue()) * action[i]);
//		if (temp > 10000000)
//			state[i].second = 10000000;
//		else if (temp < -10000000)
//			state[i].second = -10000000;
//		else
//			state[i].second = temp;
//		if(temp > 3)
//			state[i].second;
//	}
//	return newAction;
//}
//
//std::vector<float> QLearningApprox::getFeatures()
//{
//	std::vector<float> features;
//	for (int i = 0; i != state.size(); ++i)
//	{
//		features.push_back(state[i].first);
//	}
//	return features;
//}
//
//std::vector<float> QLearningApprox::getWeights()
//{
//	std::vector<float> weights;
//	for (int i = 0; i != state.size(); ++i)
//	{
//		weights.push_back(state[i].second);
//	}
//	return weights;
//}
//
//void QLearningApprox::setAction(std::vector<float>& a)
//{
//	a = getGenome();
//}
//
//
////Pure virtual function for deciding fitness override.
//float QLearningApprox::fitnessFunction(std::vector<float> genome)
//{
//	float qValueEstimate = 0.0;
//	for (int i = 0; i != state.size(); ++i)		// weighted_sum = f(x_0) * w_0 + ... + f(x_n) * w_n
//	{
//		qValueEstimate += (state[i].first + genome[i]) * state[i].second;
//	}
//	return qValueEstimate;
//}

QLearningApproxLinear::QLearningApproxLinear() : EvolutionaryStrategy(100, 10, 0.1, 0.1) {

}
QLearningApproxLinear::QLearningApproxLinear(int numberOfFeatures, float learningRate, float discountRate)
												: EvolutionaryStrategy(numberOfFeatures, 10, 0.3, 0.001) 
{
	this->learningRate = learningRate;
	this->discountRate = discountRate;
	for (int i = 0; i != numberOfFeatures; ++i)
	{
		std::pair<float, float> placeHolder = std::make_pair(0.01, 0.0);
		state.push_back(placeHolder);
	}
}
QLearningApproxLinear::QLearningApproxLinear(int numberOfFeatures, float learningRate, float discountRate, 
											 int childrenES, float mutationRateES, float initialMutationDistributionES)
												: EvolutionaryStrategy(numberOfFeatures, childrenES, mutationRateES, initialMutationDistributionES)
{
	this->learningRate = learningRate;
	this->discountRate = discountRate;
	for (int i = 0; i != numberOfFeatures; ++i)
	{
		std::pair<float, float> placeHolder = std::make_pair(0.01, 0.0);
		state.push_back(placeHolder);
	}
}

float QLearningApproxLinear::Q()
{
	float QValue = 0.0;
	for (int i = 0; i != state.size(); ++i)		// weighted_sum = f(x_0) * w_0 + ... + f(x_n) * w_n
	{
		QValue += state[i].first * state[i].second;
	}
	return QValue;
}
float QLearningApproxLinear::Q(action a)
{
	float QValue = 0.0;
	for (int i = 0; i != state.size(); ++i)		// weighted_sum = f(x_0) * w_0 + ... + f(x_n) * w_n
	{
		float stateAction = state[i].first + a[i];
		QValue += stateAction * state[i].second;
	}
	return QValue;
}

float QLearningApproxLinear::maxQ()
{
	action maxAction;
	maxAction = getGenome();
	return Q(maxAction);
}
float QLearningApproxLinear::maxQ(action a)
{
	//Unsure how to proceed.
	return 0;
}

action QLearningApproxLinear::maxAction()
{
	action maxAction;
	evolveParent();
	maxAction = getGenome();
	return maxAction;
}
//action QLearningApproxLinear::maxAction(action a)
//{
//	//Unsure how to proceed.
//	return (action)NULL;
//}

void QLearningApproxLinear::updateWeights(float reward, action a)	//Need action here??
{
	float currentQValue = Q();
	float maxQValue = maxQ();
	for (int i = 0; i != state.size(); ++i)		//w = w + lr * (r + (dr * maxQ) - currentQ) * f(s)
	{
		state[i].second += learningRate * ((reward + (discountRate * maxQValue)) - currentQValue) * a[i];	//Debatable. Should the added feature be of the state or of the action just taken??
	}
}

void QLearningApproxLinear::transition(float reward, std::vector<float> action)
{
	for (int i = 0; i != state.size(); ++i)
		state[i].first += action[i];
	updateWeights(reward, action);
}

float QLearningApproxLinear::fitnessFunction(std::vector<float> genome)
{
		float QValue = 0.0;
		for (int i = 0; i != state.size(); ++i)		// weighted_sum = f(x_0) * w_0 + ... + f(x_n) * w_n
		{
			QValue += (state[i].first + genome[i]) * state[i].second;
		}
		return QValue;
}

std::vector<feature> QLearningApproxLinear::getFeatures()
{
	std::vector<float> features;
	for (int i = 0; i != state.size(); ++i)
	{
		features.push_back(state[i].first);
	}
	return features;
}

std::vector<weight> QLearningApproxLinear::getWeights()
{
	std::vector<float> weights;
	for (int i = 0; i != state.size(); ++i)
	{
		weights.push_back(state[i].second);
	}
	return weights;
}