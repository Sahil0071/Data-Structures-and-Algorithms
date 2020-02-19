//https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-to-make-a-sorted-sequence/0
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

int minDeletion(vector<ll>v)
{
    int n=v.size();
    vector<int>lis(n,1);
    int ma=INT_MIN;
    for(auto i=0;i<n;i++)
    {
        int m=1;
        for(auto j=0;j<i;j++)
        {
            if(v[i]>v[j])
            {
                m=max(lis[j]+lis[i],m);
            }
        }
        lis[i]=m;
        ma=max(lis[i],ma);
    }
    return n-ma;
}

int32_t main()
{
	fast;
	test
	{
	    int n;
	    cin>>n;
	    input(0,n);
	    cout<<minDeletion(v)<<endl;
	}


	return 0;
}
