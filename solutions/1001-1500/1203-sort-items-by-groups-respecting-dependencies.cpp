class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        
        auto topological_sort = [&](vector<vector<int>>& g, vector<int>& indegree, vector<int>& order) {
            queue<int> q;
            for (int i = 0; i < indegree.size(); i++) {
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
            while (!q.empty()) {
                int u = q.front(); q.pop();
                order.push_back(u);
                for (auto v: g[u]) {
                    indegree[v]--;
                    if (indegree[v] == 0) {
                        q.push(v);
                    }
                }
            }
        };
        
        int group_idx = m;
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = group_idx++;
            }
        }
        
        vector<vector<int>> item_graph(n);
        vector<int> item_deg(n, 0);
        
        vector<vector<int>> group_graph(group_idx);
        vector<int> group_deg(group_idx, 0);
        
        for (int i = 0; i < n; i++) {
            for (auto x: beforeItems[i]) {
                item_graph[x].push_back(i);
                item_deg[i]++;
                if (group[i] != group[x]) {
                    group_deg[group[i]]++;
                    group_graph[group[x]].push_back(group[i]);
                }
            }
        }
        
        vector<int> item_ord;
        vector<int> group_ord;
        topological_sort(item_graph, item_deg, item_ord);
        topological_sort(group_graph, group_deg, group_ord);
        
        vector<int> ans;
        if ((int)item_ord.size() != n || (int)group_ord.size() != group_idx) {
            return ans;
        }
        
        unordered_map<int, vector<int>> mp;
        for (auto x: item_ord) {
            mp[group[x]].push_back(x);
        }
        
        for (auto x: group_ord) {
            ans.insert(ans.end(), mp[x].begin(), mp[x].end());
        }
        
        return ans;
        
        
    }
};
