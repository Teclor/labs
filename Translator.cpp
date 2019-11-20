#include <iostream>
#include <string.h>
#include <map>
#include <fstream>
#include <windows.h>
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool ruscheck = false;
	bool encheck = false;
	string fname;
	int key = 1;
	ifstream engdict;
	ifstream rusdict;
	map <string, string> rus_eng;
	map <string, string> eng_rus;
	map<string, string>::iterator it;
	char tempstr[1024];
	char* context = NULL;

	while (!ruscheck || !encheck) {
		cout << "Выберите действие: \n" <<
			" 1 - Загрузить англо-русский словарь из файла \n" <<
			" 2 - Загрузить русско-английский словарь из файла \n" <<
			" 3 - Загрузить словари из файлов по умолчанию \n"
			" 0 - Завершить программу" << endl;
		cin >> key;
		switch (key) {
		case 1:
			encheck = false;
			cout << "Введите имя файла со словарём. \nСловарь должен содержать английское слово до символа тире и синонимы через запятую: ";
			cin >> fname;
			engdict.open(fname);
			if (!engdict) cout << "Ошибка открытия файла. Попробуйте снова." << endl;
			else
			{
				eng_rus.clear();
				while (!engdict.eof()) {
					engdict.getline(tempstr, 1000);
					string a = strtok_s(tempstr, "-", &context);
					string b = strtok_s(NULL, "-", &context);
					eng_rus.insert(make_pair(a, b));
				}
				encheck = true;
				context = NULL;
			}
			break;
		case 2:
			ruscheck = false;
			cout << "Введите имя файла со словарём. \nСловарь должен содержать английское слово до символа тире и синонимы через запятую: ";
			cin >> fname;
			rusdict.open(fname);
			if (!rusdict) cout << "Ошибка открытия файла. Попробуйте снова." << endl;
			else
			{
				rus_eng.clear();
				while (!rusdict.eof()) {
					rusdict.getline(tempstr, 1000);
					string a = strtok_s(tempstr, "-", &context);
					string b = strtok_s(NULL, "-", &context);
					rus_eng.insert(make_pair(a, b));
				}
				ruscheck = true;
				context = NULL;
			}
			break;
		case 3:
			engdict.open("eng.txt");
			rusdict.open("rus.txt");
			if (!rusdict) cout << "Ошибка открытия файла русского словаря по умолчанию. Попробуйте снова." << endl;
			else
			{
				rus_eng.clear();
				while (!rusdict.eof()) {
					rusdict.getline(tempstr, 1000);
					string a = strtok_s(tempstr, "-", &context);
					string b = strtok_s(NULL, "-", &context);
					rus_eng.insert(make_pair(a, b));
				}
				ruscheck = true;
				rusdict.close();
			}
			if (!engdict) cout << "Ошибка открытия файла английского словаря по умолчанию. Попробуйте снова." << endl;
			else
			{
				eng_rus.clear();
				while (!engdict.eof()) {
					engdict.getline(tempstr, 1000);
					string a = strtok_s(tempstr, "-", &context);
					string b = strtok_s(NULL, "-", &context);
					eng_rus.insert(make_pair(a, b));
				}
				encheck = true;
				engdict.close();
			}
			break;
		case 0: return 0;
		default: cout << "Ошибка! Попробуйте снова!" << endl; break;
		}
	}	

	string word;
	while (key != 0) {
		cout << "Выберите действие: \n" <<
			" 1 - Вывести англо-русский словарь \n" <<
			" 2 - Вывести русско-английский словарь \n" <<
			" 3 - Перевести слово с английского на русский \n"<<
			" 4 - Перевести слово с русского на английский \n"<<
			" 0 - Завершить программу" << endl;
		cin >> key;
		switch (key) {
		case 1: 
			cout << "Словарь переводов с английского на русский:" << endl;
			for (it = eng_rus.begin(); it != eng_rus.end(); it++) cout << " Слово - " << it->first << " | Перевод - " << it->second << endl;
			break;
		case 2:
			cout << "Словарь переводов с русского на английский:" << endl;
			for (it = rus_eng.begin(); it != rus_eng.end(); it++) cout << " Слово - " << it->first << " | Перевод - " << it->second << endl;
			break;
		case 3:	
			cout << "Введите английское слово для перевода: ";
			cin >> word;
			if (eng_rus.find(word) != eng_rus.end())
				cout << "Перевод - " << eng_rus.find(word)->second << endl << endl;
			else
				cout << "Для данного слова перевода не найдено. Попробуйте ещё раз." << endl;
			break;
		case 4: 
			cout << "Введите русское слово для перевода: ";
			cin >> word;
			if (rus_eng.find(word) != rus_eng.end())
				cout << "Перевод - " << rus_eng.find(word)->second << endl << endl;
			else
				cout << "Для данного слова перевода не найдено. Попробуйте ещё раз." << endl;
			break;
		case 0: break;
		default: cout << "Ошибка! Попробуйте снова!" << endl; break;
		}
	}
	return 0;
}
