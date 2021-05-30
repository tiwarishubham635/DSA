int gcd(int a, int b)
    {
        if(a<b)
            return gcd(b, a);
        if(b==0)
            return a;
        return gcd(b, a%b);
    }
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int d, int n)
    {
        int g = gcd(n, d);
        for(int i=0;i<g;i++)
        {
            int tmp = arr[i];
            for(int j=i;;j = (j+d)%n)
            {
                if((j+d)%n==i)
                {
                    arr[j] = tmp;
                    break;
                }
                arr[j] = arr[(j+d)%n];
            }
        } 
}
