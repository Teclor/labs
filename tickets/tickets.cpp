#include "tickets.h"
#include <QtWidgets/QApplication>
#include <QAction>
tickets::tickets(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.QuitAction, &QAction::triggered, qApp, QApplication::quit);
	QObject::connect(ui.QuitMain, SIGNAL(triggered()), this, SLOT(changeFrameMain()));
	QObject::connect(ui.buy, SIGNAL(triggered()), this, SLOT(changeFrameBuy()));
	QObject::connect(ui.refund, SIGNAL(triggered()), this, SLOT(changeFrameRefund()));
	QObject::connect(ui.schedule, SIGNAL(triggered()), this, SLOT(changeFrameSchedule()));
	QObject::connect(ui.FAQ, SIGNAL(triggered()), this, SLOT(changeFrameFAQ()));
	QObject::connect(ui.buyPageBtn, SIGNAL(clicked()), this, SLOT(changeFrameBuy()));
	ui.stackedWidget->setCurrentIndex(4);

}

void tickets::changeFrameMain() {
	ui.stackedWidget->setCurrentIndex(4);
}

void tickets::changeFrameBuy() {
	ui.stackedWidget->setCurrentIndex(0);
}
void tickets::changeFrameRefund() {
	ui.stackedWidget->setCurrentIndex(1);
}
void tickets::changeFrameSchedule() {
	ui.stackedWidget->setCurrentIndex(2);
}
void tickets::changeFrameFAQ() {
	ui.stackedWidget->setCurrentIndex(3);
}