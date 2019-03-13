#include "EWorld.h"



EWorld::EWorld()
	:simulation_running(false),
	population_size(0)
{
}


EWorld::~EWorld()
{
}

std::string EWorld::read_command()
{
	// Get and erase command
	commands_mutex.lock();

	std::string command = commands_list.front();
	commands_list.pop_front();

	commands_mutex.unlock();

	return command;
}

void EWorld::process_command(std::string command)
{
	// Process command
	if (command == "stop" || command == "exit")
	{
		simulation_running = false;
	}
}
