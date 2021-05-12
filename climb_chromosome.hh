#include "chromosome.hh"
#pragma once
class ClimbChromosome : public Chromosome{
public:
	virtual void mutate();
	virtual ClimbChromosome* clone() const
	{
		return new ClimbChromosome(*this);
	}
	ClimbChromosome(const Cities* citi)
		:Chromosome{ citi } {

	}
	~ClimbChromosome() {}
};
