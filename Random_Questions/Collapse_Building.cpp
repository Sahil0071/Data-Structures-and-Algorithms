#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
#define fr first
#define sc second
#define pb push_back


int32_t main()
{
	fast;
	ll n;
	cin>>n;
	vector<ll>st(n),en(n);
	unordered_map<ll,ll>mp;
	for(auto i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		st[i]=x;
		mp[x]=i;
	}
	for(auto i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		en[i]=x+st[i];
	}

	
	vector<ll>ans;int end=1;
	for(auto i=0;i<n;i++)
	{
		ll col=en[i];ll pts=i;
		while(1)
		{
			if(mp.count(col)==1)
			{
				col=en[mp[col]];
			}
			
			auto lb=lower_bound(st.begin(),st.end(),col);
			if(lb-st.begin()==pts)
			{
				end=lb-st.begin();
				break;
			}
			else
			{
				col=en[lb-st.begin()-1];
				end=lb-st.begin();
			}
			pts=lb-st.begin();
		}
		ans.pb(en[end-1]);
	}
	
	for(auto i:ans)
	{
		cout<<i<<endl;
	}


	return 0;
}
