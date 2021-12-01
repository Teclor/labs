#include "Lab5.h"
#include <QtWidgets/QPushButton> 
#include <QtWidgets/QInputDialog> 
#include <QtWidgets/QVBoxLayout> 
#include <QVector>
#include <QString>

Lab5::Lab5(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	resize(640, 360);

	ui.outHeadWidget->setStyleSheet("background-color: yellow");

	QPushButton* getValuesB = new QPushButton("Calculate the result", this);
	getValuesB->resize(150, 30);
	getValuesB->move(70, 200);
	QObject::connect(getValuesB, SIGNAL(clicked()), this, SLOT(readValues()));

	QPushButton* quit = new QPushButton("Quit", this);
	quit->resize(80, 30);
	quit->setFont(QFont("Times", 18, QFont::Bold));
	quit->move(280, 330);
	QObject::connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

}



//часть, отвечающая за многочлены
class Polynomial {
protected:
	unsigned int degree;
	QVector <int> pol;
public:
	Polynomial(const int pdegree) {
		degree = pdegree;
		pol.resize(degree + 1);
	}
	int showmember(int a) { return pol.at(a); }
	int showdegree() { return degree; }
	void putadd(unsigned int b, int value) { pol[b] += value; }
	void elemfill(int value, int i);
	QString getPolynomial();
	Polynomial operator *(Polynomial& factor);
	~Polynomial() {}
};


void Polynomial::elemfill(int value, int i) {
	pol[i] = value;
}

QString Polynomial::getPolynomial() {
	QString polynom;
	for (int i = degree; i >= 0; i--) {
		if (i != 0)
			polynom += QString::number(pol.at(degree-i)) + "x^" + QString::number(i) + '+';
		else polynom += QString::number(pol.at(degree-i));
	}
	return polynom;
}


Polynomial Polynomial::operator * (Polynomial& factor) {
	unsigned int n = degree + factor.showdegree();
	Polynomial result(n);
	unsigned int degleft = degree;
	unsigned int degright = factor.showdegree();
	for (int i = degleft; i >= 0; i--) {
		for (int j = degright; j >= 0; j--) {
			int temp = pol.at(i) * factor.showmember(j);
			result.putadd(i + j, temp);
		}
	}
	return result;
}

// слот и функция для подсчета
void Lab5::readValues() {
	QString pol1 = ui.input1->text();
	QString pol2 = ui.input2->text();
	QStringList list1 = pol1.split(" ", QString::SkipEmptyParts);
	QStringList list2 = pol2.split(" ", QString::SkipEmptyParts);
	Calculate(list1, list2);

}

void Lab5::Calculate(QStringList list1, QStringList list2) {
	int deg1 = list1[0].toInt();
	int deg2 = list2[0].toInt();
	Polynomial pol1(deg1);
	Polynomial pol2(deg2);
	for (int i = 0; i <= deg1; i++) {
		pol1.elemfill(list1[i + 1].toInt(), i);
	}
	for (int i = 0; i <= deg2; i++) {
		pol2.elemfill(list2[i + 1].toInt(), i);
	}
	Polynomial result(deg1 + deg2);
	result = pol1 * pol2;
	ui.output->setText(QString("Calculated result: " + result.getPolynomial()));
}