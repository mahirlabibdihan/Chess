void upSideDown(ChessCell **x,int r,int c)
{
	for(int i=0;i<r/2;i++)
	{
		for(int j=0;j<c;j++)
		{
			ChessCell temp;
			temp.setPiece(x[i][j].getPiece());
			x[i][j].setPiece(x[r-i-1][j].getPiece);
			x[r-i-1][j].setPiece(temp.getPiece());
		}
	}
}