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


int32_t main()
{
	fast;
	ll n,i=0;
	string s;
	cin>>n;
	cin>>s;
	stack<char>st;
	st.push(s[i++]);
	while(i<n){
		if(!st.empty()&&st.top()==s[i]){
			st.pop();
		}else{
			st.push(s[i]);
		}
		i++;
	}
	string ans="";
	cout<<st.size()<<endl;
	while(!st.empty()){
		ans=st.top()+ans;
		st.pop();
	}
	cout<<ans<<endl;
	return 0;
}
