#include <random>

#include "EvolutionaryStrategy.h"

EvolutionaryStrategy::EvolutionaryStrategy(int numberOfChildren, int numberOfGenome, float mutationRate, float mutationDistribution)
{
	this->numberOfChildren = numberOfChildren;
	this->mutationRate = mutationRate;
	for (int i = 0; i != numberOfGenome; ++i)
	{
		std::pair<float, float> placeHolder = std::make_pair((rand() % 100) / 100.0, mutationDistribution);
		parent.push_back(placeHolder);
	}
}
float EvolutionaryStrategy::evolveParent()
{
	std::default_random_engine generator;
	std::vector<float> best;
	for (int i = 0; i != parent.size(); ++i)
		best.push_back(0);
	for (int i = 0; i != numberOfChildren; ++i)
	{
		std::vector<float> child;
		for (int j = 0; j != parent.size(); ++j)
		{
			std::normal_distribution<double> distribution = std::normal_distribution<double>(parent[j].second, 0.2);
			if ((rand() % 100) / 100.0 <= mutationRate)
			{
				child.push_back(parent[j].first + distribution(generator));
			}
			else
				child.push_back(parent[j].second);
		}
		if (fitnessFunction(child) > fitnessFunction(getGenome()))
			best = child;
	}
	if (fitnessFunction(best) > fitnessFunction(getGenome()))
		getGenome() = best;
	return fitnessFunction(getGenome());
}

///////////////////////
// Getters + Setters //
///////////////////////

std::vector<std::pair<float, float> >& EvolutionaryStrategy::getParent()
{
	return parent;
}

std::vector<float> EvolutionaryStrategy::getGenome()
{
	std::vector<float> genome;
	for (int i = 0; i != parent.size(); ++i)
	{
		genome.push_back(parent[i].first);
	}
	return genome;
}

std::vector<float> EvolutionaryStrategy::getMutationDistribution()
{
	std::vector<float> mutationDistributions;
	for (int i = 0; i != parent.size(); ++i)
	{
		mutationDistributions.push_back(parent[i].first);
	}
	return mutationDistributions;
}