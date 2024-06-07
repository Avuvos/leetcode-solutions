class Solution {
public:
    
    class Trie {
        vector<unordered_map<char, int>> tree;
        vector<int> counter;   
        int nodes;
    public:
        Trie(int max_len) {
            nodes = 0;
            tree.resize(max_len);
            counter.resize(max_len, 0);
        }
        
        void add(string &s) {
            int current = 0;
            for (auto &c: s) {
                if (tree[current][c] == 0) {
                    tree[current][c] = ++nodes;
                }
                current = tree[current][c];
            }
            ++counter[current];
        }
        
        int find(string &s) {
            int current = 0;
            int sz = 0;
            for (auto &c: s) {
                if (tree[current][c] == 0) {
                    return s.size();
                }
                sz++;
                current = tree[current][c];
                if (counter[current] > 0) {
                    return sz;
                }
            }
            return s.size();
        }
        
    };
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        int len = 0;
        for (auto &w: dictionary) {
            len += (int) w.size();
        }
        Trie tr(len + 17);
        for (auto &w: dictionary) {
            tr.add(w);
        }
        int n = (int) sentence.size();
        int i = 0;
        string ans;
    
        while (i < n) {
            string cur;
            while (i < n && !isspace(sentence[i])) {
                cur += sentence[i];
                i++;
            }
            i++;
            len = tr.find(cur);
            ans += cur.substr(0, min(len, (int)cur.size()));
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};
