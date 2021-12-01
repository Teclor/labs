#pragma once

#include <QtWidgets/QWidget>
#include "ui_lab6.h"

class lab6 : public QWidget
{
	Q_OBJECT

public:
	lab6(QWidget *parent = Q_NULLPTR);

private:
	Ui::lab6Class ui;

public slots:
	void Convert();
};
