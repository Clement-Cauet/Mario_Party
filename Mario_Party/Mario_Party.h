#pragma once

#include <QtWidgets/QMainWindow>
#include <qdebug.h>
#include "De.h"
#include "DeHisto.h"
#include "ui_Mario_Party.h"

class Mario_Party : public QMainWindow
{
    Q_OBJECT

public:
    Mario_Party(QWidget *parent = Q_NULLPTR);

public slots:
	void jetDeUnique();
	void resetDeUnique();
	void afficheValueDe();
	void afficheScoreDe();

private:
    Ui::Mario_PartyClass ui;
	De *de;
	DeHisto *dehisto;
};
