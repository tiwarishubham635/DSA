bool isSafe(vector<string>&a, int r, int c, int n)
	    {
		if (r >= n)
		    return false;
		if (c >= n)
		    return false;
		for (int i = 0; i < n; i++)
		{
		    if (a[r][i]=='Q')
			return false;
		    if (a[i][c]=='Q')
			return false;
		    for (int j = 0; j < n; j++)
		    {
			if ((i + j == r + c || i - j == r - c) && a[i][j]=='Q')
			    return false;
		    }
		}

		return true;
	    }

	    void helper(vector<string>&board, int row, int col, int n, vector<vector<string>>&ans)
	    {
		if(row>=n)
		{
		    ans.push_back(board);
		    return;
		}

		if(isSafe(board, row, col, n))
		{
		    board[row][col]='Q';
		    helper(board, row+1, 0, n, ans);
		    board[row][col]='.';
		}

		if(col<n-1)
		{
		    helper(board, row, col+1, n, ans);
		    board[row][col]='.';
		    return;
		}
		else
		    return;

	    }
	    vector<vector<string>> solveNQueens(int n) 
	    {
		vector<string>board;
		for(int i=0;i<n;i++)
		{
		    string x = "";
		    for(int j=0;j<n;j++)
		    {
			x += '.';
		    }
		    board.push_back(x);
		}
		vector<vector<string>>ans;
		helper(board, 0, 0, n, ans);
		return ans;
	    }
