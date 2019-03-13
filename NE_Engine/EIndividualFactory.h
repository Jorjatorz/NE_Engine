#pragma once

class EIndividual;

// Factory class for the different types of individuals
class EIndividualFactory
{
public:
	enum EIndividualType
	{
		NONE,
		ADDER
	};

	EIndividualFactory();
	~EIndividualFactory();

	// Generates a new individual in heap
	EIndividual* generateIndividual();

	//Set/Get the current individual type
	void set_individual_type(EIndividualType type);
	EIndividualType get_individual_type();

private:
	EIndividualType current_individual_type;
};

