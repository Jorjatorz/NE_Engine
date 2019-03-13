#pragma once

#include <vector>

class EIndividual;

// Auxiliary functions to select individuals of a population
namespace EIndividualSelector
{
	// Given a vector of individuals return a vector in-place with a new population from a tournament selection of K individuals
	// Deletes the old vector components
	void tournament_selection(int k, std::vector<EIndividual*>& population);
};

