class AllOne {
public:
    set<pair<int, string>> st;
    unordered_map<string, int> mp;
    AllOne() {
        
    }
    
    void inc(string key) {
        if (!mp.contains(key)) {
            mp[key] = 0;
            st.insert({mp[key], key});
        }
        st.erase({mp[key], key});
        mp[key]++;
        st.insert({mp[key], key});
    }
    
    void dec(string key) {
        st.erase({mp[key], key});
        if (--mp[key] > 0) {
            st.insert({mp[key], key});
        } else {
            mp.erase(key);
        }
    }
    
    string getMaxKey() {
        return st.empty() ? "" : st.rbegin() -> second;
    }
    
    string getMinKey() {
        return st.empty() ? "" : st.begin() -> second;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
