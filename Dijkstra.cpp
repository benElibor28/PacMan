#include "Dijkstra.h"
Vertice Aristas2[19][19];
Vertice puntosNivel1[12][12];
int Ruta[20];
int cont = 0;
float origenX=0;
float origenY = 0;

void Dijkstra::RunDijkstra(int nivel, float x, float y, float x2, float y2, bool band, bool bandBlin) {
	LLenarVerticesNivel1(nivel);
	int E, origen, destino = 0, peso, inicial;
	V = 109;
	E = 109;
	if (nivel == 1) {
		for (int i = 1; i < 13; i++) {
			for (int j = 1; j < 13; j++) {
				//scanf("%d %d %d" , &origen , &destino , &peso );
				//cout << "origen: "; cin >> origen; cout << "  destino: "; cin >> destino; cout << "  peso: "; cin >> peso;
				//cout << "origen: " << puntosNivel1[i][j].getID(); cout << "  destino: " << puntosNivel1[i][j].getAdy(); cout << "  peso: " << puntosNivel1[i][j].getPeso();
				ady[puntosNivel1[i][j].getID()].push_back(Node(puntosNivel1[i][j].getAdy(), puntosNivel1[i][j].getPeso()));  //consideremos grafo dirigido
				//ady[ destino ].push_back( Node( origen , peso ) ); //grafo no dirigido
			}
		}
	}
	if (nivel == 2) {
		for (int i = 1; i < 14; i++) {
			for (int j = 1; j < 20; j++) {
				//scanf("%d %d %d" , &origen , &destino , &peso );
				//cout << "origen: "; cin >> origen; cout << "  destino: "; cin >> destino; cout << "  peso: "; cin >> peso;
				//cout << "origen: " << Aristas2[i][j].getID(); cout << "  destino: " << Aristas2[i][j].getAdy(); cout << "  peso: " << Aristas2[i][j].getPeso();
				ady[Aristas2[i][j].getID()].push_back(Node(Aristas2[i][j].getAdy(), Aristas2[i][j].getPeso()));  //consideremos grafo dirigido
				//ady[ destino ].push_back( Node( origen , peso ) ); //grafo no dirigido
			}
		}
	}
	///*printf("Ingrese el vertice inicial: ");
	//cin >> inicial;*/
	inicial = BuscarBlinky(x, y);
	//cout << "inicial " << inicial << endl;
	destino = BuscarPacman(x2, y2, band, bandBlin);
	dijkstra(inicial,destino);
}

