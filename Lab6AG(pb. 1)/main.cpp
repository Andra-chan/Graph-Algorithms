#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool sigur(vector<vector<int>>& graf, int* pointer_noduri, int culoare, int nod_curent) {
	for (auto& nod : graf[nod_curent]) {
		if (pointer_noduri[nod] == culoare) {		// daca nodul la care avem ponter are culoare, return false
			return false;
		}
	}
	return true;
}


bool colorare_backtracking(vector<vector<int>>& graf, int* pointer_noduri, int numar_cromatic, int nod_curent, int N) {
	if (nod_curent == N) {		// ne aflam la ultimul nod
		return true;
	}
	// se va opri cand toate nodurile au culoare
	for (int color = 0; color < numar_cromatic; color++) {
		if (sigur(graf, pointer_noduri, color, nod_curent)) {		// daca nodul curent nu are culoare
			pointer_noduri[nod_curent] = color;			// ii dam o culoare(un numar de culoare)
			if (colorare_backtracking(graf, pointer_noduri, numar_cromatic, nod_curent + 1, N)) {		// backtracking la urmatorul nod
				return true;
			}
			pointer_noduri[nod_curent] = -1;		// resetam pointer-ul
		}
	}
	return false;
}


int main()
{

	ifstream fin("in.txt");
	ofstream fout("out.txt");
	int N;		// numarul de noduri
	int M;		// numarul de muchii
	fin >> N;
	fin >> M;
	vector<vector<int>> graf(N);		// facem un graf
	for (int i = 0; i < M; i++) {
		int x, y;		// perechea de noduri
		fin >> x;
		fin >> y;
		graf[x].push_back(y);		// facem perechiile in graf
		graf[y].push_back(x);
	}

	int* pointer_noduri = new int[N];		// pointer catre noduri, aici se salveaza culorile fiecarui nod
	for (int i = 0; i < N; i++)
		pointer_noduri[i] = -1;

	int numar_cromatic = 2;		// minim 2 culori
	while (true) {
		if (colorare_backtracking(graf, pointer_noduri, numar_cromatic, 0, N)) {
			break;
		}
		numar_cromatic++;		
	}
	cout << "Numarul cromatic(numarul minim de culori) este: " << numar_cromatic << endl;
	fout << numar_cromatic << endl;
	cout << "Culorile fiecarui nod sunt: ";
	for (int i = 0; i < N; i++) {
		cout << pointer_noduri[i] << " ";
		fout << pointer_noduri[i] << " ";
	}
	delete[] pointer_noduri;
	return 0;
}


