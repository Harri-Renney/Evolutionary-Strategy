#ifndef Q_LEARNING_H
#define Q_LEARNING_H

#include <utility>
#include <vector>

#include "EvolutionaryStrategyAPI/EvolutionaryStrategy.h"

//class QLearningApprox : ES::EvolutionaryStrategy {
//	std::vector<std::pair<float, float>> state;
//	float learningRate;
//	float discountRate;
//
//public:
//	QLearningApprox();
//	QLearningApprox(int numberOfFeatures, float learningRate, float discountRate);
//	float QFunction(std::vector<float> action);
//	float currentQValue();
//	float maxQFunction();
//	float maxQFunction(std::vector<float> &action);
//	std::vector<float> transitionNewState(float reward, std::vector<float> action);
//
//	//Is this equation right because we only discover reward after making transition? I think so but hard understanding maths.
//	std::vector<float> updateWeights(float reward, std::vector<float> action);
//
//	std::vector<float> getFeatures();
//
//	std::vector<float> getWeights();
//
//	void setAction(std::vector<float>& a);
//
//	//Pure virtual function for deciding fitness override.
//	float fitnessFunction(std::vector<float> genome) override;
//};


namespace QLearning {
	typedef std::vector<float> action;
	typedef float feature;
	typedef float weight;

	class QLearningDiscrete {

	};

	class QLearningApproxLinear : ES::EvolutionaryStrategy {
	private:
		std::vector<std::pair<feature, weight>> state;
		float learningRate;
		float discountRate;

		void updateWeights(float reward, action a);
	public:
		//////////////////
		// Constructors //
		//////////////////
		QLearningApproxLinear();
		QLearningApproxLinear(int numberOfFeatures, float learningRate, float discountRate);
		QLearningApproxLinear(int numberOfFeatures, float learningRate, float discountRate, int childrenES, float mutationRateES, float initialMutationDistributionES);

		float Q();
		float Q(action a);
		float maxQ();
		float maxQ(action a);
		action maxAction();
		action maxAction(action a);

		void transition(float reward, std::vector<float> action);

		/////////////////////////////////////////////////////////
		// Pure virtual function for deciding fitness override //
		/////////////////////////////////////////////////////////
		float fitnessFunction(std::vector<float> genome) override;

		std::vector<feature> getFeatures();
		std::vector<feature> getWeights();
	};

	class QLearningApproxANN {

	};
}

#endif