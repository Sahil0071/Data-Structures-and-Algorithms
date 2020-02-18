//https://practice.geeksforgeeks.org/problems/skip-the-work/0
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

int dpHelper(vector<ll>v)
{
    int n=v.size();
    vector<int>dp(n+1,0);
    dp[0]=0,dp[1]=v[0];
    for(auto i=1;i<n;i++)
    {
        dp[i+1]=min(v[i]+dp[(i+1)-2],v[i]+dp[(i+1)-1]);
    }
    return min(dp[n-1],dp[n]);
}


int32_t main()
{
	fast;
	test
	{
	    int n;
	    cin>>n;
	    input(0,n);
	    cout<<dpHelper(v)<<endl;
	}


	return 0;
}
