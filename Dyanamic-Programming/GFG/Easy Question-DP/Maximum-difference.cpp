//https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string/0
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

int maxDifference(string s)
{
    int n=s.length();
    int zeroes=0,ones=0,m=INT_MIN;
    for(auto i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            if(zeroes-ones>=1)
            {
                zeroes=zeroes-ones+1;
            }
            else
                zeroes=1;
            ones=0;
        }
        else
        {
            ones=ones+1;
        }
        //cout<<zeroes<<" ";
        m=max(zeroes,m);
    }
    return (m!=0)?m:-1;
}


int32_t main()
{
	fast;
	test
	{
	    string s;
	    cin>>s;
	    cout<<maxDifference(s)<<endl;
	}


	return 0;
}
