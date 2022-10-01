class LUPrefix {
public:
    set<int> vids;
    int total;
    LUPrefix(int n) {
        for (int vid = 1; vid <= n; ++vid) {
            vids.insert(vid);
        }
        total = n;
    }

    void upload(int video) {
        vids.erase(video);
    }

    int longest() {
        auto first = *(vids.begin());
        if (first == 1) return 0;
        if (vids.size() == 0) return total;
        return first - 1;
    }
};
/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
