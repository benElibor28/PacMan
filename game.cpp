#include "game.h"
Texture Tpared; Sprite Spared;// valor 1
Texture Tpunto; Sprite Spunto; 
Texture Tpacman; Sprite Spacman;// valor 2
Texture Tblinky; Sprite Sblinky;// valor 3
Texture TInky; Sprite SInky;// valor 4
Texture TClyde; Sprite SClyde;// valor 5
Texture TPinky; Sprite SPinky;// valor 6
Texture TVida1; Sprite SVida1;
Texture TVida2; Sprite SVida2;
Texture TVida3; Sprite SVida3;
Texture TVida4; Sprite SVida4;
Texture TVida5; Sprite SVida5;
Texture TVida6; Sprite SVida6;
Texture Tinicio; Sprite Sinicio;

Texture TgameO; Sprite SgameO;

Texture Tfon; Sprite Sfon;

SoundBuffer buffer;
Sound sonido;


Texture Tniveles; Sprite Sniveles;
Texture Tnivel1; Sprite Snivel1;
Texture Tnivel2; Sprite Snivel2;
Texture Tnivel3; Sprite Snivel3;
Texture Tnivel4; Sprite Snivel4;
Texture Tnivel5; Sprite Snivel5;
Texture Tnivel6; Sprite Snivel6;
Texture Tnivel7; Sprite Snivel7;
Texture Tnivel8; Sprite Snivel8;
Texture Tnivel9; Sprite Snivel9;
Texture Tnivel10; Sprite Snivel10;
Texture Tatras; Sprite Satras;
//////////
Texture T1; Sprite S1;
Texture T2; Sprite S2;
Texture T3; Sprite S3;
Texture T4; Sprite S4;
Texture T5; Sprite S5;
Texture T6; Sprite S6;
Texture T7; Sprite S7;
Texture T8; Sprite S8;
Texture T9; Sprite S9;
Texture T10; Sprite S10;
Text txtNivel;

Texture Tmenu; Sprite Smenu;
Texture Tiniciar; Sprite Siniciar;
Texture Tjugador; Sprite Sjugador;
Texture Tconf; Sprite Sconf;
Texture Tsalir; Sprite Ssalir;
Texture Tnegro; Sprite Snegro;

Texture TGameOver; Sprite SGameOver;
Text txtComprarVidas;
Texture TAbandonar; Sprite SAbandonar;

sf::Text Marcador;
sf::Font font;
vector<Vertice> RutA;
vector<Vertice> RutAClyde;
vector<Vertice> RutAInky;
vector<Vertice> RutAInkyDijkstra;
vector<Vertice> RutAClydeDijkstra;
vector<Vertice> RutAPinkyDijkstra;
bool killer = false;
bool MAto = false;
bool MovInky = false;
bool MovClyde = false;
bool MovPinky = false;
int victima = 0;
int matar = 0;

Vertice puntosNivel2[19][19];

//Vertice ruta[];
int movimiento = 0;
int temp = 0;
int tmpClyde = 0;
int tmpInky = 0;
int tempIDij = 0;
int tempCDij = 0;
int tempPiDij = 0;
int puntos = 0;
bool dib = false;
bool pacMan = false;
int siz = 0;
bool segunda = false;
int vida = 0;

