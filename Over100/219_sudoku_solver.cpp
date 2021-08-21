class Solution {
public:
    bool safe(vector<vector<char>>& board, int row, int col, char num)
    {
        for(int i=0;i<9;i++)
            if(board[i][col]==num)
                return false;
        
        for(int i=0;i<9;i++)
            if(board[row][i]==num)
                return false;
        
        int srow = row - row%3;
        int scol = col - col%3;
        
        for(int i=srow;i<srow+3;i++)
            for(int j=scol;j<scol+3;j++)
                if(board[i][j]==num)
                    return false;
        
        return true;
    }
    
    bool isSolvable(vector<vector<char>>& board)
    {
        int i, j;
        bool flag = 0;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
        
        if(i==9 && j==9)
            return true;
        
        for(int k=1;k<=9;k++)
        {
            if(safe(board, i, j, '0'+k))
            {
                board[i][j] = '0'+k;
                if(isSolvable(board))
                    return true;
                board[i][j] = '.';
            }
        }

        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        bool ans = isSolvable(board);
    }
};
