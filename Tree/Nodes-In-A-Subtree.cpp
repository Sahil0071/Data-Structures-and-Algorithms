#include<bits/stdc++.h>

using namespace std;



int cnt[100005][26], n;

vector<int> graph[100005];

string s;



int dfs(int u,int parent){

	int i;

	for(i = 0; i < 26; i ++)

		cnt[u][i] = 0;

	cnt[u][s[u - 1] - 'a'] ++;

	for(auto v:graph[u]){

		if(v==parent){

			continue;

		}

		dfs(v,u);

		for(i = 0; i < 26; i ++){

			cnt[u][i] += cnt[v][i];

		}

	}

}





int main()

{

	int N, Q;

	cin >> N >> Q;

	cin >> s;

	for(int i = 0; i < N - 1; i ++)

	{

		int u, v;

		cin >> u >> v;

		graph[u].push_back(v);

		graph[v].push_back(u);

	    // Process the Inputs of node details  

	}

	dfs(1,0);

	while(Q --)

	{

		int u,ans=0;

		char c;

		cin >> u >> c;

		// Process queries

		cout<<cnt[u][c-'a']<<endl;

	}

	return 0;

}
