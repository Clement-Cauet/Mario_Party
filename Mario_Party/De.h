#pragma once

class De {

public:
	De();
	De(int nbr);

	int getValueDe();
	int getScoreDe();
	void lancerDe();
	void resetDe();

private:
	int valueDe;
	int scoreDe;
};