//https://practice.geeksforgeeks.org/problems/distinct-occurrences/1
#include<iostream>
using namespace std;
int rechelper(string s,string t,int i,int j)
{
    if(j==t.length())
    {
        return 1;
    }
    if(i>=s.length())
    {
        return 0;
    }
    if(s[i]==t[j])
    {
        return (rechelper(s,t,i+1,j+1)+rechelper(s,t,i+1,j));
    }
    else
    {
        return rechelper(s,t,i+1,j);
    }
}
int DPhelper(string s,string t)
{
    int m=s.length();
    int n=t.length();
    vector<vector<int>>v(m+1,vector<int>(n+1,0));
    v[0][0]=1;
    for(auto i=1;i<=m;i++)
    {
        v[i][0]=1;
    }
    
    for(auto i=1;i<=m;i++)
    {
        for(auto j=1;j<=n;j++)
        {
            if(s[i-1]==t[j-1])
            {
                v[i][j]=v[i-1][j-1]+v[i-1][j];
            }
            else
                v[i][j]=v[i-1][j];
        }
    }
    return v[m][n];
}
int subsequenceCount(string s, string t)
{
  //Your code here
  //int ans=rechelper(s,t,0,0);
  int ans=DPhelper(s,t);
  return ans;
    
}
