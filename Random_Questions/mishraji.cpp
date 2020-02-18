//https://www.hackerrank.com/contests/codebusters2020div2/challenges/mishrajis-fun-event/submissions/code/1320962308
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,k,x,y;
    cin>>n>>k>>x;
    vector<pair<int,int>>v,v1(n);
    for(auto i=0;i<n;i++)
    {
        cin>>y;
        if(i==0)
        {
            v.push_back({y,1});
            continue;
        }
        if(y==v[i-1].first){
            v.push_back({y,(v[i-1].second)+1});
        }
        else
            v.push_back({y,1});
        
    }
    for(auto i=n-1;i>=0;i--)
    {
        
        if(i==n-1)
        {
            v1[i].first=v[i].first;
            v1[i].second=1;
            continue;
        }
        if(v[i].first==v[i+1].first){
            v1[i].first=v[i].first;
            v1[i].second=v1[i+1].second+1;
        }
        else{
            v1[i].first=v[i].first;
            v1[i].second=1;
        }
    }
    
    int i=1,j=2;int m=0;
    while(i>=0&&j<n)
    {
        int c=0;
        if(v[i].first==v[j].first&&v[i].first==x)
        {
            int k=i,l=j;c=2;k--,l++;
            while(v[k].first==v[l].first)
            {
                int tot=0;
                tot+=v[k].second+v1[l].second;
                if(tot<3)
                    break;
                c+=tot;
                k-=v[k].second;
                l+=v1[l].second; 
                if(k==0||l==n)
                    break;
            }
            i+=2,j+=2;
            
        }
        else
            i++,j++;
        m=max(c,m);
    }
    cout<<m<<endl;
    return 0;
}

