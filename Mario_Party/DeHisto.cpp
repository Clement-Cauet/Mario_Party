#include "dehisto.h"
#include <qDebug>

DeHisto::DeHisto(){

}

void DeHisto::jet(){
	this->lancerDe();
	this->getValueDe();
}

void DeHisto::jet(int n){
	for (int i = 0; i < n; i++){
		this->lancerDe();
		tab[i] = this->getValueDe();
	}
}