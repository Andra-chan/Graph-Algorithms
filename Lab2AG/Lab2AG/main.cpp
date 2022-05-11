#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("graf.txt");



int main() {
	int nr_noduri = 0;
	fin >> nr_noduri;
	cout << "In total avem " << nr_noduri << " noduri." << "\n";

	int x, y;
	int a[100][100] = { 0 };
	cout << "Graful nostru este:" << endl;
	// matricea de adiacenta
	while (fin >> x >> y)
	{
		cout << x << " " << y << "\n";
		a[x][y] = 1;
		a[y][x] = 1;
	}
	cout << "\n";
	cout << "Matricea de adiacenta este:" << endl;
	// afisare matricea de adiacenta
	for (int i = 1; i <= nr_noduri; i++)
	{
		for (int j = 1; j <= nr_noduri; j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";

}