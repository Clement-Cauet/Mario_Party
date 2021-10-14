#pragma once

#include "De.h"

class DeHisto : public De
{
	int tab[7];
	int scoreTab;

public:
	DeHisto();
	void jet();
	void jet(int nbr);
	void resetTab();

	int getValueTab(int nbr);
	int getScoreTab();
};