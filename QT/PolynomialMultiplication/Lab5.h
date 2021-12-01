#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Lab5.h"
#include <QtWidgets/QLabel> 
class Lab5 : public QMainWindow
{
	Q_OBJECT

public:
	Lab5(QWidget *parent = Q_NULLPTR);
	void Calculate(QStringList list1, QStringList list2);
private:
	Ui::Lab5Class ui;


public slots:
	void readValues();

};
