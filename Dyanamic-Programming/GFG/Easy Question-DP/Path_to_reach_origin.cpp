//https://practice.geeksforgeeks.org/problems/paths-to-reach-origin/0
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

int recApproach(int n,int m)
{
    if(n==0&&m==0)
    {
        return 1;
    }
    if(n<0||m<0)
        return 0;
    return(recApproach(n-1,m)+recApproach(n,m-1));
}

vector<vector<int>>dp(26,vector<int>(26,-1));
int TDApproach(int n,int m)
{
    if(n==0&&m==0)
    {
        return 1;
    }
    if(n<0||m<0)
        return 0;
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    dp[n][m]=(recApproach(n-1,m)+recApproach(n,m-1));
    return dp[n][m];
}


int32_t main()
{
	fast;
	test
	{
	    int n,m;
	    cin>>n>>m;
	    cout<<TDApproach(n,m)<<endl;
	}


	return 0;
}
