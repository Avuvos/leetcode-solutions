
const int MAXN = 502;

// todo prettify
vector<int> g[MAXN];
int d[MAXN], low[MAXN], scc[MAXN];
bool stacked[MAXN];
stack<int> s;
int ticks, current_scc = 0;
void tarjan(int u){
    d[u] = low[u] = ticks++;
    s.push(u);
    stacked[u] = true;
    for (int& v : g[u]){ // TODO check!
        if (d[v] == -1){
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }else if (stacked[v]){
            low[u] = min(low[u], low[v]);
        }
    }
    if (d[u] == low[u]){
        int v;
        do {
            v = s.top();
            s.pop();
            stacked[v] = false;
            scc[v] = current_scc;
        } while (u != v);
        current_scc++;
    }
}

class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
    current_scc = 0;
    fill_n(stacked, n + 1, false);
    fill_n(d, n + 1, -1);
    fill_n(low, n + 1, 0);
    fill_n(scc, n + 1, -1);
    fill_n(g, n + 1, vector<int>());
    for (auto e: edges) {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }
    int max_groups = -1;
    int comp_sum = 0;
    for (int node = 1; node <= n; node++) {
        if (d[node] == -1) tarjan(node);
    }
    for (int comp = 0; comp < current_scc; comp++) {
        int comp_max = -1;
        for (int node = 1; node <= n; node ++) {
            if (scc[node] != comp) continue;
            bool ok = true;
            vector<int> groups(n + 1, -1);
            int group_index = 0;
            queue<int> q;
            q.push(node);
            groups[node] = group_index;
            while (!q.empty()) {
                int sz = q.size();
                for (int i = 0; i < sz; i++) {
                    int node = q.front(); q.pop();
                    for (auto neib: g[node]) {
                        if (groups[neib] != -1 && abs(groups[neib] - group_index) != 1) {
                            ok = false;
                            break;
                        }
                        if (groups[neib] != -1) continue;
                        groups[neib] = group_index + 1;
                        q.push(neib);
                    }
                    if (!ok) break;
                }
                if (!ok) break;
                group_index++;
            }
            if (!ok) continue;
            comp_max = max(comp_max, group_index);
        }
        if (comp_max == -1) return -1;
        comp_sum += comp_max;
        
    }    
    return comp_sum;
}
};
