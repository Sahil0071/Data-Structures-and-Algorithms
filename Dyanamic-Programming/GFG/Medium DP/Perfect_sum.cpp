//https://practice.geeksforgeeks.org/problems/perfect-sum-problem/0
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


int32_t main()
{
	fast;
	test{
	    ll n;
	    cin>>n;
	    input(1,n+1);
	    ll sum;
	    cin>>sum;
	    vector<vector<ll>>dp(n+1,vector<ll>(sum+1,0));
	    for(auto i=0;i<=n;i++)
	    {
	        dp[i][0]=1;
	    }
	    for(auto i=1;i<=sum;i++)
	    {
	        dp[0][i]=0;
	    }
	    for(auto i=1;i<n+1;i++)
	    {
	        for(auto j=1;j<=sum;j++)
	        {
	            if(v[i]>j)
	            {
	                dp[i][j]=dp[i-1][j];
	            }
	            else
	            {
	                dp[i][j]=dp[i-1][j-v[i]]+dp[i-1][j];
	            }
	        }
	    }
	    
	    cout<<dp[n][sum]<<endl;
	}


	return 0;
}
