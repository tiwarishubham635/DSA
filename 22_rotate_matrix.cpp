Approach-1
void Solution::rotate(vector<vector<int> > &a) 
{
    int n = a.size();
    for(int i=0;i<n/2;i++)
    {
        for(int j=i;j<n-i-1;j++)
        {
            int tmp = a[i][j];
            a[i][j] = a[n-1-j][i];
            a[n-1-j][i] = a[n-1-i][n-1-j];
            a[n-1-i][n-1-j] = a[j][n-1-i];
            a[j][n-1-i] = tmp;
        }
    }
}


Approach-2:
void Solution::rotate(vector<vector<int> > &arr) 
{
    int N = arr.size();
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < i; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N / 2; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[i][N - j - 1];
            arr[i][N - j - 1] = temp;
        }
    }
}
