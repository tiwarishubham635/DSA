int openLock(vector<string> &deadends, string target)
    {
        string state = "0000";
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> v;

        if (dead.find(state) != dead.end())
            return -1;

        int level = 0;
        queue<string> q;
        q.push(state);
        v.insert(state);
        q.push("");

        while (q.size())
        {
            string curr = q.front();
            q.pop();
            //cout << curr << endl;

            if (curr.compare(target) == 0)
                return level;

            if (curr.size() == 0)
            {
                level++;
                q.push("");
                if ((q.front()).size() == 0)
                    break;
                else
                    continue;
            }

            for (int i = 0; i < 4; i++)
            {
                //move right
                char c = curr[i];
                curr[i] = (c == '9' ? '0' : c + 1);
                if (dead.find(curr) == dead.end() && v.find(curr) == v.end())
                    q.push(curr), v.insert(curr);

                //move left
                curr[i] = (c == '0' ? '9' : c - 1);
                if (dead.find(curr) == dead.end() && v.find(curr) == v.end())
                    q.push(curr), v.insert(curr);

                curr[i] = c;
            }
        }
        return -1;
    }
