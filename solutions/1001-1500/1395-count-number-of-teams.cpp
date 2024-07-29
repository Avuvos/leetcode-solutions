#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<>,rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = int(rating.size());
        int ans = 0;
        vector<int> smaller_before(n), smaller_after(n);
        indexed_set st;
        for (int i = 0; i < n; i++) {
            st.insert(rating[i]);
            smaller_before[i] = st.order_of_key(rating[i]);
        }
        st.clear();
        for (int i = n - 1; i >= 0; i--) {
            st.insert(rating[i]);
            smaller_after[i] = st.order_of_key(rating[i]);
        }
        
        for (int j = 1; j < n - 1; j++) {
            ans += smaller_before[j] * (n - j - 1 - smaller_after[j]);
            ans += (j - smaller_before[j]) * smaller_after[j];
        }
        
        return ans;
    }
};
