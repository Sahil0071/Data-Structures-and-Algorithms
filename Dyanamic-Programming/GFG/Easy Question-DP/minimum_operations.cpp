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

void recApproach(int n,int c,int *ans,int cur_no)
{
    if(cur_no==n)
    {
        if(c<*ans)
        {
            *ans=c;
        }
        return;
    }
    if(cur_no>n)
    {
        return ;
    }
    recApproach(n,c+1,ans,cur_no+1);
    if(cur_no!=0)
    recApproach(n,c+1,ans,cur_no*2);
}

int recApproach(int n)
{
    if(n==1)
    {
        return 0;
    }
    if(n<1)
    {
        return INT_MAX;
    }
    if(n&1)
    {
        return(1+min(1+recApproach((n-1)/2),recApproach(n-1)));
    }
    else
        return(1+min(recApproach(n/2),recApproach(n-1)));
     
    
}

int DPApproach(int n)
{
    if(n==0)
	return 0;
    vector<int>dp(100002,-1);
    dp[1]=1;
    for(auto i=2;i<=n;i++)
    {
        if(i&1)
        {
            dp[i]=1+min(1+dp[(i-1)/2],dp[i-1]);
        }
        else
            dp[i]=1+min(dp[i/2],dp[i-1]);
    }
    return dp[n];
    
}


int32_t main()
{
	fast;
	test{
	    int n;
	    cin>>n;
	    int ans=0;
	    //recApproach(n,0,&ans,0);
	    //cout<<ans<<endl;
	    //ans=recApproach(n);
	    //cout<<ans+1<<endl;
	    ans=DPApproach(n);
	    cout<<ans;
	}


	return 0;
}
