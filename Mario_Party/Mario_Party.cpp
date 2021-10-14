#include "Mario_Party.h"

Mario_Party::Mario_Party(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	de = new De();
	dehisto = new DeHisto();

	/* Barre de menu */
	// Onglet Fichier
	QMenu *menuFichier = new QMenu("Fichier", ui.menuBar);
	QAction *actionQuitter = new QAction("Quitter", menuFichier);
	menuFichier->addAction(actionQuitter);

	// Onglet Choisir
	QMenu *menuChoisir = new QMenu("Choisir", ui.menuBar);
	QAction *actionD = new QAction("Dé", menuChoisir);
	QAction *actionD_Histo = new QAction("DéHisto", menuChoisir);
	menuChoisir->addAction(actionD);
	menuChoisir->addAction(actionD_Histo);

	setLayout(false);
	ui.error1->setVisible(false);
	ui.error2->setVisible(false);

	QObject::connect(actionQuitter, SIGNAL(triggered()), this, SLOT(close()));
	QObject::connect(actionD, SIGNAL(triggered()), this, SLOT(layoutDe()));
	QObject::connect(actionD_Histo, SIGNAL(triggered()), this, SLOT(layoutDeHisto()));

	resetDeUnique();
	resetDeMultiple();
}

void Mario_Party::setLayout(bool visible) {
	if (visible == false) {
		ui.layoutD->setVisible(true);
		ui.layoutD_Histo->setVisible(false);
	}else{
		ui.layoutD->setVisible(false);
		ui.layoutD_Histo->setVisible(true);
	}
}

void Mario_Party::layoutDe() {
	setLayout(false);
}

void Mario_Party::layoutDeHisto() {
	setLayout(true);
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
void Mario_Party::jetDeMultiple() {
	if (ui.lineEdit->text().size() > 0) {
		QString str = ui.lineEdit->text();
		int nbr = str.toInt();
		if (nbr <= 0 || nbr > 7) {
			ui.error1->setVisible(true);
			ui.error2->setVisible(false);
		}
		else {
			ui.error1->setVisible(false);
			ui.error2->setVisible(false);
			dehisto->jet(nbr);
			afficheTabDe(nbr);
		}
	} else {
		ui.error2->setVisible(true);
		ui.error1->setVisible(false);
	}
}

void Mario_Party::afficheTabDe(int nbr) {
	// Création du tableau
	ui.tableWidget->setRowCount(nbr);
	ui.tableWidget->setColumnCount(1);;
	ui.tableWidget->setHorizontalHeaderLabels(QStringList{"Valeur"});

	// Ajout des valeurs des dés dans le tableau
	for (int i = 0; i < nbr; i++) {
		for (int j = 0; j < 1; j++) {
			int valueTab = dehisto->getValueTab(i);
			auto data = new QTableWidgetItem(QString::number(valueTab));
			data->setTextAlignment(Qt::AlignCenter);
			ui.tableWidget->setItem(i, j, data);
		}
	}
	afficheScoreTab();
}

void Mario_Party::afficheScoreTab() {
	int scoreTab = dehisto->getScoreTab();
	QString str = "";
	str = QString::number(scoreTab);
	ui.score_2->setText(str);
}

void Mario_Party::resetDeMultiple() {
	dehisto->resetTab();
	afficheScoreTab();
	ui.tableWidget->setRowCount(0);
	ui.tableWidget->setColumnCount(0);
	ui.lineEdit->text() = "";
}
