//https://practice.geeksforgeeks.org/problems/zero-sum-subarrays/0
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long int ll;
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

int zeroSum(vector<ll>v)
{
    ll n=v.size();
    mpp mp;ll c=0;
    ll sum=0;
    for(auto i=0;i<n;i++)
    {
        sum+=v[i];
        if(sum==0)
        {
            c++;
        }
        if(mp.count(sum)==1)
        {
            c+=mp[sum];
        }
        mp[sum]++;
    }
    
    return c;
}


int32_t main()
{
	fast;
	test
	{
	    ll n;
	    cin>>n;
	    input(0,n);
	    cout<<zeroSum(v)<<endl;
	}


	return 0;
}
