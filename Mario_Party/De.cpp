#include "De.h"
#include <QRandomGenerator>

De::De(){

}

De::De(int nbr){
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