void Dijkstra::LLenarVerticesNivel1(int nivel){
	if (nivel == 1) {
		Vertice vv;
		vv.setID(1); vv.setAdy(2); vv.setPeso(100); vv.setX(45); vv.setY(135); puntosNivel1[1][1] = vv;
		vv.setID(1); vv.setAdy(6); vv.setPeso(100); vv.setX(135); vv.setY(45); puntosNivel1[1][2] = vv;
		vv.setID(2); vv.setAdy(3); vv.setPeso(200); vv.setX(45); vv.setY(315); puntosNivel1[1][3] = vv;
		vv.setID(2); vv.setAdy(7); vv.setPeso(100); vv.setX(135); vv.setY(135); puntosNivel1[1][4] = vv;
		vv.setID(3); vv.setAdy(4); vv.setPeso(200); vv.setX(45); vv.setY(495); puntosNivel1[1][5] = vv;
		vv.setID(3); vv.setAdy(9); vv.setPeso(100); vv.setX(135); vv.setY(315); puntosNivel1[1][6] = vv;
		vv.setID(4); vv.setAdy(5); vv.setPeso(100); vv.setX(45); vv.setY(585); puntosNivel1[1][7] = vv;
		vv.setID(4); vv.setAdy(11); vv.setPeso(100); vv.setX(135); vv.setY(495); puntosNivel1[1][8] = vv;
		vv.setID(5); vv.setAdy(12); vv.setPeso(100); vv.setX(135); vv.setY(585); puntosNivel1[1][9] = vv;
		vv.setID(6); vv.setAdy(1); vv.setPeso(100); vv.setX(45); vv.setY(45); puntosNivel1[1][10] = vv;
		vv.setID(6); vv.setAdy(7); vv.setPeso(100); vv.setX(135); vv.setY(135); puntosNivel1[1][11] = vv;
		vv.setID(6); vv.setAdy(13); vv.setPeso(200); vv.setX(315); vv.setY(45); puntosNivel1[1][12] = vv;
		vv.setID(7); vv.setAdy(2); vv.setPeso(100); vv.setX(45); vv.setY(135); puntosNivel1[2][1] = vv;
		vv.setID(7); vv.setAdy(8); vv.setPeso(150); vv.setX(135); vv.setY(270); puntosNivel1[2][2] = vv;
		vv.setID(7); vv.setAdy(14); vv.setPeso(150); vv.setX(270); vv.setY(135); puntosNivel1[2][3] = vv;
		vv.setID(7); vv.setAdy(6); vv.setPeso(100); vv.setX(135); vv.setY(45); puntosNivel1[2][4] = vv;
		vv.setID(2); vv.setAdy(1); vv.setPeso(100); vv.setX(45); vv.setY(45); puntosNivel1[2][5] = vv;
		vv.setID(3); vv.setAdy(2); vv.setPeso(200); vv.setX(45); vv.setY(135); puntosNivel1[2][6] = vv;
		vv.setID(4); vv.setAdy(3); vv.setPeso(200); vv.setX(45); vv.setY(315); puntosNivel1[2][7] = vv;
		vv.setID(5); vv.setAdy(4); vv.setPeso(100); vv.setX(45); vv.setY(495); puntosNivel1[2][8] = vv;
		vv.setID(8); vv.setAdy(7); vv.setPeso(150); vv.setX(135); vv.setY(135); puntosNivel1[2][9] = vv;
		vv.setID(8); vv.setAdy(9); vv.setPeso(50); vv.setX(135); vv.setY(315); puntosNivel1[2][10] = vv;
		vv.setID(8); vv.setAdy(18); vv.setPeso(100); vv.setX(270); vv.setY(225); puntosNivel1[2][11] = vv;
		vv.setID(9); vv.setAdy(8); vv.setPeso(50); vv.setX(135); vv.setY(270); puntosNivel1[2][12] = vv;
		vv.setID(9); vv.setAdy(3); vv.setPeso(100); vv.setX(45); vv.setY(315); puntosNivel1[3][1] = vv;

		vv.setID(9); vv.setAdy(10); vv.setPeso(50); vv.setX(135); vv.setY(360); puntosNivel1[3][2] = vv;
		vv.setID(10); vv.setAdy(9); vv.setPeso(50); vv.setX(135); vv.setY(315); puntosNivel1[3][3] = vv;
		vv.setID(10); vv.setAdy(11); vv.setPeso(150); vv.setX(135); vv.setY(495); puntosNivel1[3][4] = vv;
		vv.setID(10); vv.setAdy(20); vv.setPeso(100); vv.setX(225); vv.setY(360); puntosNivel1[3][5] = vv;
		vv.setID(11); vv.setAdy(10); vv.setPeso(150); vv.setX(135); vv.setY(360); puntosNivel1[3][6] = vv;
		vv.setID(11); vv.setAdy(4); vv.setPeso(100); vv.setX(45); vv.setY(495); puntosNivel1[3][7] = vv;
		vv.setID(11); vv.setAdy(12); vv.setPeso(100); vv.setX(135); vv.setY(585); puntosNivel1[3][8] = vv;
		vv.setID(11); vv.setAdy(23); vv.setPeso(150); vv.setX(270); vv.setY(495); puntosNivel1[3][9] = vv;
		vv.setID(12); vv.setAdy(11); vv.setPeso(100); vv.setX(135); vv.setY(495); puntosNivel1[3][10] = vv;
		vv.setID(12); vv.setAdy(25); vv.setPeso(200); vv.setX(315); vv.setY(585); puntosNivel1[3][11] = vv;
		vv.setID(17); vv.setAdy(18); vv.setPeso(50); vv.setX(225); vv.setY(270); puntosNivel1[3][12] = vv;
		vv.setID(17); vv.setAdy(16); vv.setPeso(50); vv.setX(270); vv.setY(225); puntosNivel1[4][1] = vv;
		vv.setID(18); vv.setAdy(17); vv.setPeso(50); vv.setX(225); vv.setY(225); puntosNivel1[4][2] = vv;
		vv.setID(18); vv.setAdy(19); vv.setPeso(50); vv.setX(225); vv.setY(315); puntosNivel1[4][3] = vv;
		vv.setID(18); vv.setAdy(8); vv.setPeso(100); vv.setX(135); vv.setY(270); puntosNivel1[4][4] = vv;
		vv.setID(19); vv.setAdy(18); vv.setPeso(50); vv.setX(225); vv.setY(270); puntosNivel1[4][5] = vv;
		vv.setID(19); vv.setAdy(20); vv.setPeso(50); vv.setX(225); vv.setY(360); puntosNivel1[4][6] = vv;
		vv.setID(19); vv.setAdy(27); vv.setPeso(100); vv.setX(315); vv.setY(315); puntosNivel1[4][7] = vv;
		vv.setID(20); vv.setAdy(19); vv.setPeso(50); vv.setX(225); vv.setY(315); puntosNivel1[4][8] = vv;
		vv.setID(20); vv.setAdy(21); vv.setPeso(50); vv.setX(225); vv.setY(405); puntosNivel1[4][9] = vv;
		vv.setID(20); vv.setAdy(10); vv.setPeso(100); vv.setX(135); vv.setY(360); puntosNivel1[4][10] = vv;
		vv.setID(21); vv.setAdy(20); vv.setPeso(50); vv.setX(225); vv.setY(360); puntosNivel1[4][11] = vv;
		vv.setID(21); vv.setAdy(22); vv.setPeso(50); vv.setX(270); vv.setY(405); puntosNivel1[4][12] = vv;
		vv.setID(14); vv.setAdy(7); vv.setPeso(150); vv.setX(135); vv.setY(135); puntosNivel1[5][1] = vv;


		vv.setID(14); vv.setAdy(16); vv.setPeso(100); vv.setX(270); vv.setY(225); puntosNivel1[5][2] = vv;
		vv.setID(14); vv.setAdy(15); vv.setPeso(50); vv.setX(315); vv.setY(135); puntosNivel1[5][3] = vv;
		vv.setID(16); vv.setAdy(14); vv.setPeso(100); vv.setX(270); vv.setY(135); puntosNivel1[5][4] = vv;
		vv.setID(16); vv.setAdy(17); vv.setPeso(50); vv.setX(225); vv.setY(225); puntosNivel1[5][5] = vv;
		vv.setID(16); vv.setAdy(26); vv.setPeso(50); vv.setX(315); vv.setY(225); puntosNivel1[5][6] = vv;
		vv.setID(22); vv.setAdy(21); vv.setPeso(50); vv.setX(225); vv.setY(405); puntosNivel1[5][7] = vv;
		vv.setID(22); vv.setAdy(28); vv.setPeso(50); vv.setX(315); vv.setY(405); puntosNivel1[5][8] = vv;
		vv.setID(22); vv.setAdy(23); vv.setPeso(100); vv.setX(270); vv.setY(495); puntosNivel1[5][9] = vv;
		vv.setID(23); vv.setAdy(22); vv.setPeso(100); vv.setX(270); vv.setY(405); puntosNivel1[5][10] = vv;
		vv.setID(23); vv.setAdy(11); vv.setPeso(150); vv.setX(135); vv.setY(495); puntosNivel1[5][11] = vv;
		vv.setID(23); vv.setAdy(24); vv.setPeso(50); vv.setX(315); vv.setY(495); puntosNivel1[5][12] = vv;
		vv.setID(13); vv.setAdy(6); vv.setPeso(200); vv.setX(135); vv.setY(45); puntosNivel1[6][1] = vv;
		vv.setID(13); vv.setAdy(15); vv.setPeso(100); vv.setX(315); vv.setY(135); puntosNivel1[6][2] = vv;
		vv.setID(13); vv.setAdy(38); vv.setPeso(200); vv.setX(495); vv.setY(45); puntosNivel1[6][3] = vv;
		vv.setID(15); vv.setAdy(13); vv.setPeso(100); vv.setX(315); vv.setY(45); puntosNivel1[6][4] = vv;
		vv.setID(15); vv.setAdy(14); vv.setPeso(50); vv.setX(270); vv.setY(135); puntosNivel1[6][5] = vv;
		vv.setID(15); vv.setAdy(29); vv.setPeso(50); vv.setX(360); vv.setY(135); puntosNivel1[6][6] = vv;
		vv.setID(26); vv.setAdy(16); vv.setPeso(50); vv.setX(270); vv.setY(225); puntosNivel1[6][7] = vv;
		vv.setID(26); vv.setAdy(27); vv.setPeso(100); vv.setX(315); vv.setY(315); puntosNivel1[6][8] = vv;
		vv.setID(26); vv.setAdy(30); vv.setPeso(50); vv.setX(360); vv.setY(225); puntosNivel1[6][9] = vv;
		vv.setID(27); vv.setAdy(26); vv.setPeso(100); vv.setX(315); vv.setY(225); puntosNivel1[6][10] = vv;
		vv.setID(27); vv.setAdy(19); vv.setPeso(100); vv.setX(225); vv.setY(315); puntosNivel1[6][11] = vv;
		vv.setID(27); vv.setAdy(28); vv.setPeso(100); vv.setX(315); vv.setY(405); puntosNivel1[6][12] = vv;
		vv.setID(27); vv.setAdy(33); vv.setPeso(100); vv.setX(405); vv.setY(315); puntosNivel1[7][1] = vv;
		vv.setID(28); vv.setAdy(27); vv.setPeso(100); vv.setX(315); vv.setY(315); puntosNivel1[7][2] = vv;


		vv.setID(28); vv.setAdy(22); vv.setPeso(50); vv.setX(270); vv.setY(405); puntosNivel1[7][3] = vv;
		vv.setID(28); vv.setAdy(31); vv.setPeso(50); vv.setX(360); vv.setY(405); puntosNivel1[7][4] = vv;
		vv.setID(24); vv.setAdy(23); vv.setPeso(50); vv.setX(270); vv.setY(495); puntosNivel1[7][5] = vv;
		vv.setID(24); vv.setAdy(32); vv.setPeso(50); vv.setX(360); vv.setY(495); puntosNivel1[7][6] = vv;
		vv.setID(24); vv.setAdy(25); vv.setPeso(100); vv.setX(315); vv.setY(585); puntosNivel1[7][7] = vv;
		vv.setID(25); vv.setAdy(24); vv.setPeso(100); vv.setX(315); vv.setY(495); puntosNivel1[7][8] = vv;
		vv.setID(25); vv.setAdy(12); vv.setPeso(200); vv.setX(135); vv.setY(585); puntosNivel1[7][9] = vv;
		vv.setID(25); vv.setAdy(44); vv.setPeso(200); vv.setX(495); vv.setY(585); puntosNivel1[7][10] = vv;
		vv.setID(29); vv.setAdy(15); vv.setPeso(50); vv.setX(315); vv.setY(135); puntosNivel1[7][11] = vv;
		vv.setID(29); vv.setAdy(30); vv.setPeso(100); vv.setX(360); vv.setY(225); puntosNivel1[7][12] = vv;
		vv.setID(29); vv.setAdy(39); vv.setPeso(150); vv.setX(495); vv.setY(135); puntosNivel1[8][1] = vv;
		vv.setID(30); vv.setAdy(29); vv.setPeso(100); vv.setX(360); vv.setY(135); puntosNivel1[8][2] = vv;
		vv.setID(30); vv.setAdy(33); vv.setPeso(100); vv.setX(405); vv.setY(225); puntosNivel1[8][3] = vv;
		vv.setID(30); vv.setAdy(26); vv.setPeso(50); vv.setX(315); vv.setY(135); puntosNivel1[8][4] = vv;
		vv.setID(31); vv.setAdy(28); vv.setPeso(50); vv.setX(315); vv.setY(405); puntosNivel1[8][5] = vv;
		vv.setID(31); vv.setAdy(32); vv.setPeso(100); vv.setX(360); vv.setY(495); puntosNivel1[8][6] = vv;
		vv.setID(31); vv.setAdy(37); vv.setPeso(100); vv.setX(405); vv.setY(405); puntosNivel1[8][7] = vv;
		vv.setID(32); vv.setAdy(31); vv.setPeso(100); vv.setX(360); vv.setY(405); puntosNivel1[8][8] = vv;
		vv.setID(32); vv.setAdy(24); vv.setPeso(50); vv.setX(315); vv.setY(495); puntosNivel1[8][9] = vv;
		vv.setID(32); vv.setAdy(43); vv.setPeso(150); vv.setX(495); vv.setY(495); puntosNivel1[8][10] = vv;
		vv.setID(33); vv.setAdy(30); vv.setPeso(50); vv.setX(360); vv.setY(225); puntosNivel1[8][11] = vv;
		vv.setID(33); vv.setAdy(34); vv.setPeso(50); vv.setX(405); vv.setY(270); puntosNivel1[8][12] = vv;
		vv.setID(34); vv.setAdy(33); vv.setPeso(50); vv.setX(405); vv.setY(225); puntosNivel1[9][1] = vv;
		vv.setID(34); vv.setAdy(35); vv.setPeso(50); vv.setX(405); vv.setY(315); puntosNivel1[9][2] = vv;
		vv.setID(34); vv.setAdy(40); vv.setPeso(100); vv.setX(495); vv.setY(270); puntosNivel1[9][3] = vv;


		vv.setID(35); vv.setAdy(36); vv.setPeso(50); vv.setX(405); vv.setY(360); puntosNivel1[9][4] = vv;
		vv.setID(35); vv.setAdy(27); vv.setPeso(100); vv.setX(315); vv.setY(315); puntosNivel1[9][5] = vv;
		vv.setID(35); vv.setAdy(34); vv.setPeso(50); vv.setX(405); vv.setY(270); puntosNivel1[9][6] = vv;
		vv.setID(36); vv.setAdy(35); vv.setPeso(100); vv.setX(405); vv.setY(315); puntosNivel1[9][7] = vv;
		vv.setID(36); vv.setAdy(42); vv.setPeso(100); vv.setX(495); vv.setY(360); puntosNivel1[9][8] = vv;
		vv.setID(36); vv.setAdy(37); vv.setPeso(50); vv.setX(405); vv.setY(405); puntosNivel1[9][9] = vv;
		vv.setID(37); vv.setAdy(36); vv.setPeso(50); vv.setX(405); vv.setY(360); puntosNivel1[9][10] = vv;
		vv.setID(37); vv.setAdy(31); vv.setPeso(50); vv.setX(360); vv.setY(405); puntosNivel1[9][11] = vv;
		vv.setID(38); vv.setAdy(13); vv.setPeso(200); vv.setX(315); vv.setY(45); puntosNivel1[9][12] = vv;
		vv.setID(38); vv.setAdy(39); vv.setPeso(100); vv.setX(495); vv.setY(135); puntosNivel1[10][1] = vv;
		vv.setID(38); vv.setAdy(45); vv.setPeso(100); vv.setX(585); vv.setY(45); puntosNivel1[10][2] = vv;
		vv.setID(39); vv.setAdy(38); vv.setPeso(100); vv.setX(495); vv.setY(45); puntosNivel1[10][3] = vv;
		vv.setID(39); vv.setAdy(29); vv.setPeso(150); vv.setX(360); vv.setY(135); puntosNivel1[10][4] = vv;;
		vv.setID(39); vv.setAdy(46); vv.setPeso(100); vv.setX(585); vv.setY(135); puntosNivel1[10][5] = vv;
		vv.setID(39); vv.setAdy(40); vv.setPeso(150); vv.setX(495); vv.setY(270); puntosNivel1[10][6] = vv;
		vv.setID(40); vv.setAdy(39); vv.setPeso(150); vv.setX(495); vv.setY(135); puntosNivel1[10][7] = vv;
		vv.setID(40); vv.setAdy(34); vv.setPeso(100); vv.setX(405); vv.setY(270); puntosNivel1[10][8] = vv;
		vv.setID(40); vv.setAdy(41); vv.setPeso(50); vv.setX(495); vv.setY(315); puntosNivel1[10][9] = vv;
		vv.setID(41); vv.setAdy(40); vv.setPeso(50); vv.setX(495); vv.setY(270); puntosNivel1[10][10] = vv;
		vv.setID(41); vv.setAdy(42); vv.setPeso(50); vv.setX(495); vv.setY(360); puntosNivel1[10][11] = vv;
		vv.setID(41); vv.setAdy(47); vv.setPeso(100); vv.setX(585); vv.setY(315); puntosNivel1[10][12] = vv;
		vv.setID(42); vv.setAdy(41); vv.setPeso(50); vv.setX(495); vv.setY(315); puntosNivel1[11][1] = vv;
		vv.setID(42); vv.setAdy(36); vv.setPeso(100); vv.setX(405); vv.setY(360); puntosNivel1[11][2] = vv;
		vv.setID(42); vv.setAdy(43); vv.setPeso(150); vv.setX(495); vv.setY(495); puntosNivel1[11][3] = vv;
		vv.setID(43); vv.setAdy(42); vv.setPeso(150); vv.setX(495); vv.setY(360); puntosNivel1[11][4] = vv;


		vv.setID(43); vv.setAdy(32); vv.setPeso(150); vv.setX(360); vv.setY(495); puntosNivel1[11][5] = vv;
		vv.setID(43); vv.setAdy(44); vv.setPeso(100); vv.setX(495); vv.setY(585); puntosNivel1[11][6] = vv;
		vv.setID(43); vv.setAdy(48); vv.setPeso(100); vv.setX(585); vv.setY(495); puntosNivel1[11][7] = vv;
		vv.setID(44); vv.setAdy(43); vv.setPeso(100); vv.setX(495); vv.setY(495); puntosNivel1[11][8] = vv;
		vv.setID(44); vv.setAdy(25); vv.setPeso(200); vv.setX(315); vv.setY(585); puntosNivel1[11][9] = vv;
		vv.setID(44); vv.setAdy(49); vv.setPeso(100); vv.setX(585); vv.setY(585); puntosNivel1[11][10] = vv;
		vv.setID(45); vv.setAdy(38); vv.setPeso(100); vv.setX(495); vv.setY(45); puntosNivel1[11][11] = vv;
		vv.setID(45); vv.setAdy(46); vv.setPeso(100); vv.setX(585); vv.setY(155); puntosNivel1[11][12] = vv;
		vv.setID(46); vv.setAdy(45); vv.setPeso(100); vv.setX(585); vv.setY(45); puntosNivel1[12][1] = vv;
		vv.setID(46); vv.setAdy(39); vv.setPeso(100); vv.setX(495); vv.setY(135); puntosNivel1[12][2] = vv;
		vv.setID(46); vv.setAdy(47); vv.setPeso(200); vv.setX(585); vv.setY(315); puntosNivel1[12][3] = vv;
		vv.setID(47); vv.setAdy(46); vv.setPeso(200); vv.setX(585); vv.setY(135); puntosNivel1[12][4] = vv;
		vv.setID(47); vv.setAdy(41); vv.setPeso(100); vv.setX(495); vv.setY(315); puntosNivel1[12][5] = vv;
		vv.setID(47); vv.setAdy(48); vv.setPeso(200); vv.setX(585); vv.setY(495); puntosNivel1[12][6] = vv;
		vv.setID(48); vv.setAdy(47); vv.setPeso(200); vv.setX(585); vv.setY(315); puntosNivel1[12][7] = vv;
		vv.setID(48); vv.setAdy(43); vv.setPeso(100); vv.setX(495); vv.setY(495); puntosNivel1[12][8] = vv;
		vv.setID(48); vv.setAdy(49); vv.setPeso(100); vv.setX(585); vv.setY(585); puntosNivel1[12][9] = vv;
		vv.setID(49); vv.setAdy(48); vv.setPeso(100); vv.setX(585); vv.setY(495); puntosNivel1[12][10] = vv;
		vv.setID(49); vv.setAdy(44); vv.setPeso(100); vv.setX(495); vv.setY(585); puntosNivel1[12][11] = vv;

	}

	if (nivel == 2) {

		Vertice vv;
		vv.setID(97); vv.setAdy(98); vv.setPeso(50); vv.setX(45); vv.setY(45); vv.setXX(45); vv.setYY(90); Aristas2[1][1] = vv;
		vv.setID(97); vv.setAdy(94); vv.setPeso(50); vv.setX(45); vv.setY(45); vv.setXX(90); vv.setYY(45); Aristas2[1][2] = vv;
		vv.setID(98); vv.setAdy(97); vv.setPeso(50); vv.setX(45); vv.setY(90); vv.setXX(45); vv.setYY(45); Aristas2[1][3] = vv;
		vv.setID(98); vv.setAdy(99); vv.setPeso(50); vv.setX(45); vv.setY(90); vv.setXX(45); vv.setYY(135); Aristas2[1][4] = vv;
		vv.setID(98); vv.setAdy(99); vv.setPeso(50); vv.setX(45); vv.setY(90); vv.setXX(45); vv.setYY(135); Aristas2[1][5] = vv;
		vv.setID(99); vv.setAdy(98); vv.setPeso(50); vv.setX(45); vv.setY(135); vv.setXX(45); vv.setYY(90); Aristas2[1][6] = vv;
		vv.setID(99); vv.setAdy(100); vv.setPeso(50); vv.setX(45); vv.setY(135); vv.setXX(45); vv.setYY(180); Aristas2[1][7] = vv;
		vv.setID(100); vv.setAdy(99); vv.setPeso(50); vv.setX(45); vv.setY(180); vv.setXX(45); vv.setYY(135); Aristas2[1][8] = vv;
		vv.setID(100); vv.setAdy(101); vv.setPeso(50); vv.setX(45); vv.setY(180); vv.setXX(45); vv.setYY(225); Aristas2[1][9] = vv;
		vv.setID(101); vv.setAdy(100); vv.setPeso(50); vv.setX(45); vv.setY(225); vv.setXX(45); vv.setYY(180); Aristas2[1][10] = vv;
		vv.setID(101); vv.setAdy(102); vv.setPeso(50); vv.setX(45); vv.setY(225); vv.setXX(45); vv.setYY(270); Aristas2[1][11] = vv;
		vv.setID(102); vv.setAdy(101); vv.setPeso(50); vv.setX(45); vv.setY(270); vv.setXX(45); vv.setYY(225); Aristas2[1][12] = vv;
		vv.setID(102); vv.setAdy(103); vv.setPeso(50); vv.setX(45); vv.setY(270); vv.setXX(45); vv.setYY(315); Aristas2[1][13] = vv;
		vv.setID(103); vv.setAdy(102); vv.setPeso(50); vv.setX(45); vv.setY(315); vv.setXX(45); vv.setYY(270); Aristas2[1][14] = vv;
		vv.setID(103); vv.setAdy(104); vv.setPeso(50); vv.setX(45); vv.setY(315); vv.setXX(45); vv.setYY(360); Aristas2[1][15] = vv;
		vv.setID(103); vv.setAdy(95); vv.setPeso(50); vv.setX(45); vv.setY(315); vv.setXX(90); vv.setYY(315); Aristas2[1][16] = vv;
		vv.setID(104); vv.setAdy(103); vv.setPeso(50); vv.setX(45); vv.setY(360); vv.setXX(45); vv.setYY(315); Aristas2[1][17] = vv;
		vv.setID(104); vv.setAdy(105); vv.setPeso(50); vv.setX(45); vv.setY(360); vv.setXX(45); vv.setYY(405); Aristas2[1][18] = vv;
		vv.setID(105); vv.setAdy(104); vv.setPeso(50); vv.setX(45); vv.setY(405); vv.setXX(45); vv.setYY(360); Aristas2[1][19] = vv;
		vv.setID(105); vv.setAdy(106); vv.setPeso(50); vv.setX(45); vv.setY(405); vv.setXX(45); vv.setYY(450); Aristas2[2][1] = vv;
		vv.setID(106); vv.setAdy(105); vv.setPeso(50); vv.setX(45); vv.setY(450); vv.setXX(45); vv.setYY(405); Aristas2[2][2] = vv;
		vv.setID(106); vv.setAdy(107); vv.setPeso(50); vv.setX(45); vv.setY(450); vv.setXX(45); vv.setYY(495); Aristas2[2][3] = vv;
		vv.setID(107); vv.setAdy(106); vv.setPeso(50); vv.setX(45); vv.setY(495); vv.setXX(45); vv.setYY(450); Aristas2[2][4] = vv;
		vv.setID(107); vv.setAdy(108); vv.setPeso(50); vv.setX(45); vv.setY(495); vv.setXX(45); vv.setYY(540); Aristas2[2][5] = vv;
		vv.setID(108); vv.setAdy(107); vv.setPeso(50); vv.setX(45); vv.setY(540); vv.setXX(45); vv.setYY(495); Aristas2[2][6] = vv;


		vv.setID(108); vv.setAdy(109); vv.setPeso(50); vv.setX(45); vv.setY(540); vv.setXX(45); vv.setYY(585); Aristas2[2][7] = vv;
		vv.setID(109); vv.setAdy(108); vv.setPeso(50); vv.setX(45); vv.setY(585); vv.setXX(45); vv.setYY(540); Aristas2[2][8] = vv;
		vv.setID(109); vv.setAdy(96); vv.setPeso(50); vv.setX(45); vv.setY(585); vv.setXX(90); vv.setYY(585); Aristas2[2][9] = vv;
		vv.setID(94); vv.setAdy(97); vv.setPeso(50); vv.setX(90); vv.setY(45); vv.setXX(45); vv.setYY(45); Aristas2[2][10] = vv;
		vv.setID(94); vv.setAdy(83); vv.setPeso(50); vv.setX(90); vv.setY(45); vv.setXX(135); vv.setYY(45); Aristas2[2][11] = vv;
		vv.setID(95); vv.setAdy(103); vv.setPeso(50); vv.setX(90); vv.setY(315); vv.setXX(45); vv.setYY(315); Aristas2[2][12] = vv;
		vv.setID(95); vv.setAdy(88); vv.setPeso(50); vv.setX(90); vv.setY(315); vv.setXX(135); vv.setYY(315); Aristas2[2][13] = vv;
		vv.setID(96); vv.setAdy(109); vv.setPeso(50); vv.setX(90); vv.setY(585); vv.setXX(45); vv.setYY(585); Aristas2[2][14] = vv;
		vv.setID(96); vv.setAdy(93); vv.setPeso(50); vv.setX(90); vv.setY(585); vv.setXX(135); vv.setYY(585); Aristas2[2][15] = vv;
		vv.setID(83); vv.setAdy(94); vv.setPeso(50); vv.setX(135); vv.setY(45); vv.setXX(90); vv.setYY(45); Aristas2[2][16] = vv;
		vv.setID(83); vv.setAdy(78); vv.setPeso(50); vv.setX(135); vv.setY(45); vv.setXX(180); vv.setYY(45); Aristas2[2][17] = vv;
		vv.setID(84); vv.setAdy(79); vv.setPeso(50); vv.setX(135); vv.setY(135); vv.setXX(180); vv.setYY(135); Aristas2[2][18] = vv;
		vv.setID(84); vv.setAdy(85); vv.setPeso(50); vv.setX(135); vv.setY(135); vv.setXX(135); vv.setYY(180); Aristas2[2][19] = vv;
		vv.setID(85); vv.setAdy(84); vv.setPeso(50); vv.setX(135); vv.setY(180); vv.setXX(135); vv.setYY(135); Aristas2[3][1] = vv;
		vv.setID(85); vv.setAdy(86); vv.setPeso(50); vv.setX(135); vv.setY(180); vv.setXX(135); vv.setYY(225); Aristas2[3][2] = vv;
		vv.setID(85); vv.setAdy(84); vv.setPeso(50); vv.setX(135); vv.setY(180); vv.setXX(135); vv.setYY(135); Aristas2[3][3] = vv;
		vv.setID(86); vv.setAdy(85); vv.setPeso(50); vv.setX(135); vv.setY(225); vv.setXX(135); vv.setYY(180); Aristas2[3][4] = vv;
		vv.setID(86); vv.setAdy(87); vv.setPeso(50); vv.setX(135); vv.setY(225); vv.setXX(135); vv.setYY(270); Aristas2[3][5] = vv;
		vv.setID(87); vv.setAdy(86); vv.setPeso(50); vv.setX(135); vv.setY(270); vv.setXX(135); vv.setYY(225); Aristas2[3][6] = vv;
		vv.setID(87); vv.setAdy(88); vv.setPeso(50); vv.setX(135); vv.setY(270); vv.setXX(135); vv.setYY(315); Aristas2[3][7] = vv;
		vv.setID(87); vv.setAdy(80); vv.setPeso(50); vv.setX(135); vv.setY(270); vv.setXX(180); vv.setYY(270); Aristas2[3][8] = vv;
		vv.setID(88); vv.setAdy(87); vv.setPeso(50); vv.setX(135); vv.setY(315); vv.setXX(135); vv.setYY(270); Aristas2[3][9] = vv;
		vv.setID(88); vv.setAdy(89); vv.setPeso(50); vv.setX(135); vv.setY(315); vv.setXX(135); vv.setYY(360); Aristas2[3][10] = vv;// falta de 88 a 95
		vv.setID(89); vv.setAdy(88); vv.setPeso(50); vv.setX(135); vv.setY(360); vv.setXX(135); vv.setYY(315); Aristas2[3][11] = vv;


		vv.setID(89); vv.setAdy(90); vv.setPeso(50); vv.setX(135); vv.setY(360); vv.setXX(135); vv.setYY(405); Aristas2[3][12] = vv;
		vv.setID(90); vv.setAdy(89); vv.setPeso(50); vv.setX(135); vv.setY(405); vv.setXX(135); vv.setYY(360); Aristas2[3][13] = vv;
		vv.setID(90); vv.setAdy(91); vv.setPeso(50); vv.setX(135); vv.setY(405); vv.setXX(135); vv.setYY(450); Aristas2[3][14] = vv;
		vv.setID(91); vv.setAdy(90); vv.setPeso(50); vv.setX(135); vv.setY(450); vv.setXX(135); vv.setYY(405); Aristas2[3][15] = vv;
		vv.setID(91); vv.setAdy(92); vv.setPeso(50); vv.setX(135); vv.setY(450); vv.setXX(135); vv.setYY(495); Aristas2[3][16] = vv;
		vv.setID(92); vv.setAdy(91); vv.setPeso(50); vv.setX(135); vv.setY(495); vv.setXX(135); vv.setYY(450); Aristas2[3][17] = vv;
		vv.setID(92); vv.setAdy(81); vv.setPeso(50); vv.setX(135); vv.setY(495); vv.setXX(180); vv.setYY(495); Aristas2[3][18] = vv;
		vv.setID(93); vv.setAdy(96); vv.setPeso(50); vv.setX(135); vv.setY(585); vv.setXX(90); vv.setYY(585); Aristas2[3][19] = vv;
		vv.setID(93); vv.setAdy(82); vv.setPeso(50); vv.setX(135); vv.setY(585); vv.setXX(180); vv.setYY(585); Aristas2[4][1] = vv;
		vv.setID(78); vv.setAdy(83); vv.setPeso(50); vv.setX(180); vv.setY(45); vv.setXX(135); vv.setYY(45); Aristas2[4][2] = vv;
		vv.setID(78); vv.setAdy(69); vv.setPeso(50); vv.setX(180); vv.setY(45); vv.setXX(225); vv.setYY(45); Aristas2[4][3] = vv;
		vv.setID(79); vv.setAdy(84); vv.setPeso(50); vv.setX(180); vv.setY(135); vv.setXX(135); vv.setYY(135); Aristas2[4][4] = vv;
		vv.setID(79); vv.setAdy(70); vv.setPeso(50); vv.setX(180); vv.setY(135); vv.setXX(225); vv.setYY(135); Aristas2[4][5] = vv;
		vv.setID(80); vv.setAdy(87); vv.setPeso(50); vv.setX(180); vv.setY(270); vv.setXX(135); vv.setYY(270); Aristas2[4][6] = vv;
		vv.setID(80); vv.setAdy(72); vv.setPeso(50); vv.setX(180); vv.setY(270); vv.setXX(225); vv.setYY(270); Aristas2[4][7] = vv;
		vv.setID(81); vv.setAdy(92); vv.setPeso(50); vv.setX(180); vv.setY(495); vv.setXX(135); vv.setYY(495); Aristas2[4][8] = vv;
		vv.setID(81); vv.setAdy(76); vv.setPeso(50); vv.setX(180); vv.setY(495); vv.setXX(225); vv.setYY(495); Aristas2[4][9] = vv;
		vv.setID(82); vv.setAdy(93); vv.setPeso(50); vv.setX(180); vv.setY(585); vv.setXX(135); vv.setYY(585); Aristas2[4][10] = vv;
		vv.setID(82); vv.setAdy(77); vv.setPeso(50); vv.setX(180); vv.setY(585); vv.setXX(225); vv.setYY(585); Aristas2[4][11] = vv;
		vv.setID(69); vv.setAdy(78); vv.setPeso(50); vv.setX(225); vv.setY(45); vv.setXX(180); vv.setYY(45); Aristas2[4][12] = vv;
		vv.setID(69); vv.setAdy(61); vv.setPeso(50); vv.setX(225); vv.setY(45); vv.setXX(270); vv.setYY(45); Aristas2[4][13] = vv;
		vv.setID(70); vv.setAdy(79); vv.setPeso(50); vv.setX(225); vv.setY(135); vv.setXX(180); vv.setYY(135); Aristas2[4][14] = vv;
		vv.setID(71); vv.setAdy(72); vv.setPeso(50); vv.setX(225); vv.setY(225); vv.setXX(225); vv.setYY(270); Aristas2[4][15] = vv;
		vv.setID(71); vv.setAdy(63); vv.setPeso(50); vv.setX(225); vv.setY(225); vv.setXX(270); vv.setYY(225); Aristas2[4][16] = vv;
		vv.setID(71); vv.setAdy(72); vv.setPeso(50); vv.setX(225); vv.setY(225); vv.setXX(225); vv.setYY(270); Aristas2[4][17] = vv;
		vv.setID(72); vv.setAdy(71); vv.setPeso(50); vv.setX(225); vv.setY(270); vv.setXX(225); vv.setYY(225); Aristas2[4][18] = vv;


		vv.setID(72); vv.setAdy(80); vv.setPeso(50); vv.setX(225); vv.setY(270); vv.setXX(180); vv.setYY(270); Aristas2[4][19] = vv;
		vv.setID(72); vv.setAdy(73); vv.setPeso(50); vv.setX(225); vv.setY(270); vv.setXX(225); vv.setYY(315); Aristas2[5][1] = vv;
		vv.setID(73); vv.setAdy(72); vv.setPeso(50); vv.setX(225); vv.setY(315); vv.setXX(225); vv.setYY(270); Aristas2[5][2] = vv;
		vv.setID(73); vv.setAdy(74); vv.setPeso(50); vv.setX(225); vv.setY(315); vv.setXX(225); vv.setYY(360); Aristas2[5][3] = vv;
		vv.setID(74); vv.setAdy(73); vv.setPeso(50); vv.setX(225); vv.setY(360); vv.setXX(225); vv.setYY(315); Aristas2[5][4] = vv;
		vv.setID(74); vv.setAdy(75); vv.setPeso(50); vv.setX(225); vv.setY(360); vv.setXX(225); vv.setYY(405); Aristas2[5][5] = vv;
		vv.setID(75); vv.setAdy(74); vv.setPeso(50); vv.setX(225); vv.setY(405); vv.setXX(225); vv.setYY(360); Aristas2[5][6] = vv;
		vv.setID(75); vv.setAdy(65); vv.setPeso(50); vv.setX(225); vv.setY(405); vv.setXX(270); vv.setYY(405); Aristas2[5][7] = vv;
		vv.setID(76); vv.setAdy(81); vv.setPeso(50); vv.setX(225); vv.setY(495); vv.setXX(180); vv.setYY(495); Aristas2[5][8] = vv;
		vv.setID(76); vv.setAdy(67); vv.setPeso(50); vv.setX(225); vv.setY(495); vv.setXX(270); vv.setYY(495); Aristas2[5][9] = vv;
		vv.setID(77); vv.setAdy(82); vv.setPeso(50); vv.setX(225); vv.setY(585); vv.setXX(180); vv.setYY(585); Aristas2[5][10] = vv;
		vv.setID(77); vv.setAdy(68); vv.setPeso(50); vv.setX(225); vv.setY(585); vv.setXX(270); vv.setYY(585); Aristas2[5][11] = vv;
		vv.setID(61); vv.setAdy(69); vv.setPeso(50); vv.setX(270); vv.setY(45); vv.setXX(225); vv.setYY(45); Aristas2[5][12] = vv;
		vv.setID(61); vv.setAdy(50); vv.setPeso(50); vv.setX(270); vv.setY(45); vv.setXX(315); vv.setYY(45); Aristas2[5][13] = vv;
		vv.setID(62); vv.setAdy(70); vv.setPeso(50); vv.setX(270); vv.setY(135); vv.setXX(225); vv.setYY(135); Aristas2[5][14] = vv;
		vv.setID(62); vv.setAdy(52); vv.setPeso(50); vv.setX(270); vv.setY(135); vv.setXX(315); vv.setYY(135); Aristas2[5][15] = vv;
		vv.setID(63); vv.setAdy(71); vv.setPeso(50); vv.setX(270); vv.setY(225); vv.setXX(225); vv.setYY(225); Aristas2[5][16] = vv;
		vv.setID(63); vv.setAdy(53); vv.setPeso(50); vv.setX(270); vv.setY(225); vv.setXX(270); vv.setYY(225); Aristas2[5][17] = vv;
		vv.setID(64); vv.setAdy(73); vv.setPeso(50); vv.setX(270); vv.setY(315); vv.setXX(225); vv.setYY(315); Aristas2[5][18] = vv;
		vv.setID(64); vv.setAdy(55); vv.setPeso(50); vv.setX(270); vv.setY(315); vv.setXX(315); vv.setYY(315); Aristas2[5][19] = vv;
		vv.setID(65); vv.setAdy(75); vv.setPeso(50); vv.setX(270); vv.setY(405); vv.setXX(225); vv.setYY(405); Aristas2[6][1] = vv;
		vv.setID(65); vv.setAdy(57); vv.setPeso(50); vv.setX(270); vv.setY(405); vv.setXX(315); vv.setYY(405); Aristas2[6][2] = vv;
		vv.setID(65); vv.setAdy(66); vv.setPeso(50); vv.setX(270); vv.setY(405); vv.setXX(270); vv.setYY(450); Aristas2[6][3] = vv;
		vv.setID(66); vv.setAdy(65); vv.setPeso(50); vv.setX(270); vv.setY(450); vv.setXX(270); vv.setYY(405); Aristas2[6][4] = vv;

		vv.setID(66); vv.setAdy(67); vv.setPeso(50); vv.setX(270); vv.setY(450); vv.setXX(270); vv.setYY(495); Aristas2[6][5] = vv;
		vv.setID(67); vv.setAdy(66); vv.setPeso(50); vv.setX(270); vv.setY(495); vv.setXX(270); vv.setYY(450); Aristas2[6][6] = vv;
		vv.setID(67); vv.setAdy(76); vv.setPeso(50); vv.setX(270); vv.setY(495); vv.setXX(225); vv.setYY(495); Aristas2[6][7] = vv;
		vv.setID(67); vv.setAdy(58); vv.setPeso(50); vv.setX(270); vv.setY(495); vv.setXX(315); vv.setYY(495); Aristas2[6][8] = vv;
		vv.setID(68); vv.setAdy(77); vv.setPeso(50); vv.setX(270); vv.setY(585); vv.setXX(225); vv.setYY(585); Aristas2[6][9] = vv;
		vv.setID(68); vv.setAdy(60); vv.setPeso(50); vv.setX(270); vv.setY(585); vv.setXX(315); vv.setYY(585); Aristas2[6][10] = vv;
		vv.setID(50); vv.setAdy(61); vv.setPeso(50); vv.setX(315); vv.setY(45); vv.setXX(270); vv.setYY(45); Aristas2[6][11] = vv;
		vv.setID(50); vv.setAdy(51); vv.setPeso(50); vv.setX(315); vv.setY(45); vv.setXX(315); vv.setYY(90); Aristas2[6][12] = vv;
		vv.setID(50); vv.setAdy(42); vv.setPeso(50); vv.setX(315); vv.setY(45); vv.setXX(360); vv.setYY(45); Aristas2[6][13] = vv;
		vv.setID(51); vv.setAdy(50); vv.setPeso(50); vv.setX(315); vv.setY(90); vv.setXX(315); vv.setYY(45); Aristas2[6][14] = vv;
		vv.setID(51); vv.setAdy(52); vv.setPeso(50); vv.setX(315); vv.setY(90); vv.setXX(315); vv.setYY(135); Aristas2[6][15] = vv;
		vv.setID(52); vv.setAdy(51); vv.setPeso(50); vv.setX(315); vv.setY(135); vv.setXX(315); vv.setYY(90); Aristas2[6][16] = vv;
		vv.setID(52); vv.setAdy(43); vv.setPeso(50); vv.setX(315); vv.setY(135); vv.setXX(360); vv.setYY(135); Aristas2[6][17] = vv;
		vv.setID(52); vv.setAdy(62); vv.setPeso(50); vv.setX(315); vv.setY(135); vv.setXX(270); vv.setYY(135); Aristas2[6][18] = vv;
		vv.setID(53); vv.setAdy(63); vv.setPeso(50); vv.setX(315); vv.setY(225); vv.setXX(270); vv.setYY(225); Aristas2[6][19] = vv;
		vv.setID(53); vv.setAdy(45); vv.setPeso(50); vv.setX(315); vv.setY(225); vv.setXX(360); vv.setYY(225); Aristas2[7][1] = vv;
		vv.setID(53); vv.setAdy(54); vv.setPeso(50); vv.setX(315); vv.setY(225); vv.setXX(315); vv.setYY(270); Aristas2[7][2] = vv;
		vv.setID(54); vv.setAdy(53); vv.setPeso(50); vv.setX(315); vv.setY(270); vv.setXX(315); vv.setYY(225); Aristas2[7][3] = vv;
		vv.setID(54); vv.setAdy(55); vv.setPeso(50); vv.setX(315); vv.setY(270); vv.setXX(315); vv.setYY(315); Aristas2[7][4] = vv;
		vv.setID(55); vv.setAdy(54); vv.setPeso(50); vv.setX(315); vv.setY(315); vv.setXX(315); vv.setYY(270); Aristas2[7][5] = vv;
		vv.setID(55); vv.setAdy(56); vv.setPeso(50); vv.setX(315); vv.setY(315); vv.setXX(315); vv.setYY(360); Aristas2[7][6] = vv;
		vv.setID(55); vv.setAdy(64); vv.setPeso(50); vv.setX(315); vv.setY(315); vv.setXX(270); vv.setYY(315); Aristas2[7][7] = vv;
		vv.setID(55); vv.setAdy(46); vv.setPeso(50); vv.setX(315); vv.setY(315); vv.setXX(360); vv.setYY(315); Aristas2[7][8] = vv;
		vv.setID(56); vv.setAdy(55); vv.setPeso(50); vv.setX(315); vv.setY(360); vv.setXX(315); vv.setYY(315); Aristas2[7][9] = vv;


		vv.setID(56); vv.setAdy(57); vv.setPeso(50); vv.setX(315); vv.setY(360); vv.setXX(315); vv.setYY(405); Aristas2[7][10] = vv;
		vv.setID(57); vv.setAdy(56); vv.setPeso(50); vv.setX(315); vv.setY(405); vv.setXX(315); vv.setYY(360); Aristas2[7][11] = vv;
		vv.setID(57); vv.setAdy(65); vv.setPeso(50); vv.setX(315); vv.setY(405); vv.setXX(270); vv.setYY(405); Aristas2[7][12] = vv;
		vv.setID(57); vv.setAdy(47); vv.setPeso(50); vv.setX(315); vv.setY(405); vv.setXX(360); vv.setYY(405); Aristas2[7][13] = vv;
		vv.setID(58); vv.setAdy(67); vv.setPeso(50); vv.setX(315); vv.setY(495); vv.setXX(270); vv.setYY(495); Aristas2[7][14] = vv;
		vv.setID(58); vv.setAdy(48); vv.setPeso(50); vv.setX(315); vv.setY(495); vv.setXX(360); vv.setYY(495); Aristas2[7][15] = vv;
		vv.setID(58); vv.setAdy(59); vv.setPeso(50); vv.setX(315); vv.setY(495); vv.setXX(315); vv.setYY(540); Aristas2[7][16] = vv;
		vv.setID(59); vv.setAdy(58); vv.setPeso(50); vv.setX(315); vv.setY(540); vv.setXX(315); vv.setYY(495); Aristas2[7][17] = vv;
		vv.setID(59); vv.setAdy(60); vv.setPeso(50); vv.setX(315); vv.setY(540); vv.setXX(315); vv.setYY(585); Aristas2[7][18] = vv;
		vv.setID(60); vv.setAdy(59); vv.setPeso(50); vv.setX(315); vv.setY(585); vv.setXX(315); vv.setYY(540); Aristas2[7][19] = vv;
		vv.setID(60); vv.setAdy(68); vv.setPeso(50); vv.setX(315); vv.setY(585); vv.setXX(270); vv.setYY(585); Aristas2[8][1] = vv;
		vv.setID(60); vv.setAdy(49); vv.setPeso(50); vv.setX(315); vv.setY(585); vv.setXX(360); vv.setYY(585); Aristas2[8][2] = vv;
		vv.setID(42); vv.setAdy(50); vv.setPeso(50); vv.setX(360); vv.setY(45); vv.setXX(315); vv.setYY(45); Aristas2[8][3] = vv;
		vv.setID(42); vv.setAdy(33); vv.setPeso(50); vv.setX(360); vv.setY(45); vv.setXX(405); vv.setYY(45); Aristas2[8][4] = vv;
		vv.setID(43); vv.setAdy(52); vv.setPeso(50); vv.setX(360); vv.setY(135); vv.setXX(315); vv.setYY(135); Aristas2[8][5] = vv;
		vv.setID(43); vv.setAdy(34); vv.setPeso(50); vv.setX(360); vv.setY(135); vv.setXX(405); vv.setYY(135); Aristas2[8][6] = vv;
		vv.setID(43); vv.setAdy(44); vv.setPeso(50); vv.setX(360); vv.setY(135); vv.setXX(360); vv.setYY(180); Aristas2[8][7] = vv;
		vv.setID(44); vv.setAdy(43); vv.setPeso(50); vv.setX(360); vv.setY(180); vv.setXX(360); vv.setYY(135); Aristas2[8][8] = vv;
		vv.setID(44); vv.setAdy(45); vv.setPeso(50); vv.setX(360); vv.setY(180); vv.setXX(360); vv.setYY(225); Aristas2[8][9] = vv;
		vv.setID(45); vv.setAdy(53); vv.setPeso(50); vv.setX(360); vv.setY(225); vv.setXX(315); vv.setYY(225); Aristas2[8][10] = vv;
		vv.setID(45); vv.setAdy(35); vv.setPeso(50); vv.setX(360); vv.setY(225); vv.setXX(405); vv.setYY(225); Aristas2[8][11] = vv;
		vv.setID(45); vv.setAdy(44); vv.setPeso(50); vv.setX(360); vv.setY(225); vv.setXX(360); vv.setYY(180); Aristas2[8][12] = vv;
		vv.setID(46); vv.setAdy(55); vv.setPeso(50); vv.setX(360); vv.setY(315); vv.setXX(315); vv.setYY(315); Aristas2[8][13] = vv;
		vv.setID(46); vv.setAdy(37); vv.setPeso(50); vv.setX(360); vv.setY(315); vv.setXX(405); vv.setYY(315); Aristas2[8][14] = vv;


		vv.setID(47); vv.setAdy(57); vv.setPeso(50); vv.setX(360); vv.setY(405); vv.setXX(315); vv.setYY(405); Aristas2[8][15] = vv;
		vv.setID(47); vv.setAdy(39); vv.setPeso(50); vv.setX(360); vv.setY(405); vv.setXX(405); vv.setYY(405); Aristas2[8][16] = vv;
		vv.setID(48); vv.setAdy(58); vv.setPeso(50); vv.setX(360); vv.setY(495); vv.setXX(315); vv.setYY(495); Aristas2[8][17] = vv;
		vv.setID(48); vv.setAdy(40); vv.setPeso(50); vv.setX(360); vv.setY(495); vv.setXX(405); vv.setYY(495); Aristas2[8][18] = vv;
		vv.setID(49); vv.setAdy(60); vv.setPeso(50); vv.setX(360); vv.setY(585); vv.setXX(315); vv.setYY(585); Aristas2[8][19] = vv;
		vv.setID(49); vv.setAdy(49); vv.setPeso(50); vv.setX(360); vv.setY(585); vv.setXX(404); vv.setYY(585); Aristas2[9][1] = vv;
		vv.setID(33); vv.setAdy(42); vv.setPeso(50); vv.setX(405); vv.setY(45); vv.setXX(360); vv.setYY(45); Aristas2[9][2] = vv;
		vv.setID(33); vv.setAdy(28); vv.setPeso(50); vv.setX(405); vv.setY(45); vv.setXX(450); vv.setYY(45); Aristas2[9][3] = vv;
		vv.setID(34); vv.setAdy(43); vv.setPeso(50); vv.setX(405); vv.setY(135); vv.setXX(360); vv.setYY(135); Aristas2[9][4] = vv;
		vv.setID(34); vv.setAdy(29); vv.setPeso(50); vv.setX(405); vv.setY(135); vv.setXX(450); vv.setYY(135); Aristas2[9][5] = vv;
		vv.setID(35); vv.setAdy(45); vv.setPeso(50); vv.setX(405); vv.setY(225); vv.setXX(360); vv.setYY(225); Aristas2[9][6] = vv;
		vv.setID(35); vv.setAdy(36); vv.setPeso(50); vv.setX(405); vv.setY(225); vv.setXX(405); vv.setYY(270); Aristas2[9][7] = vv;
		vv.setID(36); vv.setAdy(35); vv.setPeso(50); vv.setX(405); vv.setY(270); vv.setXX(405); vv.setYY(225); Aristas2[9][8] = vv;
		vv.setID(36); vv.setAdy(37); vv.setPeso(50); vv.setX(405); vv.setY(270); vv.setXX(405); vv.setYY(315); Aristas2[9][9] = vv;
		vv.setID(37); vv.setAdy(36); vv.setPeso(50); vv.setX(405); vv.setY(315); vv.setXX(405); vv.setYY(270); Aristas2[9][10] = vv;
		vv.setID(37); vv.setAdy(38); vv.setPeso(50); vv.setX(405); vv.setY(315); vv.setXX(405); vv.setYY(360); Aristas2[9][11] = vv;
		vv.setID(37); vv.setAdy(46); vv.setPeso(50); vv.setX(405); vv.setY(315); vv.setXX(360); vv.setYY(315); Aristas2[9][12] = vv;
		vv.setID(38); vv.setAdy(37); vv.setPeso(50); vv.setX(405); vv.setY(360); vv.setXX(405); vv.setYY(315); Aristas2[9][13] = vv;
		vv.setID(38); vv.setAdy(39); vv.setPeso(50); vv.setX(405); vv.setY(360); vv.setXX(405); vv.setYY(405); Aristas2[9][14] = vv;
		vv.setID(38); vv.setAdy(30); vv.setPeso(50); vv.setX(405); vv.setY(360); vv.setXX(450); vv.setYY(360); Aristas2[9][15] = vv;
		vv.setID(39); vv.setAdy(38); vv.setPeso(50); vv.setX(405); vv.setY(405); vv.setXX(405); vv.setYY(360); Aristas2[9][16] = vv;
		vv.setID(39); vv.setAdy(47); vv.setPeso(50); vv.setX(405); vv.setY(405); vv.setXX(360); vv.setYY(405); Aristas2[9][17] = vv;
		vv.setID(40); vv.setAdy(48); vv.setPeso(50); vv.setX(405); vv.setY(495); vv.setXX(360); vv.setYY(495); Aristas2[9][18] = vv;
		vv.setID(40); vv.setAdy(31); vv.setPeso(50); vv.setX(405); vv.setY(495); vv.setXX(450); vv.setYY(495); Aristas2[9][19] = vv;

		vv.setID(41); vv.setAdy(49); vv.setPeso(50); vv.setX(405); vv.setY(585); vv.setXX(360); vv.setYY(585); Aristas2[10][1] = vv;
		vv.setID(41); vv.setAdy(32); vv.setPeso(50); vv.setX(405); vv.setY(585); vv.setXX(450); vv.setYY(585); Aristas2[10][2] = vv;
		vv.setID(28); vv.setAdy(33); vv.setPeso(50); vv.setX(450); vv.setY(45); vv.setXX(360); vv.setYY(45); Aristas2[10][3] = vv;
		vv.setID(28); vv.setAdy(17); vv.setPeso(50); vv.setX(450); vv.setY(45); vv.setXX(495); vv.setYY(45); Aristas2[10][4] = vv;
		vv.setID(29); vv.setAdy(34); vv.setPeso(50); vv.setX(450); vv.setY(135); vv.setXX(405); vv.setYY(135); Aristas2[10][5] = vv;
		vv.setID(29); vv.setAdy(18); vv.setPeso(50); vv.setX(450); vv.setY(135); vv.setXX(495); vv.setYY(135); Aristas2[10][6] = vv;
		vv.setID(30); vv.setAdy(38); vv.setPeso(50); vv.setX(450); vv.setY(360); vv.setXX(405); vv.setYY(360); Aristas2[10][7] = vv;
		vv.setID(30); vv.setAdy(23); vv.setPeso(50); vv.setX(450); vv.setY(360); vv.setXX(495); vv.setYY(360); Aristas2[10][8] = vv;
		vv.setID(31); vv.setAdy(40); vv.setPeso(50); vv.setX(450); vv.setY(495); vv.setXX(405); vv.setYY(495); Aristas2[10][9] = vv;
		vv.setID(31); vv.setAdy(26); vv.setPeso(50); vv.setX(450); vv.setY(495); vv.setXX(495); vv.setYY(495); Aristas2[10][10] = vv;
		vv.setID(32); vv.setAdy(41); vv.setPeso(50); vv.setX(450); vv.setY(585); vv.setXX(405); vv.setYY(585); Aristas2[10][11] = vv;
		vv.setID(32); vv.setAdy(27); vv.setPeso(50); vv.setX(450); vv.setY(495); vv.setXX(495); vv.setYY(585); Aristas2[10][12] = vv;
		vv.setID(32); vv.setAdy(27); vv.setPeso(50); vv.setX(450); vv.setY(495); vv.setXX(495); vv.setYY(585); Aristas2[10][13] = vv;
		vv.setID(17); vv.setAdy(28); vv.setPeso(50); vv.setX(495); vv.setY(45); vv.setXX(450); vv.setYY(45); Aristas2[10][14] = vv;
		vv.setID(17); vv.setAdy(14); vv.setPeso(50); vv.setX(495); vv.setY(45); vv.setXX(540); vv.setYY(45); Aristas2[10][15] = vv;
		vv.setID(18); vv.setAdy(29); vv.setPeso(50); vv.setX(495); vv.setY(135); vv.setXX(450); vv.setYY(135); Aristas2[10][16] = vv;
		vv.setID(18); vv.setAdy(19); vv.setPeso(50); vv.setX(495); vv.setY(135); vv.setXX(495); vv.setYY(180); Aristas2[10][17] = vv;
		vv.setID(19); vv.setAdy(18); vv.setPeso(50); vv.setX(495); vv.setY(180); vv.setXX(495); vv.setYY(135); Aristas2[10][18] = vv;
		vv.setID(19); vv.setAdy(20); vv.setPeso(50); vv.setX(495); vv.setY(180); vv.setXX(495); vv.setYY(225); Aristas2[10][19] = vv;
		vv.setID(20); vv.setAdy(19); vv.setPeso(50); vv.setX(495); vv.setY(225); vv.setXX(495); vv.setYY(135); Aristas2[11][1] = vv;
		vv.setID(20); vv.setAdy(21); vv.setPeso(50); vv.setX(495); vv.setY(225); vv.setXX(495); vv.setYY(270); Aristas2[11][2] = vv;
		vv.setID(21); vv.setAdy(20); vv.setPeso(50); vv.setX(495); vv.setY(270); vv.setXX(495); vv.setYY(225); Aristas2[11][3] = vv;
		vv.setID(21); vv.setAdy(22); vv.setPeso(50); vv.setX(495); vv.setY(270); vv.setXX(495); vv.setYY(315); Aristas2[11][4] = vv;
		vv.setID(22); vv.setAdy(21); vv.setPeso(50); vv.setX(495); vv.setY(315); vv.setXX(495); vv.setYY(270); Aristas2[11][5] = vv;


		vv.setID(22); vv.setAdy(23); vv.setPeso(50); vv.setX(495); vv.setY(315); vv.setXX(495); vv.setYY(360); Aristas2[11][6] = vv;
		vv.setID(22); vv.setAdy(15); vv.setPeso(50); vv.setX(495); vv.setY(315); vv.setXX(540); vv.setYY(315); Aristas2[11][7] = vv;
		vv.setID(23); vv.setAdy(24); vv.setPeso(50); vv.setX(495); vv.setY(360); vv.setXX(495); vv.setYY(405); Aristas2[11][8] = vv;
		vv.setID(23); vv.setAdy(22); vv.setPeso(50); vv.setX(495); vv.setY(360); vv.setXX(495); vv.setYY(315); Aristas2[11][9] = vv;
		vv.setID(24); vv.setAdy(23); vv.setPeso(50); vv.setX(495); vv.setY(405); vv.setXX(495); vv.setYY(360); Aristas2[11][10] = vv;
		vv.setID(24); vv.setAdy(25); vv.setPeso(50); vv.setX(495); vv.setY(405); vv.setXX(495); vv.setYY(450); Aristas2[11][11] = vv;
		vv.setID(25); vv.setAdy(24); vv.setPeso(50); vv.setX(495); vv.setY(450); vv.setXX(495); vv.setYY(405); Aristas2[11][12] = vv;
		vv.setID(25); vv.setAdy(26); vv.setPeso(50); vv.setX(495); vv.setY(450); vv.setXX(495); vv.setYY(495); Aristas2[11][13] = vv;
		vv.setID(26); vv.setAdy(25); vv.setPeso(50); vv.setX(495); vv.setY(495); vv.setXX(495); vv.setYY(450); Aristas2[11][14] = vv;
		vv.setID(26); vv.setAdy(31); vv.setPeso(50); vv.setX(495); vv.setY(495); vv.setXX(450); vv.setYY(495); Aristas2[11][15] = vv;
		vv.setID(27); vv.setAdy(32); vv.setPeso(50); vv.setX(495); vv.setY(585); vv.setXX(450); vv.setYY(585); Aristas2[11][16] = vv;
		vv.setID(27); vv.setAdy(16); vv.setPeso(50); vv.setX(495); vv.setY(585); vv.setXX(540); vv.setYY(585); Aristas2[11][17] = vv;
		vv.setID(14); vv.setAdy(17); vv.setPeso(50); vv.setX(540); vv.setY(45); vv.setXX(495); vv.setYY(45); Aristas2[11][18] = vv;
		vv.setID(14); vv.setAdy(1); vv.setPeso(50); vv.setX(540); vv.setY(45); vv.setXX(585); vv.setYY(45); Aristas2[11][19] = vv;
		vv.setID(15); vv.setAdy(22); vv.setPeso(50); vv.setX(540); vv.setY(315); vv.setXX(495); vv.setYY(315); Aristas2[12][1] = vv;
		vv.setID(15); vv.setAdy(7); vv.setPeso(50); vv.setX(540); vv.setY(315); vv.setXX(585); vv.setYY(315); Aristas2[12][2] = vv;
		vv.setID(16); vv.setAdy(27); vv.setPeso(50); vv.setX(540); vv.setY(585); vv.setXX(495); vv.setYY(585); Aristas2[13][3] = vv;
		vv.setID(16); vv.setAdy(13); vv.setPeso(50); vv.setX(540); vv.setY(585); vv.setXX(585); vv.setYY(585); Aristas2[12][4] = vv;
		vv.setID(1); vv.setAdy(14); vv.setPeso(50); vv.setX(585); vv.setY(45); vv.setXX(540); vv.setYY(45); Aristas2[12][5] = vv;
		vv.setID(1); vv.setAdy(2); vv.setPeso(50); vv.setX(585); vv.setY(45); vv.setXX(585); vv.setYY(90); Aristas2[12][6] = vv;
		vv.setID(2); vv.setAdy(1); vv.setPeso(50); vv.setX(585); vv.setY(90); vv.setXX(585); vv.setYY(45); Aristas2[12][7] = vv;
		vv.setID(2); vv.setAdy(3); vv.setPeso(50); vv.setX(585); vv.setY(90); vv.setXX(585); vv.setYY(135); Aristas2[12][8] = vv;
		vv.setID(3); vv.setAdy(2); vv.setPeso(50); vv.setX(585); vv.setY(135); vv.setXX(585); vv.setYY(90); Aristas2[12][9] = vv;
		vv.setID(3); vv.setAdy(4); vv.setPeso(50); vv.setX(585); vv.setY(135); vv.setXX(585); vv.setYY(180); Aristas2[12][10] = vv;
		vv.setID(4); vv.setAdy(3); vv.setPeso(50); vv.setX(585); vv.setY(180); vv.setXX(585); vv.setYY(135); Aristas2[12][11] = vv;
		vv.setID(4); vv.setAdy(5); vv.setPeso(50); vv.setX(585); vv.setY(180); vv.setXX(585); vv.setYY(225); Aristas2[12][12] = vv;
		vv.setID(5); vv.setAdy(4); vv.setPeso(50); vv.setX(585); vv.setY(225); vv.setXX(585); vv.setYY(180); Aristas2[12][13] = vv;
		vv.setID(5); vv.setAdy(6); vv.setPeso(50); vv.setX(585); vv.setY(225); vv.setXX(585); vv.setYY(270); Aristas2[12][14] = vv;
		vv.setID(6); vv.setAdy(5); vv.setPeso(50); vv.setX(585); vv.setY(270); vv.setXX(585); vv.setYY(225); Aristas2[12][15] = vv;
		vv.setID(6); vv.setAdy(7); vv.setPeso(50); vv.setX(585); vv.setY(270); vv.setXX(585); vv.setYY(315); Aristas2[12][16] = vv;
		vv.setID(7); vv.setAdy(6); vv.setPeso(50); vv.setX(585); vv.setY(315); vv.setXX(585); vv.setYY(270); Aristas2[12][17] = vv;
		vv.setID(7); vv.setAdy(15); vv.setPeso(50); vv.setX(585); vv.setY(315); vv.setXX(540); vv.setYY(315); Aristas2[12][18] = vv;
		vv.setID(7); vv.setAdy(8); vv.setPeso(50); vv.setX(585); vv.setY(315); vv.setXX(585); vv.setYY(360); Aristas2[12][19] = vv;
		vv.setID(8); vv.setAdy(7); vv.setPeso(50); vv.setX(585); vv.setY(360); vv.setXX(585); vv.setYY(315); Aristas2[13][1] = vv;
		vv.setID(8); vv.setAdy(9); vv.setPeso(50); vv.setX(585); vv.setY(360); vv.setXX(585); vv.setYY(405); Aristas2[13][2] = vv;
		vv.setID(9); vv.setAdy(8); vv.setPeso(50); vv.setX(585); vv.setY(405); vv.setXX(585); vv.setYY(360); Aristas2[13][3] = vv;
		vv.setID(9); vv.setAdy(10); vv.setPeso(50); vv.setX(585); vv.setY(405); vv.setXX(585); vv.setYY(450); Aristas2[13][4] = vv;
		vv.setID(10); vv.setAdy(9); vv.setPeso(50); vv.setX(585); vv.setY(450); vv.setXX(585); vv.setYY(405); Aristas2[13][5] = vv;
		vv.setID(10); vv.setAdy(11); vv.setPeso(50); vv.setX(585); vv.setY(450); vv.setXX(585); vv.setYY(495); Aristas2[13][6] = vv;
		vv.setID(11); vv.setAdy(10); vv.setPeso(50); vv.setX(585); vv.setY(495); vv.setXX(585); vv.setYY(450); Aristas2[13][7] = vv;
		vv.setID(11); vv.setAdy(12); vv.setPeso(50); vv.setX(585); vv.setY(495); vv.setXX(585); vv.setYY(540); Aristas2[13][8] = vv;
		vv.setID(12); vv.setAdy(11); vv.setPeso(50); vv.setX(585); vv.setY(540); vv.setXX(585); vv.setYY(495); Aristas2[13][9] = vv;
		vv.setID(12); vv.setAdy(13); vv.setPeso(50); vv.setX(585); vv.setY(540); vv.setXX(585); vv.setYY(585); Aristas2[13][10] = vv;
		vv.setID(13); vv.setAdy(12); vv.setPeso(50); vv.setX(585); vv.setY(585); vv.setXX(585); vv.setYY(540); Aristas2[13][11] = vv;
		vv.setID(13); vv.setAdy(16); vv.setPeso(50); vv.setX(585); vv.setY(585); vv.setXX(540); vv.setYY(585); Aristas2[13][12] = vv;
	}

	if (nivel == 3) {

		Vertice vv;
		vv.setID(1); vv.setAdy(5); vv.setPeso(50); vv.setX(90); vv.setY(135); vv.setXX(135); vv.setYY(135); Aristas2[1][1] = vv;

		vv.setID(2); vv.setAdy(8); vv.setPeso(50); vv.setX(315); vv.setY(90); vv.setXX(315); vv.setYY(135); Aristas2[1][2] = vv;

		vv.setID(3); vv.setAdy(11); vv.setPeso(50); vv.setX(495); vv.setY(90); vv.setXX(495); vv.setYY(135); Aristas2[1][3] = vv;

		vv.setID(4); vv.setAdy(5); vv.setPeso(50); vv.setX(90); vv.setY(135); vv.setXX(135); vv.setYY(135); Aristas2[1][4] = vv;

		vv.setID(5); vv.setAdy(4); vv.setPeso(50); vv.setX(135); vv.setY(135); vv.setXX(90); vv.setYY(135); Aristas2[1][5] = vv;
		vv.setID(5); vv.setAdy(6); vv.setPeso(50); vv.setX(135); vv.setY(135); vv.setXX(180); vv.setYY(90); Aristas2[1][6] = vv;
		vv.setID(5); vv.setAdy(13); vv.setPeso(50); vv.setX(135); vv.setY(135); vv.setXX(135); vv.setYY(180); Aristas2[1][7] = vv;

		vv.setID(6); vv.setAdy(5); vv.setPeso(50); vv.setX(180); vv.setY(135); vv.setXX(135); vv.setYY(135); Aristas2[1][8] = vv;
		vv.setID(6); vv.setAdy(7); vv.setPeso(50); vv.setX(180); vv.setY(135); vv.setXX(225); vv.setYY(135); Aristas2[1][9] = vv;

		vv.setID(7); vv.setAdy(6); vv.setPeso(50); vv.setX(225); vv.setY(135); vv.setXX(180); vv.setYY(135); Aristas2[1][10] = vv;
		vv.setID(7); vv.setAdy(14); vv.setPeso(50); vv.setX(225); vv.setY(135); vv.setXX(225); vv.setYY(180); Aristas2[1][11] = vv;

		vv.setID(8); vv.setAdy(2); vv.setPeso(50); vv.setX(315); vv.setY(135); vv.setXX(315); vv.setYY(90); Aristas2[1][12] = vv;
		vv.setID(8); vv.setAdy(15); vv.setPeso(50); vv.setX(315); vv.setY(135); vv.setXX(315); vv.setYY(180); Aristas2[1][13] = vv;

		vv.setID(9); vv.setAdy(10); vv.setPeso(50); vv.setX(405); vv.setY(135); vv.setXX(450); vv.setYY(135); Aristas2[1][14] = vv;
		vv.setID(9); vv.setAdy(16); vv.setPeso(50); vv.setX(405); vv.setY(135); vv.setXX(405); vv.setYY(180); Aristas2[1][15] = vv;

		vv.setID(10); vv.setAdy(9); vv.setPeso(50); vv.setX(450); vv.setY(135); vv.setXX(405); vv.setYY(135); Aristas2[1][16] = vv;
		vv.setID(10); vv.setAdy(11); vv.setPeso(50); vv.setX(450); vv.setY(135); vv.setXX(495); vv.setYY(135); Aristas2[1][17] = vv;

		vv.setID(11); vv.setAdy(10); vv.setPeso(50); vv.setX(495); vv.setY(135); vv.setXX(450); vv.setYY(135); Aristas2[1][18] = vv;
		vv.setID(11); vv.setAdy(12); vv.setPeso(50); vv.setX(495); vv.setY(135); vv.setXX(540); vv.setYY(135); Aristas2[1][19] = vv;
		vv.setID(11); vv.setAdy(3); vv.setPeso(50); vv.setX(495); vv.setY(135); vv.setXX(495); vv.setYY(90); Aristas2[2][1] = vv;
		vv.setID(11); vv.setAdy(17); vv.setPeso(50); vv.setX(495); vv.setY(135); vv.setXX(495); vv.setYY(180); Aristas2[2][2] = vv;

		vv.setID(12); vv.setAdy(11); vv.setPeso(50); vv.setX(540); vv.setY(135); vv.setXX(495); vv.setYY(135); Aristas2[2][3] = vv;

		vv.setID(13); vv.setAdy(5); vv.setPeso(50); vv.setX(135); vv.setY(180); vv.setXX(135); vv.setYY(135); Aristas2[2][4] = vv;
		vv.setID(13); vv.setAdy(18); vv.setPeso(50); vv.setX(135); vv.setY(180); vv.setXX(135); vv.setYY(225); Aristas2[2][5] = vv;

		vv.setID(14); vv.setAdy(7); vv.setPeso(50); vv.setX(225); vv.setY(180); vv.setXX(225); vv.setYY(135); Aristas2[2][6] = vv;
		vv.setID(14); vv.setAdy(19); vv.setPeso(50); vv.setX(225); vv.setY(180); vv.setXX(225); vv.setYY(225); Aristas2[2][7] = vv;

		vv.setID(15); vv.setAdy(8); vv.setPeso(50); vv.setX(315); vv.setY(180); vv.setXX(315); vv.setYY(135); Aristas2[2][8] = vv;
		vv.setID(15); vv.setAdy(21); vv.setPeso(50); vv.setX(315); vv.setY(180); vv.setXX(315); vv.setYY(225); Aristas2[2][9] = vv;

		vv.setID(16); vv.setAdy(9); vv.setPeso(50); vv.setX(405); vv.setY(180); vv.setXX(405); vv.setYY(135); Aristas2[2][10] = vv;
		vv.setID(16); vv.setAdy(23); vv.setPeso(50); vv.setX(405); vv.setY(180); vv.setXX(405); vv.setYY(225); Aristas2[2][11] = vv;

		vv.setID(17); vv.setAdy(11); vv.setPeso(50); vv.setX(495); vv.setY(180); vv.setXX(495); vv.setYY(135); Aristas2[2][12] = vv;
		vv.setID(17); vv.setAdy(24); vv.setPeso(50); vv.setX(495); vv.setY(180); vv.setXX(495); vv.setYY(225); Aristas2[2][13] = vv;

		vv.setID(18); vv.setAdy(13); vv.setPeso(50); vv.setX(135); vv.setY(225); vv.setXX(135); vv.setYY(180); Aristas2[2][14] = vv;
		vv.setID(18); vv.setAdy(25); vv.setPeso(50); vv.setX(135); vv.setY(225); vv.setXX(135); vv.setYY(270); Aristas2[2][15] = vv;

		vv.setID(19); vv.setAdy(14); vv.setPeso(50); vv.setX(225); vv.setY(225); vv.setXX(225); vv.setYY(180); Aristas2[2][16] = vv;
		vv.setID(19); vv.setAdy(20); vv.setPeso(50); vv.setX(225); vv.setY(225); vv.setXX(270); vv.setYY(225); Aristas2[2][17] = vv;

		vv.setID(20); vv.setAdy(19); vv.setPeso(50); vv.setX(270); vv.setY(225); vv.setXX(225); vv.setYY(225); Aristas2[2][18] = vv;
		vv.setID(20); vv.setAdy(21); vv.setPeso(50); vv.setX(270); vv.setY(225); vv.setXX(315); vv.setYY(225); Aristas2[2][19] = vv;

		vv.setID(21); vv.setAdy(15); vv.setPeso(50); vv.setX(315); vv.setY(225); vv.setXX(315); vv.setYY(180); Aristas2[3][1] = vv;
		vv.setID(21); vv.setAdy(26); vv.setPeso(50); vv.setX(315); vv.setY(225); vv.setXX(315); vv.setYY(270); Aristas2[3][2] = vv;
		vv.setID(21); vv.setAdy(20); vv.setPeso(50); vv.setX(315); vv.setY(225); vv.setXX(270); vv.setYY(225); Aristas2[3][3] = vv;
		vv.setID(21); vv.setAdy(22); vv.setPeso(50); vv.setX(315); vv.setY(225); vv.setXX(360); vv.setYY(225); Aristas2[3][4] = vv;

		vv.setID(22); vv.setAdy(21); vv.setPeso(50); vv.setX(360); vv.setY(225); vv.setXX(315); vv.setYY(225); Aristas2[3][5] = vv;
		vv.setID(22); vv.setAdy(23); vv.setPeso(50); vv.setX(360); vv.setY(225); vv.setXX(405); vv.setYY(225); Aristas2[3][6] = vv;


		vv.setID(23); vv.setAdy(22); vv.setPeso(50); vv.setX(405); vv.setY(225); vv.setXX(360); vv.setYY(225); Aristas2[3][7] = vv;
		vv.setID(23); vv.setAdy(16); vv.setPeso(50); vv.setX(405); vv.setY(225); vv.setXX(405); vv.setYY(180); Aristas2[3][8] = vv;

		vv.setID(24); vv.setAdy(17); vv.setPeso(50); vv.setX(495); vv.setY(225); vv.setXX(495); vv.setYY(180); Aristas2[3][9] = vv;
		vv.setID(24); vv.setAdy(27); vv.setPeso(50); vv.setX(495); vv.setY(225); vv.setXX(495); vv.setYY(270); Aristas2[3][10] = vv;

		vv.setID(25); vv.setAdy(18); vv.setPeso(50); vv.setX(135); vv.setY(270); vv.setXX(135); vv.setYY(225); Aristas2[3][11] = vv;
		vv.setID(25); vv.setAdy(28); vv.setPeso(50); vv.setX(135); vv.setY(270); vv.setXX(135); vv.setYY(315); Aristas2[3][12] = vv;

		vv.setID(26); vv.setAdy(21); vv.setPeso(50); vv.setX(315); vv.setY(270); vv.setXX(315); vv.setYY(225); Aristas2[3][13] = vv;
		vv.setID(26); vv.setAdy(31); vv.setPeso(50); vv.setX(315); vv.setY(270); vv.setXX(315); vv.setYY(315); Aristas2[3][14] = vv;

		vv.setID(27); vv.setAdy(24); vv.setPeso(50); vv.setX(495); vv.setY(270); vv.setXX(495); vv.setYY(225); Aristas2[3][15] = vv;
		vv.setID(27); vv.setAdy(34); vv.setPeso(50); vv.setX(495); vv.setY(270); vv.setXX(495); vv.setYY(315); Aristas2[3][16] = vv;

		vv.setID(28); vv.setAdy(25); vv.setPeso(50); vv.setX(135); vv.setY(315); vv.setXX(135); vv.setYY(270); Aristas2[3][17] = vv;
		vv.setID(28); vv.setAdy(35); vv.setPeso(50); vv.setX(135); vv.setY(315); vv.setXX(135); vv.setYY(360); Aristas2[3][18] = vv;
		vv.setID(28); vv.setAdy(29); vv.setPeso(50); vv.setX(135); vv.setY(315); vv.setXX(180); vv.setYY(315); Aristas2[3][19] = vv;

		vv.setID(29); vv.setAdy(28); vv.setPeso(50); vv.setX(180); vv.setY(315); vv.setXX(135); vv.setYY(315); Aristas2[4][1] = vv;

		vv.setID(30); vv.setAdy(31); vv.setPeso(50); vv.setX(270); vv.setY(315); vv.setXX(315); vv.setYY(315); Aristas2[4][2] = vv;

		vv.setID(31); vv.setAdy(30); vv.setPeso(50); vv.setX(315); vv.setY(315); vv.setXX(270); vv.setYY(315); Aristas2[4][3] = vv;
		vv.setID(31); vv.setAdy(32); vv.setPeso(50); vv.setX(315); vv.setY(315); vv.setXX(360); vv.setYY(315); Aristas2[4][4] = vv;
		vv.setID(31); vv.setAdy(26); vv.setPeso(50); vv.setX(315); vv.setY(315); vv.setXX(315); vv.setYY(270); Aristas2[4][5] = vv;

		vv.setID(32); vv.setAdy(31); vv.setPeso(50); vv.setX(360); vv.setY(315); vv.setXX(315); vv.setYY(315); Aristas2[4][6] = vv;

		vv.setID(33); vv.setAdy(34); vv.setPeso(50); vv.setX(450); vv.setY(315); vv.setXX(495); vv.setYY(315); Aristas2[4][7] = vv;

		vv.setID(34); vv.setAdy(33); vv.setPeso(50); vv.setX(495); vv.setY(315); vv.setXX(450); vv.setYY(315); Aristas2[4][8] = vv;
		vv.setID(34); vv.setAdy(27); vv.setPeso(50); vv.setX(495); vv.setY(315); vv.setXX(450); vv.setYY(270); Aristas2[4][9] = vv;
		vv.setID(34); vv.setAdy(36); vv.setPeso(50); vv.setX(495); vv.setY(315); vv.setXX(450); vv.setYY(360); Aristas2[4][10] = vv;

		vv.setID(35); vv.setAdy(28); vv.setPeso(50); vv.setX(135); vv.setY(360); vv.setXX(135); vv.setYY(315); Aristas2[4][11] = vv;
		vv.setID(35); vv.setAdy(37); vv.setPeso(50); vv.setX(135); vv.setY(360); vv.setXX(135); vv.setYY(405); Aristas2[4][12] = vv;

		vv.setID(36); vv.setAdy(34); vv.setPeso(50); vv.setX(495); vv.setY(360); vv.setXX(495); vv.setYY(315); Aristas2[4][13] = vv;
		vv.setID(36); vv.setAdy(43); vv.setPeso(50); vv.setX(495); vv.setY(360); vv.setXX(495); vv.setYY(405); Aristas2[4][14] = vv;

		vv.setID(37); vv.setAdy(35); vv.setPeso(50); vv.setX(135); vv.setY(405); vv.setXX(135); vv.setYY(360); Aristas2[4][15] = vv;
		vv.setID(37); vv.setAdy(44); vv.setPeso(50); vv.setX(135); vv.setY(405); vv.setXX(135); vv.setYY(450); Aristas2[4][16] = vv;

		vv.setID(38); vv.setAdy(45); vv.setPeso(50); vv.setX(225); vv.setY(405); vv.setXX(225); vv.setYY(450); Aristas2[4][17] = vv;
		vv.setID(38); vv.setAdy(39); vv.setPeso(50); vv.setX(225); vv.setY(405); vv.setXX(270); vv.setYY(405); Aristas2[4][18] = vv;

		vv.setID(39); vv.setAdy(38); vv.setPeso(50); vv.setX(270); vv.setY(405); vv.setXX(225); vv.setYY(405); Aristas2[4][19] = vv;
		vv.setID(39); vv.setAdy(40); vv.setPeso(50); vv.setX(270); vv.setY(405); vv.setXX(315); vv.setYY(405); Aristas2[5][1] = vv;

		vv.setID(40); vv.setAdy(39); vv.setPeso(50); vv.setX(315); vv.setY(405); vv.setXX(270); vv.setYY(405); Aristas2[5][2] = vv;
		vv.setID(40); vv.setAdy(41); vv.setPeso(50); vv.setX(315); vv.setY(405); vv.setXX(360); vv.setYY(405); Aristas2[5][3] = vv;
		vv.setID(40); vv.setAdy(46); vv.setPeso(50); vv.setX(315); vv.setY(405); vv.setXX(315); vv.setYY(450); Aristas2[5][4] = vv;

		vv.setID(41); vv.setAdy(40); vv.setPeso(50); vv.setX(360); vv.setY(405); vv.setXX(315); vv.setYY(405); Aristas2[5][5] = vv;
		vv.setID(41); vv.setAdy(42); vv.setPeso(50); vv.setX(360); vv.setY(405); vv.setXX(405); vv.setYY(405); Aristas2[5][6] = vv;

		vv.setID(42); vv.setAdy(41); vv.setPeso(50); vv.setX(405); vv.setY(405); vv.setXX(360); vv.setYY(405); Aristas2[5][7] = vv;
		vv.setID(42); vv.setAdy(47); vv.setPeso(50); vv.setX(405); vv.setY(405); vv.setXX(360); vv.setYY(450); Aristas2[5][8] = vv;

		vv.setID(43); vv.setAdy(36); vv.setPeso(50); vv.setX(495); vv.setY(405); vv.setXX(495); vv.setYY(360); Aristas2[5][9] = vv;
		vv.setID(43); vv.setAdy(48); vv.setPeso(50); vv.setX(495); vv.setY(405); vv.setXX(495); vv.setYY(450); Aristas2[5][10] = vv;

		vv.setID(44); vv.setAdy(37); vv.setPeso(50); vv.setX(135); vv.setY(450); vv.setXX(135); vv.setYY(405); Aristas2[5][11] = vv;
		vv.setID(44); vv.setAdy(50); vv.setPeso(50); vv.setX(135); vv.setY(450); vv.setXX(135); vv.setYY(495); Aristas2[5][12] = vv;

		vv.setID(45); vv.setAdy(38); vv.setPeso(50); vv.setX(225); vv.setY(450); vv.setXX(225); vv.setYY(405); Aristas2[5][13] = vv;
		vv.setID(45); vv.setAdy(52); vv.setPeso(50); vv.setX(225); vv.setY(450); vv.setXX(225); vv.setYY(495); Aristas2[5][14] = vv;

		vv.setID(46); vv.setAdy(40); vv.setPeso(50); vv.setX(315); vv.setY(450); vv.setXX(315); vv.setYY(405); Aristas2[5][15] = vv;
		vv.setID(46); vv.setAdy(53); vv.setPeso(50); vv.setX(315); vv.setY(450); vv.setXX(315); vv.setYY(495); Aristas2[5][16] = vv;

		vv.setID(47); vv.setAdy(42); vv.setPeso(50); vv.setX(405); vv.setY(450); vv.setXX(405); vv.setYY(405); Aristas2[5][17] = vv;
		vv.setID(47); vv.setAdy(54); vv.setPeso(50); vv.setX(405); vv.setY(450); vv.setXX(405); vv.setYY(495); Aristas2[5][18] = vv;

		vv.setID(48); vv.setAdy(43); vv.setPeso(50); vv.setX(495); vv.setY(450); vv.setXX(405); vv.setYY(405); Aristas2[5][19] = vv;
		vv.setID(48); vv.setAdy(56); vv.setPeso(50); vv.setX(495); vv.setY(450); vv.setXX(405); vv.setYY(495); Aristas2[6][1] = vv;

		vv.setID(49); vv.setAdy(50); vv.setPeso(50); vv.setX(90); vv.setY(495); vv.setXX(135); vv.setYY(495); Aristas2[6][2] = vv;

		vv.setID(50); vv.setAdy(44); vv.setPeso(50); vv.setX(135); vv.setY(495); vv.setXX(135); vv.setYY(450); Aristas2[6][3] = vv;
		vv.setID(50); vv.setAdy(58); vv.setPeso(50); vv.setX(135); vv.setY(495); vv.setXX(135); vv.setYY(540); Aristas2[6][4] = vv;
		vv.setID(50); vv.setAdy(49); vv.setPeso(50); vv.setX(135); vv.setY(495); vv.setXX(90); vv.setYY(495); Aristas2[6][5] = vv;
		vv.setID(50); vv.setAdy(51); vv.setPeso(50); vv.setX(135); vv.setY(495); vv.setXX(180); vv.setYY(495); Aristas2[6][6] = vv;

		vv.setID(51); vv.setAdy(50); vv.setPeso(50); vv.setX(180); vv.setY(495); vv.setXX(135); vv.setYY(495); Aristas2[6][7] = vv;
		vv.setID(51); vv.setAdy(52); vv.setPeso(50); vv.setX(180); vv.setY(495); vv.setXX(225); vv.setYY(495); Aristas2[6][8] = vv;

		vv.setID(52); vv.setAdy(51); vv.setPeso(50); vv.setX(225); vv.setY(495); vv.setXX(180); vv.setYY(495); Aristas2[6][9] = vv;
		vv.setID(52); vv.setAdy(45); vv.setPeso(50); vv.setX(225); vv.setY(495); vv.setXX(225); vv.setYY(450); Aristas2[6][10] = vv;

		vv.setID(53); vv.setAdy(46); vv.setPeso(50); vv.setX(315); vv.setY(495); vv.setXX(315); vv.setYY(450); Aristas2[6][11] = vv;
		vv.setID(53); vv.setAdy(59); vv.setPeso(50); vv.setX(315); vv.setY(495); vv.setXX(315); vv.setYY(540); Aristas2[6][12] = vv;

		vv.setID(54); vv.setAdy(47); vv.setPeso(50); vv.setX(405); vv.setY(495); vv.setXX(405); vv.setYY(450); Aristas2[6][13] = vv;
		vv.setID(54); vv.setAdy(55); vv.setPeso(50); vv.setX(405); vv.setY(495); vv.setXX(450); vv.setYY(450); Aristas2[6][14] = vv;

		vv.setID(55); vv.setAdy(54); vv.setPeso(50); vv.setX(450); vv.setY(495); vv.setXX(405); vv.setYY(495); Aristas2[6][15] = vv;
		vv.setID(55); vv.setAdy(56); vv.setPeso(50); vv.setX(450); vv.setY(495); vv.setXX(495); vv.setYY(495); Aristas2[6][16] = vv;

		vv.setID(56); vv.setAdy(55); vv.setPeso(50); vv.setX(495); vv.setY(495); vv.setXX(450); vv.setYY(495); Aristas2[6][17] = vv;
		vv.setID(56); vv.setAdy(57); vv.setPeso(50); vv.setX(495); vv.setY(495); vv.setXX(540); vv.setYY(495); Aristas2[6][18] = vv;
		vv.setID(56); vv.setAdy(48); vv.setPeso(50); vv.setX(495); vv.setY(495); vv.setXX(495); vv.setYY(450); Aristas2[6][19] = vv;
		vv.setID(56); vv.setAdy(60); vv.setPeso(50); vv.setX(495); vv.setY(495); vv.setXX(495); vv.setYY(540); Aristas2[7][1] = vv;

		vv.setID(57); vv.setAdy(56); vv.setPeso(50); vv.setX(540); vv.setY(495); vv.setXX(495); vv.setYY(495); Aristas2[7][2] = vv;

		vv.setID(58); vv.setAdy(50); vv.setPeso(50); vv.setX(135); vv.setY(540); vv.setXX(135); vv.setYY(495); Aristas2[7][3] = vv;
		vv.setID(59); vv.setAdy(53); vv.setPeso(50); vv.setX(315); vv.setY(540); vv.setXX(315); vv.setYY(495); Aristas2[7][4] = vv;
		vv.setID(60); vv.setAdy(56); vv.setPeso(50); vv.setX(495); vv.setY(540); vv.setXX(495); vv.setYY(495); Aristas2[7][5] = vv;
	}

	if (nivel == 4) {
		if (nivel == 8) {
			Vertice vv;
			vv.setID(1); vv.setAdy(4); vv.setPeso(50); vv.setX(90); vv.setY(135); vv.setXX(135); vv.setYY(135); Aristas2[1][1] = vv;
			vv.setID(2); vv.setAdy(9); vv.setPeso(50); vv.setX(90); vv.setY(495); vv.setXX(135); vv.setYY(495); Aristas2[1][2] = vv;
			vv.setID(3); vv.setAdy(4); vv.setPeso(50); vv.setX(135); vv.setY(90); vv.setXX(135); vv.setYY(135); Aristas2[1][3] = vv;
			vv.setID(4); vv.setAdy(3); vv.setPeso(50); vv.setX(135); vv.setY(135); vv.setXX(135); vv.setYY(90); Aristas2[1][4] = vv;
			vv.setID(4); vv.setAdy(1); vv.setPeso(50); vv.setX(135); vv.setY(135); vv.setXX(90); vv.setYY(135); Aristas2[1][5] = vv;
			vv.setID(4); vv.setAdy(5); vv.setPeso(50); vv.setX(135); vv.setY(135); vv.setXX(135); vv.setYY(180); Aristas2[1][6] = vv;
			vv.setID(4); vv.setAdy(11); vv.setPeso(50); vv.setX(135); vv.setY(135); vv.setXX(180); vv.setYY(135); Aristas2[1][7] = vv;
			vv.setID(6); vv.setAdy(13); vv.setPeso(50); vv.setX(135); vv.setY(225); vv.setXX(180); vv.setYY(225); Aristas2[1][8] = vv;
			vv.setID(7); vv.setAdy(16); vv.setPeso(50); vv.setX(135); vv.setY(405); vv.setXX(180); vv.setYY(405); Aristas2[1][9] = vv;
			vv.setID(9); vv.setAdy(2); vv.setPeso(50); vv.setX(135); vv.setY(495); vv.setXX(90); vv.setYY(495); Aristas2[1][10] = vv;
			vv.setID(9); vv.setAdy(10); vv.setPeso(50); vv.setX(135); vv.setY(495); vv.setXX(135); vv.setYY(540); Aristas2[1][11] = vv;
			vv.setID(9); vv.setAdy(18); vv.setPeso(50); vv.setX(135); vv.setY(495); vv.setXX(180); vv.setYY(495); Aristas2[1][12] = vv;
			vv.setID(10); vv.setAdy(9); vv.setPeso(50); vv.setX(135); vv.setY(540); vv.setXX(135); vv.setYY(495); Aristas2[1][13] = vv;
			vv.setID(11); vv.setAdy(4); vv.setPeso(50); vv.setX(180); vv.setY(135); vv.setXX(135); vv.setYY(135); Aristas2[1][14] = vv;
			vv.setID(11); vv.setAdy(12); vv.setPeso(50); vv.setX(180); vv.setY(135); vv.setXX(180); vv.setYY(180); Aristas2[1][15] = vv;
			vv.setID(11); vv.setAdy(19); vv.setPeso(50); vv.setX(180); vv.setY(135); vv.setXX(225); vv.setYY(135); Aristas2[1][16] = vv;
			vv.setID(12); vv.setAdy(11); vv.setPeso(50); vv.setX(180); vv.setY(180); vv.setXX(180); vv.setYY(135); Aristas2[1][17] = vv;
			vv.setID(12); vv.setAdy(13); vv.setPeso(50); vv.setX(180); vv.setY(180); vv.setXX(180); vv.setYY(225); Aristas2[1][18] = vv;
			vv.setID(12); vv.setAdy(20); vv.setPeso(50); vv.setX(180); vv.setY(180); vv.setXX(225); vv.setYY(180); Aristas2[1][19] = vv;
			vv.setID(13); vv.setAdy(6); vv.setPeso(50); vv.setX(180); vv.setY(225); vv.setXX(135); vv.setYY(225); Aristas2[2][1] = vv;
			vv.setID(13); vv.setAdy(12); vv.setPeso(50); vv.setX(180); vv.setY(225); vv.setXX(180); vv.setYY(180); Aristas2[2][2] = vv;
			vv.setID(13); vv.setAdy(14); vv.setPeso(50); vv.setX(180); vv.setY(225); vv.setXX(180); vv.setYY(270); Aristas2[2][3] = vv;
			vv.setID(14); vv.setAdy(21); vv.setPeso(50); vv.setX(180); vv.setY(270); vv.setXX(225); vv.setYY(270); Aristas2[2][4] = vv;
			vv.setID(15); vv.setAdy(23); vv.setPeso(50); vv.setX(180); vv.setY(360); vv.setXX(225); vv.setYY(360); Aristas2[2][5] = vv;
			vv.setID(15); vv.setAdy(16); vv.setPeso(50); vv.setX(180); vv.setY(360); vv.setXX(180); vv.setYY(405); Aristas2[2][6] = vv;
			vv.setID(16); vv.setAdy(15); vv.setPeso(50); vv.setX(180); vv.setY(405); vv.setXX(180); vv.setYY(360); Aristas2[2][7] = vv;
			vv.setID(16); vv.setAdy(7); vv.setPeso(50); vv.setX(180); vv.setY(405); vv.setXX(135); vv.setYY(405); Aristas2[2][8] = vv;
			vv.setID(16); vv.setAdy(17); vv.setPeso(50); vv.setX(180); vv.setY(405); vv.setXX(180); vv.setYY(450); Aristas2[2][9] = vv;
			vv.setID(17); vv.setAdy(16); vv.setPeso(50); vv.setX(180); vv.setY(450); vv.setXX(180); vv.setYY(405); Aristas2[2][10] = vv;
			vv.setID(17); vv.setAdy(18); vv.setPeso(50); vv.setX(180); vv.setY(450); vv.setXX(180); vv.setYY(495); Aristas2[2][11] = vv;
			vv.setID(17); vv.setAdy(24); vv.setPeso(50); vv.setX(180); vv.setY(450); vv.setXX(225); vv.setYY(450); Aristas2[2][12] = vv;
			vv.setID(18); vv.setAdy(17); vv.setPeso(50); vv.setX(180); vv.setY(495); vv.setXX(180); vv.setYY(450); Aristas2[2][13] = vv;
			vv.setID(18); vv.setAdy(9); vv.setPeso(50); vv.setX(180); vv.setY(495); vv.setXX(135); vv.setYY(495); Aristas2[2][14] = vv;
			vv.setID(18); vv.setAdy(25); vv.setPeso(50); vv.setX(180); vv.setY(495); vv.setXX(225); vv.setYY(495); Aristas2[2][15] = vv;
			vv.setID(19); vv.setAdy(11); vv.setPeso(50); vv.setX(225); vv.setY(135); vv.setXX(180); vv.setYY(135); Aristas2[2][16] = vv;
			vv.setID(19); vv.setAdy(20); vv.setPeso(50); vv.setX(225); vv.setY(135); vv.setXX(225); vv.setYY(180); Aristas2[2][17] = vv;
			vv.setID(19); vv.setAdy(26); vv.setPeso(50); vv.setX(225); vv.setY(135); vv.setXX(270); vv.setYY(135); Aristas2[2][18] = vv;
			vv.setID(20); vv.setAdy(19); vv.setPeso(50); vv.setX(225); vv.setY(180); vv.setXX(225); vv.setYY(135); Aristas2[2][19] = vv;
			vv.setID(20); vv.setAdy(12); vv.setPeso(50); vv.setX(225); vv.setY(180); vv.setXX(180); vv.setYY(180); Aristas2[3][1] = vv;
			vv.setID(21); vv.setAdy(14); vv.setPeso(50); vv.setX(225); vv.setY(270); vv.setXX(180); vv.setYY(270); Aristas2[3][2] = vv;
			vv.setID(21); vv.setAdy(22); vv.setPeso(50); vv.setX(225); vv.setY(270); vv.setXX(225); vv.setYY(315); Aristas2[3][3] = vv;
			vv.setID(22); vv.setAdy(21); vv.setPeso(50); vv.setX(225); vv.setY(315); vv.setXX(225); vv.setYY(270); Aristas2[3][4] = vv;
			vv.setID(22); vv.setAdy(23); vv.setPeso(50); vv.setX(225); vv.setY(315); vv.setXX(225); vv.setYY(360); Aristas2[3][5] = vv;
			vv.setID(22); vv.setAdy(27); vv.setPeso(50); vv.setX(225); vv.setY(315); vv.setXX(270); vv.setYY(315); Aristas2[3][6] = vv;
			vv.setID(23); vv.setAdy(22); vv.setPeso(50); vv.setX(225); vv.setY(360); vv.setXX(225); vv.setYY(315); Aristas2[3][7] = vv;
			vv.setID(23); vv.setAdy(15); vv.setPeso(50); vv.setX(225); vv.setY(360); vv.setXX(180); vv.setYY(360); Aristas2[3][8] = vv;
			vv.setID(24); vv.setAdy(17); vv.setPeso(50); vv.setX(225); vv.setY(450); vv.setXX(180); vv.setYY(450); Aristas2[3][9] = vv;
			vv.setID(24); vv.setAdy(25); vv.setPeso(50); vv.setX(225); vv.setY(450); vv.setXX(225); vv.setYY(495); Aristas2[3][10] = vv;
			vv.setID(25); vv.setAdy(24); vv.setPeso(50); vv.setX(225); vv.setY(495); vv.setXX(225); vv.setYY(450); Aristas2[3][11] = vv;
			vv.setID(25); vv.setAdy(28); vv.setPeso(50); vv.setX(225); vv.setY(495); vv.setXX(270); vv.setYY(495); Aristas2[3][12] = vv;
			vv.setID(26); vv.setAdy(19); vv.setPeso(50); vv.setX(270); vv.setY(135); vv.setXX(225); vv.setYY(135); Aristas2[3][13] = vv;
			vv.setID(26); vv.setAdy(30); vv.setPeso(50); vv.setX(270); vv.setY(135); vv.setXX(315); vv.setYY(135); Aristas2[3][14] = vv;
			vv.setID(27); vv.setAdy(22); vv.setPeso(50); vv.setX(270); vv.setY(315); vv.setXX(225); vv.setYY(315); Aristas2[3][15] = vv;
			vv.setID(27); vv.setAdy(33); vv.setPeso(50); vv.setX(270); vv.setY(315); vv.setXX(315); vv.setYY(315); Aristas2[3][16] = vv;
			vv.setID(28); vv.setAdy(25); vv.setPeso(50); vv.setX(270); vv.setY(495); vv.setXX(225); vv.setYY(495); Aristas2[3][17] = vv;
			vv.setID(28); vv.setAdy(36); vv.setPeso(50); vv.setX(270); vv.setY(495); vv.setXX(315); vv.setYY(495); Aristas2[3][18] = vv;
			vv.setID(29); vv.setAdy(30); vv.setPeso(50); vv.setX(315); vv.setY(90); vv.setXX(315); vv.setYY(135); Aristas2[3][19] = vv;
			vv.setID(30); vv.setAdy(29); vv.setPeso(50); vv.setX(315); vv.setY(135); vv.setXX(315); vv.setYY(90); Aristas2[4][1] = vv;
			vv.setID(30); vv.setAdy(26); vv.setPeso(50); vv.setX(315); vv.setY(135); vv.setXX(270); vv.setYY(135); Aristas2[4][2] = vv;
			vv.setID(30); vv.setAdy(31); vv.setPeso(50); vv.setX(315); vv.setY(135); vv.setXX(315); vv.setYY(180); Aristas2[4][3] = vv;
			vv.setID(30); vv.setAdy(38); vv.setPeso(50); vv.setX(315); vv.setY(135); vv.setXX(360); vv.setYY(135); Aristas2[4][4] = vv;
			vv.setID(31); vv.setAdy(30); vv.setPeso(50); vv.setX(315); vv.setY(180); vv.setXX(315); vv.setYY(135); Aristas2[4][5] = vv;
			vv.setID(32); vv.setAdy(33); vv.setPeso(50); vv.setX(315); vv.setY(270); vv.setXX(315); vv.setYY(315); Aristas2[4][6] = vv;
			vv.setID(33); vv.setAdy(32); vv.setPeso(50); vv.setX(315); vv.setY(315); vv.setXX(315); vv.setYY(270); Aristas2[4][7] = vv;
			vv.setID(33); vv.setAdy(27); vv.setPeso(50); vv.setX(315); vv.setY(315); vv.setXX(270); vv.setYY(315); Aristas2[4][8] = vv;
			vv.setID(33); vv.setAdy(34); vv.setPeso(50); vv.setX(315); vv.setY(315); vv.setXX(315); vv.setYY(360); Aristas2[4][9] = vv;
			vv.setID(34); vv.setAdy(33); vv.setPeso(50); vv.setX(315); vv.setY(360); vv.setXX(315); vv.setYY(315); Aristas2[4][10] = vv;
			vv.setID(35); vv.setAdy(36); vv.setPeso(50); vv.setX(315); vv.setY(450); vv.setXX(315); vv.setYY(495); Aristas2[4][11] = vv;
			vv.setID(36); vv.setAdy(35); vv.setPeso(50); vv.setX(315); vv.setY(495); vv.setXX(315); vv.setYY(450); Aristas2[4][12] = vv;
			vv.setID(36); vv.setAdy(28); vv.setPeso(50); vv.setX(315); vv.setY(495); vv.setXX(270); vv.setYY(495); Aristas2[4][13] = vv;
			vv.setID(36); vv.setAdy(37); vv.setPeso(50); vv.setX(315); vv.setY(495); vv.setXX(315); vv.setYY(540); Aristas2[4][14] = vv;
			vv.setID(36); vv.setAdy(39); vv.setPeso(50); vv.setX(315); vv.setY(495); vv.setXX(360); vv.setYY(495); Aristas2[4][15] = vv;
			vv.setID(37); vv.setAdy(36); vv.setPeso(50); vv.setX(315); vv.setY(540); vv.setXX(315); vv.setYY(495); Aristas2[4][16] = vv;
			vv.setID(38); vv.setAdy(30); vv.setPeso(50); vv.setX(360); vv.setY(135); vv.setXX(315); vv.setYY(135); Aristas2[4][17] = vv;
			vv.setID(38); vv.setAdy(40); vv.setPeso(50); vv.setX(360); vv.setY(135); vv.setXX(405); vv.setYY(135); Aristas2[4][18] = vv;
			vv.setID(39); vv.setAdy(46); vv.setPeso(50); vv.setX(360); vv.setY(495); vv.setXX(405); vv.setYY(495); Aristas2[4][19] = vv;
			vv.setID(39); vv.setAdy(36); vv.setPeso(50); vv.setX(360); vv.setY(495); vv.setXX(315); vv.setYY(495); Aristas2[5][1] = vv;
			vv.setID(40); vv.setAdy(38); vv.setPeso(50); vv.setX(405); vv.setY(135); vv.setXX(360); vv.setYY(135); Aristas2[5][2] = vv;
			vv.setID(40); vv.setAdy(41); vv.setPeso(50); vv.setX(405); vv.setY(135); vv.setXX(405); vv.setYY(180); Aristas2[5][3] = vv;
			vv.setID(40); vv.setAdy(47); vv.setPeso(50); vv.setX(405); vv.setY(135); vv.setXX(450); vv.setYY(135); Aristas2[5][4] = vv;
			vv.setID(41); vv.setAdy(40); vv.setPeso(50); vv.setX(405); vv.setY(180); vv.setXX(405); vv.setYY(135); Aristas2[5][5] = vv;
			vv.setID(41); vv.setAdy(48); vv.setPeso(50); vv.setX(405); vv.setY(180); vv.setXX(450); vv.setYY(135); Aristas2[5][6] = vv;
			vv.setID(42); vv.setAdy(50); vv.setPeso(50); vv.setX(405); vv.setY(270); vv.setXX(450); vv.setYY(270); Aristas2[5][7] = vv;
			vv.setID(42); vv.setAdy(43); vv.setPeso(50); vv.setX(405); vv.setY(270); vv.setXX(405); vv.setYY(315); Aristas2[5][8] = vv;
			vv.setID(43); vv.setAdy(42); vv.setPeso(50); vv.setX(405); vv.setY(315); vv.setXX(405); vv.setYY(270); Aristas2[5][9] = vv;
			vv.setID(43); vv.setAdy(44); vv.setPeso(50); vv.setX(405); vv.setY(315); vv.setXX(405); vv.setYY(360); Aristas2[5][10] = vv;
			vv.setID(44); vv.setAdy(43); vv.setPeso(50); vv.setX(405); vv.setY(360); vv.setXX(405); vv.setYY(315); Aristas2[5][11] = vv;
			vv.setID(44); vv.setAdy(51); vv.setPeso(50); vv.setX(405); vv.setY(360); vv.setXX(450); vv.setYY(360); Aristas2[5][12] = vv;
			vv.setID(45); vv.setAdy(53); vv.setPeso(50); vv.setX(405); vv.setY(450); vv.setXX(450); vv.setYY(450); Aristas2[5][13] = vv;
			vv.setID(45); vv.setAdy(46); vv.setPeso(50); vv.setX(405); vv.setY(450); vv.setXX(405); vv.setYY(495); Aristas2[5][14] = vv;
			vv.setID(46); vv.setAdy(39); vv.setPeso(50); vv.setX(405); vv.setY(495); vv.setXX(360); vv.setYY(495); Aristas2[5][15] = vv;
			vv.setID(46); vv.setAdy(45); vv.setPeso(50); vv.setX(405); vv.setY(495); vv.setXX(405); vv.setYY(450); Aristas2[5][16] = vv;
			vv.setID(46); vv.setAdy(54); vv.setPeso(50); vv.setX(405); vv.setY(495); vv.setXX(450); vv.setYY(495); Aristas2[5][17] = vv;
			vv.setID(47); vv.setAdy(40); vv.setPeso(50); vv.setX(450); vv.setY(135); vv.setXX(405); vv.setYY(135); Aristas2[5][18] = vv;
			vv.setID(47); vv.setAdy(48); vv.setPeso(50); vv.setX(450); vv.setY(135); vv.setXX(450); vv.setYY(180); Aristas2[5][19] = vv;
			vv.setID(47); vv.setAdy(56); vv.setPeso(50); vv.setX(450); vv.setY(135); vv.setXX(495); vv.setYY(135); Aristas2[6][1] = vv;
			vv.setID(48); vv.setAdy(47); vv.setPeso(50); vv.setX(450); vv.setY(180); vv.setXX(450); vv.setYY(135); Aristas2[6][2] = vv;
			vv.setID(48); vv.setAdy(41); vv.setPeso(50); vv.setX(450); vv.setY(180); vv.setXX(405); vv.setYY(180); Aristas2[6][3] = vv;
			vv.setID(48); vv.setAdy(49); vv.setPeso(50); vv.setX(450); vv.setY(180); vv.setXX(450); vv.setYY(225); Aristas2[6][4] = vv;
			vv.setID(49); vv.setAdy(48); vv.setPeso(50); vv.setX(450); vv.setY(225); vv.setXX(450); vv.setYY(180); Aristas2[6][5] = vv;
			vv.setID(49); vv.setAdy(50); vv.setPeso(50); vv.setX(450); vv.setY(225); vv.setXX(450); vv.setYY(270); Aristas2[6][6] = vv;
			vv.setID(49); vv.setAdy(58); vv.setPeso(50); vv.setX(450); vv.setY(225); vv.setXX(495); vv.setYY(225); Aristas2[6][7] = vv;
			vv.setID(50); vv.setAdy(49); vv.setPeso(50); vv.setX(450); vv.setY(270); vv.setXX(450); vv.setYY(225); Aristas2[6][8] = vv;
			vv.setID(50); vv.setAdy(42); vv.setPeso(50); vv.setX(450); vv.setY(270); vv.setXX(405); vv.setYY(270); Aristas2[6][9] = vv;
			vv.setID(51); vv.setAdy(44); vv.setPeso(50); vv.setX(450); vv.setY(360); vv.setXX(405); vv.setYY(360); Aristas2[6][10] = vv;
			vv.setID(51); vv.setAdy(52); vv.setPeso(50); vv.setX(450); vv.setY(360); vv.setXX(450); vv.setYY(405); Aristas2[6][11] = vv;
			vv.setID(52); vv.setAdy(51); vv.setPeso(50); vv.setX(450); vv.setY(405); vv.setXX(450); vv.setYY(360); Aristas2[6][12] = vv;
			vv.setID(52); vv.setAdy(53); vv.setPeso(50); vv.setX(450); vv.setY(405); vv.setXX(450); vv.setYY(450); Aristas2[6][13] = vv;
			vv.setID(52); vv.setAdy(59); vv.setPeso(50); vv.setX(450); vv.setY(405); vv.setXX(495); vv.setYY(405); Aristas2[6][14] = vv;
			vv.setID(53); vv.setAdy(52); vv.setPeso(50); vv.setX(450); vv.setY(450); vv.setXX(450); vv.setYY(405); Aristas2[6][15] = vv;
			vv.setID(53); vv.setAdy(45); vv.setPeso(50); vv.setX(450); vv.setY(450); vv.setXX(405); vv.setYY(450); Aristas2[6][16] = vv;
			vv.setID(53); vv.setAdy(54); vv.setPeso(50); vv.setX(450); vv.setY(450); vv.setXX(450); vv.setYY(495); Aristas2[6][17] = vv;
			vv.setID(54); vv.setAdy(53); vv.setPeso(50); vv.setX(450); vv.setY(495); vv.setXX(450); vv.setYY(450); Aristas2[6][18] = vv;
			vv.setID(54); vv.setAdy(46); vv.setPeso(50); vv.setX(450); vv.setY(495); vv.setXX(405); vv.setYY(495); Aristas2[6][19] = vv;
			vv.setID(54); vv.setAdy(61); vv.setPeso(50); vv.setX(450); vv.setY(495); vv.setXX(495); vv.setYY(495); Aristas2[7][1] = vv;
			vv.setID(55); vv.setAdy(56); vv.setPeso(50); vv.setX(495); vv.setY(90); vv.setXX(495); vv.setYY(135); Aristas2[7][2] = vv;
			vv.setID(56); vv.setAdy(55); vv.setPeso(50); vv.setX(495); vv.setY(135); vv.setXX(495); vv.setYY(90); Aristas2[7][3] = vv;
			vv.setID(56); vv.setAdy(47); vv.setPeso(50); vv.setX(495); vv.setY(135); vv.setXX(450); vv.setYY(135); Aristas2[7][4] = vv;
			vv.setID(56); vv.setAdy(63); vv.setPeso(50); vv.setX(495); vv.setY(135); vv.setXX(540); vv.setYY(135); Aristas2[7][5] = vv;
			vv.setID(58); vv.setAdy(49); vv.setPeso(50); vv.setX(495); vv.setY(225); vv.setXX(450); vv.setYY(225); Aristas2[7][6] = vv;
			vv.setID(59); vv.setAdy(52); vv.setPeso(50); vv.setX(495); vv.setY(405); vv.setXX(450); vv.setYY(405); Aristas2[7][7] = vv;
			vv.setID(61); vv.setAdy(54); vv.setPeso(50); vv.setX(495); vv.setY(495); vv.setXX(450); vv.setYY(495); Aristas2[7][8] = vv;
			vv.setID(62); vv.setAdy(61); vv.setPeso(50); vv.setX(495); vv.setY(540); vv.setXX(495); vv.setYY(495); Aristas2[7][9] = vv;
			vv.setID(63); vv.setAdy(56); vv.setPeso(50); vv.setX(540); vv.setY(135); vv.setXX(495); vv.setYY(135); Aristas2[7][10] = vv;
			vv.setID(64); vv.setAdy(61); vv.setPeso(50); vv.setX(540); vv.setY(495); vv.setXX(495); vv.setYY(495); Aristas2[7][11] = vv;











		}

	}
		

}

