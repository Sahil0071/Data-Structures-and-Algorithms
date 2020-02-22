//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/entrance-examination-01e4a1b9/description/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(i,a,b) for(int i=a;i<b;i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define endl "\n"
bool visited[2000010];
#define extra 1000001

unordered_map<ll,ll>mp;
int a,b;
void total(int n,int s)
{
    if(mp.count(s)==0)
    {
        mp[s]=1;
    }
    if(n<=0)
    {
        return ;
    }
    total(n-1,s+a);
    //total(n-1,s);
    total(n-1,s-b);
}

int find(int n)
{
    /*unordered_map<ll,ll>mp;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n-i;j++)
        {
            if(mp.count(a*i-b*j)==1)
                break;
            mp[a*i-b*j]=1;
        }
    }
    return mp.size();*/
    
    /*for(int i=1;i<=2000001;i++)
	{
	    vis[i]=0;
	}
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n-i;j++)
        {
            if(vis[a*i-b*j+extra])break;
            vis[a*i-b*j+extra]=1;
        }
    }
    int cnt=0;
	for(int i=1;i<=2000001;i++)
	{
	    if(vis[i])cnt++;
	}
	return cnt;*/
}

int solve(int n)
{
    queue<pair<ll,ll>>q;
    ll s=n*b;
	ll d=n*a+s;
	q.push({s,0});
	memset(visited,0,sizeof(visited));
	visited[s]=1;
	while(!q.empty())
	{
		ll temp=q.front().first;
		ll lvl=q.front().second;
		q.pop();
		if(lvl>=n)
		{
			continue;
		}
		if(temp+a<=d)
		{
			if(!visited[temp+a])
			{
			    visited[temp+a]=1;
				q.push({temp+a,1+lvl});
			}
		}
		if(temp-b>=0)
		{
			if(!visited[temp-b])
			{
			    visited[temp-b]=1;
				q.push({temp-b,1+lvl});
			}
		}
	}
	int ans=0;
	for(ll i=0;i<=d;i++)
        ans+=visited[i];
    return ans;
}

int32_t main()
{
    fast;
    int t,s=0;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n>>a>>b;
        //total(n,s);
        //cout<<find(n)<<endl;
        cout<<solve(n)<<endl;
    }
    
    return 0;
}

