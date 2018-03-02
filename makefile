basicES: Examples/basicES.cpp EvolutionaryStrategyAPI/EvolutionaryStrategy.cpp
	g++ -std=c++17 -o Build/basicES Examples/basicES.cpp EvolutionaryStrategyAPI/EvolutionaryStrategy.cpp
qLearningES: Examples/qLearningES.cpp EvolutionaryStrategyAPI/EvolutionaryStrategy.cpp QLearning.cpp
	g++ -std=c++17 -o Build/qLearningES Examples/qLearningES.cpp EvolutionaryStrategyAPI/EvolutionaryStrategy.cpp QLearning.cpp