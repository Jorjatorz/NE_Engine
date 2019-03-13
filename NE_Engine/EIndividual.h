#pragma once

#include <vector>

// Base class for an evolutionary individual
class EIndividual
{
public:
	EIndividual();
	virtual ~EIndividual();

	virtual void evaluate(const std::vector<double>& params = std::vector<double>()) = 0;
	virtual EIndividual* crossover(const EIndividual* parent2) = 0;
	virtual void mutate() = 0;

	// Returns a copy of the individual
	virtual EIndividual* clone() = 0;

	// Returns true if the individual is better than other (by default maximization)
	bool has_better_fitness(const EIndividual* other) const;

	// Returns the fitness of the individual
	double get_fitness()
	{
		return fitness;
	}

protected:
	double fitness;
};

