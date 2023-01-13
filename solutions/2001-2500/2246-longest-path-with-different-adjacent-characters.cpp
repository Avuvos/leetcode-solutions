class Solution {
public:
    vector<vector<int>> g;
    int ans = 0;
    string label;
    //dfs(u) will return a list of children and the path length
    //if i go down to each child.
    //to calc the answer for node u is to pick the 2 best children
    //this will be saved in res_u_root.
    int dfs(int u, int p) {
        int len = 0;
        int res_u_root = 1;
        priority_queue<int> pq;
        
        for (auto v: g[u]) {
            if (v == p) continue;
            int child_len = (label[u] != label[v]) + dfs(v, u);
            if (label[u] == label[v]) child_len = 0;
            len = max(len, child_len);
            pq.push(child_len);
        }
        
        //to get the answer if the root of the path is u
        //pick the two best paths starting from u and combine them
        int cnt = 0;
        while (!pq.empty() && cnt < 2) {
            cnt++;
            res_u_root += pq.top();
            pq.pop();
        }        
        ans = max(ans, res_u_root);
        return len;
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n = (int) s.size();
        g = vector<vector<int>>(n);
        label = s;
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) continue;
            g[parent[i]].push_back(i);
        }
        
        dfs(0, -1);
        return ans;
    }
};
