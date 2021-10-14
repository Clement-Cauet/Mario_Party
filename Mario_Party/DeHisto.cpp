#include "dehisto.h"
#include <qDebug>

DeHisto::DeHisto(){

}

void DeHisto::jet(){
	lancerDe();
	this->getValueDe();
}

void DeHisto::jet(int nbr){
	for (int i = 0; i < nbr; i++){
		lancerDe();
		this->tab[i] = this->getValueDe();
		this->scoreTab += this->tab[i];
	}
}

int DeHisto::getValueTab(int nbr) {
	return this->tab[nbr];
}

int DeHisto::getScoreTab() {
	return this->scoreTab;
}

void DeHisto::resetTab() {
	this->scoreTab = 0;
}


