class Solution {
public:
    bool isValidSerialization(string preorder) {
        int deg=1;
        vector<string>arr;
        string tmp = "";
        for(int i=0;i<preorder.size();i++)
        {
            if(preorder[i]==',')
                arr.push_back(tmp), tmp = "";
            else
                tmp += preorder[i];
        }
        arr.push_back(tmp);
        
        for(int i=0;i<arr.size();i++)
        {
            deg--; // subtract 1 for indegree
            if(deg < 0)
                return false;
            if(arr[i].compare("#")!=0)
                deg += 2; // add two for outdegree of non-null node
        }
        
        return deg==0;
    }
};
