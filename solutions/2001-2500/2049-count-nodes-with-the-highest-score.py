class Solution:
    def countHighestScoreNodes(self, parents: List[int]) -> int:
        tree = defaultdict(list)
        n = len(parents)
        for i in range(1, n):
            tree[parents[i]].append(i)
        
        sizes = [0] * n
        def dfs(node):
            if len(tree[node]) == 0:
                sizes[node] = 1
                return sizes[node]
            res = 1
            for child in tree[node]:
                res += dfs(child)
            sizes[node] = res
            return sizes[node]
        dfs(0)
        
        scores = [0] * n
        max_score = 0
        for i in range(n):
            s = 1
            for c in tree[i]:
                s *= sizes[c]
            if i != 0:
                s *= (sizes[0] - sizes[i])
            scores[i] = s
            max_score = max(max_score, s)
            
        return sum(1 for s in scores if s == max_score)

        
