#include "chess_piece.h"
#include "chess_board.h"
extern ChessBoard board;
ChessPiece::ChessPiece(PieceColor team)
{
	this->team=team;
}
PieceColor ChessPiece::getTeam()
{
	return team;
}
PieceName ChessPiece::getType()
{
	return type;
}
King::King(PieceColor team):ChessPiece(team)
{
	this->team=team; 
	type=KING;
}
void King::draw(int x,int y)
{
	if(team==__WHITE__)
	{
		iG::IShowImage::BMP(x,y,"Data\\Image\\King_White.png");
	}
	
	else
	{
		iG::IShowImage::BMP(x,y,"Data\\Image\\King_Black.png");
	}
	
	
}

bool King::isValidMove(int r1,int c1,int r2,int c2)
{
	return abs(r1-r2)<2&&abs(c1-c2)<2;
}

Queen::Queen(PieceColor team):ChessPiece(team)
{
	this->team=team;
	type=QUEEN;
}

bool Queen::isValidMove(int r1,int c1,int r2,int c2)
{
	if(r1==r2)
	{
		int i;
		for(i=min(c1,c2)+1;i<max(c1,c2);i++)
		{
			if(!board.at(r1,i).isEmpty())
			{
				break;
			}
		}
		return i==max(c1,c2);
	}
	else if(c1==c2)
	{
		int i;
		for(i=min(r1,r2)+1;i<max(r1,r2);i++)
		{
			if(!board.at(i,c1).isEmpty())
			{
				break;
			}		
		}
		return i==max(r1,r2);
	}
	else if(r1-c1==r2-c2)
	{
		int i,j;
		for(i=min(r1,r2)+1,j=min(c1,c2)+1;i<max(r1,r2);i++,j++)
		{
			if(!board.at(i,j).isEmpty())
			{
				break;
			}
		}
		return i==max(r1,r2);
	}
	else if(r1+c1==r2+c2)
	{
		int i,j;
		for(i=min(r1,r2)+1,j=max(c1,c2)-1;i<max(r1,r2);i++,j--)
		{
			if(!board.at(i,j).isEmpty())
			{
				break;
			}
		}
		return i==max(r1,r2);
	}
	else
	{
		return false;
	}
}
void Queen::draw(int x,int y)
{
	if(team==__WHITE__)
	{
		iG::IShowImage::BMP(x,y,"Data\\Image\\Queen_White.png");
	}
	
	else
	{
		iG::IShowImage::BMP(x,y,"Data\\Image\\Queen_Black.png");
	}
}

Bishop::Bishop(PieceColor team):ChessPiece(team)
{
	this->team=team;
	type=BISHOP;
}
bool Bishop::isValidMove(int r1,int c1,int r2,int c2)
{
	if(r1-c1==r2-c2)
	{
		int i,j;
		for(i=min(r1,r2)+1,j=min(c1,c2)+1;i<max(r1,r2);i++,j++)
		{
			if(!board.at(i,j).isEmpty())
			{
				break;
			}
		}
		return i==max(r1,r2);
	}
	else if(r1+c1==r2+c2)
	{
		int i,j;
		for(i=min(r1,r2)+1,j=max(c1,c2)-1;i<max(r1,r2);i++,j--)
		{
			if(!board.at(i,j).isEmpty())
			{
				break;
			}
		}
		return i==max(r1,r2);
	}
	return false;
}
void Bishop::draw(int x,int y)
{
	if(team==__WHITE__)
	{
		iG::IShowImage::BMP(x,y,"Data\\Image\\Bishop_White.png");
	}
	
	else
	{
		iG::IShowImage::BMP(x,y,"Data\\Image\\Bishop_Black.png");
	}
}

