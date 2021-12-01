#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

int Direction(int A0, int A1, int B0, int B1, int C0, int C1) {
	return (B0 - A0) * (C1 - B1) - (B1 - A1) * (C0 - B0);
}

void Jarvis()
{
	ifstream inFile("input.txt");
	int n;
	char tmpStr[255];
	inFile.getline(tmpStr, 20);
	n = atoi(tmpStr);
	int** arr = new int *[n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[2];

	for (int i = 0; i < n; i++)
	{
		inFile.getline(tmpStr,20);
		arr[i][0] = atoi(strtok(tmpStr, " "));
		arr[i][1] = atoi(strtok(NULL, " "));
	}

	vector <int> P(n);
	for (int i = 0; i < n; i++)
		P[i] = i;
	for (int i = 1; i < n; i++)
		if (arr[P[i]][0] < arr[P[0]][0])
		{
			swap(P[0],P[i]);
		}
	vector <int> H;
	H.push_back(P[0]);
	P.erase(P.begin());
    vector<int>(P).swap(P);
	P.push_back(H[0]);
	while (true)
	{
		int right = 0;
		for (int i = 1; i < P.size(); i++) {
			if (Direction(arr[H[H.size()-1]][0], arr[H[H.size()-1]][1], arr[P[right]][0], arr[P[right]][1], arr[P[i]][0], arr[P[i]][1]) < 0)
				right = i;
		}
		if (P[right] == H[0])
			break;
		else
		{
			H.push_back(P[right]);
            P.erase(P.begin() + right);
            vector<int>(P).swap(P);
		}

	}
	ofstream outFile("output.txt");
	outFile << "Координаты точек, в порядке их соединения для построения МВО" <<endl;
	for (int i = 0; i < H.size(); i++)
		outFile << arr[H[i]][0] << " " << arr[H[i]][1] <<endl;
    cout << "Solution in output.txt";
}

int main()
{
	Jarvis();
	return 0;
}