void Dijkstra::init(){
	for (int i = 1; i <= V; ++i) {
		distancia[i] = INF;  //inicializamos todas las distancias con valor infinito
		visitado[i] = false; //inicializamos todos los vértices como no visitados
		previo[i] = -1;      //inicializamos el previo del vertice i con -1
	}
}

void Dijkstra::relajacion(int actual, int adyacente, int peso){
	if (distancia[actual] + peso < distancia[adyacente]) {
		distancia[adyacente] = distancia[actual] + peso;  
		previo[adyacente] = actual;                        
		Q.push(Node(adyacente, distancia[adyacente])); 
	}
}

void Dijkstra::print(int destino){
	//cout << "DEs " << destino<<endl;
	if (previo[destino] != -1) //si aun poseo un vertice previo
		print(previo[destino]);  //recursivamente sigo explorando
	//cout << " des " << destino << endl;
	v.push_back(destino);
	//LlenarRuta(destino);
}

void Dijkstra::dijkstra(int inicial,int destino){
	init(); //inicializamos nuestros arreglos
	Q.push(Node(inicial, 0)); //Insertamos el vértice inicial en la Cola de Prioridad
	distancia[inicial] = 0;      //Este paso es importante, inicializamos la distancia del inicial como 0
	int actual, adyacente, peso;
	while (!Q.empty()) {                   //Mientras cola no este vacia
		actual = Q.top().first;            //Obtengo de la cola el nodo con menor peso, en un comienzo será el inicial
		Q.pop();                           //Sacamos el elemento de la cola
		if (visitado[actual]) continue; //Si el vértice actual ya fue visitado entonces sigo sacando elementos de la cola
		visitado[actual] = true;         //Marco como visitado el vértice actual
		for (int i = 0; i < ady[actual].size(); ++i) { //reviso sus adyacentes del vertice actual
			adyacente = ady[actual][i].first;   //id del vertice adyacente
			peso = ady[actual][i].second;        //peso de la arista que une actual con adyacente ( actual , adyacente )
			if (!visitado[adyacente]) {        //si el vertice adyacente no fue visitado
				relajacion(actual, adyacente, peso); //realizamos el paso de relajacion
			}
		}
	}
	print(destino);
}

