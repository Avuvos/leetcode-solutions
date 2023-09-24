class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        //suffix i gives me the first position on the RIGHT that is less than myself, or n if there isnt any
        //prefix i gives me the first position on the LEFT that is less than myself, or -1 if there isnt any.
        
        //lets take index = prefix[i]
        //ps[i + 1] = prefix[index + 1] cuz we want to include maxHeights[index]
        //+ the count of elements that im in the minimum
        //which is equal to i - index
        //[5, 2, 4, 4, 3]
        //we have i = 4 and index = 1
        //so we add i - index = 3
        //[5, 2, 4, 1]
        //now on i = 4, index = -1
        //we add 3 - (-1) = 4 which is good.
        
        
        //now we do the same idea of the suffix, but notice suffix[i] actually does contain the values for the ith element
        //so we are at i and our index is index.
        //we want to add (index - i)
        //[5, 4, 2, 6, 7, 1]
        //i = 2, index = 5
        //indeed we need to add 5 - 2 = 3
        //and then add sf[5]
        
        int n = (int) maxHeights.size();
        vector<int> prefix(n, -1), suffix(n, n);
        vector<int> stk;
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && maxHeights[stk.back()] >= maxHeights[i]) {
                prefix[stk.back()] = i;
                stk.pop_back();
            }
            stk.push_back(i);
        }
        while (!stk.empty()) stk.pop_back();
        
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && maxHeights[stk.back()] >= maxHeights[i]) {
                suffix[stk.back()] = i;
                stk.pop_back();
            }
            stk.push_back(i);
        }
        
        vector<long long> ps(n + 1, 0), sf(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int index = prefix[i]; 
            ps[i + 1] = ps[index + 1] + 1LL * maxHeights[i] * (i - index);
        }

        for (int i = n - 1; i >= 0; i--) {
            int index = suffix[i];
            sf[i] = sf[index] + 1LL * maxHeights[i] * (index - i);
        }
        
        
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long cur = sf[i] + ps[i];
            ans = max(ans, cur);
        }
        return ans;
    }
};
