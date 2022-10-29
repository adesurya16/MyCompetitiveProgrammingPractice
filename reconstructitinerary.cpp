#include <bits/stdc++.h>
using namespace std;

bool comp(string s1, string s2)
{
    return (s1[0] < s2[0]) || (s1[0] == s2[0] && s1[1] < s2[1]) || (s1[0] == s2[0] && s1[1] == s2[1] && s1[2] < s2[2]);
}

void printGraph(map<string, vector<string>> &graph)
{
    for (auto const &[key, val] : graph)
    {
        cout << key << " :";
        int n = val.size();
        for (int i = 0; i < n; i++)
        {
            cout << " " << val[i];
        }
        cout << endl;
    }
}

string createKey(string &s1, string &s2)
{
    return s1 + ":" + s2;
}

bool isVisited(map<string, int> &v, string &s)
{
    return (v.find(s) == v.end() || v[s] == 0);
}

bool isDFS(map<string, vector<string>> &g, string s, map<string, int> &v, vector<string> &p, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {

        int sz = g[s].size();
        for (int i = 0; i < sz; i++)
        {
            string adj = g[s][i];
            string k = createKey(s, adj);

            if (!isVisited(v, k))
            {
                p.push_back(adj);
                v[k]--;
                if (isDFS(g, adj, v, p, n - 1))
                {
                    return 1;
                }
                p.pop_back();
                v[k]++;
            }
        }

        return 0;
    }
}

vector<string> findItinerary(vector<vector<string>> &tickets)
{
    map<string, vector<string>> graph;
    map<string, int> visited;
    set<string> s;
    for (auto &t : tickets)
    {
        string node = t[0];
        string adj = t[1];
        string k = createKey(node, adj);
        if (s.find(k) == s.end())
        {
            if (graph.find(node) != graph.end())
            {
                graph[node].push_back(adj);
            }
            else
            {
                vector<string> tmp;
                tmp.push_back(adj);
                graph[node] = tmp;
            }
            s.insert(k);
        }

        visited[k]++;
    }
    // print graph make sure
    // sort the edges
    for (auto &g : graph)
    {
        sort(g.second.begin(), g.second.end(), comp);
    }
    // printGraph(graph);
    string currStr = "JFK";
    // set<string> visitedEdge; // node:node
    vector<string> path;
    path.push_back(currStr);
    int nEdge = tickets.size();
    bool b = isDFS(graph, currStr, visited, path, nEdge);
    return path;
}

void printArr(vector<string> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}

void solve(int cases = 1)
{
    // solve the problem here
    int n;
    cin >> n;
    vector<vector<string>> arr;
    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        vector<string> tmp;
        cin >> s1 >> s2;
        tmp.push_back(s1);
        tmp.push_back(s2);
        arr.push_back(tmp);
    }
    printArr(findItinerary(arr));
}

int main()
{
    int cases = 1; // 1 or more cases
    // cin >> cases;
    while (cases--)
    {
        solve();
    }
    return 0;
}

/*
[["EZE","AXA"],["TIA","ANU"],["ANU","JFK"],["JFK","ANU"],["ANU","EZE"],["TIA","ANU"],["AXA","TIA"],["TIA","JFK"],["ANU","TIA"],["JFK","TIA"]]
["JFK","ANU","EZE","AXA","TIA","ANU","JFK","TIA","ANU","TIA","JFK"]
*/