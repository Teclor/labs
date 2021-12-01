#include "Lab5.h" 
#include <QtWidgets/QApplication> 
#include <QtWidgets/QTextEdit> 
#include <QtWidgets/QLabel> 


int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	Lab5 w;
	w.show();
	return app.exec();
	/*




	//quit->show(); 
	QPushButton* First = new QPushButton("Enter the 1st", &w);
	First->resize(100, 20);
	First->move(100, 230);
	QObject::connect(First, SIGNAL(clicked()),qApp, SLOT(read(inputForm)));
	

	

	int stats[7] = { 1,2,3,4,5,6,7 };


	w.setCentralWidget(centralWidget);

	QLabel* label[7];

	for (int i = 0; i < 7; i++) {
		label[i] = new QLabel(QString("S: %1").arg(stats[i]));
		layout->addWidget(label[i]);
	}
	*/

	


}