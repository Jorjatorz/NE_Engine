#pragma once

#include <vector>
#include <list>
#include <mutex>

#include "EIndividualFactory.h"

// Base class for all the different worlds
class EWorld
{
public:
	EWorld();
	virtual ~EWorld();

	// Main function. Executes the simulation of the world
	virtual void simulate() = 0;

protected:
	// True if simulation is running
	bool simulation_running;
	// Factory for individual generation
	EIndividualFactory individual_factory;
	// Population vector
	std::vector<EIndividual*> population_vector;
	int population_size;
	
	// Command parser----------------------------------------
	// List containing the commands received. Will be modified concurrently
	std::list<std::string> commands_list;
	std::mutex commands_mutex;
	// List containing the JSON responds of the commands. Will be modified concurrently
	std::list<std::string> responses_list;
	std::mutex responses_mutex;
	// Read and processes the commands in the commands list.
	virtual std::string read_command();
	virtual void process_command(std::string command);
};

