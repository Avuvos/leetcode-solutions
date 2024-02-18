typedef long long ll;
const int N = 5e5+1;
unordered_map<char, unordered_map<char, int>> trie[N];
int counter[N];

class Trie {
    // vector<unordered_map<char, unordered_map<char, int>>> trie; //mx[0]['a']=1  means that e(0,1)='a'.
    // vector<ll> counter;
    int nodes;
public:
    Trie(int max_len){
        nodes = 0;
        for (int i = 0; i < max_len; i++) {
            trie[i].clear();
            counter[i] = 0;
        }
    }

    ll add(const string& s) {
        int current_node = 0;
        ll res = 0;
        string t = s;
        reverse(t.begin(), t.end());
        for (int i = 0; i < s.size(); i++) {
            char c1 = s[i], c2 = t[i];
            if (trie[current_node][c1][c2] == 0) {
                trie[current_node][c1][c2] = ++nodes;
            }
            current_node = trie[current_node][c1][c2];
            res += counter[current_node];
        }
        ++counter[current_node];
        return res;
    }
};

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        int sz = 0;
        for (auto &word: words) {
            sz += (int) (word.size());
        }
        sz++;
        Trie t(sz);
        ll ans = 0;
        for (auto &word: words) {
            ans += t.add(word);
        }
        return ans;
    }
};
