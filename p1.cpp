#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");

const int oo = (1 << 30);
const int Nmax = 50005;
int V, E, S;
int distanta[Nmax];
bool inCoada[Nmax];
vector<pair<int, int>> graf[Nmax];

struct  compara
{
    bool operator ()(int x, int y)
    {
        return (distanta[x] > distanta[y]);
    }
};

priority_queue<int, vector<int>, compara> coada;

void Dijkstra(int S)
{
    for (int i = 0;i <= V;i++)
        distanta[i] = oo; // Daca nu se schimba, distanta este INF
    distanta[S] = 0;
    coada.push(S);
    inCoada[S] = true;

    while (!coada.empty())
    {
        int nodCurent = coada.top();
        coada.pop();
        inCoada[nodCurent] = false;

        for (unsigned int i = 0;i < graf[nodCurent].size();i++)
        {
            int nodVecin = graf[nodCurent][i].first;
            int cost = graf[nodCurent][i].second;

            if (distanta[nodCurent] + cost < distanta[nodVecin])
            {
                distanta[nodVecin] = distanta[nodCurent] + cost;
                if (!inCoada[nodVecin])
                {
                    coada.push(nodVecin);
                    inCoada[nodVecin] = true;
                }
            }
        }
    }

}

void print()
{
    for (int i = 0;i < V;i++)
        if (distanta[i] != oo) fout << distanta[i] << " ";
        else fout << "INF" << " ";
}

int main(int argc, int * argv[]) {
    // calea fisierului de intrare se afla la argv[1]
    ifstream fin("in.txt");
    // calea fisierului de intrare se afla la argv[1]
    ofstream fout("out.txt");

    // citirea din fisier
    fin >> V >> E >> S;
    // indexare de la 0
    for (int i = 0;i < E;i++)
    {
        // x - nodul sursa al arcului
        // y - nodul destinatie
        // w - ponderea
        int x, y, w;
        fin >> x >> y >> w;
        graf[x].push_back(make_pair(y, w));
    }
    Dijkstra(S);
    print();
    return 0;
}