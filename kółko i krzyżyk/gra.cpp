#include "gra.h"
#include <iostream>


using namespace std;

gra::gra() {
	memset(pola1, '-', sizeof(pola1));

}

gra::~gra() {

}

void gra::drukuj() {

	//pomoc
	for (int i = 0; i < 3; i++) {
		cout << " " << 1 + (3 * i) << " | " << 2 + (3 * i) << " | " << 3 + (3 * i) << " " << endl;
		cout << "-----------" << endl;
		
		
	}
	

	cout << "\\/-GRA-\\/" << endl;
	cout << "-----------" << endl;
	for (int i = 0; i < 3; i++) {
		cout << " " << pola1[0 + (3 * i)] << " | " << pola1[1 + (3 * i)] << " | " << pola1[2 + (3 * i)] << " " << endl;
		cout << "-----------" << endl;
		
	}
}

void gra::ruch() {
	cout << "Ruch gracza [ " << czyjRuch << " ] " << endl;
	cin >> pole;

	pola1[pole - 1] = czyjRuch;

	// zmiana gracza
	if (czyjRuch == 'O') {
		czyjRuch = 'X';
	}
	else {
		czyjRuch = 'O';
	}

	gra::sprawdz();
}


bool gra::sprawdz() {
	//123,456,789,147,258,369,159,753
	//012,345,678,036,147,258,048,642
	return (
		gra::sprawdz(0, 1, 2) || //1
		gra::sprawdz(3, 4, 5) || //2
		gra::sprawdz(6, 7, 8) || //3
		gra::sprawdz(0, 3, 6) || //4
		gra::sprawdz(1, 4, 7) || //5
		gra::sprawdz(2, 5, 8) || //6
		gra::sprawdz(0, 4, 8) || //7
		gra::sprawdz(6, 4, 2)//8
		);	
}

bool gra::sprawdz(int x, int y, int z) {
	if (pola1[x] == pola1[y] && pola1[x] == pola1[z]) {	
		zwyciesca = pola1[x];
		return true;
	}
	else {
		return false;
	}
}

char gra::getZwyciesca() {
	return zwyciesca;
}

