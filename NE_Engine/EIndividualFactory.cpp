#include "EIndividualFactory.h"

#include "EAdderIndividual.h"

EIndividualFactory::EIndividualFactory()
	:current_individual_type(NONE)
{
}


EIndividualFactory::~EIndividualFactory()
{
}

EIndividual * EIndividualFactory::generateIndividual()
{
	switch (current_individual_type)
	{
	case EIndividualFactory::NONE:
		return nullptr;
		break;
	case EIndividualFactory::ADDER:
		return new EAdderIndividual();
	default:
		break;
	}
}

void EIndividualFactory::set_individual_type(EIndividualType type)
{
	current_individual_type = type;
}

EIndividualFactory::EIndividualType EIndividualFactory::get_individual_type()
{
	return current_individual_type;
}
