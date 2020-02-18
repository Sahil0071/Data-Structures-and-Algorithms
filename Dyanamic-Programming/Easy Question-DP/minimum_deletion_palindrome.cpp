//https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions/0
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

int dp[1002][1002];
int MinDeletion(string s,int i,int j)
{
    if(i>=j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(s[i]==s[j])
    {
        dp[i][j]=MinDeletion(s,i+1,j-1);
        return dp[i][j];
    }
    else
    {
        dp[i][j]= (1+min(MinDeletion(s,i+1,j),MinDeletion(s,i,j-1)));
        return dp[i][j];
    }
    
}

int lps(string s)
{
    
    int n=s.length();
    memset(dp,0,sizeof(dp));
    
    for(auto i=0;i<n;i++)
    {
        dp[i][i]=1;
    }
    
    for(auto l=2;l<=n;l++)
    {
        for(auto i=0;i<n-l+1;i++)
        {
            auto j=i+l-1;
            if(s[i]==s[j])
            {
                dp[i][j]=(l==2)?2:dp[i+1][j-1]+2;
            }
            else
            {
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1];
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
	    memset(dp,-1,sizeof(dp));
	    //cout<<MinDeletion(s,0,s.length()-1)<<endl;
	    cout<<n-lps(s)<<endl;
	}


	return 0;
}
