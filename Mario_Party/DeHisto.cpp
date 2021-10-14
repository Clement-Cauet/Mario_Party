#include "dehisto.h"
#include <qDebug>

DeHisto::DeHisto(){

}

void DeHisto::jet(){
	this->lancerDe();
	this->getValueDe();
}

void DeHisto::jet(int nbr){
	for (int i = 0; i < nbr; i++){
		de->lancerDe();
		this->tab[i] = this->getValueDe();
	}
}

int DeHisto::getValueTab(int nbr) {
	return this->tab[nbr];
}
