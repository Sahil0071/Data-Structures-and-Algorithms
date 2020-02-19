//https://practice.geeksforgeeks.org/problems/maximum-sum-bitonic-subsequence/0
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
#define test ll t;cin>>t;while(t--)
#define input(a,b) vector<int>v(b);for(auto i=a;i<b;i++)cin>>v[i]
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef unordered_map<ll,ll> mpp;
typedef pair<ll,ll> ii;

int bitonicSeq(vector<int>v)
{
    int n=v.size();
    vector<int>inc(n+1,0),dec(n+1,0);
    for(auto i=0;i<n;i++)
    {
        inc[i]=v[i],dec[i]=v[i];
    }
    for(auto i=1;i<n;i++)
    {
        for(auto j=0;j<i;j++)
        {
            if(v[j]<v[i])
            {
                inc[i]=max(inc[i],inc[j]+v[i]);
            }
        }
    }
    for(auto i=n-2;i>=0;i--)
    {
        for(auto j=n-1;j>i;j--)
        {
            if(v[j]<v[i])
            {
                dec[i]=max(dec[i],dec[j]+v[i]);
            }
        }
    }
    int ans=INT_MIN;
    for(auto i=0;i<n;i++)
    {
        ans=max(ans,inc[i]+(dec[i]-v[i]));
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
	    input(0,n);
	    cout<<bitonicSeq(v)<<endl;
	}


	return 0;
}
