#include "EIndividualSelector.h"

#include "EIndividual.h"
#include "RandomGenerator.h"

void EIndividualSelector::tournament_selection(int k, std::vector<EIndividual*>& population)
{
	RandomGenerator rand;
	std::vector<EIndividual*> newPopulation;
	for (int i = 0; i < population.size(); ++i)
	{
		EIndividual* best = population.at(rand.randomInteger(0, population.size() - 1));
		for (int j = 1; j < k; ++j)
		{
			EIndividual* oponent = population.at(rand.randomInteger(0, population.size() - 1));
			if (oponent->has_better_fitness(best))
			{
				best = oponent;
			}
		}
		newPopulation.push_back(best->clone());
	}

	for (int i = 0; i < population.size(); ++i)
	{
		delete population.at(i);
	}
	population.clear();
	population = std::move(newPopulation);
}
