class Solution:
    def maxScoreIndices(self, nums: List[int]) -> List[int]:
        N = len(nums)
        pref = [0 for i in range(N + 1)]
        pref[0] = nums[0]
        for i in range(1, N):
            pref[i] = nums[i] + pref[i - 1]
        
        maxScore = 0
        dic = {} #map idx to its score
        for i in range(N):
            lsum = 0 if i == 0 else i - pref[i - 1]
            rsum = pref[N - 1] - pref[i] + nums[i]
            score = lsum + rsum
            dic[i] = score
            maxScore = max(maxScore, score)
        
        dic[N] = N - pref[N - 1]
        maxScore = max(maxScore, dic[N])
        res = []
        
        for k in dic:
            if dic[k] == maxScore:
                res.append(k)
        
        return res
