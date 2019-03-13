#include "EAdderIndividual.h"

#include <iostream>

EAdderIndividual::EAdderIndividual()
	:nn(1, 1)
{
}

EAdderIndividual::EAdderIndividual(const EAdderIndividual& other)
{
	fitness = other.fitness;
	nn = other.nn;
}


EAdderIndividual::~EAdderIndividual()
{
}

void EAdderIndividual::evaluate(const std::vector<double>& params)
{
	nn.execute(params);

	double out = nn.getOutput().front();

	if (int(out) == int(params.front()) + 1)
	{
		fitness = 1;
	}
	else
	{
		fitness = 0;
	}

}

EAdderIndividual* EAdderIndividual::crossover(const EIndividual* parent2)
{
	EAdderIndividual* child = new EAdderIndividual();
	child->nn = nn.crossOver(static_cast<const EAdderIndividual*>(parent2)->nn);

	return child;
}

void EAdderIndividual::mutate()
{
	nn.mutate();
}

EAdderIndividual* EAdderIndividual::clone()
{
	return new EAdderIndividual(*this);
}
