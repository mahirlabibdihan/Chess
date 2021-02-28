#include "chess_cell.h"
#include "chess_board.h"
extern ChessBoard board;
ChessCell::ChessCell()
{
	piece=NULL;
}
void ChessCell::draw()
{
	iG::ISetColor::iSolid(getColor());
	iG::IDraw::IFilled::iRectangle(x,y,width,height);
	if(piece!=NULL) piece->draw(x+width/6,y);
}
void ChessCell::setPiece(ChessPiece* piece)
{
	this->piece=piece;
}
void ChessCell::clear()
{
	piece=NULL;
}
bool ChessCell::isEmpty()
{
	return piece==NULL;
}
void ChessCell::setR(int r)
{
	this->r=r;
}

void ChessCell::setC(int c)
{
	this->c=c;
}

bool ChessCell::move(int r,int c,ChessPiece* piece)
{
	if(piece->isValidMove(r,c,this->r,this->c))
	{
		this->piece=piece;
		return true;
	}
	return false;
}

PieceColor ChessCell::getTeam()
{
	return piece->getTeam();
}