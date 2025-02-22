#pragma once
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

class gra
{
public:

	gra();
	~gra();

	void drukuj();

	bool sprawdz();
	bool sprawdz(int x, int y, int z);
	bool sprawdz2(int x, int y, int z);

	void ruch();
	char getZwyciesca();

	void startGry();

private:
	char pola1[9][9];
	int zbiorpol1 = 4;
	char czyjRuch = 'O';
	char zwyciesca = '-';
	int pole = 0;

	char duzePola1[9];
};

