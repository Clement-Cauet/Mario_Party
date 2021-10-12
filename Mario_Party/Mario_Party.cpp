#include "De.h"
#include "Mario_Party.h"

Mario_Party::Mario_Party(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	De de;
}

/* Lancer dé unique */
void Mario_Party::jetDeUnique() {
	de->lancerDe();
	afficheValueDe();
	afficheScoreDe();
}

void Mario_Party::resetDeUnique() {
	de->resetDe();
	afficheValueDe();
	afficheScoreDe();
}

void Mario_Party::afficheValueDe(){
	int valueDe = de->getValueDe();
	QString str = "";
	str = QString::number(valueDe);
	ui.result->setText(str);
}

void Mario_Party::afficheScoreDe(){
	int scoreDe = de->getScoreDe();
	QString str = "";
	str = QString::number(scoreDe);
	ui.score->setText(str);
}

/* Lancer dé multiple */
