#ifndef __CHESS_CELL__
#define __CHESS_CELL__
#include "chess_piece.h"
#include "main.h"
#include "Box.h"


class ChessCell:public Box{
private:
	int r,c;
public:
	ChessPiece* piece;
	ChessCell();
	void draw();
	bool isEmpty();
	void clear();
	void setPiece(ChessPiece* piece);
	void setR(int);
	void setC(int);
	bool move(int,int,ChessPiece*);
	PieceColor getTeam();
};
#endif