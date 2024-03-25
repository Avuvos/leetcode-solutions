typedef long long ll;
class Trie {
    vector<unordered_map<char, int>> trie; //mx[0]['a']=1  means that e(0,1)='a'.
    vector<int> counter;
    vector<pair<int, int>> min_index;
    int nodes;
public:
    Trie(int max_len){
        nodes = 0;
        trie = vector<unordered_map<char, int>>(max_len);
        counter = vector<int>(max_len);
        min_index = vector<pair<int, int>>(max_len, {-1, -1});
    }

    void add(string& s, int index) {
        int current_node = 0;
        for (auto chr : s) {
            // c key in map mx[v] is exists or created here.
            if (trie[current_node][chr] == 0) {
                trie[current_node][chr] = ++nodes;
            }
            current_node = trie[current_node][chr];
            if (min_index[current_node].first == -1 || min_index[current_node].second > s.size()) {
                min_index[current_node].first = index;
                min_index[current_node].second = s.size();
            }
        }
        ++counter[current_node];
        if (min_index[current_node].first == -1 || min_index[current_node].second > s.size()) {
            min_index[current_node].first = index;
            min_index[current_node].second = s.size();
        }
    }

    int find(string& s) {
        int current_node = 0;
        int ans = -1;
        for (auto chr : s) {
            if (trie[current_node][chr] == 0) {
                return ans;
            }
            current_node = trie[current_node][chr];
            ans = min_index[current_node].first;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int mx = 17;
        for (auto &w: wordsContainer) mx += (int) w.size();
        Trie tr(mx);
        int mn_len = mx, mn_index = -1;
        for (int i = 0; i < wordsContainer.size(); i++) {
            string word = wordsContainer[i];
            reverse(word.begin(), word.end());
            tr.add(word, i);
            if (word.size() < mn_len) {
                mn_len = word.size();
                mn_index = i;
            }
        }
        int q = (int) wordsQuery.size();
        vector<int> ans(q, mn_index);
        for (int i = 0; i < q; i++) {
            string cur = wordsQuery[i];
            reverse(cur.begin(), cur.end());
            int index = tr.find(cur);
            if (index != -1) {
                ans[i] = index;
            }
        }
        return ans;
    }
};
