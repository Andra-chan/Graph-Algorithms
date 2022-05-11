#include <iostream>
#include <fstream>
#include <vector>

int frunza_minima(const std::vector<int>& parinte, std::vector<int> &frecventa)		// afla codificare Pufer
{
	for (unsigned i = 0; i < size(parinte); i++)
		if (frecventa[i] == 0) {
			frecventa[parinte[i]]--;
			frecventa[i]--;
			return i;
		}
	return -1;
}

int main(int argc, char* argv[])
{
	std::ifstream fin("in.txt");
	std::ofstream fout("out.txt");
	int numar;
	fin >> numar;								// numarul de noduri al arborelui
	std::vector<int> parinte(numar);			// parintele unui nod
	std::vector<int> frecventa(numar);			// frecventa de aparitie a unui nod diferit de radacina arborelui(retine la ce nod am ajuns)
	std::vector<std::pair<int, int>> frunza;
	for (unsigned i = 0; i < numar; i++) {
		fin >> parinte[i];
		if (parinte[i] != -1) frecventa[parinte[i]]++;		// daca citim un parinte care nu este radacina arborelui, crestem frecventa
	}
	fout << size(parinte) - 1 << std::endl;					// in codificare Pufer avem numar-1 elemente
	for (int i = 0; i < size(parinte) - 1; i++)
	{
		fout << parinte[frunza_minima(parinte, frecventa)] << " ";		// cu ajutorul functiei frunza_minima() calculam codificarea
	}
	fin.close();
	fout.close();
	return 0;
}