#ifndef __CHESS_PIECE__ 
#define __CHESS_PIECE__
#include "main.h"
// enum PieceName{KING,QUEEN,BISHOP,KNIGHT,ROOK,PAWN};
#include "Point.h"
#include "Color.h"
// #include "chess_board.h"
class ChessPiece:public Point{
protected:
	int cellR,cellC,show;
	PieceColor team;
public:
	ChessPiece(PieceColor);
	virtual bool isValidMove(int,int,int,int)=0;
	virtual void draw(int,int)=0;
	bool isDead();
	void selectTeam(PieceColor);
	PieceColor getTeam();
	void setR(int);
	void setC(int);
};

class King:public ChessPiece{
public:
	King(PieceColor);
	bool isValidMove(int,int,int,int);
	void draw(int,int);
};

class Queen:public ChessPiece{
public:
	Queen(PieceColor);
	bool isValidMove(int,int,int,int);
	void draw(int,int);
};

class Bishop:public ChessPiece{
public:
	Bishop(PieceColor);
	bool isValidMove(int,int,int,int);
	void draw(int,int);
};

class Knight:public ChessPiece{
public:
	Knight(PieceColor);
	bool isValidMove(int,int,int,int);
	void draw(int,int);
};

class Rook:public ChessPiece{
public:
	Rook(PieceColor);
	bool isValidMove(int,int,int,int);
	void draw(int,int);
};

class Pawn:public ChessPiece{
public:
	Pawn(PieceColor);
	bool isValidMove(int,int,int,int);
	void draw(int,int);
};
#endif