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

/*
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):
		val(x),
		left(nullptr), right(nullptr)
	{}
};
*/

class TreeNode{
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x){
		val=x;
		left=right=nullptr;
	}
};

int findMirrorImage(TreeNode *lTree,TreeNode *rTree,int node){
	if(!lTree||!rTree){
		return -1;
	}
	if(lTree->val==node){
		return rTree->val;
	}
	if(rTree->val==node){
		return lTree->val;
	}
	int ans=findMirrorImage(lTree->left,rTree->right,node);
	if(ans!=-1){
		return ans;
	}
	return findMirrorImage(lTree->right,rTree->left,node);
}

int32_t main()
{
	c_p_c();
	int n,q,node,u,v;char l;
	cin>>n>>q;
	map<int,TreeNode*> m;
	m[1]=new TreeNode(1);
	while(n-->1){
		cin>>u>>v>>l;
		TreeNode* newnode= new TreeNode(v);
		m[v]=newnode;
		if(l=='R'){
			m[u]->right=newnode;
		}
		if(l=='L'){
			m[u]->left=newnode;
		}
	}
	while(q--){
		cin>>node;
		if(node==1){
			cout<<1<<endl;
			continue;
		}
		int ans=findMirrorImage(m[1]->left,m[1]->right,node);
		cout<<ans<<endl;
	}
	
	return 0;
}
