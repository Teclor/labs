#include "tickets.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	tickets w;
	w.show();
	return a.exec();
}
