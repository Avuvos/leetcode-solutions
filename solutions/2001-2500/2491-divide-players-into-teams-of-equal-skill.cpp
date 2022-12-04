typedef long long ll;
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        ll sum = 0;
        for (auto s: skill) sum += s;
        if (sum % (n/2) != 0) return -1;
        
        sort(skill.begin(), skill.end());
        ll s = sum / (n / 2);
        int l = 0, r = n - 1;
        ll prod = 0;
        while (l < r) {
            if (skill[l] + skill[r] != s) return -1;
            prod += skill[l] * skill[r];
            l++;
            r--;
        }
        return prod;
        
        
    }
};
