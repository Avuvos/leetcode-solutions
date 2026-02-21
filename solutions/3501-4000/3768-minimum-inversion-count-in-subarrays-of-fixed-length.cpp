#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef tree<
    pair<int, int>,
    null_type,
    less<pair<int, int>>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

class Solution {
public:
    long long minInversionCount(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 1e18 + 2, inv = 0;
        ordered_set st;
        for (int i = 0; i < n; i++) {
            if (st.size() == k) {
                inv -= st.order_of_key({nums[i - k], i - k});
                st.erase({nums[i - k], i - k});
            }
            st.insert({nums[i], i});
            inv += (st.size() - st.order_of_key({nums[i], i}) - 1);
            if (st.size() == k) {
                ans = min(ans, inv);
            }
        }
        return ans;
    }
};
