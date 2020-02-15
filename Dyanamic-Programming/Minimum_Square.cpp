//https://practice.geeksforgeeks.org/problems/get-minimum-squares/0
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

int numSquares(int n) 
{
        
    vector<int>arr;
    for(auto i=1;i*i<=n;i++)
    {
        arr.push_back(i*i);
        if(i*i==n)
        {
            return 1;
        }
    }
    vector<int>dp(n+1,-1);
    dp[0]=0;
    
    for(auto i=1;i<=n;i++)
    {
        for (auto  c : arr)
            if (i - c >= 0 && dp[i - c] != -1)
                dp[i] = dp[i] > 0 ? min(dp[i], dp[i - c] + 1) : dp[i - c] + 1;

    }
    return dp[n];
    
}


int32_t main()
{
	fast;
	test{
    	int n;
    	cin>>n;
    	cout<<numSquares(n)<<endl;
	}


	return 0;
}