void Dijkstra::LlenarRuta(int fantasma, float x, float y) {
	bool pri = true;
	origenX = x;
	origenY = y;
	vector<Vertice> Rut;
	int movimientos = 0;
	int direccion = 0;
	for (int x = 0; x < v.size(); x++) {
		//cout << " N: " << v[x] << " " << endl;
		for (int i = 1; i < 14; i++){
			for (int j = 1; j < 20; j++) {
				if (v[x + 1] != NULL){
					if (Aristas2[i][j].getID() == v[x] && Aristas2[i][j].getAdy() == v[x + 1]) {

						//cout << "Encontro la arista ID: " << Aristas2[i][j].getID() << Aristas2[i][j].getX() << "," << Aristas2[i][j].getY() <<"  ADY: " << Aristas2[i][j].getAdy()  << Aristas2[i][j].getXX() << "," << Aristas2[i][j].getYY() << endl;
						Rut.push_back(Aristas2[i][j]);
					}
				}
			}
		}
	}
	game gg;
	//cout << "sizex "<<Rut.size();
	if (fantasma == 3) {
		gg.MoverBlinky(Rut);
	}if (fantasma == 4) {
		gg.MoverInkyD(Rut);
	}if (fantasma == 5) {
		gg.moverClydeDijkstra(Rut);
	}if (fantasma == 6) {
		gg.moverPinkyDijkstra(Rut);
	}
	//for (int x = 0; x <1 ; x++) 
	//{
	//	cout << " N: " << v[x] << " " << endl;
	//	for (int i = 1; i < 13; i++)
	//	{
	//		for (int j = 1; j < 13; j++)
	//		{
	//			if (v[x + 1] != NULL)
	//			{

	//				if (puntosNivel1[i][j].getID() == v[x] && puntosNivel1[i][j].getAdy() == v[x+1])
	//				{
	//					cout << "Encontro la arista " << puntosNivel1[i][j].getX() << "," << puntosNivel1[i][j].getY() << "Peso : " << puntosNivel1[i][j].getPeso() << endl;
	//					if (puntosNivel1[i][j].getPeso() == 50)
	//					{
	//						
	//						if (origenX == puntosNivel1[i][j].getX() && origenY < puntosNivel1[i][j+1].getY()) {
	//							direccion = 1;//der
	//						}if (origenX == puntosNivel1[i][j].getX() && origenY > puntosNivel1[i][j-1].getY()) {
	//							direccion = 2;//izq
	//						}if (origenX > puntosNivel1[i][j].getX() && origenY == puntosNivel1[i-1][j].getY()) {
	//							direccion = 3;//arriba
	//						}if (origenX < puntosNivel1[i][j].getX() && origenY == puntosNivel1[i+1][j].getY()) {
	//							direccion = 4;//abajo
	//						}
	//						movimientos += 1;
	//						Rute vv;
	//						vv.setMov(1); vv.setDireccion(direccion); Rut.push_back(vv);
	//					}if (puntosNivel1[i][j].getPeso() == 100)
	//					{
	//						
	//						if (origenX == puntosNivel1[i][j].getX() && origenY < puntosNivel1[i][j].getY()) {
	//							
	//							direccion = 1;//dercout
	//						}if (origenX == puntosNivel1[i][j].getX() && origenY > puntosNivel1[i][j].getY()) {
	//							direccion = 2;//izq
	//						}if (origenX > puntosNivel1[i][j].getX() && origenY == puntosNivel1[i][j].getY()) {
	//							direccion = 3;//arriba
	//						}if (origenX < puntosNivel1[i][j].getX() && origenY == puntosNivel1[i][j].getY()) {
	//							direccion = 4;//abajo
	//						}
	//						Rute vv;
	//						vv.setMov(2); vv.setDireccion(direccion); Rut.push_back(vv);
	//					}if (puntosNivel1[i][j].getPeso() == 150)
	//					{
	//						if (origenX == puntosNivel1[i][j].getX() && origenY < puntosNivel1[i][j].getY()) {
	//							direccion = 1;//der
	//						}if (origenX == puntosNivel1[i][j].getX() && origenY > puntosNivel1[i][j].getY()) {
	//							direccion = 2;//izq
	//						}if (origenX > puntosNivel1[i][j].getX() && origenY == puntosNivel1[i][j].getY()) {
	//							direccion = 3;//arriba
	//						}if (origenX < puntosNivel1[i][j].getX() && origenY == puntosNivel1[i][j].getY()) {
	//							direccion = 4;//abajo
	//						}
	//						Rute vv;
	//						vv.setMov(3); vv.setDireccion(direccion); Rut.push_back(vv);
	//					}if (puntosNivel1[i][j].getPeso() == 200)
	//					{
	//						if (origenX == puntosNivel1[i][j].getX() && origenY < puntosNivel1[i][j].getY()) {
	//							direccion = 1;//der
	//						}if (origenX == puntosNivel1[i][j].getX() && origenY > puntosNivel1[i][j].getY()) {
	//							direccion = 2;//izq
	//						}if (origenX > puntosNivel1[i][j].getX() && origenY == puntosNivel1[i][j].getY()) {
	//							direccion = 3;//arriba
	//						}if (origenX < puntosNivel1[i][j].getX() && origenY == puntosNivel1[i][j].getY()) {
	//							direccion = 4;//abajo
	//						}
	//						Rute vv;
	//						vv.setMov(4); vv.setDireccion(direccion); Rut.push_back(vv);
	//					}
	//				}
	//			}
	//		}
	//	}
	//}

	////cout << "del Origen al segundo Nodo es: Mov: " << Rut[0].getMov() << " Direcion: " << Rut[0].getDireccion() << endl;
	//for (int x = 1; x < v.size(); x++) {
	//	cout << " N: " << v[x]<<" "<<endl;
	//	for (int i = 1; i < 13; i++) 
	//	{
	//		for (int j = 1; j < 13; j++) {
	//			if (v[x + 1] != NULL) 
	//			{
	//				if (puntosNivel1[i][j].getAdy() == v[x]) {
	//					origenX = puntosNivel1[i][j].getX();
	//					origenY = puntosNivel1[i][j].getY();
	//						
	//				}
	//				
	//				if (puntosNivel1[i][j].getID() == v[x] && puntosNivel1[i][j].getAdy() == v[x + 1]) 
	//				{
	//                       //cout << "Encontro la arista "<< puntosNivel1[i][j].getX()<<","<< puntosNivel1[i][j].getY()<<"Peso : "<< puntosNivel1[i][j].getPeso()<<endl;
	//                       if (puntosNivel1[i][j].getPeso() == 50) 
	//					   {
	//						   if (origenX == puntosNivel1[i][j].getX() && origenY < puntosNivel1[i][j].getY()) {
	//							   direccion = 1;//der
	//						   }if (origenX == puntosNivel1[i][j].getX() && origenY > puntosNivel1[i][j].getY()) {
	//							   direccion = 2;//izq
	//						   }if (origenX > puntosNivel1[i][j].getX() && origenY == puntosNivel1[i][j].getY()) {
	//							   direccion = 3;//arriba
	//						   }if (origenX < puntosNivel1[i][j].getX() && origenY == puntosNivel1[i][j].getY()) {
	//							   direccion = 4;//abajo
	//						   }
	//						   movimientos += 1;
	//						   Rute vv;
	//						   vv.setMov(1); vv.setDireccion(direccion); Rut.push_back(vv);
	//				       }if (puntosNivel1[i][j].getPeso() == 100)
	//					   {
	//						   if (origenX == puntosNivel1[i][j].getX() && origenY < puntosNivel1[i][j].getY()) {
	//							   direccion = 1;//der
	//						   }if (origenX == puntosNivel1[i][j].getX() && origenY > puntosNivel1[i][j].getY()) {
	//							   direccion = 2;//izq
	//						   }if (origenX > puntosNivel1[i][j].getX() && origenY == puntosNivel1[i][j].getY()) {
	//							   direccion = 3;//arriba
	//						   }if (origenX < puntosNivel1[i][j].getX() && origenY == puntosNivel1[i][j].getY()) {
	//							   direccion = 4;//abajo
	//						   }
	//						   Rute vv;
	//						   vv.setMov(2); vv.setDireccion(direccion); Rut.push_back(vv);
	//					   }if (puntosNivel1[i][j].getPeso() == 150)
	//					   {
	//						   if (origenX == puntosNivel1[i][j].getX() && origenY < puntosNivel1[i][j].getY()) {
	//							   direccion = 1;//der
	//						   }if (origenX == puntosNivel1[i][j].getX() && origenY > puntosNivel1[i][j].getY()) {
	//							   direccion = 2;//izq
	//						   }if (origenX > puntosNivel1[i][j].getX() && origenY == puntosNivel1[i][j].getY()) {
	//							   direccion = 3;//arriba
	//						   }if (origenX < puntosNivel1[i][j].getX() && origenY == puntosNivel1[i][j].getY()) {
	//							   direccion = 4;//abajo
	//						   }
	//						   Rute vv;
	//						   vv.setMov(3); vv.setDireccion(direccion); Rut.push_back(vv);
	//					   }if (puntosNivel1[i][j].getPeso() == 200)
	//					   {
	//						   if (origenX == puntosNivel1[i][j].getX() && origenY < puntosNivel1[i][j].getY()) {
	//							   direccion = 1;//der
	//						   }if (origenX == puntosNivel1[i][j].getX() && origenY > puntosNivel1[i][j].getY()) {
	//							   direccion = 2;//izq
	//						   }if (origenX > puntosNivel1[i][j].getX() && origenY == puntosNivel1[i][j].getY()) {
	//							   direccion = 3;//arriba
	//						   }if (origenX < puntosNivel1[i][j].getX() && origenY == puntosNivel1[i][j].getY()) {
	//							   direccion = 4;//abajo
	//						   }
	//						   Rute vv;
	//						   vv.setMov(4); vv.setDireccion(direccion); Rut.push_back(vv);
	//					   }
	//				
	//				
	//				}
	//			}
	//		}
	//	}
	//}
	//
}

