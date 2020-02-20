//https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1
long long countWays(int m){
    // your code here
    
    vector<int>v(m+1,0);
    v[0]=1;
    v[1]=1;
    for(auto i=2;i<=m;i++)
    {
        if(i&1)
        {
            v[i]=v[i-1];
        }
        else
            v[i]=v[i-1]+1;
    }
    return v[m];
    
}
