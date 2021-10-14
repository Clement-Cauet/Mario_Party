#include "De.h"
#include <QRandomGenerator>

De::De(){
	this->scoreDe = 0;
}

De::De(int nbr){
	this->valueDe = nbr;
	this->scoreDe = 0;
}

int De::getValueDe(){
	return this->valueDe;
}

int De::getScoreDe()
{
	return this->scoreDe;
}

void De::lancerDe(){
	this->valueDe = QRandomGenerator::global()->bounded(1, 7);
	this->scoreDe += this->valueDe;
}

void De::resetDe(){
	this->valueDe = 0;
	this->scoreDe = 0;
}
