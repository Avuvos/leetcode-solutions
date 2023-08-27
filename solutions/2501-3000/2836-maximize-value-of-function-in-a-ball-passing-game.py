class Solution:
    def getMaxFunctionValue(self, receiver: List[int], k: int) -> int:
        LOG = 40
        n = len(receiver)
        parent = [[0 for _ in range(n)] for _ in range(LOG)]
        value = [[0 for _ in range(n)] for _ in range(LOG)]
        
        for node in range(n):
            parent[0][node] = receiver[node]
            value[0][node] = node
        
        for bit in range(1, LOG):
            for node in range(n):
                parent[bit][node] = parent[bit - 1][parent[bit - 1][node]]
                value[bit][node] = value[bit - 1][parent[bit - 1][node]] + value[bit - 1][node]
        
        
        ans = 0
        k += 1
        for start in range(n):
            node = start
            s = 0
            for bit in range(LOG):
                if (k >> bit) & 1:
                    s += value[bit][node]
                    node = parent[bit][node]
            ans = max(ans, s)
        
        return ans
