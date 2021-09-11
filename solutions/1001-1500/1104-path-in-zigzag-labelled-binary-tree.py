class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        res = []
        n = label
        
        while n > 1:    
            res.append(n)
            depth = int(math.log(n, 2)) #the required next node's depth
            offset = (2**(depth+1))-1-n #the length between 2^depth to current node
            n = (2**depth + offset)//2 #calculate the new node
            
        res.append(1)
        return res[::-1]
