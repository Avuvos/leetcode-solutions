class Solution {
    char parent[26];
    void make_set(char v) {
        parent[v - 'a'] = v;
    }

    char find_set(char v) {
        if (v == parent[v - 'a'])
            return v;
        return find_set(parent[v - 'a']);
    }

    bool union_sets(char a, char b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            parent[b - 'a'] = a;
            return true;
        }
        return false;
    }

public:
    bool equationsPossible(vector<string>& equations) {
        for (char c = 'a'; c <= 'z'; c++) 
            make_set(c);
        for (auto eq: equations)
            if (eq[1] == '=')
                union_sets(eq[0], eq[3]);
        for (auto eq: equations) {
            if (eq[1] == '=') continue;
            char s1 = find_set(eq[0]);
            char s2 = find_set(eq[3]);
            if (s1 == s2) return false;
        }
        return true;
    }
};
