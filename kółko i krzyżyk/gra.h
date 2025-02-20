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

	void ruch();
	char getZwyciesca();

private:
	char pola1[9][9];
	char czyjRuch = 'O';
	char zwyciesca = '-';
	int pole = 0;
};

