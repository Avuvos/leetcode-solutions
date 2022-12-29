class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        lst = sorted([(a, b, i) for i, (a, b) in enumerate(tasks)])
        heap = []
        heapq.heappush(heap, (lst[0][1], lst[0][2]))
        time = lst[0][0]
        ans = []
        index = 1
        while index < len(lst) or heap:
            while index < len(lst) and lst[index][0] <= time:
                heapq.heappush(heap, (lst[index][1], lst[index][2]))
                index += 1
            if heap:
                ans.append(heap[0][1])
                time += heap[0][0]
                heapq.heappop(heap)
            else:
                time = lst[index][0]
        return ans
            
        
                    
