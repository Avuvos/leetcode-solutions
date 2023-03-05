class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, unordered_set<int>> mp;
        int ans = 0, n = (int) arr.size();

        for (int i = 0; i < n; ++i) {
            mp[arr[i]].insert(i);
        }

        vector<bool> seen(n, false);
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int qsize = (int) q.size();
            for (int i = 0; i < qsize; ++i) {
                int index = q.front(); q.pop();
                if (index == n - 1) return ans;
                if (seen[index]) continue;
                seen[index] = true;
                if (index - 1 >= 0 && !seen[index - 1]) {
                    q.push(index - 1);
                }
                if (index + 1 < n && !seen[index + 1]) {
                    q.push(index + 1);
                }
                bool to_clear = false;
                for (int j: mp[arr[index]]) {
                    if (j != index) {
                        to_clear = true;
                        q.push(j);
                    }
                }
                if (to_clear)
                    mp[arr[index]].clear();
            }
            ans++;
        }
        return n - 1;
    }
};
