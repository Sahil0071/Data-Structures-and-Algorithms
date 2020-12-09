#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long int
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

int x;
// Idea is to find the farthest node two times.
// First find the farthest node from any random node and then again find the farthest node from that node. Since we know these two nodes will always be leaf node. This question is similar to diameter in a tree.
void dfs(int u,vector<int>graph[],vector<bool>vis,int count,int &maxCount){

	vis[u]=true;
	count++;
	for(auto v:graph[u]){
		if(!vis[v]){
			if(count>=maxCount){
				maxCount=count;
				x=v;
			}
			dfs(v,graph,vis,count,maxCount);
		}
	}
}

void dfsUtils(int u,vector<int>graph[],int n){

	vector<bool>vis(n+1,0);
	int maxCount=INT_MIN;

	dfs(1,graph,vis,0,maxCount);
	int node1=x;
	vis.resize(n+1,false);

	dfs(x,graph,vis,0,maxCount);
	cout<<node1<<" "<<x<<endl;
}


int32_t main()
{
	fast;
	int n,u,v;
	cin>>n;
	vector<int>graph[n+2];
	for(auto i=1;i<n;i++){
		cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	dfsUtils(1,graph,n);
	

	return 0;
}
