#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Mario_Party.h"

class Mario_Party : public QMainWindow
{
    Q_OBJECT

public:
    Mario_Party(QWidget *parent = Q_NULLPTR);

private:
    Ui::Mario_PartyClass ui;
};
