class Solution:
    def findLucky(self, arr: List[int]) -> int:
        
        d = {} #keys are the numbers, values are the frequency of the number
        lucky_lst = [] #lucky numbers list
        
        for num in arr: #O(n)
            if num in d: #O(1) on average
                d[num] += 1 #add one to the frequency
            else:
                d[num] = 1 #frequency is one      
                
        for key in d: #O(n)
            if d[key] == key: #check if the number is lucky
                lucky_lst.append(key)
                
        if lucky_lst: #return max if it exsists, else return -1
            return max(lucky_lst) #again O(n)
        else:
            return -1
        
        #in total the time complexity is O(n) :D
