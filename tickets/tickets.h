#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_tickets.h"

class tickets : public QMainWindow
{
	Q_OBJECT

public:
	tickets(QWidget* parent = Q_NULLPTR);

private:
	Ui::ticketsClass ui;

public slots:
	void changeFrameMain();
	void changeFrameBuy();
	void changeFrameRefund();
	void changeFrameFAQ();
	void changeFrameSchedule();
};
