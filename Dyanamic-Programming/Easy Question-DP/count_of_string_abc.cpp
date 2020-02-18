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

int recApproach(int n,int b,int c)
{
    if(b<0||c<0)
    {
        return 0;
    }
    if(n==0)
    {
        return 1;
    }
    if(b==0&&c==0)
    {
        return 1;
    }
    int res=recApproach(n-1,b,c)+recApproach(n-1,b-1,c)+recApproach(n-1,b,c-1);
    return res;
}

int efficientApproach(int n)
{
    return 1+(n*2)+(n*((n*n)-1)/2);
}

int32_t main()
{
	fast;
	test
	{
	    int n;
	    cin>>n;
	    //cout<<recApproach(n,1,2)<<endl;
	    cout<<efficientApproach(n)<<endl;
	}


	return 0;
}