Knight::Knight(PieceColor team):ChessPiece(team)
{
	this->team=team;
	type=KNIGHT;
}
bool Knight::isValidMove(int r1,int c1,int r2,int c2)
{
	return r1!=r2&&c1!=c2&&abs(r1-r2)+abs(c1-c2)==3;
	// if(r1!=r2&&c1!=c2)
	// {
	// 	if(r2-r1==2&&c2-c1==1)
	// 	{
	// 		return board.at((r1+r2)/2,c1).isEmpty()||board.at((r1+r2)/2,c2).isEmpty();
	// 	}
	// 	else if(r2-r1==2&&c1-c2==1)
	// 	{
	// 		return board.at((r1+r2)/2,c1).isEmpty()||board.at((r1+r2)/2,c2).isEmpty();
	// 	}
	// 	else if(r1-r2==2&&c2-c1==1)
	// 	{
	// 		return board.at((r1+r2)/2,c1).isEmpty()||board.at((r1+r2)/2,c2).isEmpty();
	// 	}
	// 	else if(r1-r2==2&&c1-c2==1)
	// 	{
	// 		return board.at((r1+r2)/2,c1).isEmpty()||board.at((r1+r2)/2,c2).isEmpty();
	// 	}
	// 	else if(r2-r1==1&&c1-c2==2)
	// 	{
	// 		return board.at(r1,(c1+c2)/2).isEmpty()||board.at(r2,(c1+c2)/2).isEmpty();
	// 	}
	// 	else if(r1-r2==1&&c1-c2==2)
	// 	{
	// 		return board.at(r1,(c1+c2)/2).isEmpty()||board.at(r2,(c1+c2)/2).isEmpty();
	// 	}
	// 	else if(r2-r1==1&&c2-c1==2)
	// 	{
	// 		return board.at(r1,(c1+c2)/2).isEmpty()||board.at(r2,(c1+c2)/2).isEmpty();
	// 	}
	// 	else if(r1-r2==1&&c2-c1==2)
	// 	{
	// 		return board.at(r1,(c1+c2)/2).isEmpty()||board.at(r2,(c1+c2)/2).isEmpty();
	// 	}
	// 	else
	// 	{
	// 		return false;
	// 	} 
			
	// }
	// else
	// {
	// 	return false;
	// } 
}
void Knight::draw(int x,int y)
{
	if(team==__WHITE__)
	{
		iG::IShowImage::BMP(x,y,"Data\\Image\\Knight_White.png");
	}
	
	else
	{
		iG::IShowImage::BMP(x,y,"Data\\Image\\Knight_Black.png");
	}
}
Rook::Rook(PieceColor team):ChessPiece(team)
{
	this->team=team;
	type=ROOK;
}
bool Rook::isValidMove(int r1,int c1,int r2,int c2)
{
	if(r1==r2)
	{
		int i;
		for(i=min(c1,c2)+1;i<max(c1,c2);i++)
		{
			if(!board.at(r1,i).isEmpty())
			{
				break;
			}
		}
		return i==max(c1,c2);
	}
	else if(c1==c2)
	{
		int i;
		for(i=min(r1,r2)+1;i<max(r1,r2);i++)
		{
			if(!board.at(i,c1).isEmpty())
			{
				break;
			}		
		}
		return i==max(r1,r2);
	}
	else
	{
		return false;
	} 
}
void Rook::draw(int x,int y)
{
	if(team==__WHITE__)
	{
		iG::IShowImage::BMP(x,y,"Data\\Image\\Rook_White.png");
	}
	
	else
	{
		iG::IShowImage::BMP(x,y,"Data\\Image\\Rook_Black.png");
	}
}
Pawn::Pawn(PieceColor team):ChessPiece(team)
{
	this->team=team;
	type=PAWN;
}
bool Pawn::isValidMove(int r1,int c1,int r2,int c2)
{
	if(board.at(r2,c2).isEmpty())
	{
		return c1==c2&&r2-r1==team*1;
	}
	else
	{
		return abs(c1-c2)==1&&r2-r1==team*1;
	}
	
}
void Pawn::draw(int x,int y)
{
	if(team==__WHITE__)
	{
		iG::IShowImage::BMP(x,y,"Data\\Image\\Pawn_White.png");
	}
	
	else
	{
		iG::IShowImage::BMP(x,y,"Data\\Image\\Pawn_Black.png");
	}
}