//https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence/0
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

int lcsVar(string s)
{
    int n=s.length();
    vector<vector<int>>lcs(n+1,vector<int>(n+1,0));
    for(auto i=1;i<=n;i++)
    {
        for(auto j=i+1;j<=n;j++)
        {
            if(s[i-1]==s[j-1])
            {
                lcs[i][j]=1+lcs[i-1][j-1];
            }
            else
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
        }
    }
    int ans=INT_MIN;
    for(auto i=1;i<=n;i++)
    {
        ans=max(lcs[i][n],ans);
    }
    return ans;
}


int32_t main()
{
	fast;
	test
	{
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	    cout<<lcsVar(s)<<endl;
	}


	return 0;
}
