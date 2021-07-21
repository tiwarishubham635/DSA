string pushDominoes(string dominoes) 
    {
        int n = dominoes.size();
        vector<int>forces(n);
        
        int force = 0;
        
        for(int i=0;i<n;i++) // forces on right 
        {
            if(dominoes[i]=='L')
                force = 0;
            else if(dominoes[i]=='R')
                force = n;
            else
                force = max(force-1, 0);
            
            forces[i] = force;
        }
        
        force = 0;
        
         for(int i=n-1;i>=0;i--) // forces on left
        {
            if(dominoes[i]=='R')
                force = 0;
            else if(dominoes[i]=='L')
                force = n;
            else
                force = max(force-1, 0);
            
            forces[i] -= force;
        }
        
        string ans = dominoes;
        for(int i=0;i<n;i++)
        {
            if(forces[i]>0)
                ans[i] = 'R';
            else if(forces[i] < 0)
                ans[i] = 'L';
            else
                ans[i] = '.';
        }
        return ans;
    }
