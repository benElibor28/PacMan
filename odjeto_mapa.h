#pragma once
class odjeto_mapa
{
public:
	void setGrafico(int);
	int getGrafico();
	void setX(float);
	float getX();
	void setY(float);
	float getY();
	void setXP(float);
	float getXP();
	void setYP(float);
	float getYP();
	void setPunto(bool);
	bool getPunto();
	void setKill(bool);
	bool getKill();
private:
	int grafico;
	float x;
	float y;
	float xp;
	float yp;
	bool punto;
	bool kill;
};

