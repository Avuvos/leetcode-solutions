#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less_equal<>,rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1 = {nums[0]}, arr2 = {nums[1]};
        indexed_set st1, st2;
        st1.insert(nums[0]);
        st2.insert(nums[1]);

        auto greater_count = [&](indexed_set &st, int x) -> int {
            st.insert(x);
            int val = st.order_of_key(x + 1);
            st.erase(st.lower_bound(x - 1));
            return st.size() - val;
        };

        for (int i = 2; i < nums.size(); i++) {
            int c1 = greater_count(st1, nums[i]);
            int c2 = greater_count(st2, nums[i]);
            if ((c2 > c1) || (c1 == c2 && arr2.size() < arr1.size())) {
                st2.insert(nums[i]);
                arr2.push_back(nums[i]);
            } else {
                st1.insert(nums[i]);
                arr1.push_back(nums[i]);
            }
           
        }
        vector<int> result(arr1.begin(), arr1.end());
        for (auto &x: arr2) result.push_back(x);
        return result;
    }
};
