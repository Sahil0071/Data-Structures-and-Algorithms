//https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
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

int kadanes(vector<ll>v)
{
    ll cur_sum=INT_MIN;
    ll max_sum=INT_MIN;
    ll n=v.size();
    for(auto i=0;i<n;i++)
    {
        cur_sum=max(v[i],cur_sum+v[i]);
        max_sum=max(cur_sum,max_sum);
    }
    return max_sum;
}


int32_t main()
{
	fast;
	test
	{
	    ll n;
	    cin>>n;
	    input(0,n);
	    cout<<kadanes(v)<<endl;
	}


	return 0;
}
