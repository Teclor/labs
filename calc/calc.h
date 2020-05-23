#pragma once

#include <QtWidgets/QMainWindow>
#include <QtMath>
#include <QVector>
#include "ui_calc.h"
constexpr auto G_CONST = 9.8;
class calc : public QMainWindow
{
	Q_OBJECT

public:
	calc(QWidget *parent = Q_NULLPTR);
	void calculate();
private:
	Ui::calcClass ui;
	QVector <QString> buffer;
	QVector <bool> bufferStatus;
	void showBuf(int a);
public slots:
	void slotButtonClicked();
};

long int factorial(int N);