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
int subsequenceCount(string s, string t)
{
  //Your code here
  int ans=rechelper(s,t,0,0);
  return ans;
    
}
