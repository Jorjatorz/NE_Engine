#include "EWorld.h"



EWorld::EWorld()
	:simulation_running(false),
	population_size(0)
{
}


EWorld::~EWorld()
{
}

void EWorld::read_process_commands()
{
	// Get and erase command
	commands_mutex.lock();
	std::string command = commands_list.front();
	commands_list.pop_front();
	commands_mutex.unlock();

	// Process command
	if (command == "stop")
	{
		simulation_running = false;
	}
}
