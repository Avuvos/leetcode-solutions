class Allocator {
public:
    vector<int> arr;
    int arr_size;
    Allocator(int n) {
        arr = vector<int>(n, -1);
        arr_size = n;
    }
    
    int allocate(int size, int mID) {
        int streak = 0;
        for (int i = 0; i < arr_size; i++) {
            if (arr[i] == -1) {
                streak++;
            } else {
                streak = 0;
            }
            if (streak == size) {
                for (int j = i - size + 1; j <= i; j++) {
                    arr[j] = mID;
                }
                return i - size + 1;
            }
        }
        return -1;
    }
    
    int free(int mID) {
        int cnt = 0;
        for (int i = 0; i < arr_size; i++) {
            if (arr[i] == mID) {
                cnt++;
                arr[i] = -1;
            }
        }
        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */
