#include "gra.h"
#include <iostream>


using namespace std;

gra::gra() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			pola1[j][i] = '-';
		}
		duzePola1[i] = '-';
	}
}

gra::~gra() {

}

void gra::drukuj() {




	cout << "\\/-GRA-\\/" << endl;
	cout << "-----------" << endl;


	for (int i = 0; i < 9; i = i + 3) {
		for (int j = 0; j < 9; j = j + 3) {
			cout
				<< pola1[0 + j][i]
				<< " | " << pola1[1 + j][i]
				<< " | " << pola1[2 + j][i]
				<< " ||";
			cout
				<< pola1[0 + j][i + 1]
				<< " | " << pola1[1 + j][i + 1]
				<< " | " << pola1[2 + j][i + 1]
				<< " ||";
			cout
				<< pola1[0 + j][i + 2]
				<< " | " << pola1[1 + j][i + 2]
				<< " | " << pola1[2 + j][i + 2]
				<< " ||";
			cout << endl;
		}
		cout << "-------" << endl;
	}

	cout << "-----" << endl;
	for (int i = 0; i < 9; i = i + 3) {
		cout << duzePola1[i] << " | " << duzePola1[i + 1] << " | " << duzePola1[i + 2] << endl;
		cout << "-----" << endl;
	}

}

void gra::ruch() {
	cout << "Ruch gracza [ " << czyjRuch << " ] " << endl;
	cin >> pole;

	while (pola1[pole-1][zbiorpol1] != '-') {
		cin >> pole;
	}

	pola1[pole - 1][zbiorpol1] = czyjRuch;
	
	gra::sprawdz();

	zbiorpol1 = pole - 1;

	// zmiana gracza
	if (czyjRuch == 'O') {
		czyjRuch = 'X';
	}
	else {
		czyjRuch = 'O';
	}
}


bool gra::sprawdz() {
	//123,456,789,147,258,369,159,753
	//012,345,678,036,147,258,048,642
	if (
		gra::sprawdz(0, 1, 2) || //1
		gra::sprawdz(3, 4, 5) || //2
		gra::sprawdz(6, 7, 8) || //3
		gra::sprawdz(0, 3, 6) || //4
		gra::sprawdz(1, 4, 7) || //5
		gra::sprawdz(2, 5, 8) || //6
		gra::sprawdz(0, 4, 8) || //7
		gra::sprawdz(6, 4, 2)//8
		) {
		cout << "";
		if (
			gra::sprawdz2(0, 1, 2) || //1
			gra::sprawdz2(3, 4, 5) || //2
			gra::sprawdz2(6, 7, 8) || //3
			gra::sprawdz2(0, 3, 6) || //4
			gra::sprawdz2(1, 4, 7) || //5
			gra::sprawdz2(2, 5, 8) || //6
			gra::sprawdz2(0, 4, 8) || //7
			gra::sprawdz2(6, 4, 2)//8
			) {
			return true;
		}
	}
}

bool gra::sprawdz2(int x, int y, int z) {
	if (duzePola1[x] == duzePola1[y] 
		&& duzePola1[x] == duzePola1[z] 
		&& duzePola1[x] != '-'
		) {
		zwyciesca = duzePola1[x];
		cout << "SPRAWDZILEM" << endl;
		return true;
	}
	else {
		return false;
	}
}

bool gra::sprawdz(int x, int y, int z) {
	if (pola1[x][zbiorpol1] == pola1[y][zbiorpol1] 
		&& pola1[x][zbiorpol1] == pola1[z][zbiorpol1]
		&& pola1[x][zbiorpol1] != '-'
		) 
	{
		duzePola1[zbiorpol1] = pola1[x][zbiorpol1];
		return true;
	}
	else {
		return false;
	}
}

char gra::getZwyciesca() {
	return zwyciesca;
}

void gra::startGry() {

	gra::drukuj();

	// Ruch graczy
	while (zwyciesca == '-') {
		gra::ruch();
		system("cls");
		gra::drukuj();
	}

	//koniec gry
	cout << "KONIEC GRY, ZWYCIESCA TO [ " << gra::getZwyciesca() << " ] " << endl;
}

