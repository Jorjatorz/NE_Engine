#include "EIterativeWorld.h"

#include <iostream>
#include <vector>
#include "EIndividual.h"
#include "EIndividualSelector.h"
#include "RandomGenerator.h"

EIterativeWorld::EIterativeWorld(int max_iterations)
	:current_iteration(0),
	max_iterations(max_iterations)
{
	individual_factory.set_individual_type(EIndividualFactory::ADDER);
	population_size = 100;
	for (int i = 0; i < population_size; i++)
	{
		population_vector.push_back(individual_factory.generateIndividual());
	}
}


EIterativeWorld::~EIterativeWorld()
{
	for (int i = 0; i < population_size; i++)
	{
		delete population_vector.at(i);
	}
}

void EIterativeWorld::simulate()
{
	RandomGenerator rand;
	simulation_running = true;
	while (simulation_running && current_iteration < max_iterations)
	{
		// Evaluation
		for(auto& individual : population_vector)
		{
			individual->evaluate(std::vector<double>(1, rand.randomInteger(0, 100)));
			std::cout << individual->get_fitness() << std::endl;
		}

		// Selection
		EIndividualSelector::tournament_selection(5, population_vector);

		// Crossover
		std::vector<EIndividual*> childs;
		for (auto& individual : population_vector)
		{
			if (rand.randomFloat() < 0.6)
			{
				EIndividual* other_parent = population_vector.at(rand.randomInteger(0, population_size - 1));
				childs.push_back(individual->crossover(other_parent));
			}
		}
		for (int i = 0; i < childs.size(); ++i)
		{
			int elem = rand.randomInteger(0, population_size - 1);
			delete population_vector.at(elem);
			population_vector[elem] = childs.at(i);
		}
		childs.clear();

		// Mutation
		for (auto& individual : population_vector)
		{
			if (rand.randomFloat() < 0.10)
				individual->mutate();
		}
	}
}
