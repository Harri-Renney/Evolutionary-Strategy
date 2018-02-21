#include <iostream>
#include <iomanip>

#include "../EvolutionaryStrategyAPI/EvolutionaryStrategy.h"

class SimpleGenome : public EvolutionaryStrategy{
private:
	std::vector<float> simpleGenome;
public:
	SimpleGenome(int numberOfFeatures, int numberOfChidren, float mutationRate, float mutationDistribution) : EvolutionaryStrategy(numberOfFeatures, numberOfChidren, mutationRate, mutationDistribution)
	{
		for (int i = 0; i != numberOfFeatures; ++i)
			simpleGenome.push_back((rand() % 100) / 100.0);
	}
	float currentFitness()
	{
		float ret = 0;
		for (int i = 0; i != simpleGenome.size(); ++i)
		{
			ret += simpleGenome[i];
		}
		return ret;
	}
	float fitnessFunction(std::vector<float> genome) override
	{
		float ret = 0;
		for (int i = 0; i != genome.size(); ++i)
		{
			ret += genome[i];
		}
		return ret;
	}
	bool evaluateGenome()
	{
		if (fitnessFunction(simpleGenome) > (simpleGenome.size() * 1))
			return true;
		else
			return false;
	}

	std::vector<float>& getSimpleGenome()
	{
		return simpleGenome;
	}
	void setSimpleGenome(std::vector<float>& g)
	{
		simpleGenome = g;
	}

	void printSimpleGenome()
	{
		for (int j = 0; j != simpleGenome.size(); ++j)
		{
			std::cout << simpleGenome[j] << ", ";
		}
		std::cout << " With fitness: " << currentFitness() << std::endl;
	}
};

int main()
{
	std::cout << "This is a simple example of the Evolutionary Strategy API being used to solve a simple problem where the sum of all genomes must exceed: genomeLength * 1" << std::endl << std::endl;
	std::cout << std::setprecision(2) << std::fixed;
	SimpleGenome sg(3, 100, 0.1, 0.1);

	int i = 0;
	while (!sg.evaluateGenome())
	{
		std::cout << "Genome Generation " << i << " : ";
		sg.printSimpleGenome();
		sg.evolveParent();
		std::vector<float> temp = sg.getGenome();
		sg.setSimpleGenome(temp);
		++i;
	}

	std::cout << std::endl << "Final Genome: ";
	sg.printSimpleGenome();

	int c;
	std::cin >> c;
	return 0;
}