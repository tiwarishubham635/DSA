vector <int> rotate (int n, int d)
{
    vector<int>ans;
    ans.push_back((n<<d)|n>>(32-d));
    ans.push_back((n>>d)|n<<(32-d));
    return ans;
}
