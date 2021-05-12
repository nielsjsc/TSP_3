#include "climb_chromosome.hh"


void ClimbChromosome::mutate() {
	double f1 = this->get_fitness();
	ClimbChromosome *clone_ = this->clone();
	std::uniform_int_distribution<int> dist(0, clone_->order_.size() - 1);
	int p = dist(generator_);
	if (p == 0) {
		std::swap(clone_->order_[p], clone_->order_[clone_->order_.size() - 1]);
	}
	else {
		std::swap(clone_->order_[p], clone_->order_[p-1]);
	}
	double f2 = this->get_fitness();
	if (p == clone_->order_.size() - 1) {
		std::swap(clone_->order_[p], clone_->order_[0]);
	}
	else
	{
		std::swap(clone_->order_[p], clone_->order_[p+1]);
	}
	double f3 = this->get_fitness();
	if (f1 >= f2 && f1 >= f3) return;
	if (f2 >= f1 && f2 >= f3) {
		if (p == 0) {
			std::swap(order_[p], order_[order_.size() - 1]);
		}
		else {
			std::swap(order_[p], order_[p - 1]);
		}
		return;
	}
	if (f3 >= f1 && f3 >= f2) {
		if (p == order_.size() - 1) {
			std::swap(order_[p], order_[0]);
		}
		else
		{
			std::swap(order_[p], order_[p + 1]);
		}
	}
}



