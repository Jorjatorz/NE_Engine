#pragma once

#include "EIndividual.h"
#include "NEATNN.h"


class EAdderIndividual :
	public EIndividual
{
public:
	EAdderIndividual();
	EAdderIndividual(const EAdderIndividual& other);
	~EAdderIndividual();

	// Inherited via EIndividual
	virtual void evaluate(const std::vector<double>& params) override;
	virtual EAdderIndividual* crossover(const EIndividual* parent2) override;
	virtual void mutate() override;
	virtual EAdderIndividual* clone() override;

private:
	NEATNN nn;
};

