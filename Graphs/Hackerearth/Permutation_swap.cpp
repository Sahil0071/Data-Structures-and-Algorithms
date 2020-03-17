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


void dfs(vector<int>g[],int src,vector<bool>&visited,unordered_set<int>&s)
{
	visited[src]=true;
	s.insert(src);
	for(auto n:g[src])
	{
		if(!visited[n])
		{
			dfs(g,n,visited,s);
		}
	}
}


int32_t main()
{
	fast;
	test
	{
	    ll n,m;
	    cin>>n>>m;
	    mpp mp;
		vector<int>g[n+1];
	    vector<int>p(n),q(n);
	    for(auto i=0;i<n;i++)
	    {
	        cin>>p[i];
	    }
	    for(auto i=0;i<n;i++)
	    {
	        cin>>q[i];
	    }
		while(m--)
		{
			int u,v;
			cin>>u>>v;
			g[u].pb(v);
			g[v].pb(u);
		}
		int c=0;vector<bool>visited(n+1,false);
		for(auto i=1;i<n+1;i++)
		{
			unordered_set<int>s,s1;c=0;
			if(!visited[i])
			{
				dfs(g,i,visited,s);

				for(auto i:s)
				{
					s1.insert(p[i-1]);
					
				}
				for(auto i:s)
				{
					if(s1.find(q[i-1])==s.end())
					{
						cout<<"NO"<<endl;c++;
							break;
						
					}
				}
				
			}
			if(c!=0)
				break;
			
		}
		if(c==0)
		{
			cout<<"YES"<<endl;
		}
			
	    
	}


	return 0;
}
