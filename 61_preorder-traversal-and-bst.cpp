int canRepresentBST(int arr[], int n) 
{
  stack<int>s;
  int root = INT_MIN;
  for(int i=0;i<n;i++)
  {
      if(arr[i]<root)
          return false;

      while(s.size()&&s.top()<arr[i])
      {
          root = s.top();
          s.pop();
      }

      s.push(arr[i]);
  }
  return true;
}
