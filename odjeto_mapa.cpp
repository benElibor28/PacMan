#include "odjeto_mapa.h"





void odjeto_mapa::setGrafico(int g)
{
	grafico = g;
}

int odjeto_mapa::getGrafico()
{
	return grafico;
}
void odjeto_mapa::setX(float _X)
{
	x = _X;
}

void odjeto_mapa::setKill(bool k)
{
	kill = k;
}

bool odjeto_mapa::getKill()
{
	return kill;
}

float odjeto_mapa::getX()
{
	return x;
}

void odjeto_mapa::setY(float _Y)
{
	y = _Y;
}

float odjeto_mapa::getY()
{
	return y;
}

void odjeto_mapa::setXP(float _X)
{
	xp = _X;
}

float odjeto_mapa::getXP()
{
	return xp;
}

void odjeto_mapa::setYP(float _Y)
{
	yp = _Y;
}

float odjeto_mapa::getYP()
{
	return yp;
}

void odjeto_mapa::setPunto(bool  p)
{
	punto = p;
}

bool odjeto_mapa::getPunto()
{
	return punto;
}
