//https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference/0
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

int maxSum(vector<ll>v,int k)
{
    int n=v.size();
    unordered_map<ll,ll>mp;
    ll s=0;
    for(auto i=0;i<n;i++)
    {
        if(mp.count(i)==0)
        {
            for(auto j=i+1;j<n;j++)
            {
                if(v[i]-v[j]<k&&mp.count(j)==0)
                {
                    s+=v[i]+v[j];
                    mp[i]=1,mp[j]=1;
                    break;
                }
            }
        }
        
    }
    return s;
}


int32_t main()
{
	fast;
	test
	{
	    int n,k;
	    cin>>n;
	    input(0,n);
	    cin>>k;
	    sort(v.begin(),v.end(),greater<int>());
	    /*for(auto i:v)
	    {
	        cout<<i<<" ";
	    }
	    cout<<endl;*/
	    cout<<maxSum(v,k)<<endl;
	}


	return 0;
}
