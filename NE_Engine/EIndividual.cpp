#include "EIndividual.h"



EIndividual::EIndividual()
	:fitness(0)
{
}


EIndividual::~EIndividual()
{
}

bool EIndividual::has_better_fitness(const EIndividual* other) const
{
	return fitness >= other->fitness;
}
