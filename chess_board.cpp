#include "chess_board.h"
#include "chess_team.h"
extern ChessTeam teamWhite, teamBlack;
ChessBoard::ChessBoard()
{
	this->row = this->col = 8;
	selectedCellR = selectedCellC = 0;
	selectedPieceR = selectedPieceC = -1;
	turn = __WHITE__;
}

void ChessBoard::draw()
{
	iG::ISetColor::iSolid(WHITE);
	iG::IDraw::iRectangle(x, y, width, height, 20);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cell[i][j].draw();
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (selectedCellR == i && selectedCellC == j)
			{
				iG::ISetColor::iTrans(RED, 1);
				iG::IDraw::iRectangle(cell[i][j].getX(), cell[i][j].getY(), cell[i][j].getWidth(), cell[i][j].getHeight(), 10);
			}
			if (selectedPieceR == i && selectedPieceC == j)
			{
				iG::ISetColor::iTrans(RED, .5);
				iG::IDraw::IFilled::iRectangle(cell[i][j].getX(), cell[i][j].getY(), cell[i][j].getWidth(), cell[i][j].getHeight());
			}
		}
	}
}

void ChessBoard::setBoard()
{
	cout << getRow() << " " << unit << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cell[i][j].setPiece(teamWhite.at(i, j));
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cell[row - i - 1][col - j - 1].setPiece(teamBlack.at(i, j));
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if ((i + j) % 2)
			{
				cell[i][j].setColor(BLACK);
			}
			else
			{
				cell[i][j].setColor(WHITE);
			}

			cell[i][j].setX(x + j * unit);
			cell[i][j].setY(y + i * unit);
			cell[i][j].setWidth(unit);
			cell[i][j].setHeight(unit);
			cell[i][j].setR(i);
			cell[i][j].setC(j);
		}
	}
}
void ChessBoard::specialKeyControl(unsigned char key)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		if (selectedCellR < row - 1)
			selectedCellR++;
		break;
	case GLUT_KEY_DOWN:
		if (selectedCellR > 0)
			selectedCellR--;
		break;
	case GLUT_KEY_LEFT:
		if (selectedCellC > 0)
			selectedCellC--;
		break;
	case GLUT_KEY_RIGHT:
		if (selectedCellC < col - 1)
			selectedCellC++;
		break;
	}
}

void ChessBoard::selectCell(int r, int c)
{
	selectedCellR = r;
	selectedCellC = c;
}

void ChessBoard::selectPiece(int r, int c)
{
	selectedPieceR = r;
	selectedPieceC = c;
}

void ChessBoard::deSelectPiece()
{
	selectedPieceR = selectedPieceC = -1;
}

void ChessBoard::keyControl(unsigned char key)
{
	switch (key)
	{
	case  '\r':
		if (!cell[selectedCellR][selectedCellC].isEmpty())
		{
			if (selectedPieceR == -1)
			{
				if (cell[selectedCellR][selectedCellC].getTeam() == turn)
				{
					selectPiece(selectedCellR, selectedCellC);
					if (turn == __BLACK__)
					{
						turn = __WHITE__;
					}
					else
					{
						turn = __BLACK__;
					}
				}
			}
			else if (selectedCellR == selectedPieceR && selectedCellC == selectedPieceC)
			{
				deSelectPiece();
				if (turn == __BLACK__)
				{
					turn = __WHITE__;
				}
				else
				{
					turn = __BLACK__;
				}
			}
			else if (cell[selectedCellR][selectedCellC].getTeam() != cell[selectedPieceR][selectedPieceC].getTeam())
			{
				if (cell[selectedCellR][selectedCellC].move(selectedPieceR, selectedPieceC, cell[selectedPieceR][selectedPieceC].piece))
				{
					cell[selectedPieceR][selectedPieceC].clear();
					deSelectPiece();
				}
			}
		}
		else if (selectedPieceR != -1)
		{
			if (cell[selectedCellR][selectedCellC].move(selectedPieceR, selectedPieceC, cell[selectedPieceR][selectedPieceC].piece))
			{
				cell[selectedPieceR][selectedPieceC].clear();
				deSelectPiece();
			}
		}
		break;

	case 'c':
		deSelectPiece();
		break;
	case 'x':
		setBoard();
		break;
	}
}
ChessCell ChessBoard::at(int i, int j)
{
	return cell[i][j];
}