int Dijkstra::BuscarPacman(float x, float y, bool bandX, bool bandY){
	int puntos = 0;
	for (int i = 1; i < 14; i++){
		for (int j = 1; j < 20; j++) {
			if (bandX == true) {
				if (x != 45 ) {
					if ((Aristas2[i][j].getY() - 22.5) == x) {
						Aristas2[i][j].setY(Aristas2[i][j].getY() - 22.5);
					}
				}
			}
			if (bandY == true) {
				if (y != 45 ) {
					if ((Aristas2[i][j].getX() - 22.5) == y) {
						Aristas2[i][j].setX(Aristas2[i][j].getX() - 22.5);
					}
				}
			}
			if (Aristas2[i][j].getX() == y && Aristas2[i][j].getY() == x) {
				int x = (int) Aristas2[i][j].getX();
				int y = (int) Aristas2[i][j].getY();
				if (Aristas2[i][j].getX() - x) {
					Aristas2[i][j].setX(Aristas2[i][j].getX() + 22.5);
				}
				if (Aristas2[i][j].getY() - y) {
					Aristas2[i][j].setY(Aristas2[i][j].getY() + 22.5);
				}
				puntos = Aristas2[i][j].getID();
			}
		}
	}
	return puntos;
}

int Dijkstra::BuscarBlinky(float x, float y){
	//cout << "x en dij " << x << " y en dij " << y << endl;
	bool band = false;
	int puntos = 0;
	for (int i = 1; i < 14; i++){
		for (int j = 1; j < 20; j++) {
			if (Aristas2[i][j].getX() == y && Aristas2[i][j].getY() == x){
				//cout << "i: " << i << " j: " << j;
				puntos = Aristas2[i][j].getID();
				if (x == 495 && y == 450) {
					cout << "vadsv " << Aristas2[i][j].getID() << endl;
				}
				return puntos;
				
				//band = true;
			}
		}
	}
	
	//if (band == false) {
	//	for (int i = 1; i < 14; i++) {
	//		for (int j = 1; j < 20; j++) {
	//			if (Aristas2[i][j].getX() == y && Aristas2[i][j].getY() != x) {
	//				//cout << "i: " << i << " j: " << j;
	//				puntos = Aristas2[i][j].getID();
	//				band = true;
	//			}
	//		}
	//	}
	//}
	//cout << "puntos blinky " << puntos << endl;
	return puntos;
}














