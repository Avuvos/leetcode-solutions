class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, k: int) -> int:
        G = defaultdict(list)
        for u, v, w in flights:
            G[u].append((v, w))
        
        seen = {}
        heap = [(0, 0, src)]
        #dijkstra
        while heap:
            dist, stops, node = heappop(heap)
            if node == dst and stops <= k + 1: return dist
            
            if node not in seen or seen[node] > stops:
                seen[node] = stops
                for v, w in G[node]:
                    heappush(heap, (dist + w, stops + 1, v))
                
        return -1
        
