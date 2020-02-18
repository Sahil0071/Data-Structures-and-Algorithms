//https://practice.geeksforgeeks.org/problems/count-number-of-hops/0
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

int dpHelper(int n)
{
    vector<int>dp(n+1,0);
    dp[0]=1,dp[1]=1,dp[2]=2,dp[3]=4;
    for(auto i=4;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[n];
}


int32_t main()
{
	fast;
	test
	{
	    int n;
	    cin>>n;
	    cout<<dpHelper(n)<<endl;
	}


	return 0;
}
