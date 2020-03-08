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

void buildTree(vector<ll>&tree,ll s,ll e,vector<ll>&arr,ll index)
{
	if(s==e)
	{
		tree[index]=arr[s];
		return;
	}
	ll mid=s+(e-s)/2;
	buildTree(tree,s,mid,arr,2*index);
	buildTree(tree,mid+1,e,arr,2*index+1);
	tree[index]=min(tree[2*index],tree[2*index+1]);
	return;
}

int query(vector<ll>&tree,ll ss,ll se,ll qs,ll qe,ll index)
{
	if(ss>=qs&&se<=qe)
	{
		return tree[index];
	}
	if(se<qs||ss>qe)
	{
		return INT_MAX;
	}
	ll mid=ss+(se-ss)/2;
	ll leftAns=query(tree,ss,mid,qs,qe,2*index);
	ll rightAns=query(tree,mid+1,se,qs,qe,2*index+1);
	return min(leftAns,rightAns);
}

void updateNode(vector<ll>&tree,ll ss,ll se,ll i,ll inc,ll index)
{
	if(se<i||ss>i)
	{
		return;
	}
	if(ss==se)
	{
		tree[index]=inc;
		return ;
	}
	ll mid=ss+(se-ss)/2;
	if(ss<=i&&i<=mid)
		updateNode(tree,ss,mid,i,inc,2*index);
	else
		updateNode(tree,mid+1,se,i,inc,2*index+1);
	tree[index]=min(tree[2*index],tree[2*index+1]);
	return;
}


int32_t main()
{
	fast;
	ll n,q;
	cin>>n>>q;
	vector<ll>arr(n);
	for(auto i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	vector<ll>tree(4*n+1);
	buildTree(tree,0,n-1,arr,1);
	while(q--)
	{
		ll o,x,y;
		cin>>o>>x>>y;
		if(o==1)
		{
			cout<<query(tree,0,n-1,x-1,y-1,1)<<endl;
		}
		else
		{
			updateNode(tree,0,n-1,x-1,y,1);
		}
		
	}
	return 0;
}
