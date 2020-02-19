//https://practice.geeksforgeeks.org/problems/shortest-common-supersequence/0
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
#define test ll t;cin>>t;while(t--)
#define input(a,b) vector<ll>v(b);for(auto i=a;i<b;i++)cin>>v[i]
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef unordered_map<ll,ll> mpp;
typedef pair<ll,ll> ii;

int lcs(string x,string y)
{
    vector<vector<int>>lcs(x.length()+1,vector<int>(y.length()+1,0));
    for(auto i=1;i<=x.length();i++)
    {
        for(auto j=1;j<=y.length();j++)
        {
            if(x[i-1]==y[j-1])
            {
                lcs[i][j]=1+lcs[i-1][j-1];
            }
            else
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
        }
    }
    return lcs[x.length()][y.length()];
}


int32_t main()
{
	fast;
	test
	{
	    string x,y;
	    cin>>x>>y;
	    int l=lcs(x,y);
	    int m=x.length(),n=y.length();
	    cout<<m+n-l<<endl;
	}


	return 0;
}