int mapLevel1[15][15] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
						  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
						  {1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
						  {1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
						  {1,1,1,0,1,1,0,1,0,1,1,0,1,1,1},
						  {1,1,1,0,1,0,0,0,0,0,1,0,1,1,1},
						  {1,1,1,0,0,0,1,0,1,0,0,0,1,1,1},
						  {1,1,0,0,1,0,0,0,0,0,1,0,0,1,1},
						  {1,1,1,0,0,0,1,0,1,0,0,0,1,1,1},
						  {1,1,1,0,1,0,0,0,0,0,1,0,1,1,1},
						  {1,1,1,0,1,1,0,1,0,1,1,0,1,1,1},
						  {1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
						  {1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
						  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
						  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };

int mapLevel2[15][15] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
						  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						  {1,0,1,1,1,1,1,0,1,1,1,1,1,0,1},
						  {1,0,1,0,0,0,6,0,0,0,0,0,1,0,1},
						  {1,0,1,0,1,1,1,1,0,1,1,0,1,0,1},
						  {1,0,1,0,1,0,0,0,0,0,1,0,1,0,1},
						  {1,0,1,0,0,0,1,0,1,0,1,0,1,0,1},
						  {1,0,0,0,1,0,4,3,0,0,1,0,0,2,1},
						  {1,0,1,0,1,0,1,0,1,0,0,0,1,0,1},
						  {1,0,1,0,1,0,0,0,0,0,1,0,1,0,1},
						  {1,0,1,0,1,1,0,1,1,1,1,0,1,0,1},
						  {1,0,1,0,0,0,5,0,0,0,0,0,1,0,1},
						  {1,0,1,1,1,1,1,0,1,1,1,1,1,0,1},
						  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
						  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };

int mapLevel3[15][15] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
						  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
						  {1,1,1,0,1,1,1,1,1,1,1,0,1,1,1},
						  {1,1,0,2,0,0,0,0,0,0,0,0,0,1,1},
						  {1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
						  {1,1,1,0,0,0,1,1,1,0,0,0,1,1,1},
						  {1,1,1,1,1,0,1,0,1,0,1,1,1,1,1},
						  {0,0,0,0,0,0,0,3,1,0,0,0,0,0,0},
						  {1,1,1,1,1,0,1,0,1,0,1,1,1,1,1},
						  {1,1,1,0,0,0,1,1,1,0,0,0,1,1,1},
						  {1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
						  {1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
						  {1,1,1,0,1,1,1,1,1,1,1,0,1,1,1},
						  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
						  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };

int mapLevel4[15][15] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
						  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
						  {1,1,1,0,1,0,1,1,1,0,1,0,1,1,1},
						  {1,1,2,0,0,0,0,0,0,0,0,0,0,1,1},
						  {1,1,1,0,1,1,1,1,1,1,1,0,1,1,1},
						  {1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
						  {1,1,1,1,0,1,1,0,1,1,0,1,1,1,1},
						  {1,1,1,0,0,1,0,3,0,1,0,0,1,1,1},
						  {1,1,1,1,0,1,1,1,1,1,0,1,1,1,1},
						  {1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
						  {1,1,1,0,1,1,1,1,1,1,1,0,1,1,1},
						  {1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
						  {1,1,1,0,1,0,1,1,1,0,1,0,1,1,1},
						  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
						  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };

int mapLevel5[15][15] = { {1,1,1,1,1,1,1,0,1,1,1,1,1,1,1},
						  {1,1,1,1,1,1,1,0,1,1,1,1,1,1,1},
						  {1,1,1,1,1,0,1,0,1,0,1,1,1,1,1},
						  {1,1,1,2,0,0,0,0,0,0,0,0,1,1,1},
						  {1,1,1,0,1,1,1,1,1,1,1,0,1,1,1},
						  {1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
						  {1,1,1,0,1,1,1,1,1,1,1,0,1,1,1},
						  {1,1,1,0,0,1,0,3,0,1,0,0,1,1,1},
						  {1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
						  {1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
						  {1,1,1,0,1,1,1,1,1,1,1,0,1,1,1},
						  {1,1,1,0,0,0,0,0,0,0,0,0,1,1,1},
						  {1,1,1,1,1,0,1,0,1,0,1,1,1,1,1},
						  {1,1,1,1,1,1,1,0,1,1,1,1,1,1,1},
						  {1,1,1,1,1,1,1,0,1,1,1,1,1,1,1} };

int mapLevel7[15][15] = { {1,1,1,1,1,1,1,0,1,1,1,1,1,1,1},
						  {1,1,1,1,1,1,1,0,1,1,1,1,1,1,1},
						  {1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
						  {1,1,0,2,0,0,0,0,0,0,0,0,0,1,1},
						  {1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
						  {1,1,1,0,0,0,0,0,0,0,0,0,1,1,1},
						  {1,1,1,0,0,1,1,1,1,1,0,0,1,1,1},
						  {1,1,1,0,1,1,0,3,0,1,1,0,1,1,1},
						  {1,1,1,0,0,1,1,0,1,1,0,0,1,1,1},
						  {1,1,1,0,0,0,0,0,0,0,0,0,1,1,1},
						  {1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
						  {1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
						  {1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
						  {1,1,1,1,1,1,1,0,1,1,1,1,1,1,1},
						  {1,1,1,1,1,1,1,0,1,1,1,1,1,1,1} };

int mapLevel6[15][15] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
						  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
						  {1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
						  {1,1,0,1,0,1,1,1,1,1,0,1,0,1,1},
						  {1,1,0,1,0,0,0,0,0,0,0,1,0,1,1},
						  {1,1,0,1,0,1,1,0,1,1,0,1,0,1,1},
						  {1,1,0,1,0,1,0,0,0,1,0,1,0,1,1},
						  {1,1,0,1,0,1,1,1,1,1,0,1,0,1,1},
						  {0,0,0,1,0,0,0,0,0,0,0,1,0,0,0},
						  {1,1,0,1,0,1,1,1,1,1,0,1,0,1,1},
						  {1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
						  {1,1,0,1,1,1,1,1,1,1,1,1,0,1,1},
						  {1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
						  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
						  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };

int mapLevel8[15][15] = { {1,1,1,1,1,1,1,0,1,1,1,1,1,1,1},
						  {1,1,1,1,1,1,1,0,1,1,1,1,1,1,1},
						  {1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
						  {1,1,0,2,0,0,0,0,0,0,0,0,0,1,1},
						  {1,1,1,0,0,0,1,0,1,0,0,0,1,1,1},
						  {1,1,1,0,0,1,1,1,1,1,0,0,1,1,1},
						  {1,1,1,1,0,0,1,0,1,0,0,1,1,1,1},
						  {1,1,1,1,0,0,0,3,1,0,0,1,1,1,1},
						  {1,1,1,1,0,0,1,0,1,0,0,1,1,1,1},
						  {1,1,1,0,0,1,1,1,1,1,0,0,1,1,1},
						  {1,1,1,0,0,0,1,0,1,0,0,0,1,1,1},
						  {1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
						  {1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
						  {1,1,1,1,1,1,1,0,1,1,1,1,1,1,1},
						  {1,1,1,1,1,1,1,0,1,1,1,1,1,1,1} };

int mapLevel9[15][15] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
						  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
						  {1,1,0,0,0,0,1,1,0,0,0,0,0,1,1},
						  {1,1,0,1,1,0,1,1,0,0,1,1,0,1,1},
						  {1,1,0,1,0,0,0,0,0,0,0,1,0,1,1},
						  {1,1,0,0,0,0,1,1,1,0,0,0,0,1,1},
						  {1,1,0,0,1,0,1,0,1,0,1,0,0,1,1},
						  {0,0,0,0,1,2,1,3,0,0,1,0,0,0,0},
						  {1,1,0,0,1,0,1,0,1,0,1,0,0,1,1},
						  {1,1,0,0,0,0,1,1,1,0,0,0,0,1,1},
						  {1,1,0,1,0,0,0,0,0,0,0,1,0,1,1},
						  {1,1,0,1,1,0,1,1,0,0,1,1,0,1,1},
						  {1,1,0,0,0,0,1,1,0,0,0,0,0,1,1},
						  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
						  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };

int mapLevel10[15][15] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
						  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
						  {1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
						  {1,1,0,1,1,0,0,1,0,0,1,1,0,1,1},
						  {1,1,0,1,0,0,0,1,0,0,0,1,0,1,1},
						  {1,1,0,0,0,0,1,1,1,0,0,0,0,1,1},
						  {1,1,0,0,1,0,1,0,1,0,1,0,0,1,1},
						  {0,0,0,1,1,2,1,3,0,0,1,1,0,0,0},
						  {1,1,0,0,1,0,1,0,1,0,1,0,0,1,1},
						  {1,1,0,0,0,0,1,1,1,0,0,0,0,1,1},
						  {1,1,0,1,0,0,0,1,0,0,0,1,0,1,1},
						  {1,1,0,1,1,0,0,1,0,0,1,1,0,1,1},
						  {1,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
						  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
						  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };

game::game()
{
}

game::~game()
{
}

void game::MoverPacMan(){
	MovAutomatico(movimiento);
	std::this_thread::sleep_for(std::chrono::milliseconds(150));
}

void game::moverBinky() {
	MovAutomaticoBlinky();
	std::this_thread::sleep_for(std::chrono::milliseconds(150));
}

void game::movClyde() {
	movAutClyde();
	std::this_thread::sleep_for(std::chrono::milliseconds(150));
}

void game::moverInky(std::vector<Vertice> Rut) {
	RutAInky.clear();
	tmpInky = 0;
	for (int t = 0; t < Rut.size(); t++) {
		RutAInky.push_back(Rut[t]);
	}
}

void game::movAutomaticoInky() {
	if (tmpInky < RutAInky.size()) {
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 15; j++) {
				if (Matrix[i][j].getCas().getX() == RutAInky[tmpInky].getY() && Matrix[i][j].getCas().getY() == RutAInky[tmpInky].getX()) {
					odjeto_mapa nodo;
					nodo.setGrafico(0);
					nodo.setX(Matrix[i][j].getCas().getX());
					nodo.setY(Matrix[i][j].getCas().getY());
					nodo.setPunto(Matrix[i][j].getCas().getPunto());
					nodo.setXP(Matrix[i][j].getCas().getX() + 22.5);
					nodo.setYP(Matrix[i][j].getCas().getY() + 22.5);
					Matrix[i][j].setCas(nodo);
				}
				//cout << "i " << i << " j " << j << " Matrix x " << Matrix[i][j].getCas().getX() << " " << Matrix[i][j].getCas().getGrafico() <<endl;
				if (Matrix[i][j].getCas().getX() == RutAInky[tmpInky].getYY() && Matrix[i][j].getCas().getY() == RutAInky[tmpInky].getXX()) {
					//cout << "id ady " << RutA[temp].getAdy() << " x " << RutA[temp].getXX() << " y " << RutA[temp].getYY() << endl;
					/*cout << " id " << RutA[0].getID() << endl;
					cout << "id ady  " << RutA[0].getAdy() << endl;
					*/
					//if (Matrix[i][j].getCas().getGrafico() != 1) {
					//cout << " x  ru " << RutA[0].getYY() << " y ru " << RutA[1].getXX() << endl;
					odjeto_mapa nodo;
					nodo.setGrafico(4);
					nodo.setX(Matrix[i][j].getCas().getX());
					nodo.setY(Matrix[i][j].getCas().getY());
					Matrix[i][j].setCas(nodo);

					//}
				}
			}
		}
	}
}

void game::movInky(){
	movAutomaticoInky();
	std::this_thread::sleep_for(std::chrono::milliseconds(150));
}

void game::movAutClyde() {
	bool band = false;
	if (tmpClyde < RutAClyde.size()) {
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 15; j++) {
				if (Matrix[i][j].getCas().getX() == RutAClyde[tmpClyde].getY() && Matrix[i][j].getCas().getY() == RutAClyde[tmpClyde].getX()) {
					//cout << "id " << RutAClyde[tmpClyde].getID() << " x " << RutAClyde[tmpClyde].getY() << " y " << RutAClyde[tmpClyde].getX() << endl;
					odjeto_mapa nodo;
					nodo.setGrafico(0);
					nodo.setX(Matrix[i][j].getCas().getX());
					nodo.setY(Matrix[i][j].getCas().getY());
					nodo.setPunto(Matrix[i][j].getCas().getPunto());
					nodo.setXP(Matrix[i][j].getCas().getX() + 22.5);
					nodo.setYP(Matrix[i][j].getCas().getY() + 22.5);
					Matrix[i][j].setCas(nodo);
				}
				//cout << "x cly " << RutAClyde[tmpClyde].getX() << " y cly " << RutAClyde[tmpClyde].getY() << endl;
				if (Matrix[i][j].getCas().getX() == RutAClyde[tmpClyde].getYY() && Matrix[i][j].getCas().getY() == RutAClyde[tmpClyde].getXX()) {
					//cout << "id ady " << RutAClyde[tmpClyde].getAdy() << " x " << RutAClyde[tmpClyde].getYY() << " y " << RutAClyde[tmpClyde].getXX() << endl;
					if (Matrix[i][j].getCas().getGrafico() == 1 && Matrix[i][j].getCas().getGrafico() == 3 && Matrix[i][j].getCas().getGrafico() == 4 && Matrix[i][j].getCas().getGrafico() == 6) {
						//cout << "aja " << endl;
						odjeto_mapa nodo;
						nodo.setGrafico(5);
						nodo.setX(RutAClyde[tmpClyde].getY());
						nodo.setY(RutAClyde[tmpClyde].getX());
						Matrix[i][j].setCas(nodo);
						band = true;
					}
					else {
						odjeto_mapa nodo;
						nodo.setGrafico(5);
						nodo.setX(Matrix[i][j].getCas().getX());
						nodo.setY(Matrix[i][j].getCas().getY());
						nodo.setPunto(Matrix[i][j].getCas().getPunto());
						Matrix[i][j].setCas(nodo);
					}
				}
			}
		}
	}
	if (band = false) {

	}
}

void game::moverClyde(std::vector<Vertice> Rut){
	RutAClyde.clear();
	tmpClyde = 0;
	for (int t = 0; t < Rut.size(); t++) {
		RutAClyde.push_back(Rut[t]);
	}
	/*for (int t = 0; t < RutAClyde.size(); t++) {
		cout<<"ruta id f "<< RutAClyde[t].getID();
		cout << "x f " << RutAClyde[t].getYY() << " y f  " << RutAClyde[t].getXX() << endl;
	}
	cout << endl;
	cout << "size floyd " << RutAClyde.size() << endl;*/
}

void game::FloydClyde(){
	bool bandX = false;
	bool bandY = false;
	sf::Vector2f position = SClyde.getPosition();
	sf::Vector2f positionP = Spacman.getPosition();
	if (positionP.x == 607.5) {
		positionP.x = 585;
	}
	if (positionP.x < 67.5) {
		positionP.x = 45;
	}
	if (positionP.y == 607.5) {
		positionP.y = 585;
	}
	if (positionP.y < 67.5) {
		positionP.y = 45;
	}
	int x = (int)positionP.x;
	int y = (int)positionP.y;
	if (positionP.x - x) {
		bandX = true;
	}
	if (positionP.y - y) {
		bandY = true;
	}
	// << "x " << position.x << " y " << position.y << endl;
	Floyd ff;
	ff.RunFloyd(2, position.x, position.y, positionP.x, positionP.y,bandX,bandY);	
	ff.LlenarRuta(5);
}

void game::floydInky() {
	bool bandX = false;
	bool bandY = false;
	sf::Vector2f position = SInky.getPosition();
	sf::Vector2f positionP = Spacman.getPosition();
	if (positionP.x == 607.5) {
		positionP.x = 585;
	}
	if (positionP.x < 67.5) {
		positionP.x = 45;
	}
	if (positionP.y == 607.5) {
		positionP.y = 585;
	}
	if (positionP.y < 67.5) {
		positionP.y = 45;
	}
	int x = (int)positionP.x;
	int y = (int)positionP.y;
	if (positionP.x - x) {
		bandX = true;
	}
	if (positionP.y - y) {
		bandY = true;
	}
	//cout << "x " << position.x << " y " << position.y << endl;
	Floyd ff;
	ff.RunFloyd(2, position.x, position.y, positionP.x, positionP.y, bandX, bandY);
	ff.LlenarRuta(4);
}

void game::MoverBlinky(std::vector<Vertice> Rut) {
	RutA.clear();
	temp = 0;
	for (int t = 0; t < Rut.size(); t++) {
		RutA.push_back(Rut[t]);
	}
	/*for (int t = 0; t < RutA.size(); t++) {
		cout<<"ruta id "<<RutA[t].getID();
		cout << "x " << RutA[t].getYY() << " y  " << RutA[t].getXX() << endl;
	}
	cout << endl;*/
}

void game::MovAutomaticoBlinky(){
	if(temp < RutA.size()) 	{
			for (int i = 0; i < 15; i++){
				for (int j = 0; j < 15; j++) {
					if (Matrix[i][j].getCas().getX() == RutA[temp].getY() && Matrix[i][j].getCas().getY() == RutA[temp].getX()) {
						odjeto_mapa nodo;
						nodo.setGrafico(0);
						nodo.setX(Matrix[i][j].getCas().getX());
						nodo.setY(Matrix[i][j].getCas().getY());
						nodo.setPunto(Matrix[i][j].getCas().getPunto());
						nodo.setXP(Matrix[i][j].getCas().getX() + 22.5);
						nodo.setYP(Matrix[i][j].getCas().getY() + 22.5);
						Matrix[i][j].setCas(nodo);
					}
					//cout << "i " << i << " j " << j << " Matrix x " << Matrix[i][j].getCas().getX() << " " << Matrix[i][j].getCas().getGrafico() <<endl;
					if (Matrix[i][j].getCas().getX() == RutA[temp].getYY() && Matrix[i][j].getCas().getY() == RutA[temp].getXX()) {
						//cout << "id ady " << RutA[temp].getAdy() << " x " << RutA[temp].getXX() << " y " << RutA[temp].getYY() << endl;
						/*cout << " id " << RutA[0].getID() << endl;
						cout << "id ady  " << RutA[0].getAdy() << endl;
						*/
						//if (Matrix[i][j].getCas().getGrafico() != 1) {
						//cout << " x  ru " << RutA[0].getYY() << " y ru " << RutA[1].getXX() << endl;
							odjeto_mapa nodo;
							nodo.setGrafico(3);
							nodo.setX(Matrix[i][j].getCas().getX());
							nodo.setY(Matrix[i][j].getCas().getY());
							Matrix[i][j].setCas(nodo);
							
						//}
					}
				}
			}
	}
}

void game::DijkstraBliky() {
	bool bandX = false;
	bool bandY = false;
	sf::Vector2f position = Sblinky.getPosition();
	sf::Vector2f positionP = Spacman.getPosition();
	if (MAto == true) {
		position = Sblinky.getPosition();
		positionP.x = 315;
		positionP.y = 315;
	}
	else {
		position = Sblinky.getPosition();
		positionP = Spacman.getPosition();
	}
	if (positionP.x == 607.5) {
		positionP.x = 585;
	}
	if (positionP.x < 67.5) {
		positionP.x = 45;
	}
	if (positionP.y == 607.5) {
		positionP.y = 585;
	}
	if (positionP.y < 67.5) {
		positionP.y = 45;
	}
	int x = (int) positionP.x;
	int y = (int) positionP.y;
	if (positionP.x - x ) {
		bandX = true;
	}
	if (positionP.y - y) {
		bandY = true;
	}
	//cout << "x b " << position.x << " y b " << position.y << endl;
	Dijkstra dd;
	dd.RunDijkstra(2,position.x, position.y, positionP.x, positionP.y, bandX, bandY);
	dd.LlenarRuta(3, position.x, position.y);
}

void game::preva(){
	cout << "prueba thread _________________________________________________";
	std::this_thread::sleep_for(std::chrono::milliseconds(7000));
}

void game::run(int n){
	initView();
	//guardar("Ale", 5, 3);
	Nivel(2,false,0);
	CargarNivel(n, 15, 15,9);
	DijkstraBliky();
	FloydClyde();
	floydInky();
	int u = 0;
	while (renderWindow.isOpen()) {
		while (renderWindow.pollEvent(event)) {
			eventeclas();
		}
		std::thread HiloPacMan(&game::MoverPacMan, this);
		HiloPacMan.join();
		CargarNivel(n, 15, 15, movimiento);
		renderWindow.display();
		std::thread HiloBinky(&game::moverBinky, this);
		HiloBinky.join();
		DijkstraBliky();
		temp++;
		CargarNivel(n, 15, 15, movimiento);
		std::thread HiloClyde(&game::movClyde, this);
		HiloClyde.join();
		FloydClyde();
		tmpClyde++;
		CargarNivel(n, 15, 15, movimiento);
		std::thread HiloInky(&game::movInky , this);
		HiloInky.join();
		floydInky();
		tmpInky++;
		dijkstraComerPinky();
		movAutomaticoPinkyDijkstra();
		tempPiDij++;
		VerificarMatar();
		MovFantasmasMuertos();
		CargarNivel(n, 15, 15, movimiento);
		renderWindow.display();
	}
}

void game::initView(){
	//tecla = false;
	renderWindow.create(sf::VideoMode(1200, 680), "PAC-MAN");
}

void game::agregaBoton() {

}

void game::eventBoton() {

}

void game::HacerNivel(int nivel, bool se){
	if (nivel == 1) {

		for (int i = 0; i < 15; i++){
			for (int j = 0; j < 15; j++){
					odjeto_mapa cas;
					cas.setX(i * 45);
					cas.setY(j * 45);
					cas.setXP(i * 22.5);
					cas.setYP(j * 22.5);
					cas.setGrafico(mapLevel1[i][j]);
					Matrix[i][j].setCas(cas);
				
			}
		}
		
	}
	if (nivel == 2) {
		for (int i = 0; i < 15; i++){
			for (int j = 0; j < 15; j++){
				if (se == 1) {
					odjeto_mapa cas;
					cas.setX(i * 45);
					cas.setY(j * 45);
					cas.setKill(false);
					if (Matrix[i][j].getCas().getPunto() == true) {
						cas.setXP((i * 45) + 22.5);
						cas.setYP((j * 45) + 22.5);
						cas.setPunto(true);
					}
					else {
						cas.setPunto(false);
					}
					if (i == 3 && j == 1) {
						cas.setKill(true);
					}if (i == 10 && j == 3) {
						cas.setKill(true);
					}if (i == 12 && j == 13) {
						cas.setKill(true);
					}if (i == 3 && j == 11) {
						cas.setKill(true);
					}
					cas.setGrafico(mapLevel2[i][j]);
					Matrix[i][j].setCas(cas);
				}
				else {
					odjeto_mapa cas;
					cas.setX(i * 45);
					cas.setY(j * 45);
					cas.setXP((i * 45) + 22.5);
					cas.setYP((j * 45) + 22.5);
					cas.setPunto(true);
					cas.setKill(false);
					cas.setGrafico(mapLevel2[i][j]);
					if (i == 3 && j == 1) {
						cas.setKill(true);
					}if (i == 10 && j == 3) {
						cas.setKill(true);
					}if (i == 12 && j == 13) {
						cas.setKill(true);
					}if (i == 3 && j == 11) {
						cas.setKill(true);
					}
					Matrix[i][j].setCas(cas);
				}
			}
		}
	}
}

void game::Nivel(int n, bool se,int vidas){	
	temp = 0;
	tmpClyde = 0;
	if (!font.loadFromFile("stocky.ttf")){
	}
	Tpared.loadFromFile("casilla.png");
	Spared.setTexture(Tpared);
	Tpacman.loadFromFile("pm.png");
	Spacman.setTexture(Tpacman);
	Tblinky.loadFromFile("blinky.png");
	Sblinky.setTexture(Tblinky);
	TInky.loadFromFile("inky.png");
	SInky.setTexture(TInky);
	TClyde.loadFromFile("clyde.png");
	SClyde.setTexture(TClyde);
	TPinky.loadFromFile("pinky.png");
	SPinky.setTexture(TPinky);
	HacerNivel(n,se);
}

void game::eventeclas(){
	if (event.type == sf::Event::KeyPressed){
		
		if (event.key.code == sf::Keyboard::Escape){
			// Do something when Escape is pressed...
		}
		if (event.key.code == sf::Keyboard::W){
			cout << "WWWWWWWWW";
		}
		if (event.key.code == sf::Keyboard::Right){
			cout << "tecleo" << endl;
			sf::Vector2f position = Spacman.getPosition();
			std::cout << position.x << " " << position.y << "\n";
			cambiarDireccion(1);
			validarMovimiento(position.x , position.y , 1,1);
			movimiento = 1;
		}if (event.key.code == sf::Keyboard::Left){
			sf::Vector2f position = Spacman.getPosition();
			cambiarDireccion(2);
			validarMovimiento(position.x , position.y , 2,1);
			movimiento = 2;
		}if (event.key.code == sf::Keyboard::Up){
			sf::Vector2f position = Spacman.getPosition();
			cambiarDireccion(4);
			validarMovimiento( position.x , position.y , 4,1);
			movimiento = 4;
		}if (event.key.code == sf::Keyboard::Down){
			sf::Vector2f position = Spacman.getPosition();
			cambiarDireccion(3);
			validarMovimiento( position.x , position.y , 3,1);
			movimiento = 3;
		}
	}
}

void game::CargarNivel(int nivel, int t1, int t2, int dir) {
	pacMan = false;
	bool blin = false;
	renderWindow.clear();
	if (nivel == 2) {
		//Texture Tfon; Sprite Sfon;
		Tfon.loadFromFile("simpsonG.jpeg");
		Sfon.setTexture(Tfon);
		renderWindow.draw(Sfon);
	}
	if (nivel== 1) {
		Tfon.loadFromFile("jokerG.jpeg");
		Sfon.setTexture(Tfon);
		renderWindow.draw(Sfon);
	}
	if (nivel == 3) {
		Tfon.loadFromFile("ironG.jpeg");
		Sfon.setTexture(Tfon);
		renderWindow.draw(Sfon);
	}
	if (nivel == 4) {
		Tfon.loadFromFile("spiderG.jpeg");
		Sfon.setTexture(Tfon);
		renderWindow.draw(Sfon);
	}
	if (nivel == 5) {
		Tfon.loadFromFile("batmanG.jpeg");
		Sfon.setTexture(Tfon);
		renderWindow.draw(Sfon);
	}
	if (nivel == 6) {
		Tfon.loadFromFile("supermanG.jpeg");
		Sfon.setTexture(Tfon);
		renderWindow.draw(Sfon);
	}
	if (nivel == 7) {
		Tfon.loadFromFile("deadG.jpeg");
		Sfon.setTexture(Tfon);
		renderWindow.draw(Sfon);
	}
	if (nivel == 8) {
		Tfon.loadFromFile("oneG.jpeg");
		Sfon.setTexture(Tfon);
		renderWindow.draw(Sfon);
	}
	if (nivel == 9) {
		Tfon.loadFromFile("narutoG.jpeg");
		Sfon.setTexture(Tfon);
		renderWindow.draw(Sfon);
	}
	if (nivel == 10) {
		Tfon.loadFromFile("dragonG.jpeg");
		Sfon.setTexture(Tfon);
		renderWindow.draw(Sfon);
	}

	if (MAto == true) {
		if (victima == 3) {
			//cout << "se esta muriendo el fantasma" << endl;
			Tblinky.loadFromFile("ojos.jpeg");
			Sblinky.setTexture(Tblinky);
		}if (victima == 4) {
			TInky.loadFromFile("ojos.jpeg");
			SInky.setTexture(TInky);
		}if (victima == 5) {
			TClyde.loadFromFile("ojos.jpeg");
			SClyde.setTexture(TClyde);
		}if (victima == 6) {
			TPinky.loadFromFile("ojos.jpeg");
			SPinky.setTexture(TPinky);
		}
	}if (matar == 0) {
		Tblinky.loadFromFile("blinky.png");
		Sblinky.setTexture(Tblinky);
		TInky.loadFromFile("inky.png");
		SInky.setTexture(TInky);
		TClyde.loadFromFile("clyde.png");
		SClyde.setTexture(TClyde);
		TPinky.loadFromFile("pinky.png");
		SPinky.setTexture(TPinky);
	}
	if (killer == true)
	{
		Tblinky.loadFromFile("Fazul.jpeg");
		Sblinky.setTexture(Tblinky);
		TInky.loadFromFile("Fazul.jpeg");
		SInky.setTexture(TInky);
		TClyde.loadFromFile("Fazul.jpeg");
		SClyde.setTexture(TClyde);
		TPinky.loadFromFile("Fazul.jpeg");
		SPinky.setTexture(TPinky);
	}if (killer == false && MAto == false)
	{
		Tblinky.loadFromFile("blinky.png");
		Sblinky.setTexture(Tblinky);
		TInky.loadFromFile("inky.png");
		SInky.setTexture(TInky);
		TClyde.loadFromFile("clyde.png");
		SClyde.setTexture(TClyde);
		TPinky.loadFromFile("pinky.png");
		SPinky.setTexture(TPinky);
	}
	for (int i = 0; i < t1; i++) {
		for (int j = 0; j < t2; j++) {
				if (Matrix[i][j].getCas().getGrafico() == 1) {
					Spared.setPosition(Matrix[i][j].getCas().getX(), Matrix[i][j].getCas().getY());
					renderWindow.draw(Spared);
				}
				if (Matrix[i][j].getCas().getGrafico() == 2) {
					if (dir == 1) {
						odjeto_mapa nodo;
						nodo.setGrafico(Matrix[i + 1][j].getCas().getGrafico());
						nodo.setX(Matrix[i][j].getCas().getX() + 45);
						nodo.setY(Matrix[i][j].getCas().getY());
						if (nodo.getGrafico() != 1) {
							Spacman.setPosition(Matrix[i][j].getCas().getX() + 22.5, Matrix[i][j].getCas().getY());
							//DijkstraBliky();
						}
						else {
							Spacman.setPosition(Matrix[i][j].getCas().getX(), Matrix[i][j].getCas().getY());
							//DijkstraBliky();
						}
					}if (dir == 2) {
						odjeto_mapa nodo;
						nodo.setGrafico(Matrix[i - 1][j].getCas().getGrafico());
						nodo.setX(Matrix[i - 1][j].getCas().getX());
						nodo.setY(Matrix[i][j].getCas().getY());
						if (nodo.getGrafico() != 1) {
							Spacman.setPosition(Matrix[i][j].getCas().getX() - 22.5, Matrix[i][j].getCas().getY());
							//DijkstraBliky();
						}
						else {
							Spacman.setPosition(Matrix[i][j].getCas().getX(), Matrix[i][j].getCas().getY());
							//DijkstraBliky();
						}
					}if (dir == 3) {
						odjeto_mapa nodo;
						nodo.setGrafico(Matrix[i][j + 1].getCas().getGrafico());
						nodo.setX(Matrix[i][j].getCas().getX());
						nodo.setY(Matrix[i][j].getCas().getY() + 45);
						if (nodo.getGrafico() != 1) {
							Spacman.setPosition(Matrix[i][j].getCas().getX(), Matrix[i][j].getCas().getY() + 22.5);
							//DijkstraBliky();
						}
						else {
							Spacman.setPosition(Matrix[i][j].getCas().getX(), Matrix[i][j].getCas().getY());
							//DijkstraBliky();
						}
					}if (dir == 4) {
						odjeto_mapa nodo;
						nodo.setGrafico(Matrix[i][j - 1].getCas().getGrafico());
						nodo.setX(Matrix[i][j].getCas().getX());
						nodo.setY(Matrix[i][j - 1].getCas().getY());
						if (nodo.getGrafico() != 1) {
							Spacman.setPosition(Matrix[i][j].getCas().getX(), Matrix[i][j].getCas().getY() - 22.5);
							//DijkstraBliky();
						}
						else {
							Spacman.setPosition(Matrix[i][j].getCas().getX(), Matrix[i][j].getCas().getY());
							//DijkstraBliky();
						}
					}if (dir == 9) {
						Spacman.setPosition(Matrix[i][j].getCas().getX(), Matrix[i][j].getCas().getY());
					}
					renderWindow.draw(Spacman);
					stringstream ss;
					ss << puntos;
					string str = ss.str();
					Marcador.setFont(font); Marcador.setCharacterSize(35); Marcador.setPosition(690, 10); Marcador.setFillColor(sf::Color::White);
					Marcador.setString("Puntos: " + str);
					renderWindow.draw(Marcador);
					pacMan = true;
					temp = 0;
					tmpClyde = 0;
					tmpInky = 0;
				}
				if (Matrix[i][j].getCas().getGrafico() == 3) {
					Sblinky.setPosition(Matrix[i][j].getCas().getX(), Matrix[i][j].getCas().getY());
					renderWindow.draw(Sblinky);
					blin = true;
				}
				if (Matrix[i][j].getCas().getGrafico() == 4) {
					SInky.setPosition(Matrix[i][j].getCas().getX(), Matrix[i][j].getCas().getY());
					renderWindow.draw(SInky);
					blin = true;
				}
				if (Matrix[i][j].getCas().getGrafico() == 5) {
					//cout << "clyde" << endl;
					//cout << "cor carga x " << Matrix[i][j].getCas().getX() << " cor carga y " << Matrix[i][j].getCas().getY() << endl;
					SClyde.setPosition(Matrix[i][j].getCas().getX(), Matrix[i][j].getCas().getY());
					renderWindow.draw(SClyde);
					blin = true;
				}
				if (Matrix[i][j].getCas().getGrafico() == 6) {
					SPinky.setPosition(Matrix[i][j].getCas().getX(), Matrix[i][j].getCas().getY());
					renderWindow.draw(SPinky); 
					blin = true;
				}
				if (Matrix[i][j].getCas().getGrafico() == 0) {
					if (Matrix[i][j].getCas().getPunto() == 1) {
						sf::CircleShape circulo(5.f);
						circulo.setFillColor(sf::Color::Yellow);
						circulo.setPosition(Matrix[i][j].getCas().getXP(), Matrix[i][j].getCas().getYP());
						renderWindow.draw(circulo);
					}
				}
				if (Matrix[i][j].getCas().getKill() == true) {
					sf::CircleShape circulo(9.f);
					circulo.setFillColor(sf::Color::Red);
					circulo.setPosition(Matrix[i][j].getCas().getXP(), Matrix[i][j].getCas().getYP());
					renderWindow.draw(circulo);
				}
		}
		/*cout << endl;
		cout << endl;*/
	}
	if (vida == 1) {
		TVida1.loadFromFile("mu.png");
		SVida1.setTexture(TVida1);
		TVida2.loadFromFile("vidam.png");
		SVida2.setTexture(TVida2);
		TVida3.loadFromFile("vidam.png");
		SVida3.setTexture(TVida3);
		TVida4.loadFromFile("vidam.png");
		SVida4.setTexture(TVida4);
		TVida5.loadFromFile("vidam.png");
		SVida5.setTexture(TVida5);
		TVida6.loadFromFile("vidam.png");
		SVida6.setTexture(TVida6);
	}
	else if (vida == 2) {
		TVida1.loadFromFile("mu.png");
		SVida1.setTexture(TVida1);
		TVida2.loadFromFile("mu.png");
		SVida2.setTexture(TVida2);
		TVida3.loadFromFile("vidam.png");
		SVida3.setTexture(TVida3);
		TVida4.loadFromFile("vidam.png");
		SVida4.setTexture(TVida4);
		TVida5.loadFromFile("vidam.png");
		SVida5.setTexture(TVida5);
		TVida6.loadFromFile("vidam.png");
		SVida6.setTexture(TVida6);
	}
	else if (vida == 3) {
		TVida1.loadFromFile("mu.png");
		SVida1.setTexture(TVida1);
		TVida2.loadFromFile("mu.png");
		SVida2.setTexture(TVida2);
		TVida3.loadFromFile("mu.png");
		SVida3.setTexture(TVida3);
		TVida4.loadFromFile("vidam.png");
		SVida4.setTexture(TVida4);
		TVida5.loadFromFile("vidam.png");
		SVida5.setTexture(TVida5);
		TVida6.loadFromFile("vidam.png");
		SVida6.setTexture(TVida6);
	}
	else if (vida == 4) {
		TVida1.loadFromFile("mu.png");
		SVida1.setTexture(TVida1);
		TVida2.loadFromFile("mu.png");
		SVida2.setTexture(TVida2);
		TVida3.loadFromFile("mu.png");
		SVida3.setTexture(TVida3);
		TVida4.loadFromFile("mu.png");
		SVida4.setTexture(TVida4);
		TVida5.loadFromFile("vidam.png");
		SVida5.setTexture(TVida5);
		TVida6.loadFromFile("vidam.png");
		SVida6.setTexture(TVida6);
	}
	else if (vida == 5) {
		TVida1.loadFromFile("mu.png");
		SVida1.setTexture(TVida1);
		TVida2.loadFromFile("mu.png");
		SVida2.setTexture(TVida2);
		TVida3.loadFromFile("mu.png");
		SVida3.setTexture(TVida3);
		TVida4.loadFromFile("mu.png");
		SVida4.setTexture(TVida4);
		TVida5.loadFromFile("mu.png");
		SVida5.setTexture(TVida5);
		TVida6.loadFromFile("vidam.png");
		SVida6.setTexture(TVida6);
	}
	else if (vida == 6) {
		TVida1.loadFromFile("mu.png");
		SVida1.setTexture(TVida1);
		TVida2.loadFromFile("mu.png");
		SVida2.setTexture(TVida2);
		TVida3.loadFromFile("mu.png");
		SVida3.setTexture(TVida3);
		TVida4.loadFromFile("mu.png");
		SVida4.setTexture(TVida4);
		TVida5.loadFromFile("mu.png");
		SVida5.setTexture(TVida5);
		TVida6.loadFromFile("mu.png");
		SVida6.setTexture(TVida6);
		////ventana game over 
		runGameOver();
	}
	else {
		TVida1.loadFromFile("vidam.png");
		SVida1.setTexture(TVida1);
		TVida2.loadFromFile("vidam.png");
		SVida2.setTexture(TVida2);
		TVida3.loadFromFile("vidam.png");
		SVida3.setTexture(TVida3);
		TVida4.loadFromFile("vidam.png");
		SVida4.setTexture(TVida4);
		TVida5.loadFromFile("vidam.png");
		SVida5.setTexture(TVida5);
		TVida6.loadFromFile("vidam.png");
		SVida6.setTexture(TVida6);
	}
	SVida1.setPosition(690, 600);
	renderWindow.draw(SVida1);
	SVida2.setPosition(730, 600);
	renderWindow.draw(SVida2);
	SVida3.setPosition(770, 600);
	renderWindow.draw(SVida3);
	SVida4.setPosition(810, 600);
	renderWindow.draw(SVida4);
	SVida5.setPosition(850, 600);
	renderWindow.draw(SVida5);
	SVida6.setPosition(890, 600);
	renderWindow.draw(SVida6);
	if (pacMan == false && blin == true && killer == false) {
		segunda = true;
		movimiento = 9;
		vida++;
		Nivel(2, segunda,vida);
		DijkstraBliky();
		FloydClyde();
		//eventeclas();
	}
	pacMan = false;
	blin = false;
}

void game::validarMovimiento(float x, float y, int dirreccion,int p){
	for (int i = 0; i < 15; i++){
		for (int j = 0; j < 15; j++){
			if (dirreccion == 1) {
				if (Matrix[i][j].getCas().getX() == x + 22.5 && Matrix[i][j].getCas().getY() == y) {
					if (Matrix[i][j].getCas().getKill() == true) {
						//cout << "matar a los putos fantasma es verda ya aa maldicion"<<endl;
						killer = true;
					}
					if (Matrix[i][j].getCas().getGrafico() == 9) {
						EntradasSalidas(2, x, y, dirreccion);
						dirreccion = 5;
						j = 20;
						i = 20;
					}
					if (Matrix[i][j].getCas().getGrafico() == 3) {
						if (killer == true) {
							victima = Matrix[i][j].getCas().getGrafico();
							MAto = true;
						}
					}
					if (Matrix[i][j].getCas().getGrafico() == 4) {
						if (killer == true) {
							victima = Matrix[i][j].getCas().getGrafico();
							MAto = true;
							MovInky = true;
						}
					}if (Matrix[i][j].getCas().getGrafico() == 5) {
						if (killer == true) {
							//cout << "mato a clyde por la izquierda" << endl;
							victima = Matrix[i][j].getCas().getGrafico();
							MAto = true;
							MovClyde = true;
						}
					}if (Matrix[i][j].getCas().getGrafico() == 6) {
						if (killer == true) {
							//cout << "mato a Pinky por la izquierda" << endl;
							victima = Matrix[i][j].getCas().getGrafico();
							MAto = true;
							MovPinky = true;
						}
					}
					if (Matrix[i][j].getCas().getGrafico() == 0) {
						cambiarCoordenadas(x, y, dirreccion, p);
						dirreccion = 5;
						j = 20;
						i = 20;
					}
				}
			}if (dirreccion == 2) {
				//cout << Matrix[i][j].getCas().getX()<<" / " << Matrix[i][j].getCas().getY()<<endl;
				if (Matrix[i][j].getCas().getX() == x - 22.5 && Matrix[i][j].getCas().getY() == y) {
					if (Matrix[i][j].getCas().getKill() == true) {
						//cout << "matar a los putos fantasma es verda ya aa maldicion"<<endl;
						killer = true;
					}
					if (Matrix[i][j].getCas().getGrafico() == 9) {


						EntradasSalidas(2, x, y, dirreccion);
						dirreccion = 5;
						j = 20;
						i = 20;
					}
					if (Matrix[i][j].getCas().getGrafico() == 3) {

						if (killer == true) {
							victima = Matrix[i][j].getCas().getGrafico();
							MAto = true;
						}
					}
					if (Matrix[i][j].getCas().getGrafico() == 4) {

						if (killer == true) {
							victima = Matrix[i][j].getCas().getGrafico();
							MAto = true;
							MovInky = true;
						}
					}if (Matrix[i][j].getCas().getGrafico() == 5) {

						if (killer == true) {
							//cout << "mato a clyde por la izquierda" << endl;
							victima = Matrix[i][j].getCas().getGrafico();
							MAto = true;
							MovClyde = true;
						}
					}if (Matrix[i][j].getCas().getGrafico() == 6) {

						if (killer == true) {
							//cout << "mato a Pinky por la izquierda" << endl;
							victima = Matrix[i][j].getCas().getGrafico();
							MAto = true;
							MovPinky = true;
						}
					}
					if (Matrix[i][j].getCas().getGrafico() == 0) {
						cambiarCoordenadas(x, y, dirreccion, p);
						dirreccion = 5;
						j = 20;
						i = 20;
					}
				}
			}if (dirreccion == 3) {
				if (Matrix[i][j].getCas().getX() == x && Matrix[i][j].getCas().getY() == y+22.5) {
					if (Matrix[i][j].getCas().getKill() == true) {
						//cout << "matar a los putos fantasma es verda ya aa maldicion"<<endl;
						killer = true;
					}
					if (Matrix[i][j].getCas().getGrafico() == 9) {


						EntradasSalidas(2, x, y, dirreccion);
						dirreccion = 5;
						j = 20;
						i = 20;
					}
					if (Matrix[i][j].getCas().getGrafico() == 3) {

						if (killer == true) {
							victima = Matrix[i][j].getCas().getGrafico();
							MAto = true;
						}
					}
					if (Matrix[i][j].getCas().getGrafico() == 4) {

						if (killer == true) {
							victima = Matrix[i][j].getCas().getGrafico();
							MAto = true;
							MovInky = true;
						}
					}if (Matrix[i][j].getCas().getGrafico() == 5) {

						if (killer == true) {
							//cout << "mato a clyde por la izquierda" << endl;
							victima = Matrix[i][j].getCas().getGrafico();
							MAto = true;
							MovClyde = true;
						}
					}if (Matrix[i][j].getCas().getGrafico() == 6) {

						if (killer == true) {
							//cout << "mato a Pinky por la izquierda" << endl;
							victima = Matrix[i][j].getCas().getGrafico();
							MAto = true;
							MovPinky = true;
						}
					}
					if (Matrix[i][j].getCas().getGrafico() == 0) {
						cambiarCoordenadas(x, y, dirreccion, p);
						dirreccion = 5;
						j = 20;
						i = 20;
					}
				}
			}
			if (dirreccion == 4) {
				if (Matrix[i][j].getCas().getX() == x && Matrix[i][j].getCas().getY() == y - 22.5) {
					if (Matrix[i][j].getCas().getKill() == true) {
						//cout << "matar a los putos fantasma es verda ya aa maldicion"<<endl;
						killer = true;
					}
					if (Matrix[i][j].getCas().getGrafico() == 9) {


						EntradasSalidas(2, x, y, dirreccion);
						dirreccion = 5;
						j = 20;
						i = 20;
					}
					if (Matrix[i][j].getCas().getGrafico() == 3) {

						if (killer == true) {
							victima = Matrix[i][j].getCas().getGrafico();
							MAto = true;
						}
					}
					if (Matrix[i][j].getCas().getGrafico() == 4) {

						if (killer == true) {
							victima = Matrix[i][j].getCas().getGrafico();
							MAto = true;
							MovInky = true;
						}
					}if (Matrix[i][j].getCas().getGrafico() == 5) {

						if (killer == true) {
							//cout << "mato a clyde por la izquierda" << endl;
							victima = Matrix[i][j].getCas().getGrafico();
							MAto = true;
							MovClyde = true;
						}
					}if (Matrix[i][j].getCas().getGrafico() == 6) {

						if (killer == true) {
							//cout << "mato a Pinky por la izquierda" << endl;
							victima = Matrix[i][j].getCas().getGrafico();
							MAto = true;
							MovPinky = true;
						}
					}
					if (Matrix[i][j].getCas().getGrafico() == 0) {
						cambiarCoordenadas(x, y, dirreccion, p);
						dirreccion = 5;
						j = 20;
						i = 20;
					}
				}
			}
		}
	}
}

void game::cambiarCoordenadas(float x ,float y, int direccion, int p){
	bool v1 = true;
	bool v2 = true;
	bool v3 = true;
	for (int i = 0; i < 15; i++){
		for (int j = 0; j < 15; j++){
			//if (direccion == 1) {			
				if (direccion == 1) {
					if (Matrix[i][j].getCas().getX() == x - 22.5 && Matrix[i][j].getCas().getY() == y && v1 == true) {
						odjeto_mapa nodo;
						nodo.setGrafico(0);
						nodo.setX(x - 22.5);
						nodo.setY(y);
						nodo.setPunto(false);
						nodo.setKill(false);
						Matrix[i][j].setCas(nodo);
						v1 = false;
					}
					if (Matrix[i][j].getCas().getX() == x +22.5 && Matrix[i][j].getCas().getY() == y && v2 == true){
						if (Matrix[i][j].getCas().getPunto() == true) {
							puntos += 10;
						}
						if (Matrix[i][j].getCas().getGrafico() != 1) {
							odjeto_mapa nodo;
							nodo.setGrafico(2);
							nodo.setX(x + 22.5);
							nodo.setY(y);
							nodo.setPunto(false);
							Matrix[i][j].setCas(nodo);
							v2 = false;
						}
					}
				}
				if (direccion == 2) {
					if (Matrix[i][j].getCas().getX() == x + 22.5 && Matrix[i][j].getCas().getY() == y && v1 == true) {
						odjeto_mapa nodo;
						nodo.setGrafico(0);
						nodo.setX(x + 22.5);
						nodo.setY(y);
						nodo.setPunto(false);
						nodo.setKill(false);
						Matrix[i][j].setCas(nodo);
						v1 = false;
					}
					if (Matrix[i][j].getCas().getX() == x - 22.5 && Matrix[i][j].getCas().getY() == y && v3 == true) {
							odjeto_mapa nodo;
							nodo.setGrafico(2);
							nodo.setX(x - 22.5);
							nodo.setY(y);
							nodo.setPunto(false);
							Matrix[i][j].setCas(nodo);
							v3 = false;
					}
				}
				if (direccion == 3) {
					if (Matrix[i][j].getCas().getX() == x && Matrix[i][j].getCas().getY() == y - 22.5 && v1 == true) {
						odjeto_mapa nodo;
						nodo.setGrafico(0);
						nodo.setX(x);
						nodo.setY(y - 22.5);
						nodo.setPunto(false);
						nodo.setKill(false);
						Matrix[i][j].setCas(nodo);
						v1 = false;
					}
					if (Matrix[i][j].getCas().getX() == x && Matrix[i][j].getCas().getY() == y + 22.5 && v3 == true) {
						/*if (Matrix[i][j+1].getCas().getGrafico() == 1) {
							odjeto_mapa nodo;
							nodo.setGrafico(2);
							nodo.setX(x);
							nodo.setY(y);
							nodo.setPunto(false);
							Matrix[i][j].setCas(nodo);
							v3 = false;
						}
						else {*/
							odjeto_mapa nodo;
							nodo.setGrafico(2);
							nodo.setX(x);
							nodo.setY(y + 22.5);
							nodo.setPunto(false);
							Matrix[i][j].setCas(nodo);
							v3 = false;
						//}
						
					}
				}
				if (direccion == 4) {
					if (Matrix[i][j].getCas().getX() == x && Matrix[i][j].getCas().getY() == y +22.5 && v1 == true) {
						odjeto_mapa nodo;
						nodo.setGrafico(0);
						nodo.setX(x);
						nodo.setY(y+22.5);
						nodo.setPunto(false);
						nodo.setKill(false);
						Matrix[i][j].setCas(nodo);
						v1 = false;
					}
					if (Matrix[i][j].getCas().getX() == x  && Matrix[i][j].getCas().getY() == y-22.5 && v3 == true) {
						odjeto_mapa nodo;
						nodo.setGrafico(2);
						nodo.setX(x);
						nodo.setY(y - 22.5);
						nodo.setPunto(false);
						Matrix[i][j].setCas(nodo);
						v3 = false;
					}
				}
		}
	}
}

void game::cambiarDireccion(int dir){
	if (dir == 1) {
		Tpacman.loadFromFile("pm.png");
		Spacman.setTexture(Tpacman);
	}
	if (dir == 2) {
		Tpacman.loadFromFile("pmL.png");
		Spacman.setTexture(Tpacman);
	}
	if (dir == 3) {
		Tpacman.loadFromFile("pmD.png");
		Spacman.setTexture(Tpacman);
	}
	if (dir == 4) {
		Tpacman.loadFromFile("pmU.png");
		Spacman.setTexture(Tpacman);
	}
}

void game::MovAutomatico(int dir){
	if (dir == 1) {
		sf::Vector2f position = Spacman.getPosition();
		cambiarDireccion(movimiento);
		validarMovimiento(position.x, position.y, movimiento,1);
		
	}
	if (dir == 2) {
		sf::Vector2f position = Spacman.getPosition();
		cambiarDireccion(movimiento);
		validarMovimiento(position.x, position.y, movimiento,1);
		
	}
	if (dir == 3) {
		sf::Vector2f position = Spacman.getPosition();
		cambiarDireccion(movimiento);
		validarMovimiento(position.x, position.y, movimiento,1);
		
	}
	if (dir == 4) {
		sf::Vector2f position = Spacman.getPosition();
		cambiarDireccion(movimiento);
		validarMovimiento(position.x, position.y, movimiento,1);
		
	}
	
}

void game::VerificarMatar(){
	//cout << "la victima es: " << victima << endl;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (Matrix[i][j].getCas().getX() == 315 && Matrix[i][j].getCas().getY() == 315) {
				if (Matrix[i][j].getCas().getGrafico() == 3) {
					//cout << "ya esta en el infierno el bliki cabron"<<endl;
					MAto = false;
				}
			}if (Matrix[i][j].getCas().getX() == 360 && Matrix[i][j].getCas().getY() == 315) {
				if (Matrix[i][j].getCas().getGrafico() == 5) {
					//cout << "ya esta en el infierno el bliki cabron"<<endl;
					tempCDij = 0;
					MAto = false;
					MovClyde = false;
				}
			}if (Matrix[i][j].getCas().getX() == 315 && Matrix[i][j].getCas().getY() == 270) {
				if (Matrix[i][j].getCas().getGrafico() == 6) {
					//cout << "ya esta en el infierno el bliki cabron"<<endl;
					tempPiDij = 0;
					MAto = false;
					MovPinky = false;
				}
			}
		}
	}
	if (killer == true) {
		matar++;
	}
	if (matar == 10) {
		killer = false;
		//MAto = false;
		matar = 0;
	}
}

void game::EntradasSalidas(int nivel, float x, float y, int dirreccion){
	bool v1 = true;
	bool v2 = true;
	bool v3 = true;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (nivel == 2) {
				if (dirreccion == 1) {
					if (Matrix[i][j].getCas().getX() == 585 && Matrix[i][j].getCas().getY() == 315 && v1 == true) {
						cout << "Entradas y salidas para pacman el locoooooooo salidad" << endl;
						odjeto_mapa nodo;
						nodo.setGrafico(0);
						nodo.setX(585);
						nodo.setY(315);
						nodo.setPunto(false);
						nodo.setKill(false);
						Matrix[i][j].setCas(nodo);
						v1 = false;
					}if (Matrix[i][j].getCas().getX() == 315 && Matrix[i][j].getCas().getY() == 45 && v2 == true) {
						cout << "Entradas y salidas para pacman el locoooooooo entrada" << endl;
						odjeto_mapa nodo;
						nodo.setGrafico(2);
						nodo.setX(315);
						nodo.setY(45);
						nodo.setPunto(false);
						Matrix[i][j].setCas(nodo);
						v2 = false;
					}
				}
				/*if (dirreccion == 4) {
					if (Matrix[i][j].getCas().getX() == 585 && Matrix[i][j].getCas().getY() == 315 && v1 == true) {
						cout << "Entradas y salidas para pacman el locoooooooo salidad" << endl;
						odjeto_mapa nodo;
						nodo.setGrafico(0);
						nodo.setX(315);
						nodo.setY(45);
						nodo.setPunto(false);
						nodo.setKill(false);
						Matrix[i][j].setCas(nodo);
						v1 = false;
					}if (Matrix[i][j].getCas().getX() == 315 && Matrix[i][j].getCas().getY() == 45 && v2 == true) {
						cout << "Entradas y salidas para pacman el locoooooooo entrada" << endl;
						odjeto_mapa nodo;
						nodo.setGrafico(2);
						nodo.setX(585);
						nodo.setY(315);
						nodo.setPunto(false);
						Matrix[i][j].setCas(nodo);
						v2 = false;
					}
				}*/

			}
		}
	}






}

void game::dijkstraComerInky()
{
	bool bandX = false;
	bool bandY = false;
	sf::Vector2f position;
	sf::Vector2f positionP;
	if (MAto == true) {
		position = SInky.getPosition();
		positionP.x = 315;
		positionP.y = 225;
	}
	if (positionP.x == 607.5) {
		positionP.x = 585;
	}
	if (positionP.x < 67.5) {
		positionP.x = 45;
	}
	if (positionP.y == 607.5) {
		positionP.y = 585;
	}
	if (positionP.y < 67.5) {
		positionP.y = 45;
	}
	int x = (int)positionP.x;
	int y = (int)positionP.y;
	if (positionP.x - x) {
		bandX = true;
	}
	if (positionP.y - y) {
		bandY = true;
	}
	Dijkstra dd;
	dd.RunDijkstra(2, position.x, position.y, positionP.x, positionP.y, bandX, bandY);
	dd.LlenarRuta(4, position.x, position.y);


}

void game::dijkstraComerClyde()
{
	//cout << "clyde dijkstra " << endl;
	bool bandX = false;
	bool bandY = false;
	sf::Vector2f position;
	sf::Vector2f positionP;
	if (MAto == true) {
		position = SClyde.getPosition();
		positionP.x = 360;
		positionP.y = 315;
	}
	if (positionP.x == 607.5) {
		positionP.x = 585;
	}
	if (positionP.x < 67.5) {
		positionP.x = 45;
	}
	if (positionP.y == 607.5) {
		positionP.y = 585;
	}
	if (positionP.y < 67.5) {
		positionP.y = 45;
	}
	int x = (int)positionP.x;
	int y = (int)positionP.y;
	if (positionP.x - x) {
		bandX = true;
	}
	if (positionP.y - y) {
		bandY = true;
	}
	Dijkstra dd;
	dd.RunDijkstra(2, position.x, position.y, positionP.x, positionP.y, bandX, bandY);
	dd.LlenarRuta(5, position.x, position.y);
}

void game::dijkstraComerPinky()
{
	bool bandX = false;
	bool bandY = false;
	sf::Vector2f position;
	sf::Vector2f positionP;
	if (MAto == true) {
		position = SPinky.getPosition();
		positionP.x = 315;
		positionP.y = 270;
	}
	else {
		position = SPinky.getPosition();
		positionP = Spacman.getPosition();
	}

	if (positionP.x == 607.5) {
		positionP.x = 585;
	}
	if (positionP.x < 67.5) {
		positionP.x = 45;
	}
	if (positionP.y == 607.5) {
		positionP.y = 585;
	}
	if (positionP.y < 67.5) {
		positionP.y = 45;
	}
	int x = (int)positionP.x;
	int y = (int)positionP.y;
	if (positionP.x - x) {
		bandX = true;
	}
	if (positionP.y - y) {
		bandY = true;
	}
	Dijkstra dd;
	dd.RunDijkstra(2, position.x, position.y, positionP.x, positionP.y, bandX, bandY);
	dd.LlenarRuta(6, position.x, position.y);
}

void game::movAutomaticoClydeDijkstra2()
{
	cout << "mov clyde";

}

void game::movAutomaticoClydeDijkstra()
{
	cout << "mov clyde";
	tempCDij++;
	if (tempCDij < RutAClydeDijkstra.size()) {

		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 15; j++) {
				if (Matrix[i][j].getCas().getX() == RutAClydeDijkstra[tempCDij].getY() && Matrix[i][j].getCas().getY() == RutAClydeDijkstra[tempCDij].getX()) {
					odjeto_mapa nodo;
					nodo.setGrafico(0);
					nodo.setX(Matrix[i][j].getCas().getX());
					nodo.setY(Matrix[i][j].getCas().getY());
					nodo.setPunto(Matrix[i][j].getCas().getPunto());
					nodo.setXP(Matrix[i][j].getCas().getX() + 22.5);
					nodo.setYP(Matrix[i][j].getCas().getY() + 22.5);
					Matrix[i][j].setCas(nodo);
				}
				if (Matrix[i][j].getCas().getX() == RutAClydeDijkstra[tempCDij].getYY() && Matrix[i][j].getCas().getY() == RutAClydeDijkstra[tempCDij].getXX()) {
					if (Matrix[i][j].getCas().getGrafico() != 1) {
						odjeto_mapa nodo;
						nodo.setGrafico(5);
						nodo.setX(Matrix[i][j].getCas().getX());
						nodo.setY(Matrix[i][j].getCas().getY());
						Matrix[i][j].setCas(nodo);
					}
				}
			}
		}
	}

}

void game::movAutomaticoInkyDijkstra()
{
	if (tempIDij < RutAInkyDijkstra.size()) {
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 15; j++) {
				if (Matrix[i][j].getCas().getX() == RutAInkyDijkstra[tempIDij].getY() && Matrix[i][j].getCas().getY() == RutAInkyDijkstra[tempIDij].getX()) {
					odjeto_mapa nodo;
					nodo.setGrafico(0);
					nodo.setX(Matrix[i][j].getCas().getX());
					nodo.setY(Matrix[i][j].getCas().getY());
					nodo.setPunto(Matrix[i][j].getCas().getPunto());
					nodo.setXP(Matrix[i][j].getCas().getX() + 22.5);
					nodo.setYP(Matrix[i][j].getCas().getY() + 22.5);
					Matrix[i][j].setCas(nodo);
				}
				if (Matrix[i][j].getCas().getX() == RutAInkyDijkstra[tempIDij].getYY() && Matrix[i][j].getCas().getY() == RutAInkyDijkstra[tempIDij].getXX()) {
					if (Matrix[i][j].getCas().getGrafico() != 1) {
						odjeto_mapa nodo;
						nodo.setGrafico(4);
						nodo.setX(Matrix[i][j].getCas().getX());
						nodo.setY(Matrix[i][j].getCas().getY());
						Matrix[i][j].setCas(nodo);
					}
				}
			}
		}
	}
}

void game::movAutomaticoPinkyDijkstra()
{

	if (tempPiDij < RutAPinkyDijkstra.size()) {
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 15; j++) {
				if (Matrix[i][j].getCas().getX() == RutAPinkyDijkstra[tempPiDij].getY() && Matrix[i][j].getCas().getY() == RutAPinkyDijkstra[tempPiDij].getX()) {
					odjeto_mapa nodo;
					nodo.setGrafico(0);
					nodo.setX(Matrix[i][j].getCas().getX());
					nodo.setY(Matrix[i][j].getCas().getY());
					nodo.setPunto(Matrix[i][j].getCas().getPunto());
					nodo.setXP(Matrix[i][j].getCas().getX() + 22.5);
					nodo.setYP(Matrix[i][j].getCas().getY() + 22.5);
					Matrix[i][j].setCas(nodo);
				}
				if (Matrix[i][j].getCas().getX() == RutAPinkyDijkstra[tempPiDij].getYY() && Matrix[i][j].getCas().getY() == RutAPinkyDijkstra[tempPiDij].getXX()) {
					if (Matrix[i][j].getCas().getGrafico() != 1) {
						odjeto_mapa nodo;
						nodo.setGrafico(6);
						nodo.setX(Matrix[i][j].getCas().getX());
						nodo.setY(Matrix[i][j].getCas().getY());
						Matrix[i][j].setCas(nodo);
					}
				}
			}
		}
	}
}

void game::MovFantasmasMuertos()
{
	if (MAto == true && victima == 4) {
		//cout << "ya esta en el infierno el Inky se esta muerinendo cabron el dijskraaa" << endl;


	}if (MovInky == true) {
		//cout << "ya esta en el infierno el Inky se esta muerinendo cabron" << endl;
		dijkstraComerInky();
		movAutomaticoInkyDijkstra();
		tempIDij++;
	}if (MovClyde == true) {

		dijkstraComerClyde();
		movAutomaticoClydeDijkstra();
		tempCDij++;
	}if (MovPinky == true) {
		cout << "ya esta en el infierno el Pinky se esta muerinendo cabron" << endl;
		dijkstraComerPinky();
		movAutomaticoPinkyDijkstra();
		tempPiDij++;
	}

}

void game::MoverInkyD(std::vector<Vertice> Rut)
{
	RutAInkyDijkstra.clear();
	tempIDij = 0;
	for (int t = 0; t < Rut.size(); t++) {
		RutAInkyDijkstra.push_back(Rut[t]);
		//cout << RutAInkyDijkstra[t].getID() << " ";
	}
}
void game::moverClydeDijkstra(std::vector<Vertice> Rut)
{
	RutAClydeDijkstra.clear();
	tempCDij = 0;
	for (int t = 0; t < Rut.size(); t++) {
		RutAClydeDijkstra.push_back(Rut[t]);
		//cout << RutAClydeDijkstra[t].getID() << " ";
	}


}

void game::moverPinkyDijkstra(std::vector<Vertice> Rut)
{
	RutAPinkyDijkstra.clear();
	tempPiDij = 0;
	for (int t = 0; t < Rut.size(); t++) {
		RutAPinkyDijkstra.push_back(Rut[t]);
		//cout << RutAPinkyDijkstra[t].getID() << " ";
	}
}

void game::runNivelesWindow() {
	initNivelesWindow();
	while (nivelesWindow.isOpen()) {
		while (nivelesWindow.pollEvent(event)) {
			eventoNiveles();
		}

		botonesNiveles();

		nivelesWindow.display();
	}
}

void game::iniGameOverWindow() {
	gameOverWindow.create(sf::VideoMode(1200, 675), "PAC-MAN");
	TGameOver.loadFromFile("gameOver.jpg");
	SGameOver.setTexture(TGameOver);
}

void game::runGameOver() {
	iniGameOverWindow();
	while (gameOverWindow.isOpen()) {
		while (gameOverWindow.pollEvent(event)) {
			eventoGameOber();
		}
		botonesGameOver();
		gameOverWindow.display();
	}
}
void game::botonesGameOver() {
	if (!font.loadFromFile("FLATS.ttf")) {
	}

	TgameO.loadFromFile("gameOver.jpj");
	SgameO.setTexture(TgameO);

	TAbandonar.loadFromFile("salir.png");
	SAbandonar.setTexture(TAbandonar);
	SAbandonar.setPosition(590, 410);
	
	txtComprarVidas.setFont(font); txtComprarVidas.setCharacterSize(30); txtComprarVidas.setPosition(450, 100); txtComprarVidas.setFillColor(sf::Color::Yellow);
	txtComprarVidas.setString("COMPRAR VIDAS: 1500 pts");
	gameOverWindow.draw(SgameO);
	gameOverWindow.draw(txtComprarVidas);
	gameOverWindow.draw(SAbandonar);
}

void game::eventoGameOber() {
	switch (event.type) {
	case sf::Event::Closed:
		//window.close();
		break;
	case sf::Event::MouseButtonPressed:
		sf::Vector2i mousePos = sf::Mouse::getPosition(gameOverWindow);
		sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
		/*if (Siniciar.getGlobalBounds().contains(mousePosF)) {
			run(1);
			gameOverWindow.close();
		}*/
		//else if (Sjugador.getGlobalBounds().contains(mousePosF)) {
		//	if (!buffer.loadFromFile("pacman_eatghost.wav")) {
		//		//cout << "no se ha podido generar el sonido";
		//	}
		//	else {
		//		sonido.setBuffer(buffer);
		//	}
		//	sonido.play();
		//}
		if (txtComprarVidas.getGlobalBounds().contains(mousePosF)) {
			//cout << "niveles";
			/*runGameOver();
			menuWindow.close();*/
		}
		else if (SAbandonar.getGlobalBounds().contains(mousePosF)) {
			//cout << "salir";
			menuWindow.close();
		}

	}
}

void game::guardar(String nombre, int puntos, int fantasmas){
	//cout << "entraaaaaaaaaaa" << endl;
	//FILE* archivo;
	//errno_t err = fopen_s(&archivo,"archivo.txt", "w");
	//cout << "ERR " << err << endl;
	//if (err == NULL) {
	//	//fwrite(&nombre, sizeof(String), 1, archivo);
	//	string n = std::to_string(puntos);
	//	cout << "n " << n << endl;
	//	fwrite(&n, sizeof(string), 1, archivo);
	//	/*string n1 = std::to_string(fantasmas);
	//	fwrite(&n1, sizeof(string), 1, archivo);*/
	//}
	//fclose(archivo);
}

void game::cargar(){

}

void game::runMenuWindow() {
	initMenuWindow();
	while (menuWindow.isOpen()) {
		while (menuWindow.pollEvent(event)) {
			eventoMenu();
		}
		botonesMenu();
		menuWindow.display();
	}
}

void game::initMenuWindow() {
	menuWindow.create(sf::VideoMode(1200, 675), "PAC-MAN");
	Tmenu.loadFromFile("fondoIni.jpeg");
	Smenu.setTexture(Tmenu);
}

void game::botonesMenu() {
	if (!font.loadFromFile("FLATS.ttf")){
	}
	Tiniciar.loadFromFile("btnIniciar.png");
	Siniciar.setTexture(Tiniciar);
	Siniciar.setPosition(410, 410);

	Tjugador.loadFromFile("jugador.png");
	Sjugador.setTexture(Tjugador);
	Sjugador.setPosition(510, 410);

	Tconf.loadFromFile("confi.png");
	Sconf.setTexture(Tconf);
	Sconf.setPosition(610, 410);

	Tsalir.loadFromFile("salir.png");
	Ssalir.setTexture(Tsalir);
	Ssalir.setPosition(710, 410);

	Tnegro.loadFromFile("negro.png");
	Snegro.setTexture(Tnegro);
	Snegro.setPosition(400, 400);

	menuWindow.draw(Smenu);
	menuWindow.draw(Snegro);
	menuWindow.draw(Siniciar);
	menuWindow.draw(Sjugador);
	menuWindow.draw(Sconf);
	menuWindow.draw(Ssalir);
}

void game::eventoMenu() {
	switch (event.type)	{
	case sf::Event::Closed:
		//window.close();
		break;
	case sf::Event::MouseButtonPressed:
		sf::Vector2i mousePos = sf::Mouse::getPosition(menuWindow);
		sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
		if (Siniciar.getGlobalBounds().contains(mousePosF)){
			cout << "iniciar";
			run(2);
			menuWindow.close();
		}
		else if (Sjugador.getGlobalBounds().contains(mousePosF)){
			cout << "jugador";
			if (!buffer.loadFromFile("pacman_eatghost.wav")) {
				cout << "no se ha podido generar el sonido";
			}
			else {
				sonido.setBuffer(buffer);
			}
			sonido.play();
		}
		else if (Sconf.getGlobalBounds().contains(mousePosF)){
			cout << "niveles";
			runNivelesWindow();
			menuWindow.close();
		}
		else if (Ssalir.getGlobalBounds().contains(mousePosF)){
			cout << "salir";
			menuWindow.close();
		}

	}
}

void game::initNivelesWindow() {

	nivelesWindow.create(sf::VideoMode(1200, 675), "PAC-MAN");
	Tniveles.loadFromFile("inicio.jpeg");
	Sniveles.setTexture(Tniveles);


}

void game::botonesNiveles() {
	//nivelesWindow.clear();
	if (!font.loadFromFile("FLATS.ttf"))
	{
		// error...
	}

	txtNivel.setFont(font); txtNivel.setCharacterSize(35); txtNivel.setPosition(450, 100); txtNivel.setFillColor(sf::Color::Yellow);
	txtNivel.setString("N I V E L E S");


	Tnivel1.loadFromFile("jokerP.jpeg");
	Snivel1.setTexture(Tnivel1);
	Snivel1.setPosition(100, 220);
	T1.loadFromFile("1.png");
	S1.setTexture(T1);
	S1.setPosition(100, 220);

	Tnivel2.loadFromFile("simpsonP.jpeg");
	Snivel2.setTexture(Tnivel2);
	Snivel2.setPosition(300, 220);
	T2.loadFromFile("2.png");
	S2.setTexture(T2);
	S2.setPosition(300, 220);

	Tnivel3.loadFromFile("ironP.jpeg");
	Snivel3.setTexture(Tnivel3);
	Snivel3.setPosition(500, 220);
	T3.loadFromFile("3.png");
	S3.setTexture(T3);
	S3.setPosition(500, 220);

	Tnivel4.loadFromFile("spiderP.jpeg");
	Snivel4.setTexture(Tnivel4);
	Snivel4.setPosition(700, 220);
	T4.loadFromFile("4.png");
	S4.setTexture(T4);
	S4.setPosition(700, 220);

	Tnivel5.loadFromFile("batmanP.png");
	Snivel5.setTexture(Tnivel5);
	Snivel5.setPosition(900, 220);
	T5.loadFromFile("5.png");
	S5.setTexture(T5);
	S5.setPosition(900, 220);

	Tnivel6.loadFromFile("supermanP.jpeg");
	Snivel6.setTexture(Tnivel6);
	Snivel6.setPosition(100, 345);
	T6.loadFromFile("6.png");
	S6.setTexture(T6);
	S6.setPosition(100, 345);

	Tnivel7.loadFromFile("deadP.jpeg");
	Snivel7.setTexture(Tnivel7);
	Snivel7.setPosition(300, 345);
	T7.loadFromFile("7.png");
	S7.setTexture(T7);
	S7.setPosition(300, 345);

	Tnivel8.loadFromFile("oneP.jpeg");
	Snivel8.setTexture(Tnivel8);
	Snivel8.setPosition(500, 345);
	T8.loadFromFile("8.png");
	S8.setTexture(T8);
	S8.setPosition(500, 345);

	Tnivel9.loadFromFile("narutoP.jpeg");
	Snivel9.setTexture(Tnivel9);
	Snivel9.setPosition(700, 345);
	T9.loadFromFile("9.png");
	S9.setTexture(T9);
	S9.setPosition(700, 345);

	Tnivel10.loadFromFile("dragonP.jpeg");
	Snivel10.setTexture(Tnivel10);
	Snivel10.setPosition(900, 345);
	T10.loadFromFile("10.png");
	S10.setTexture(T10);
	S10.setPosition(900, 345);

	Tatras.loadFromFile("atras.png");
	Satras.setTexture(Tatras);
	Satras.setPosition(595, 500);


	nivelesWindow.draw(Sniveles);
	nivelesWindow.draw(Snivel1);
	nivelesWindow.draw(S1);
	nivelesWindow.draw(Snivel2);
	nivelesWindow.draw(S2);
	nivelesWindow.draw(Snivel3);
	nivelesWindow.draw(S3);
	nivelesWindow.draw(Snivel4);
	nivelesWindow.draw(S4);
	nivelesWindow.draw(Snivel5);
	nivelesWindow.draw(S5);
	nivelesWindow.draw(Snivel6);
	nivelesWindow.draw(S6);
	nivelesWindow.draw(Snivel7);
	nivelesWindow.draw(S7);
	nivelesWindow.draw(Snivel8);
	nivelesWindow.draw(S8);
	nivelesWindow.draw(Snivel9);
	nivelesWindow.draw(S9);
	nivelesWindow.draw(Snivel10);
	nivelesWindow.draw(S10);
	nivelesWindow.draw(Satras);

	nivelesWindow.draw(txtNivel);

}

void game::eventoNiveles() {
	switch (event.type)
	{
	case sf::Event::Closed:
		//window.close();
		break;

	case sf::Event::MouseButtonPressed:
		sf::Vector2i mousePos = sf::Mouse::getPosition(nivelesWindow);
		sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

		if (Snivel1.getGlobalBounds().contains(mousePosF))
		{
			cout << "1";
			run(1);
			nivelesWindow.close();

		}
		else if (Snivel2.getGlobalBounds().contains(mousePosF)) {
			cout << "2";
			run(2);
			nivelesWindow.close();
		}
		else if (Snivel3.getGlobalBounds().contains(mousePosF)) {
			cout << "3";
			run(3);
			nivelesWindow.close();
		}
		else if (Snivel4.getGlobalBounds().contains(mousePosF)) {
			cout << "4";
			run(8);
			nivelesWindow.close();
		}
		else if (Snivel5.getGlobalBounds().contains(mousePosF)) {
			cout << "5";
			run(1);
			nivelesWindow.close();
		}
		else if (Snivel6.getGlobalBounds().contains(mousePosF)) {
			cout << "6";
			run(2);
			nivelesWindow.close();
		}
		else if (Snivel7.getGlobalBounds().contains(mousePosF)) {
			cout << "7";
			run(3);
			nivelesWindow.close();
		}
		else if (Snivel8.getGlobalBounds().contains(mousePosF)) {
			cout << "8";
			run(8);
			nivelesWindow.close();
		}
		else if (Snivel9.getGlobalBounds().contains(mousePosF)) {
			cout << "9";
			run(1);
			nivelesWindow.close();
		}
		else if (Snivel10.getGlobalBounds().contains(mousePosF)) {
			cout << "10";
			run(2);
			nivelesWindow.close();
		}
		else if (Satras.getGlobalBounds().contains(mousePosF))
		{
			cout << "atras";

			runMenuWindow();
			nivelesWindow.close();

		}


		break;

	}

}






