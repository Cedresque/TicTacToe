#pragma once
class Brett
{
public:
	Brett();
	void initBrett();
	void printBrett();
	bool setPoint( bool Player1);
	bool setPlayer( bool Player1);
	bool wincondition(bool Player1);
	bool unentschieden();

private:
	char board[3][3];
	char P1;
	char P2;
	int x;
	int y;
};

