class Trie {
    typedef long long ll;
    vector<unordered_map<char, int>> trie; //mx[0]['a']=1  means that e(0,1)='a'.
    vector<ll> counter;
    int nodes;
public:
    Trie(int max_len){
        nodes = 0;
        trie = vector<unordered_map<char, int>>(max_len);
        counter = vector<ll>(max_len);
    }

    void add(const string& s) {
        int current_node = 0;
        for (auto chr : s) {
            if (trie[current_node][chr] == 0) {
                trie[current_node][chr] = ++nodes;
            }
            current_node = trie[current_node][chr];
        }
        ++counter[current_node];
    }

    int find(const string& s) {
        int current_node = 0;
        for (int j = 0; j < s.size(); j++) {
            char chr = s[j];
            if (trie[current_node][chr] == 0) {
                return j - 1;
            }
            current_node = trie[current_node][chr];
        }
        return s.size() - 1;
    }
};

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        int n = 0;
        for (auto &w: words) {
            n += w.size();
        }
        n += 2;
        Trie tr(n);
        for (auto &w: words) {
            tr.add(w);
        }
        int m = target.size();
        const int inf = 1e9 + 2;
        vector<int> dp(m + 1, inf);
        dp[0] = 0;
        for (int i = 0; i < m; i++) {
            if (dp[i] >= inf) continue;
            string sub = target.substr(i);
            int res = tr.find(sub);
            if (res < 0) continue;
            if (dp[m] < inf) break;
            for (int k = 1; k <= res + 1; k++) {
                dp[i + k] = min(dp[i + k], 1 + dp[i]);
            }
        }
        return dp[m] < inf ? dp[m] : -1;
    }
};
