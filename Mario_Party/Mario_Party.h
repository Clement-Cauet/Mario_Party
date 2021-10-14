#pragma once

#include <QtWidgets/QMainWindow>
#include <QTableWidgetItem>
#include <qdebug.h>
#include "De.h"
#include <QStringList>
#include <QAction>
#include <QFormLayout>
#include "De.h"
#include "DeHisto.h"
#include "ui_Mario_Party.h"

class Mario_Party : public QMainWindow
{
    Q_OBJECT

public:
    Mario_Party(QWidget *parent = Q_NULLPTR);

public slots:
	void setLayout(bool visible);
	void layoutDe();
	void layoutDeHisto();

	void jetDeUnique();
	void resetDeUnique();
	void afficheValueDe();
	void afficheScoreDe();

	void jetDeMultiple();
	void resetDeMultiple();
	void afficheTabDe(int nbr);

private:
    Ui::Mario_PartyClass ui;
	De *de;
	DeHisto *dehisto;
};
