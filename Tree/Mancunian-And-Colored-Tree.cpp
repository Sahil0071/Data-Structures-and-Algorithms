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

vector<int>ans(100005,-1);
vector<int>col(100005);
unordered_map<int,vector<int>>mp;


void dfs(int u,vector<int>graph[]){
	
	for(auto v:graph[u]){
		if(mp.count(u)){
			for(auto i:mp[u]){
				mp[v].pb(i);
				if(col[i]==col[v]){
					ans[v]=i;
				}
			}
		}
		mp[v].pb(v);
		dfs(v,graph);
	}
}


int32_t main()
{
	fast;
	int n,c,u,q;
	cin>>n>>c;
	vector<int>graph[n+1];
	for(auto i=1;i<n;i++){
		cin>>u;
		graph[u].pb(i+1);
	}
	for(auto i=1;i<=n;i++){
		cin>>col[i];
	}
	mp[1].pb(1);
	dfs(1,graph);
	for(auto i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;

	return 0;
}
