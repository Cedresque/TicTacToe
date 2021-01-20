#include <iostream>
#include "Brett.h"

using namespace std;

Brett::Brett()
{
	initBrett();
}

void::Brett::initBrett() {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			board[x][y] = ' ';
		}
	}
}

void::Brett::printBrett() {
	cout << "  || 1 | 2 | 3 |" << endl;
	cout << "----------------" << endl;
	cout << "----------------" << endl;
	for (int y = 0; y < 3; y++) {
		cout << " " << y+1 << "||";
		for (int x = 0; x < 3; x++) {
			cout <<" " << board[y][x] << " |";
		}
		cout << endl;
		cout << "----------------" << endl;
	}
}

bool::Brett::setPoint(bool Player1) {
	if (Player1) {
		cout << "Spieler 1";
	}
	else{
		cout << "Spieler 2";
	}
	cout << " bitte Spalte angeben." << endl;
	cin >> y;
	if (Player1) {
		cout << "Spieler 1";
	}
	else {
		cout << "Spieler 2";
	}
	cout << " bitte Reihe angeben." << endl;
	cin >> x;
	if (x > 3 || y > 3|| x<1 || y<1 ) {
		cout << "Bitte ein valides Feld eingeben" << endl;
		return false;
	}
	else if (board[y-1][x-1] == ' '){
		if (Player1) {
			board[y-1][x-1] = P1;
		}
		else{
			board[y-1][x-1] = P2;
		}
		printBrett();
		return true;
	}
	else{
		cout << "Feld  belegt. Bitte neues Feld angeben." << endl;
	}
	return false;
}

bool::Brett::setPlayer( bool Player1) {
	if (Player1) {
		cout << "Spieler 1, welches Symbol moechten sie nutzen?" << endl;
		cin >> P1;
		return false;
	}
	else {
		cout << "Spieler 2, welches Symbol moechten sie nutzen?" << endl;
		cin >> P2;
		if (P2 == P1) {
			cout << "Gleiche Zeichen, bitte verschiedene Zeiten wählen." << endl;
			return true;
		}
		else {
			return false;
		}
	}
}

bool::Brett::unentschieden() {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (board[x][y] == ' ') {
				return false;
			}
		}
	}
	cout << "Unentschieden. Viel Glueck naechstes Mal." << endl;
	return true;
}

bool::Brett::wincondition(bool Player1) {
	//Sieg auf x-Achse
	for (int y = 0; y < 3; y++) {
		if (board[y][0] == board[y][1]){
			if (board[y][1] == board[y][2]) {
				if (board[y][2] != ' ') {
					if (Player1) {
						cout << "Spieler 1";
					}
					else {
						cout << "Spieler 2";
					}
					cout << " hat gewonnen. Herzlichen Glueckwunsch!" << endl;
					return true;
				}
			}
		}
	}
	//Sieg auf y-Achse
	for (int x = 0; x < 3; x++) {
		if (board[0][x] == board[1][x]) {
			if (board[1][x] == board[2][x]) {
				if (board[2][x] != ' ') {
					if (Player1) {
						cout << "Spieler 1";
					}
					else {
						cout << "Spieler 2";
					}
					cout << "hat gewonnen. Herzlichen Glueckwunsch!" << endl;
					return true;
				}
			}
		}
	}
	//Sieg auf Diagonale 1
	if (board[0][0] == board[1][1]) {
		if (board[1][1] == board[2][2]) {
			if (board[2][2] != ' ') {
				if (Player1) {
					cout << "Spieler 1";
				}
				else {
					cout << "Spieler 2";
				}
				cout << " hat gewonnen. Herzlichen Glueckwunsch!" << endl;
				return true;
			}
		}
	}
	//Sieg auf Diagonale 2
	if (board[0][2] == board[1][1]) {
		if (board[1][1] == board[2][0]) {
			if (board[2][0] != ' ') {
				if (Player1) {
					cout << "Spieler 1";
				}
				else {
					cout << "Spieler 2";
				}
				cout << " hat gewonnen. Herzlichen Glueckwunsch!" << endl;
				return true;
			}
		}
	}
	return false;
}