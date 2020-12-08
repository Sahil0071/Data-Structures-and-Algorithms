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

map<int,set<int>>succ;

// Get all the successors of a node
set<int> dfs(int u,vector<int>graph[]){
	set<int>s;
	s.insert(u);
	for(auto v:graph[u]){
		set<int>sc=dfs(v,graph);
		s.insert(sc.begin(),sc.end());
	}
	succ[u]=s;
	return s;
}

int c=0;map<int,int>mp;
void dfs_(int u,vector<int>graph[]){
	if(mp.count(u)){
		c++;
		return;
	}
	for(auto v:graph[u]){
		dfs_(v,graph);
	}
}

int32_t main()
{
	fast;
	int n,u,q;
	cin>>n;
	vector<int>graph[n+1];
	for(auto i=1;i<=n;i++){
		cin>>u;
		if(u!=-1){
			graph[u].push_back(i);
		}
	}
	cin>>q;
	for(auto i=0;i<q;i++){
		cin>>u;
		mp[u]=1;
	}
	dfs_(1,graph);
	cout<<c<<endl;

	return 0;
}
