#pragma once
#include "Vertice.h"
#include "Includes.h"
#include <climits>
#include <iomanip>
#include "game.h"

using namespace std;

class Floyd
{
private:
	int path[109][109];
	int floyd[109][109];
	int cost[109][109];
	Vertice Aristas2[19][19];
	vector<int> V;

public:
	void RunFloyd(int, float, float, float, float,bool,bool);
	void HacerFloyd(int);
	void LLenarVerticesNivel1(int);
	void llamarMatriX();

	int printPath(int path[109][109], int v, int u);
	void printSolution(int cost[109][109], int path[109][109]);
	void FloydWarshell(int adjMatrix[109][109]);
	int BuscarPacman(float, float,bool,bool);
	int BuscarClyde(float, float);
	void LlenarRuta(int);
};

