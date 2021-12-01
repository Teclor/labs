#include "lab6.h"
#include <QDebug>
lab6::lab6(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.QuitBtn, SIGNAL(clicked()), qApp, SLOT(quit()));
	QObject::connect(ui.Convert, SIGNAL(clicked()), this, SLOT(Convert()));
}

void lab6::Convert() {
	QString in = ui.inputForm->text();
	QString out;
	bool check;
	int inSys = ui.inSys->currentText().toInt();
	int outSys = ui.outSys->currentText().toInt();
	out = QString::number(in.toInt(&check, inSys), outSys);
	if (check) ui.output->setText(QString("Calculated result: " + out));
	else ui.output->setText(QString("Invalid input!"));
}