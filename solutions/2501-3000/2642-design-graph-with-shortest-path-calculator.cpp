class Graph {
public:
    typedef long long ll;
    vector<array<ll, 3>> e;
    vector<vector<ll>> sp;
    const ll INF = 1e18;
    int cnt = 0;
    Graph(int n, vector<vector<int>>& edges) {
        sp = vector<vector<ll>>(n, vector<ll>(n, INF));
        for (auto &ed: edges) {
            e.push_back({ed[0], ed[1], ed[2]});
        }
        for (int i = 0; i < n; ++i) {
            bf(sp[i], i);
        }
    }
    void bf(vector<ll>& d, int source) {
        d[source] = 0;
        for (;;)
        {
            bool any = false;
            for (int j = e.size() - 1; j >= 0; j--)
                if (d[e[j][0]] < INF)
                    if (d[e[j][1]] > d[e[j][0]] + e[j][2])
                    {
                        d[e[j][1]] = d[e[j][0]] + e[j][2];
                        any = true;
                    }
            if (!any)  break;
        }
    }

    void addEdge(vector<int> edge) {
        e.push_back({edge[0], edge[1], edge[2]});
    }

    int shortestPath(int node1, int node2) {
        bf(sp[node1], node1);
        if (sp[node1][node2] == INF) return -1;
        return sp[node1][node2];
    }
};
