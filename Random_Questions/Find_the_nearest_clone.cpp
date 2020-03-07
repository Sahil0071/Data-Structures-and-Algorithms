//https://www.hackerrank.com/challenges/find-the-nearest-clone/submissions/code/146252405?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=graphs
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */

int bfs(vector<pair<int,int>>g[],int src,int id)
{
    queue<int>q;
    q.push(src);
    unordered_map<int,int>mp;mp[src]=0;
    while(!q.empty())
    {
        auto node=q.front();
        q.pop();
        for(auto nei:g[node])
        {
            if(mp.count(nei.first)==0)
            {
                q.push(nei.first);
                mp[nei.first]=1+mp[node];
                if(nei.second==id)
                {
                    return mp[nei.first];
                }
            }
            
        }
    }
    return -1;
}

int findShortest(int n, vector<int> f, vector<int> t, vector<long> id, int val) {
    // solve here

    vector<pair<int,int>>g[n+1];
    for(auto i=0;i<t.size();i++)
    {
        g[t[i]].push_back({f[i],id[f[i]-1]});
        g[f[i]].push_back({t[i],id[t[i]-1]});
    }
    int d=bfs(g,val,id[val-1]);
    return d;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

    fout << ans << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

