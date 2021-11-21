#pragma once
#include "Includes.h"
#include <iostream>
#include "Matrices.h"
#include <thread> 
#include "Dijkstra.h"
#include "Vertice.h"
#include "Rute.h"
#include "Floyd.h"

using namespace std;
using namespace sf;

class game
{
public:
	//static bool tecla;
	Matrices Matrix[15][15];
	game();
	~game();
	void run(int);
	void runGameOver();
	void MoverBlinky(std::vector<Vertice>);
	void moverClyde(std::vector<Vertice>);
	void moverInky(std::vector<Vertice>);
	void MoverInkyD(std::vector<Vertice>);
	void moverClydeDijkstra(std::vector<Vertice>);
	void moverPinkyDijkstra(std::vector<Vertice>);
	void runNivelesWindow();
	void runMenuWindow();
private:
	sf::RenderWindow renderWindow;
	sf::RenderWindow menuWindow;
	sf::RenderWindow gameOverWindow;
	sf::Event event;
	sf::RenderWindow nivelesWindow;
	
	//Metodos
	
	
	void initView();
	void agregaBoton();
	void eventBoton();
	void HacerNivel(int, bool);
	void Nivel(int, bool,int);
	void eventeclas();
	void CargarNivel(int , int ,int,int);
	void validarMovimiento(float, float, int,int);
	void cambiarCoordenadas(float , float , int,int);
	void cambiarDireccion(int);
	void MovAutomatico(int);
	void MovAutomaticoBlinky();
	void movAutomaticoInky();
	void movInky();
	void floydInky();
	void MoverPacMan();
	void FloydClyde();
	void moverBinky();
	void movClyde();
	void movAutClyde();
	void DijkstraBliky();
	void preva();
	void VerificarMatar();
	void EntradasSalidas(int, float, float, int);
	void dijkstraComerInky();
	void dijkstraComerClyde();
	void dijkstraComerPinky();
	void movAutomaticoClydeDijkstra2();
	void movAutomaticoClydeDijkstra();
	void movAutomaticoInkyDijkstra();
	void movAutomaticoPinkyDijkstra();
	void MovFantasmasMuertos();

	void initNivelesWindow();
	void botonesNiveles();
	void eventoNiveles();

	void initMenuWindow();
	void botonesMenu();
	void eventoMenu();

	void iniGameOverWindow();
	void botonesGameOver();
	void eventoGameOber();

	void guardar(String nombre, int puntos, int fantasmas);
	void cargar();
};

