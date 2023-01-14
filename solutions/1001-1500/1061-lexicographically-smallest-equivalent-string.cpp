
class Solution {
    struct dsu {
    vector<int> parent;
    vector<int> size_;
    vector<char> min_element;

    dsu(int n) {
        parent = vector<int>(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        size_ = vector<int>(n, 1);
        min_element = vector<char>(n);
        for (int i = 'a'; i <= 'z'; i++) min_element[i - 'a'] = i;
    }

    int find_(int x) {
        int root = x;
        while (root != parent[root]) {
            root = parent[root];
        }
        //Path compression
        while (parent[x] != root) {
            int p = parent[x];
            parent[x] = root;
            x = p;
        }
        return root;
    }
    bool union_(int x,int y) {
        int X = find_(x);
        int Y = find_(y);
        // x and y are already in the same set
        if (X == Y) return false;

        // x and y are not in same set, so we merge them
        if (size_[X] < size_[Y]) swap(X, Y);

        // merge yRoot into xRoot
        parent[Y] = X;
        size_[X] += size_[Y];
        min_element[X] = min(min_element[X], min_element[Y]);
        return true;
    }
};
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        dsu ds(26);
        for (int i = 0; i < s1.size(); i++) {
            ds.union_(s1[i] - 'a', s2[i] - 'a'); 
        }
        string ans;
        for (auto c: baseStr) {
            int cp = ds.find_(c - 'a');
            ans += ds.min_element[cp];
        }
        return ans;
    }
};
