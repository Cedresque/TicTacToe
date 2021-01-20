#include <iostream>
#include "Brett.h"

using namespace std;

int main() {
	bool Player1 = true;
	bool isDone = false;
	Brett game;
	game.setPlayer(Player1);
	while (game.setPlayer(!Player1)) {

	}
	game.printBrett();
	while (isDone == false) {
		while (Player1) {
			if (game.setPoint(Player1)) {
				if (game.wincondition(Player1)){
					if (game.unentschieden()){
						isDone = true;
					}
				}
				Player1 = false;
			}
		}
		while (Player1 == false && isDone == false) {
			if (game.setPoint(Player1)) {
				if (game.wincondition(Player1)){
					if (game.unentschieden()){
						isDone = true;
					}
				}
				Player1 = true;
			}
		}

	}
	system("Pause");
	return 0;
}