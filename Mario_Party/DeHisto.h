#pragma once

#include "De.h"

class DeHisto : public De
{
	int tab[7];

public:
	DeHisto();
	void jet();
	void jet(int nbr);
	int getValueTab(int nbr);
};