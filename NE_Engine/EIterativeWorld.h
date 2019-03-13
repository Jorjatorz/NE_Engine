#pragma once

#include "EWorld.h"


class EIterativeWorld :
	public EWorld
{
public:
	EIterativeWorld(int max_iterations);
	~EIterativeWorld();

	// Inherited via EWorld
	virtual void simulate() override;

private:
	// Number of iterations to simulate
	int max_iterations;
	// Current number of iterations
	int current_iteration;
};

