//https://practice.geeksforgeeks.org/problems/minimal-moves-to-form-a-string/0
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


int dpHelper(string s)
{
    int n=s.length();
    vector<int>dp(n+1,0);dp[0]=1;dp[1]=1;
    for(auto i=1;i<n;i++)
    {
        
        if((i+1)&1)
        {
            dp[i]=dp[i-1]+1;
        }
        else
        {
            int pos=(i+1)/2;
            string s1=s.substr(0,pos);
            string s2=s.substr(pos,pos);
            if(s1.compare(s2)==0)
            {
                dp[i]=min(dp[i-1]+1,dp[pos-1]+1);
            }
            else
                dp[i]=dp[i-1]+1;
        }
        
    }
    
    return dp[n-1];
}

int32_t main()
{
	fast;
	test
	{
	    string s;
	    cin>>s;
	    cout<<dpHelper(s)<<endl;
	}


	return 0;
}
