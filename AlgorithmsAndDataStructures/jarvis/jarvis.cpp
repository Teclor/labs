#include <conio.h>
#include <iostream>
#include <fstream>
using namespace std;

#define WHITE 0
#define GREY 1
#define BLACK 2

int n, e;
int capacity[100][100], flow[100][100], colours[100], pathArr[100];
int startPoint, endPoint;
int numsQueue[102];

void enqueue(int x)
{
	numsQueue[endPoint] = x;
	endPoint++;
	colours[x] = GREY;
}
int dequeue()
{
	int x = numsQueue[startPoint];
	startPoint++;
	colours[x] = BLACK;
	return x;
}

int bfs(int start, int end)
{
	int u, v;
	for (u = 0; u < n; u++)
		colours[u] = WHITE;

	startPoint = 0;
	endPoint = 0;
	enqueue(start);
	pathArr[start] = -1;
	while (startPoint != endPoint)
	{
		u = dequeue();

		for (v = 0; v < n; v++)
		{
			if (colours[v] == WHITE && (capacity[u][v] - flow[u][v]) > 0) {
				enqueue(v);
				pathArr[v] = u;
			}
		}
	}
	if (colours[end] == BLACK)
		return 0;
	else return 1;
}

int max_flow(int source, int stock)
{
	int i, j, u;
	int maxflow = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			flow[i][j] = 0;
	}
	while (bfs(source, stock) == 0)
	{
		int delta = 10000;
		for (u = n - 1; pathArr[u] >= 0; u = pathArr[u])
		{
			delta = min(delta, (capacity[pathArr[u]][u] - flow[pathArr[u]][u]));
		}
		for (u = n - 1; pathArr[u] >= 0; u = pathArr[u])
		{
			flow[pathArr[u]][u] += delta;
			flow[u][pathArr[u]] -= delta;
		}
		maxflow += delta;
	}
	return maxflow;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream fin("input.txt");
	fin >> n;
	cout << "Количество вершин: " << n << endl;
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			fin >> capacity[i][j];
	}

	cout << "Максимальный поток: " << max_flow(0, n - 1) << endl;

	return 0;
}
