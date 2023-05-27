class Solution {
public:
    
    struct dsu {
        vector<int> parent;
        vector<int> size_;

        dsu(int n) {
            parent = vector<int>(n);
            for (int i = 0; i < n; i++) parent[i] = i;
            size_ = vector<int>(n, 1);
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
            return true;
        }
    };
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end()) + 2;
        vector<int> p =vector<int>(n + 1, -1);
        p[0] = p[1] = -2;
        for (int i = 2; i * i <= n; i++) {
            if (p[i] == -1) {
                for (int j = i * i; j <= n; j += i)
                    p[j] = i;
            }
        }
        set<int> primes;
        map<int, int> pos;
        int idx = 0;
        if (nums.size() == 1) return true;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int fp = p[x];
            if (x == 1) return false;
            while (x > 1) {
                int z = p[x];
                if (z == -1) z = x; //this means x is a prime!
                while (x % z == 0) x /= z;
                if (primes.find(z) == primes.end()) {
                    primes.insert(z);
                    pos[z] = idx++;
                }                
                
            }
        }
        dsu ds(primes.size());
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int z = p[x];
            if (z == -1) z = x;
            int first_prime = z;
            
            while (x > 1) {
                z = p[x];
                if (z == -1) z = x; //this means x is a prime!
                while (x % z == 0) x /= z;
                ds.union_(pos[first_prime], pos[z]);
            }
        }
        set<int> parents;
        for (int i = 0; i < primes.size(); i++) {
            int par = ds.find_(i);
            parents.insert(par);
        }
        if (parents.size() == 1) return true;
        return false;
        
    }
};
