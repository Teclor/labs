#include "calc.h"
#include "qobject.h"
#include <QDebug>
calc::calc(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	QPushButton *btnArr[5][5] = {
		 {ui.e_btn , ui.pi_btn , ui.g_btn , ui.clear_btn , ui.delete_btn},
		 {ui.num_7 , ui.num_8 , ui.num_9 , ui.result_btn , ui.multiply_btn},
		 {ui.num_4 , ui.num_5 , ui.num_6 , ui.plus_btn , ui.divide_btn},
		 {ui.num_1 , ui.num_2 , ui.num_3 , ui.minus_btn , ui.sqrt_btn},
		 {ui.sign_btn , ui.num_0 , ui.point_btn , ui.factorial_btn , ui.power_btn}
	};

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			connect(btnArr[i][j], SIGNAL(clicked()), this, SLOT(slotButtonClicked()));
		}
	}
}

void calc::slotButtonClicked(){
	QString btnText = qobject_cast<QPushButton*>(sender())->text();
	//��������� ������� ������
	if (btnText == "Clear") {
		buffer.clear(); 
		ui.screen->setText("0");
		ui.history_screen->clear();
		return;
	}
	QString scrText = ui.screen->text();
	if (btnText == "Delete" && scrText.contains(QRegExp("^-?[0-9]+\\.?[0-9]*$"))) {
		scrText.chop(1);
		ui.screen->setText(scrText);
		return;
	}
	if (scrText=="ERROR" || (scrText == "0" && btnText != ".")) scrText = "";
	int len = scrText.length();
	QString last = "";
	if (len > 0) last = scrText.right(1);
	//��������� ����� �����	
	if (len > 0 && btnText == "+/-") if (scrText[0] == '-') scrText.remove(0, 1); else scrText = "-" + scrText;
	//��������� ������� ������ ��� ��������� ������ - ��� ������ ��������
	if (((len == 0 && buffer.size() == 0) ||
		((buffer.size()%2 == 0 && len > 1 && (last == "+" || last == "-" || last == "*" || last == "/" || last == "^")))) &&
		(btnText.contains(QRegExp("[0-9]")) || btnText == "-" || btnText == "e" || btnText == "pi" || btnText == "g")) {
		//�� ������ ����� � ���� ���� ��� ������ 1-� ������� � ��������
		//� ��� ���� ������ ����� ��� "-"
		ui.history_screen->setText(ui.history_screen->text() + scrText);
		if (btnText == "e") scrText = QString::number(M_E); else if (btnText == "pi") scrText = QString::number(M_PI); else if (btnText == "g") scrText = QString::number(G_CONST);
		else
		scrText = btnText; //������� ��, ��� ���� ����������, � ���������� ������� ������
	}
	else if ((scrText + btnText).contains(QRegExp("^-?[0-9]+\\.?[0-9]*$"))) {
		scrText += btnText; //���� ������ ����� - ��������� ������
	}
	else if (scrText.contains(QRegExp("^-?[0-9]+\\.?[0-9]*[SQRT]{0,4}!?$"))) { //��� ������� �����
		if (btnText == "=") {
			if (!buffer.empty()) {
				ui.history_screen->setText(ui.history_screen->text() + scrText);
				if(buffer.back()!="SQRT" && buffer.back() != "!") buffer.push_back(scrText);
				calculate();
			}
			return;
		}
		if (btnText == "*" || btnText == "/" || btnText == "+" || btnText == "-" || btnText == "SQRT" || btnText == "^" || btnText == "!") { //��������� ����������
			if (buffer.empty()) ui.history_screen->clear();
			buffer.push_back(scrText); //�������� � ����� ����� �������
			scrText += btnText; //���������� �������� �� ����.������� ������
			buffer.push_back(btnText); //�������� � ����� ��������
		}
	}

	ui.screen->setText(scrText);

}
//������� ���������� ���� ���������� � �������������� �������
void calc::calculate() {
	try {
		for (int i = 0; i < buffer.size(); i++) {
			if (buffer[i] == "SQRT") {
				//showBuf(0);
				double tmp = qSqrt(buffer[i - 1].toDouble());
				if (!tmp) throw 1;
				buffer[i - 1] = QString::number(tmp); buffer.remove(i); i--;
			}
			else if (buffer[i] == "!") {
				//showBuf(0);
				int tmp = factorial(buffer[i - 1].toDouble());
					buffer[i - 1] = QString::number(tmp); buffer.remove(i); i--;
			}
			else if (buffer[i] == "^") {
				double tmp = qPow(buffer[i - 1].toDouble(), buffer[i + 1].toDouble());
					buffer[i - 1] = QString::number(tmp); buffer.remove(i, 2); i--;
			}
		}
		for (int i = 0; i < buffer.size(); i++) {
			if (buffer[i] == "/") {
				if (buffer[i + 1] == "0") throw 1;
				double tmp = buffer[i - 1].toDouble()/buffer[i+1].toDouble();
					buffer[i - 1] = QString::number(tmp); buffer.remove(i,2); i--;
			}
			else if (buffer[i] == "*") {
				double tmp = buffer[i - 1].toDouble() * buffer[i + 1].toDouble();
					buffer[i - 1] = QString::number(tmp); buffer.remove(i, 2); i--;
			}
		}
		for (int i = 0; i < buffer.size(); i++) {
			if (buffer[i] == "+") {
				double tmp = buffer[i - 1].toDouble() + buffer[i + 1].toDouble();
					buffer[i - 1] = QString::number(tmp); buffer.remove(i, 2); i--;
			}
			else if (buffer[i] == "-") {
				double tmp = buffer[i - 1].toDouble() - buffer[i + 1].toDouble();
					buffer[i - 1] = QString::number(tmp); buffer.remove(i, 2); i--;
			}
		}
		ui.screen->setText(buffer[0]);
		showBuf(0);
		buffer.clear();
	}
	catch (...) {
		ui.screen->setText("ERROR");
		ui.history_screen->clear();
	}
}
//������� ����������
long int factorial(int N)
{
	if (N < 0) return 0;
	if (N == 0) return 1;
	else return N * factorial(N - 1);
}


//����� ������ � �������
void calc::showBuf(int a) {
	for (int i = 0; i < buffer.size(); i++) {
		qDebug() << buffer[i];
	}
	qDebug() << " CURRENT I: " << a;
	qDebug() << "-------------------------------------------\n";
}