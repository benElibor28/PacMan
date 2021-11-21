#pragma once
#include "Includes.h"
#include "Vertice.h"
#include <vector>
#include <queue>
#include "Rute.h"
#include "game.h"
#define MAX 10005 
#define Node pair< int , int > 
#define INF 1<<30
using namespace std;
struct cmp {
	bool operator() (const Node& a, const Node& b) {
		return a.second > b.second;
	}
};
class Dijkstra
{
private:
	
	vector< Node > ady[MAX]; 
	int distancia[MAX];       
	bool visitado[MAX];      
	priority_queue< Node, vector<Node>, cmp > Q; 
	int V;                     
	int previo[MAX];
	vector<int> v;
public:
	void RunDijkstra(int,float, float, float, float, bool, bool);
	void LLenarVerticesNivel1(int);
	void init();
	void relajacion(int, int, int);
	void print(int);
	void dijkstra(int,int);
	void LlenarRuta(int, float,float);
	int BuscarPacman(float,float, bool, bool);
	int BuscarBlinky(float, float);
	
};

