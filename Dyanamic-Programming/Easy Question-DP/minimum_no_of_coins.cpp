//https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins/0
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

void findNo(int n)
{
    int ans=0;
    int coins[]={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000} ;
    for(auto i=9;i>=0;i--)
    {
        ans=n/coins[i];
        for(auto j=1;j<=ans;j++)
        {
            cout<<coins[i]<<" ";
        }
        n%=coins[i];
    }
}


int32_t main()
{
	fast;
	test
	{
	    int n;
	    cin>>n;
	    findNo(n);
	    cout<<endl;
	  
	}
	return 0;
}
