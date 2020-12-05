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


string findPathToNode(vector<pair<char,ll>>graph[],ll node,ll v){
	string s="";
	vector<pair<ll,char>>par(v+1);
	queue<ll> q;
	par[1]={1,'s'};
	q.push(1);
	while(!q.empty()){
		ll n=q.front();
		q.pop();
		if(n==node){
			break;
		}
		for(auto i:graph[n]){
			ll v=i.sc;
			char p=i.fr;
			q.push(v);
			par[v]={n,p};
		}
	}
	while(par[node].sc!='s'){
		s=par[node].sc+s;
		node=par[node].fr;
	}
	return s;
}

ll findMirrorImage(vector<pair<char,ll>>graph[],ll node,ll v){
	string path=findPathToNode(graph,node,v);
	if(path.length()==0){
		return 1;
	}
	queue<ll> q;
	q.push(1);ll i=0;
	while(!q.empty()){
		ll n=q.front();
		q.pop();
		for(auto ne:graph[n]){
			if(path[i]!=ne.fr){
				q.push(ne.sc);
				i++;
				if(i==path.length()){
					return ne.sc;
				}
				break;
			}
		}
	}
	return -1;
}


int32_t main()
{
	fast;
	ll n,q,u,v,node;char l;
	cin>>n>>q;
	vector<pair<char,ll>>graph[n+1];
	ll m=n--;
	while(n--){
		cin>>u>>v>>l;
		graph[u].pb({l,v});
	}
	
	while(q--){
		cin>>node;
		cout<<findMirrorImage(graph,node,m)<<endl;
	}

	
	return 0;
}
