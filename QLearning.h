#ifndef Q_LEARNING_H
#define Q_LEARNING_H

#include <utility>
#include <vector>

#include "EvolutionaryStrategyAPI/EvolutionaryStrategy.h"

class QLearningApprox : EvolutionaryStrategy {
	std::vector<std::pair<float, float>> state;
	float learningRate;
	float discountRate;

public:
	QLearningApprox();
	QLearningApprox(int numberOfFeatures, float learningRate, float discountRate);
	float QFunction(std::vector<float> action);
	float currentQValue();
	float maxQFunction();
	float maxQFunction(std::vector<float> &action);
	void transitionNewState(float reward, std::vector<float> action);

	//Is this equation right because we only discover reward after making transition? I think so but hard understanding maths.
	void updateWeights(float reward, std::vector<float> action);

	std::vector<float> getFeatures();

	std::vector<float> getWeights();

	void setAction(std::vector<float>& a);

	//Pure virtual function for deciding fitness override.
	float fitnessFunction(std::vector<float> genome) override;
};

#endif