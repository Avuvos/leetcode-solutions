class Solution:
    def findHighAccessEmployees(self, access_times: List[List[str]]) -> List[str]:
        mp = defaultdict(list)
        for s, t in access_times:
            mp[s].append(t)
        from datetime import timedelta
        ans = []
        for s, t in mp.items():
            t.sort()
            # print(s, t)
            for i in range(0, len(t) - 2):
                d1 = timedelta(hours = int(t[i][0:2]),minutes = int(t[i][2::]))
                d2 = timedelta(hours = int(t[i + 2][0:2]), minutes = int(t[i + 2][2::]))
                # print(d1, d2)
                d3 = d2 - d1
                # print(d3, d3.seconds)
                if d3.seconds < 3600:
                    ans.append(s)
                    break
        return ans
                              
