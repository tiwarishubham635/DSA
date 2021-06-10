/*vector<string> generateParenthesis(int n) 
    {
        vector<string>ans;
        if(n==1)
        {
            ans.push_back("()");
            return ans;
        }
        vector<string> prev = generateParenthesis(n-1);
        unordered_set<string>s;
        for(int i=0;i<prev.size();i++)
        {
            string x = prev[i];
            for(int j=0;j<x.size();j++)
            {
                for(int k=j+1;k<x.size();k++)
                {
                    if(x[j]=='('&&x[k]==')')
                        s.insert(x.substr(0,j+1)+'('+x.substr(j+1, k-j)+')'+x.substr(k+1));
                }
                
                if(x[j]==')')
                    s.insert(x.substr(0,j+1)+"()"+x.substr(j+1));
                
                if(x[j]=='(')
                    s.insert(x.substr(0,j+1)+"()"+x.substr(j+1));
            }
        }
        for(auto i=s.begin();i!=s.end();i++)
            ans.push_back(*i);
        return ans;
    }*/
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addingpar(res, "", n, 0);
        return res;
    }
    void addingpar(vector<string> &v, string str, int n, int m){
        if(n==0 && m==0) {
            v.push_back(str);
            return;
        }
        if(m > 0){ addingpar(v, str+")", n, m-1); }
        if(n > 0){ addingpar(v, str+"(", n-1, m+1); }
    }

/*
FASTEST
vector<string> ans;
    void dfs(string& generated, int n, int l, int r){
        if(l>n || r>l) return;
        if(l==r && l==n){
            ans.push_back(generated);
            return;
        }
        generated += "(";
        dfs(generated,n,l+1,r);
        generated.pop_back();
        generated += ")";
        dfs(generated,n,l,r+1);
        generated.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string generated = "";
        dfs(generated, n, 0, 0);
        return ans;
    }
*/
