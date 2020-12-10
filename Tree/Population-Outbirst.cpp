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

struct a{
	int p,l,c;
}ans[1000005];


/*
Level wise input and according to the no of child a node can have.

Input is happen level wise so at first ->    0
		                            / \ 
					   1   2
					  / \  |
					 5   4 10  
*/
int32_t main()
{
	fast;
	int n,rc0,u,r;
	cin>>n>>rc0;

	// queue({{node,no. of child},levels});
	queue<pair<pair<int,int>,int>>q;

	// Starting node is zero.
	q.push({{0,rc0},0});

	// Have to set child until ch becomes zero and also store rank.
	int ch=rc0,rank=1;

	for(auto i=0;i<n;i++){
		auto node=q.front();
		while(!ch){
			q.pop();
			node=q.front();
			ch=node.fr.sc;
			rank=1;
		}
		auto level=node.sc;
		
		cin>>u>>r;
		q.push({{u,r},level+1});
		ans[i].p=node.fr.fr;
		ans[i].l=level+1;
		ans[i].c=rank++;
		ch--;
	}
	for(auto i=0;i<n;i++){
		cout<<ans[i].p<<" "<<ans[i].l<<" "<<ans[i].c<<endl;
	}

	return 0;
}
